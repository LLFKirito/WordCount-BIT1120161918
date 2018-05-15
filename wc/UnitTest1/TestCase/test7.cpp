#include<stdio.h>
#include<string.h>
#define isletter(x) (((x)>64&&(x)<91)||((x)>96&&(x)<123))
char model[25]={0},a[110]={0};
int lm,la;
int visit[25][110];
int search(int i,int j)
{
	if(visit[i][j]) return 0;
	visit[i][j]=1;
	int flag=1,k,fm,fa;
	while(i<lm)
	{	if(model[i]=='$'&&a[j]!=0)
			{ flag=0;break; }
		if(model[i]=='$'&&a[j]==0)
			{ break; }
		if(j>la) break;
		
		if( isletter(model[i]) && model[i+1]=='?' )
		{	if(model[i]!=a[j])
			{	i+=2;
				continue;	
			}
			else if(a[j]==model[i]&&a[j]!=model[i+2])
			{	i+=2;j+=1;
				continue;
			}
			else
			{	flag=search(i+2,j);
			    if(flag==1) break;
			    else
				{	flag=search(i+2,j+1);
					break;
				}
			}
		}
		else if( model[i]=='.' && model[i+1]=='?' )
		{	flag=search(i+2,j);
			if(flag==1) break;
			else
			{	flag=search(i+2,j+1);
				break;
			}
		}
		else if( isletter(model[i]) && model[i+1]=='*' )
		{	if(model[i+2]==0)
				{break;}
			else if(model[i]!=a[j])
			{	i+=2;
				continue;	
			}
			else if(a[j]==model[i])
			{	if(model[i+2]!=model[i])
				{	for(k=j;a[k]==a[j];k++)  {;}
					i+=2;j=k;
					continue;
				}
				else
				{	for(fm=0,k=i+2;model[k]==model[i]&&model[k+1]!='+'&&model[k+1]!='*'&&model[k+1]!='?';k++)
						{fm++;}
					for(fa=1,k=j+1;a[k]==a[j];k++)
						{fa++;}
					if(fa<fm)
						{flag=0;break;}
					else
					{	i=i+fm+2;
						for(k=j+fa;k>=j+fm;k--)
						{	flag=search(i,k);
							if(flag==1) return 1;
						}
						if(flag==0) break;
					}
				}
			}
		}	
		else if( model[i]=='.' && model[i+1]=='*' )
		{	if(model[i+2]==0)
				{break;}
			else
			{	for(k=j;(a[k]==a[j]||a[k-1]==a[j]||a[k]==0)&&k<=la;k++)
				{	flag=search(i+2,k);
					if(flag==1) return 1;
				}
				if(flag==0) break;
			}	
		}
		else if( isletter(model[i]) && model[i+1]=='+' )
		{	if(model[i]!=a[j])
				{ flag=0;break; }
			else if(model[i+2]==0)  break;
			else
			{	for(fm=1,k=i+2;model[k]==model[i]&&model[k+1]!='+'&&model[k+1]!='*'&&model[k+1]!='?';k++)
					{fm++;}
				for(fa=1,k=j+1;a[k]==a[j];k++)
					{fa++;}
				if(fa<fm)
					{flag=0;break;}
				else
				{	i=i+fm+1;
					for(k=j+fa;k>=j+fm;k--)
					{	flag=search(i,k);
						if(flag==1) return 1;
					}
					if(flag==0) break;
				}
			}
		}
		else if( model[i]=='.' && model[i+1]=='+' )
		{	if(a[j]==0)
				{flag=0;break;}
			else
			{	if(model[i+2]==0) break;
				else
				{	for(k=j+1;(a[k-1]==a[j]||a[k]==0)&&k<=la;k++)
					{	flag=search(i+2,k);
						if(flag==1) 
						return 1;
					}
					if(flag==0) break;
				}
			}
		}
		else if( model[i]=='.')
		{	if( isletter(a[j]) )
				{ i++;j++;continue; }	
			else
				{ flag=0;break; }
		}		
		else if( isletter(model[i]) )
		{	if( a[j]==model[i])
				{i++;j++;continue;}	
			else
				{ flag=0;break; }
		}
	}
	return flag;
}
int main()
{
	int j,flag;
	scanf("%s",model);
	lm=strlen(model);
	while( ~scanf("%s",a) )
	{	flag=1;
		memset(visit,0,sizeof visit);
		la=strlen(a);
		if(model[0]=='^')  flag=search(1,0);
		else
		{	for(j=0;j<la;j++)
			{
				flag=search(0,j);
				if(flag==1) break;
			}
		}
		if(flag==0) printf("NO\n");
		else printf("YES\n");
		memset(a,0,sizeof(a));
	}
	return 0; 
} 
