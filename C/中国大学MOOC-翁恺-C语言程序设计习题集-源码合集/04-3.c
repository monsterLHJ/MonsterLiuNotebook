#include<stdio.h>
int main(){
	int N,M,count=0,sum=0;
	int i,j;
	scanf("%d%d",&M,&N);
	for(i=M;i<=N;i++)
	{  
	    int isPrime = 1;// isPrime用来标记是否为素数
	    if(i==1)
	   {
		 isPrime=0;
		 continue;
	    }
	    else
	   {
	  	 for(j=2;j<i;j++)
	  	 { 
			if(i%j==0)
			 {
				isPrime=0;
		  	  break;
		  	}
	  	  }
	    }
	    if(isPrime == 1 )
	    {
		  sum=sum+i;
		  count++;
	     }
	}
	printf("%d %d\n",count,sum);
}