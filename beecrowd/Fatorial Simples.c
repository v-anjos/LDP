#include<stdio.h>

int fat, N;

int main()
{
  scanf("%d", &N) ;
  
  if(N > 0 && N < 13){
  	  for(fat = 1; N > 1; N = N - 1)
 	 	{
      fat = fat * N;
 		}
  }

  printf("%d\n", fat);
  return 0;
}
