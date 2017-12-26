/*
 *  pthread_hello.h
 *  
 *
 *  Created by Ankush Mittal on 01/03/15.
 *  Copyright 2015 IIT. All rights reserved.
 *
 */

#include <stdio.h>
#include <sys/types.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>
#define MAX 900

time_t t1,t2;
int A[3];
long long a[MAX][MAX],b[MAX][MAX],c[MAX][MAX]={0},i,j,k;
pthread_t threads1, threads2, threads3; //threads4;

void *hello1(void *arg)
{
	
	printf("Hello 1 from node \n");
	//printf("Enter data for thread 1: ");
	/*for(i=0;i<(MAX/3);i++)
	{
		for(j=0;j<(MAX/3);j++)
		{
			scanf("%d",&a[i][j]);
		}
	}*/
	for(i=0;i<(MAX/3);i++)
	{
		for(j=0;j<(MAX);j++)
		{
			c[i][j]=0;
			for(k=0;k<(MAX);k++)
			{
				c[i][j]=c[i][j] + (a[i][k] * b[k][j]) ;
			}
		}	
	}
	
	return (NULL);
}

void *hello2(void *arg)
{
	
	printf("Hello 2 from node \n");
	pthread_join(threads1,NULL);
	//printf("Enter data for thread 2: ");
	/*for(i=(MAX/3);i<2*(MAX/3);i++)
	{
		for(j=(MAX/3);j<2*(MAX/3);j++)
		{
			scanf("%d",&a[i][j]);
		}
	}*/
	for(i=(MAX/3);i<2*(MAX/3);i++)
	{
		for(j=0;j<(MAX);j++)
		{
			c[i][j]=0;
			for(k=0;k<(MAX);k++)
			{
				c[i][j]=c[i][j] + (a[i][k] * b[k][j]) ;
			}
		}	
	}
	return (NULL);
}
void *hello3(void *arg)
{
	
	printf("Hello 3 from node \n");
	pthread_join(threads2,NULL);
	//printf("Enter data for thread 3: ");
	/*for(i=2*(MAX/3);i<3*(MAX/3);i++)
	{
		for(j=2*(MAX/3);j<3*(MAX/3);j++)
		{
			scanf("%d",&a[i][j]);
		}
	}*/
	for(i=2*(MAX/3);i<3*(MAX/3);i++)
	{
		for(j=0;j<(MAX);j++)
		{
			c[i][j]=0;
			for(k=0;k<(MAX);k++)
			{
				c[i][j]=c[i][j] + (a[i][k] * b[k][j]) ;
			}
		}	
	}
	return (NULL);
}
/*void *hello4(void *arg)
{
	
	printf("Hello 4 from node \n");
	pthread_join(threads3,NULL);
	//printf("Enter data for thread 4: ");
	for(i=3*(MAX/4);i<4*(MAX/4);i++)
	{
		a[i]=rand();
		s4=s4+a[i];
	}
	return (NULL);
}*/

int main(int argc, char* argv[]) {
	
	pthread_attr_t pthread_custom_attr1, pthread_custom_attr2, 		     pthread_custom_attr3; /*pthread_custom_attr4;*/
	int *p;
	int temp;
	for(i=0;i<(MAX);i++)
	{
		for(j=0;j<(MAX);j++)
		{
			a[i][j]=rand();
			b[i][j]=rand();
		}
	}
	

	pthread_attr_init(&pthread_custom_attr1);
	pthread_create(&threads1, &pthread_custom_attr1, hello1, (void *)(p));
	pthread_attr_init(&pthread_custom_attr2);
	pthread_create(&threads2, &pthread_custom_attr2, hello2, (void *)(p));
	pthread_attr_init(&pthread_custom_attr3);
	pthread_create(&threads3, &pthread_custom_attr3, hello3, (void *)(p));
	/*pthread_attr_init(&pthread_custom_attr4);
	pthread_create(&threads4, &pthread_custom_attr4, hello4, (void *)(p));*/
	
	
	(void) time(&t1);
	pthread_join(threads3,NULL);
	(void) time (&t2);
	for(i=0;i<(MAX);i++)
	{
		for(j=0;j<(MAX);j++)
		{
			printf("%lld\t",c[i][j]);
		}
		printf("\n");	
	}
	printf("Time= %2f\n",(double) t2-t1);
	
}
