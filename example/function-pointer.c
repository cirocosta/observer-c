/**
 * Super basic example of a working function pointer.
 */

#include <stdio.h>
#include <stdlib.h>

void populateArray(int *array, size_t arraySize, size_t (*getNextValue)(size_t))
{
	int value;
	size_t i = 0;

	for (; i < arraySize; i++){
		value = getNextValue(i);
		array[i] = value;
		printf("%d\n", value);
	}
}

size_t getNextRandomValue(size_t index)
{
	return index;
}


int main(int argc, char const *argv[])
{

	int myarray[10];
	populateArray(myarray, 10, getNextRandomValue);

	return 0;
}
