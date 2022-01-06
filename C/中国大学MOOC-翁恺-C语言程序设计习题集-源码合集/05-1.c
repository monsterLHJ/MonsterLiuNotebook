#include <stdio.h>
int gcd(int a, int b) 
{    
	int r; 
	do 
	{     
		r = a % b; 
		a = b;   
		b = r;   
	} while (r);   
	return a;
}
int main(void)
{   
	int a, b; 
	scanf("%d/%d", &a, &b);  
	printf("%d/%d\n", a/gcd(a, b),b/gcd(a,b));  
	return 0;
}