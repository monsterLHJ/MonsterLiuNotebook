#include<stdio.h>  
int main()  
{  
    int a,b,i,j;  
    int sum=0,number;  
    scanf("%d %d",&a,&b);  
    number=a;  
    sum=a;        
	for(i=1;i<b;i++)  
    {  
        number=number*10+a;  
        sum=sum+number;  
    }     
    printf("%d",sum);  
    return 0;  
}  
