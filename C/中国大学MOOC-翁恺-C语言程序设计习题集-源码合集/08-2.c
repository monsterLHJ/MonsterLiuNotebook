#include<stdio.h>
int main()
    {
    int M,N;
    int i,j,flag=0;
	int arr[20][20];
    int n[20][20];
    scanf("%d%d",&M,&N);
    for(i=0;i<M;i++)
	{
        for(j=0;j<N;j++)
		{
            scanf("%d",&arr[i][j]);
        }
    }
    for(i=1;i<M-1;i++)
    {
        for(j=1;j<N-1;j++)
		{
			if(arr[i][j]>arr[i][j+1]&&arr[i][j]>arr[i][j-1]
			&&arr[i][j]>arr[i+1][j]&&arr[i][j]>arr[i-1][j])
			{
				printf("%d %d %d\n",arr[i][j],i+1,j+1);
				flag=1;
			}
        }
    }
	if(flag==0)
		printf("None %d %d",M,N);
}