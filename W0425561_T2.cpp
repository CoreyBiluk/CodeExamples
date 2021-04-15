
//EETG 1008 Computer Programming I
//Test #2
//Corey Biluk W0425561
//April 27,2020


#include "stdafx.h"


void main(){

	equation data[10];
	int i;
	int sz;

	FILE* bfile = fopen("equations.bin", "r");
	if (bfile == NULL)
		printf("File Error\n");
	else
	{
		fseek(bfile, 0, SEEK_END);
		sz = ftell(bfile) / sizeof(equation);
		fseek(bfile, 0, SEEK_SET);
		fread(data, sizeof(equation), sz, bfile);
	}
	//printf("%d\n", sz);								//TEST if OPEN is returning 10

	for (i = 0; i < sz; i++){
		fscanf(bfile, "%lf %lf %c", (data + i)->num1, (data + i)->num2, (data + i)->op);

		printf("%lf %c %lf =\n", (data + i)->num1, (data + i)->op, (data + i)->num2);  
	}

	FILE* tfile = fopen("results.txt", "w");

	if (tfile == NULL)
		printf("File error\n");
	else
	{
		for (i = 0; i < sz; i++){
			fprintf(tfile, "%f %c %f %c %f\n", (data + i)->num1, (data + i)->op, (data + i)->num2, '=', (data + i)->result);
		}
		fclose(tfile);
		fclose(bfile);
	}
	system("pause");
}

