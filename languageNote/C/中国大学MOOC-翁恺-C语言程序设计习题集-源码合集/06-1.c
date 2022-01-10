// 主要是参考了网上其他同学的方法，囧
#include <stdio.h>  
int main()  
{  
    char chr;  
    int num;  
    int flag = 0;  
    int result = 0;  
    scanf("%d", &result);  
    while ( (chr = getchar()) != '=' ) 
	{  
        if ( chr == '+' ) 
		{  
           scanf("%d", &num);  
           result += num;  
        }
		else if ( chr == '-' ) 
		{  
            scanf("%d", &num);  
            result -= num;  
         }
		else if ( chr == '*' ) 
		{  
            scanf("%d", &num);  
            result *= num;  
	    }
		else if ( chr == '/' ) 
		{  
           scanf("%d", &num);  
            if ( num )
			{  
                result /= num;  
            }
			else 
			{  
                flag = 1;  
               break;  
            }  
        }
		else 
		{  
            flag = 1;  
            break;  
        }  
    }        
  if ( flag ) 
  {  
        printf("ERROR\n");  
   }
  else 
  {  
        printf("%d\n", result);  
   }      
   return 0;  
}  
