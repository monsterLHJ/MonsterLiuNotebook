#include<stdio.h>
int main()
{
	int day,temp;
	scanf("%d",&day);
	temp=day%5;
	if (1<=temp&&temp<=3)
		printf("Fishing in day %d",day);
	else
		printf("Drying in day %d",day);
	return 0;
}
