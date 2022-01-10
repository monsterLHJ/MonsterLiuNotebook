#include<stdio.h>
int main()
{   
      int n,i;
	int out[10];
	long int A,B,C;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%ld%ld%ld",&A,&B,&C);
		if(A+B>C)
			out[i]=1;
		else
			out[i]=0;

	}
	for(i=1;i<=n;i++)
	{
		if(out[i]==1)
			printf("Case #%d: true\n",i);
		else
			printf("Case #%d: false\n",i);

	}
	return 0;
}
