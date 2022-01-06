#include<stdio.h>
int main()
{
	int digit;
	scanf("%d",&digit);
	printf("%d\n",digit/16+digit%16);
	return 0;
}