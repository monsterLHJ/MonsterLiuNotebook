#include<stdio.h>

int main()

{

  int  speed=0;

  scanf("%d",&speed);

  if(speed>60)

  printf("Speed: %d - Speeding\n",speed);

  else{

  if(speed<=60)

  printf("Speed: %d - OK\n",speed);

  }

  return 0;

  }