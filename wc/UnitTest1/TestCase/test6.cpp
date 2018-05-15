#include<stdio.h>
int main()
{
	int test,M,N,i,j;
	scanf("%d %d",&M,&N);
	for(i=1;i<=100000000;i++)
	{
		test=i;
		for(j=1;j<=M;j++)
		{	
			if(test%(N-1)!=0)
				break;
			test=test*N/(N-1)+1;
		}
		if(j==M+1)
			break;
	}
	printf("%d\n%d\n",i,test);
	return 0;
}

