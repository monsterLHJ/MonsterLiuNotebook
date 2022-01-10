#include<stdio.h>
int main()
{
	int num,N,inNum[100],count=0;
	int i=0;
	scanf("%d%d",&num,&N);
	for(i=0;;i++)
	{
		scanf("%d",&inNum[i]);
		if(inNum[i]<0)
			break;
	}
	for(i=0;;i++)
	{   
		if(inNum[i]<0||count>=N)
		{
			printf("Game Over\n");
			break;
		}
		if(inNum[i]<num)
		{
			printf("Too small\n");
			count++;
		}
		if(inNum[i]>num)
		{
			printf("Too big\n");
			count++;
		}
		if(inNum[i]==num&&count==0)
		{
			printf("Bingo!\n");
			break;
		}
		if(inNum[i]==num&&count<3)
		{
			printf("Lucky You!\n");
			break;
		}
		if(inNum[i]==num&&count>=3&&count<=N-1)
		{
			printf("Good Guess!\n");
			break;
		}
	}
	return 0;
}
