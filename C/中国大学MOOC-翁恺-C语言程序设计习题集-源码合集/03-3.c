#include<stdio.h>
int main()
{
	int t1,t2,t3;
	scanf("%d:%d",&t1,&t2);
      if (t1>=13)
		t3=t1-12;
	else
		t3=t1;
	if(t1>=12)
	   printf("%d:%d PM",t3,t2);
	else
		printf("%d:%d AM",t3,t2);
	return 0;
}
