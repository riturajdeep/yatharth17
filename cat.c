#include<stdio.h>
#inlcude<pthread.h>

pthread_mutex_t ca;
int food=1;

void cat()
{
	pthread_mutex_lock(&ca);
	pthread_mutex_lock(&ca1);
	printf("Cat eatng food..");
	printf("Cat finesh food..");
	pthread_mutex_unlock(&ca1);
	sleep(1);
	pthread_mutex_unlock(&ca);
}

void mouse()
{
	
	pthread_mutex_lock(&ca);
	pthread_mutex_lock(&ca1);
	printf("Mouse eatng food..");
	printf("Mouse fineshed food..");
	pthread_mutex_unlock(&ca);
	sleep(1);
	pthread_mutex_unlock(&ca1);
}

void main()
{
	printf("Food is smelling yummy....");
	
	pthread_create(&ca, NULL, cat, NULL);
	pthread_create(&ca1, NULL, mouse, NULL);
	pthread_join(ca, NULL);
	pthread_join(ca1, NULL);
	
	printf("Food is eaten..");
}