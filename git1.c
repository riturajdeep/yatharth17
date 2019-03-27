#include<stdio.h> 
// Function to find the waiting time for all 
// processes 
void findWaitingTime(int processes[], int n, 
                        int bt[], int wt[]) 
{ 
    // waiting time for first process is 0 
    wt[0] = 0; 
    
    // calculating waiting time 
    for (int i = 1; i < n ; i++ ) 
        wt[i] = bt[i-1] + wt[i-1] ; 
} 
    
// Function to calculate turn around time 
void findTurnAroundTime( int processes[], int n, 
                int bt[], int wt[], int tat[]) 
{ 
    // calculating turnaround time by adding 
    // bt[i] + wt[i] 
    for (int i = 0; i < n ; i++) 
        tat[i] = bt[i] + wt[i]; 
