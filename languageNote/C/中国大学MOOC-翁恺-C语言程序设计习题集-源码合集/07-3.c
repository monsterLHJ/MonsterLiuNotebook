#include<stdio.h>
#include <math.h>
int main(){
	int N,M,count=0,sum=0;
	int i,j;
	scanf("%d%d",&M,&N);
	for(i=2;count<=N;i++)
	{  
	    int isPrime = 1;// isPrime��������Ƿ�Ϊ����
	  	for(j=2;j<=sqrt(i);j++)//ע�⣡��������j<i,����һ���������г�ʱ��
	  	{ 
			if(i%j==0)
			{
				isPrime=0;
		  		break;
		  	}
	  	 }
	    if(isPrime == 1 )
		  count++;
		if(count>=M&&count<=N&&isPrime==1)
		{
			printf("%d",i);
			if((count-M+1)%10==0)
				printf("\n");
			else if(count!=N)
				printf(" ");
		}
	}
}