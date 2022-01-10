#include<stdio.h>
int main(){
	int N;
	int i,j;
	scanf("%d",&N);
	for(i=1;i<=N;i++)
	{
		for(j=1;j<=i;j++)
		{
			printf("%d*%d=%-4d",j,i,i*j);	
		}
		printf("\n");
	}
	return 0;
}