#include<stdio.h>
int main()
{
	int A,min,max;
	int jo,a,b,c;
	int count=0;
	scanf("%d",&A);
	min=A*100;max=(A+4)*100;
	for(jo=min;jo<max;jo++)
	{
		a=jo/100;b=(jo-a*100)/10;c=jo%10;
	if(a==b||a==c||b==c)
		continue;
	if(a<A||b<A||c<A||a>A+3||b>A+3||c>A+3)
		continue;
	else
		printf("%d",jo);
		count++;
	if(count%6!=0)
		printf(" ");
	else
		printf("\n");

	}
	return 0;
}
