#include<stdio.h>
int main()
{
	int i,n,m,t,sum;
	int f(int t,int n,int m);
	scanf("%d %d",&n,&m);
	for(i=1;;i++)             
	{      
		sum=f(i,n,m);    //
		if(sum!=0) 
		{
			printf("%d\n",i*(m-1));
			printf("%d\n",sum);
			break; 
		}
	}
	return 0;
} 
int f(int t,int n,int m)
{
	int i,temp;
	if(n==1)             //
		{
			return (n*m+1);
		}
	for(i=n-1;i>=1;i--)
	{
		
		if((t*m+1)%(m-1)!=0)  return 0;
		else
		{
			temp=(t*m+1)/(m-1);
			t=temp;
		}  
	}
	return (temp*m+1);
}
