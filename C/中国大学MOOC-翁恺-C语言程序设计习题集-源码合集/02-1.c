#include<stdio.h>
int main()
{
	int h1;
	float temp1,temp2;
	int foot,inch;
	scanf("%d",&h1);
	temp2=h1/100.0;
	temp1=temp2/0.3048;
	foot=(int)(temp1);
	inch = (int)((temp1-foot)*12);
	printf("%d %d\n",foot,inch);
	return 0;
}