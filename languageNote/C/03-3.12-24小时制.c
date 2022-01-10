#include<stdio.h>


int main()
{
	int h,m;
	scanf("%d:%d",&h,&m);
	if(h - 12 <= 12){
		printf("%d:%d AM",h,m);
	} else{
		printf("%d:%d PM",h-12,m);
	}
return 0;
}

