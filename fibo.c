#include "types.h"
#include "stat.h"
#include "user.h"

int fib(int n) 
{ 
  int a = 0, b = 1, c, i; 
  int j= 0; 
	if( n == 0) 
    return a; 
	
	while(j < 100){
		
  for (i = 2; i <= n; i++) 
  { 
     c = a + b; 
     a = b; 
     b = c; 
  } 
	j++;	
}
  return b; 
} 

int main(int argc, char **argv){
	int n; 
	n = 1000000000;
	printf(1,"The value is: %d",fib(n)); 
	exit(); 		
		
}