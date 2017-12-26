#include<stdio.h>
#include<time.h>
#include<stdlib.h>

# define MAX 100
int main()
{
	time_t t1,t2;
	long long a[MAX][MAX],b[MAX][MAX],c[MAX][MAX] = {0},i,j,k,**p1,**p2,**p3;
	p1 = (long long **)malloc(MAX*sizeof(long long*));
	p2 = (long long **)malloc(MAX*sizeof(long long*));
	p3 = (long long **)malloc(MAX*sizeof(long long*));
	for(i=0;i<MAX;i++)
		p1[i] = (long long **)malloc(MAX*sizeof(long long));
	for(i=0;i<MAX;i++)
		p2[i] = (long long **)malloc(MAX*sizeof(long long));
	for(i=0;i<MAX;i++)
		p3[i] = (long long **)malloc(MAX*sizeof(long long));
	for(i=0;i<MAX;i++)
	{
		for(j=0;j<MAX;j++)
			{
				p1[i][j] = rand();
				p1[i][j] = p1[i][j]%10;
			}
	}
	for(i=0;i<MAX;i++)
	{
		for(j=0;j<MAX;j++)
			{
				p2[i][j] = rand();
				p2[i][j] = p2[i][j]%10;
			}
	}
	(void) time(&t1);
	for(i=0;i<MAX;i++)
	{
		for(j=0;j<MAX;j++)
			{
			p3[i][j]=0;
				for(k=0;k<MAX;k++)
					{
						p3[i][j] = p3[i][j] + (p1[i][k] * p2[k][j]);
					}
			}
	}
	(void) time(&t2);
	
	for(i=0;i<MAX;i++)
	{
		for(j=0;j<MAX;j++)
			{
				printf("%lld\t",p3[i][j]);
			}
		printf("\n");
	}
	printf("TIME : %d\n", (int) (t2-t1));
	free(p1);
	free(p2);
	free(p3);
	return 0;				
	
}
