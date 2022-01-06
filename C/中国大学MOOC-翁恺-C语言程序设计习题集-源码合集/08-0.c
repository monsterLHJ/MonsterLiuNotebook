#include<stdio.h>
int main()
{   
    int N,X;
	int a,i,loc=0;
	scanf("%d%d",&N,&X);
	for(i=1;i<=N;i++)
	{
		scanf("%d",&a);
		if(X==a)
		{
			loc=i;
			printf("%d",loc-1);
		}
	}
	if(loc==0)
		printf("Not Found");

	return 0;
}
