//Corey Biluk
//April 10, 2020	

#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

/*/////////////////////////////////////////////////////////////////////////////////////////////////////
This program will open the text file "Assign.txt", read the contents. Then create a new text file
"numfile.txt", and write the desired information to the new file.  The information to be printed to
the new file will be all numeric data from "Assign9.txt". This is done by using a token to parse the
stored data and the isdigit() function to determine which information is numerical.  Once determined
to be numerical data, the data is converted to decimal by the strtod() function and then written to
the file. Both files are then closed.
////////////////////////////////////////////////////////////////////////////////////////////////////*/

void main(){
	
	//Variable declarations
	
	FILE* fpFile1 = NULL;							//File pointer for "Assign9.txt" file
	FILE* fpFile2 = NULL;							//File pointer for "numfile.txt" file
	char *token, *temp;
	char read[100];
	double num1;

	fpFile2 = fopen("numfile.txt", "w");					//Open "numfile.txt" file in write mode and set to fpFile2 pointer
	if (fpFile2 == NULL)							//File error checking
		printf("File Error");

	fpFile1 = fopen("Assign9.txt", "r");					//Open "Assign9.txt" file in read mode and set to fpFile1 pointer
	if (fpFile1 == NULL)							//File error checking
		printf("File Error");
	else
	{
		while (fgets(read, 100, fpFile1) != NULL)			//This function reads the file and stores the strings in read array	
		{
			puts(read);						//Print read array strings to console window
			token = strtok(read, " ");				//Set token to value of first char in read array
			while (token != NULL)					//Loop strtok() function until token equals NULL to parse whole array
			{
				if (isdigit(token[0]))				//Determine if token is a digit
				{
					num1 = strtod(token, &temp);		//Convert char to decimal and store in num1 variable
					fprintf(fpFile2, "%lf \t", num1);	//Write num1 value and a TAB to "numfile.txt"
				}
				token = strtok(NULL, " ");			//Continue parsing the array
			}
			fprintf(fpFile2, "\n");					//Write a new line to file for data formatting
		}
	}
	fclose(fpFile1);							//Close "Assign9.txt" file
	fclose(fpFile2);							//Close "numfile.txt" file
	system("pause");							//System pause to read console window
}
 
