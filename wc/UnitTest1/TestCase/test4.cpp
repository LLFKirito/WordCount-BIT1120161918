#include<stdio.h>
#include<math.h>
int main()
{
    int k,M,N;
	double x,y;
    scanf("%d %d",&N,&M);   
	if(N==1) k=2;
	else if(M==2) k=M;
	else k=1;	
	x=1.0*k*pow(1.0*M,1.0*N)+1-M;	
	y=pow(1.0*(M-1)/M,1.0*N)*(x+M-1.0)+1-M;	
	printf("%.0lf\n%.0lf\n",y,x);
	return 0;
}
