#include<stdio.h>
int main()
{   
	int A[10];
	int i,j,k;
	for(i=0;i<10;i++)
	{
		scanf("%d",&A[i]);
	}
	for(j=1;j<10;j++)
	{
		for(;A[j]>0;A[j]--)
		{
		     printf("%d",j);
			 for(;A[0]>0;A[0]--)
				 printf("0");
		}
	}
	return 0;
}
