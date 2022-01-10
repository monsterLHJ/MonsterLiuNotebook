#include<stdio.h>
#include<string.h>
int main()
{   
	int N,i,a;
	int Max;
	int arr[10]={0};        //用来存放每个数字出现的次数
	char str[30]="",str_temp[10];
	scanf("%d",&N);
	for(i=1;i<=N;i++)
	{
		scanf("%d",&a);
		for(;a>0;)
		{
			arr[a%10]++;
			a=a/10;
		}
	}
	Max=0;                     //初始化最大次数为0
	for(i=0;i<10;i++)
	{
		if (arr[i]>Max)
			Max=arr[i];
	}
	printf("%d:",Max);
	for(i=0;i<10;i++)
	{
		if(arr[i]==Max)
			printf(" %d",i);
	}
	return 0;
}

