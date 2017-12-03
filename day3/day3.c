/*--------------------part 1--------------------*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(){
	int input, result, location, middle;
	location = middle = 0;
	input = 277678;
	result = 0;

	middle = sqrt(input);
	middle = middle/2;
	location = ceil(sqrt(input))*ceil(sqrt(input)) - input;
	result = abs(location - middle);
	result += middle;
	printf("middle = %d\nlocation = %d\nresult = %d\n",middle, location, result);
	return 0;	
}
