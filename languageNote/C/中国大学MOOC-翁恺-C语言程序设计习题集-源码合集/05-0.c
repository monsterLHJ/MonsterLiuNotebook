#include<stdio.h>
int main(){
	int N;
	int i;
	double fenZi=2,fenMu=1,old_fenZi,old_fenMu;
	double sum=0,temp;
	scanf("%d",&N);
	for(i=1;i<=N;i++)
	{
		temp=fenZi/fenMu;
		sum=sum+temp;
		old_fenZi=fenZi;
		old_fenMu=fenMu;
		fenZi=old_fenZi+old_fenMu;
		fenMu=old_fenZi;
	}
	printf("%.2f\n",sum);
	return 0;
}