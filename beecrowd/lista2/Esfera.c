#include <stdio.h>

int main(){
	float pi, r, volume;
	
	pi = 3.14159;
	
	scanf("%f", &r);
	
	volume = (4/3.0)*pi*(r*r*r);
	
	printf("VOLUME = %.3f\n", volume);	
	
  return 0;
}
