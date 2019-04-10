#include<stdio.h>
#include<unistd.h>
#include<semaphore.h>
#include<pthread.h>
int NumCats,NumBowl,NumMice,all_cats,all_Bowl,all_Mice;
sem_t food;
void *CatsEating()
{
	if(NumCats<=all_cats && NumBowl<=all_Bowl && NumBowl > 0 && NumCats > 0)
	{
		sem_wait(&food);
		NumBowl--;
		NumCats--;
		printf("\n\n Cat %d have eaten the bowl %d",all_cats-NumCats,all_Bowl-NumBowl);
		sem_post(&food);
	}
}
void *MiceEating()
{
	if(NumMice<=all_Mice && NumBowl<=all_Bowl && NumBowl>0 && NumMice>0)
	{
		sem_wait(&food);
		NumBowl--;
		NumMice--;
		printf("\n Mice %d have eaten the bowl %d", all_Mice-NumMice,all_Bowl-NumBowl);
		sem_post(&food);
	}
	else return 0;
}
int main()
{
	pthread_t th,th1;
	printf("\n Enter the total no. of cats :");
	scanf("%d",&NumCats);
	printf("\n Enter the total no. of mice :");
	scanf("%d",&NumMice);
	printf("\n Enter the total no. of Bowl of food :");
	scanf("%d",&NumBowl);
	printf("\n **************************************\n");
	all_cats=NumCats;
	all_Bowl=NumBowl;
	all_Mice=NumMice;
	sem_init(&food,0,1);
	while((NumBowl>0) && (NumCats>0 || NumMice > 0))
	{
		pthread_create(&th,NULL,CatsEating,NULL);
		pthread_create(&th1,NULL,MiceEating,NULL);
	}
	while((NumBowl>0) && (NumCats>0 || NumMice>0))
	{
		pthread_join(th,NULL);
		pthread_join(th1,NULL);
	}
	printf("\n\n***************************************\n");
	return 0;	
}
