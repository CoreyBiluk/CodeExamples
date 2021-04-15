//EETG 1008 Computer Programming I
//Assignment 7 - Pointers
//Corey Biluk W0425561
//March 30, 2020	

#include "stdafx.h"
#include "arrEdit.h"
#include "Messages.h"

/*/////////////////////////////////////////////////////////////////////////////////////////////////////
This program generates an array filled with random int values.  The size of the array is based on the
user's input.  Once the array is generated, the program will sort the values in the array from smallest
to largest.  Once sorted, the program will display the sorted array and then prompt the user to quit or
continue.
////////////////////////////////////////////////////////////////////////////////////////////////////*/
void main(){

	//Variable declarations
	int* arrRandom, size;
	int i;
	char quit;

	do{											//Loop entire program

		arrsize(&size);							//Call array size function
		arrRandom = genarr(size);				//Call random array generator function

		printf("The generated array is:\n");	//Print Random array
		for (i = 0; i < size; i++){				//Loop to print random array 
			printf("%d\n", arrRandom[i]);
		}

		arrsort(arrRandom, size);				//Call array sorting function

		printf("\nThe sorted array is:\n");		//Print sorted array
		for (i = 0; i < size; i++){				//Loop to print random array 
			printf("%d\n", arrRandom[i]);
		}
		free(arrRandom);						//Frees allocated memory
		Continue(&quit);						//Call Continue function

	} while (quit != 'q'&& quit != 'Q');		//Loop program until user chooses to terminate program
	printf("program terminated by operator\n");	//Program termination message
	system("pause");							//Pause for user to read termination message
}
