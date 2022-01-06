#include<stdio.h>
int main()
{   
    int n,a,b,c,i;
	scanf("%d",&n);
	a=n/100;
	b=(n-a*100)/10;
	c=n%10;
	for(i=1;i<=a;i++)
	{
		if(a!=0)
			printf("B");
	}
	for(i=1;i<=b;i++)
	{
		if(b!=0)
			printf("S");
	}
	for(i=1;i<=c;i++)
	{
		if(c!=0)
			printf("%d",i);
	}
	return 0;
}
