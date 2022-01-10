#include<stdio.h>
int main()
{
	int time,minute,hour,m,temp;
	scanf("%d%d",&time,&minute);
	hour=time/100;
	m=time%100;
	temp=m+minute;
	if(temp<0)
	{
		hour=hour-(-temp/60)-1;
		m=60-(-temp%60);
	}
	else
	{
		hour=hour+temp/60;
		m=temp%60;
	}
	printf("%d\n",hour*100+m);
	return 0;
}