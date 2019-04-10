#include<stdio.h>
void findwt(int Process[],int n,int burst_time[],int wait_time[],int arrival_time[])
{
	wait_time[0]=0;
	int i;
	for(i = 1;i<n;i++)
	{
		wait_time[i]=burst_time[i-1]+wait_time[i-1];
	}
}
void findtat(int Process[],int n, int burst_time[],int wait_time[],int tat[])
{
	int i;
	for(i=0;i<n;i++)
	{
		tat[i]=burst_time[i]+wait_time[i];
	}
}

void fcfs(int Process[],int n,int burst_time[],int arrival_time[])
{
	int wait_time[n], total_wait_time=0; int tat[n], total_tat=0;
	findwt(Process,n,burst_time,wait_time,arrival_time);
	findtat(Process,n,burst_time,wait_time,tat);
	int i;
	printf("\n\n");
	printf("                First come first serve                 \n");
	printf("Process\t Arrival Time\t Burst Time\t Waiting time\t TurnArroundTime\n");
	for(i=0;i<n;i++)
	{
		total_wait_time=total_wait_time+wait_time[i];
		total_tat=total_tat+tat[i];
		printf("P%d",i+1);
        printf("           %d\t",arrival_time[i]);
		printf("          %d\t",burst_time[i]);
		printf("               %d\t",wait_time[i]);
		printf("        %d\t",tat[i]);
		printf("\n");
	}
	int a=(float)total_wait_time/(float)n;
	int b=(float)total_tat/(float)n;
	printf("Average Waiting time is : %d ",a);
    printf("\nAverage Turn Around Time is : %d ",b);
	
}
void sjf(int Process[],int burst_time[], int n,int arrival_time[])
{
	int wait_time[n],tat[n],i,j,temp,total=0,pos;
	float avg_wait_time,avg_tat;
	 //sorting burst time in ascending order using selection sort
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(burst_time[j]<burst_time[pos])
                pos=j;
        }
 
        temp=burst_time[i];
        burst_time[i]=burst_time[pos];
        burst_time[pos]=temp;
 
        temp=Process[i];
        Process[i]=Process[pos];
        Process[pos]=temp;
    }
 
    wait_time[0]=0;            //waiting time for first process will be zero
 
    //calculate waiting time
    for(i=1;i<n;i++)
    {
        wait_time[i]=0;
        for(j=0;j<i;j++)
            wait_time[i]+=burst_time[j];
 
        total+=wait_time[i];
    }
 
    avg_wait_time=(float)total/n;      //average waiting time
    total=0;
    printf("\n\n");
    printf("                 Shortest Job First                  ");
    printf("\nProcess\t    Arrival Time  \tBurst Time    \tWaiting Time  \tTurnaround Time");
    for(i=0;i<n;i++)
    {
        tat[i]=burst_time[i]+wait_time[i];     //calculate turnaround time
        total+=tat[i];
        printf("\nP%d\t\t %d\t\t %d\t\t    %d\t\t\t%d",Process[i],arrival_time[i],burst_time[i],wait_time[i],tat[i]);
    }
 
    avg_tat=(float)total/n;     //average turnaround time
    printf("\n\nAverage Waiting Time=%f",avg_wait_time);
    printf("\nAverage Turnaround Time=%f\n",avg_tat);
	
}
void idle_condition(int Process[],int bt[],int n,int arrival_time[])
{
	int wait_time[n],tat[n],i,j,temp,total=0,pos;
	float avg_wt,avg_tat;
	 //sorting burst time in ascending order using selection sort
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(bt[j]<bt[pos])
                pos=j;
        }
 
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
 
        temp=Process[i];
        Process[i]=Process[pos];
        Process[pos]=temp;
    }
 
    wait_time[0]=1;            //waiting time for first process is one due to idle condition
 
    //calculate waiting time
    for(i=1;i<n;i++)
    {
        wait_time[i]=1;
        for(j=0;j<i;j++)
            wait_time[i]+=bt[j];
 
        total+=wait_time[i];
    }
 
    avg_wt=(float)total/n;      //average waiting time
    total=0;
    printf("\n\n");
    printf("             Cpu is in Idle Condition  for 1 unit             ");
    printf("\nProcess\t   Arrival Time \t Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wait_time[i];     //calculate turnaround time
        total+=tat[i];
        printf("\nP%d\t\t %d\t\t %d\t\t    %d\t\t\t%d",Process[i],arrival_time[i],bt[i],wait_time[i],tat[i]);
    }
 
    avg_tat=(float)total/n;     //average turnaround time
    printf("\n\nAverage Waiting Time=%f",avg_wt);
    printf("\nAverage Turnaround Time=%f\n",avg_tat);
}

int main()
{
   int Process[20],burst_time[20],arrival_time[20],n,i;
   printf("Enter the total number of Process to be executed: \n");
   scanf("%d",&n);
   printf("\nEnter Burst Time and Arrival time:\n");
    for(i=0;i<n;i++)
    {
        printf("P%d:",i+1);
        scanf("%d  %d",&burst_time[i],&arrival_time[i]);
        Process[i]=i+1;         //contains process number
    }
   fcfs(Process,n,burst_time,arrival_time);
   sjf(Process,burst_time,n,arrival_time);
   idle_condition(Process,burst_time,n,arrival_time);
}
