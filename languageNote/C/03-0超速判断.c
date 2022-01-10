#include<stdio.h>


int main()
{
	int s = 0;
	printf("您的车速为：");
	scanf("%d",&s);
	if(s <= 60){
		printf("Speed: %d - OK",s);
	}else{
		printf("Speed: %d - Speeding",s);
	}
return 0;
}

