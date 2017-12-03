/*--------------------part 2--------------------*/
#include <stdlib.h>
#include <stdio.h>
#define SIZE 9
#define NORTH 1 //y - 1
#define EAST 2 //x + 1
#define SOUTH 3 //y + 1
#define WEST 4 //x - 1

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

int GetValueFromDir(int** array, int x, int y, int dir)
{
	if(dir == NORTH)
	{
		if(y-1 < 0)
		{
			return 0;
		}
		return array[y-1][x];	
	}
	if(dir == EAST)
	{
		if(x+1 > SIZE-1)
		{
			return 0;
		}
		return array[y][x+1];
	}
	if(dir == SOUTH)
	{
		if(y+1 > SIZE - 1)
		{
			return 0;
		}
		return array[y+1][x];
	}
	if(dir == WEST)
	{
		if(x - 1 < 0)
		{
			return 0;
		}
		return array[y][x-1];
	}
}

int CalculateValue(int** array, int x, int y);
{
	int sum = 0;

	
	
	return sum;
}

int Direction(int** array, int x, int y)
{
	if(GetValueFromDir(array, x, y, NORTH) == 0 && GetValueFromDir(array, x, y, EAST) == 0 &&  GetValueFromDir(array, x, y, SOUTH) == 0 && GetValueFromDir(array, x, y, WEST) == 0)
	{
		return EAST;
	}	
	if(GetValueFromDir(array, x, y, NORTH) == 0 && GetValueFromDir(array, x, y, EAST) == 0 &&  GetValueFromDir(array, x, y, SOUTH) == 0 && GetValueFromDir(array, x, y, WEST) != 0)
	{
		return NORTH;
	}	
	if(GetValueFromDir(array, x, y, NORTH) == 0 && GetValueFromDir(array, x, y, EAST) == 0 &&  GetValueFromDir(array, x, y, SOUTH) != 0 && GetValueFromDir(array, x, y, WEST) == 0)
	{
		return WEST;
	}	
	if(GetValueFromDir(array, x, y, NORTH) == 0 && GetValueFromDir(array, x, y, EAST) != 0 &&  GetValueFromDir(array, x, y, SOUTH) != 0 && GetValueFromDir(array, x, y, WEST) == 0)
	{
		return WEST;
	}	
	if(GetValueFromDir(array, x, y, NORTH) == 0 && GetValueFromDir(array, x, y, EAST) != 0 &&  GetValueFromDir(array, x, y, SOUTH) == 0 && GetValueFromDir(array, x, y, WEST) == 0)
	{
		return SOUTH;
	}	
	if(GetValueFromDir(array, x, y, NORTH) != 0 && GetValueFromDir(array, x, y, EAST) != 0 &&  GetValueFromDir(array, x, y, SOUTH) == 0 && GetValueFromDir(array, x, y, WEST) == 0)
	{
		return SOUTH;
	}
	if(GetValueFromDir(array, x, y, NORTH) != 0 && GetValueFromDir(array, x, y, EAST) == 0 &&  GetValueFromDir(array, x, y, SOUTH) == 0 && GetValueFromDir(array, x, y, WEST) == 0)
	{
		return EAST; 
	}	
	if(GetValueFromDir(array, x, y, NORTH) != 0 && GetValueFromDir(array, x, y, EAST) == 0 &&  GetValueFromDir(array, x, y, SOUTH) == 0 && GetValueFromDir(array, x, y, WEST) != 0)
	{
		return EAST;
	}
	if(GetValueFromDir(array, x, y, NORTH) == 0 && GetValueFromDir(array, x, y, EAST) == 0 &&  GetValueFromDir(array, x, y, SOUTH) == 0 && GetValueFromDir(array, x, y, WEST) != 0)
	{
		return SOUTH;
	}	
	if(GetValueFromDir(array, x, y, NORTH) == 0 && GetValueFromDir(array, x, y, EAST) == 0 &&  GetValueFromDir(array, x, y, SOUTH) != 0 && GetValueFromDir(array, x, y, WEST) != 0)
	{
		return NORTH;
	}					
	return 0;	
}

int main()
{
	int** array;
	int prevx, prevy, dir;
	//malloc an array of size SIZE
	array = malloc(SIZE * sizeof* array);
	for(int i = 0; i < SIZE; i++)
	{
		array[i] = malloc(SIZE * sizeof *array[i]);
	}
	array[SIZE/2][SIZE/2] = 1;
	dir = 2;
	prevx = prevy = SIZE/2;
	int i = 2;
	while(dir != 0)
	{
		dir = Direction(array, prevx, prevy);
		if(prevx+1 == SIZE && prevy+1 == SIZE)
		{
			dir = 0;
		}
		if(dir == NORTH && prevy - 1 >= 0)
		{
			array[prevy - 1][prevx] = CalculateValue(array, prevx, prevy-1);
			prevy--;
		}	
		if(dir == EAST && prevx + 1 <= SIZE)
		{
			array[prevy][prevx + 1] = CalculateValue(array,prevx+1,prevy);
			prevx++;
		}
		if(dir == SOUTH && prevy + 1 <= SIZE)
		{
			array[prevy + 1][prevx] = CalculateValue(array,prevx,prevy+1);
			prevy++;
		}
		if(dir == WEST && prevx - 1 >= 0)
		{
			array[prevy][prevx - 1] = CalculateValue(array,prevx-1,prevy);
			prevx--;
		}
		i++;
	}
	

	printarray(array);

	//Free the malloc'ed array
	for(int i = 0; i < SIZE; i++)
	{
		free(array[i]);
	}
	free(array);

	return 0;
}
