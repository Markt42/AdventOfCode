/*--------------------part 2--------------------*/
#include <stdlib.h>
#include <stdio.h>
#define SIZE 3

void printarray(int** array)
{
	for(int i = 0; i < SIZE; i++){
		for(int j = 0; j < SIZE; j++){
			printf("%d ",array[i][j]);
		}
		printf("\n");
	}
	return;
}

int main()
{
	int** array;
	int middle = (SIZE-1)/2;
	//malloc an array of size SIZE
	array = malloc(SIZE * sizeof* array);
	for(int i = 0; i < SIZE; i++)
	{
		array[i] = malloc(SIZE * sizeof *array[i]);
	}

	//initialize middle item to 1
	array[middle][middle] = 1;			

	printarray(array);

	//Free the malloc'ed array
	for(int i = 0; i < SIZE; i++)
	{
		free(array[i]);
	}
	free(array);

	return 0;
}
