//EETG 1008 Computer Programming I
//Project #1 - Scientific Calculator
//Corey Biluk W0425561
//February 27, 2020	

//The program is a limited function scientific calculator.  

//Part A consists of basic math operations whose operator can be defined by a single character. 
//For example: addition (+),subtraction (-), divison (/)...etc.  The program will assess the entered floats and character, determine which operation to perform based
//on string compare results, perform the operation and then print the results to the console window.

//Part B consists of other math operations (trig functions, logarithms...etc) whose operator is defined by a word or multiple characters.
//For example: sine (sin), logarithm base 10 (log10), square root (sqrt)...etc.  The program will analyze the string and float stored by scanf and determine which operation
//to perform based on string compare results, perform the operation and then print the results to the console window.

//The program has invalid input detection as well as being able to detect attempted invalid mathematical operations.  The program will also loop allowing for multiple calculations
//until the operator chooses to terminate the program.

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define PI acos(-1)

void main() {

	char c, cQuit, str[100], results[100];
	float f1 = 0, f2 = 0, fResult, fHalfPI = 1.5*PI;

	do{													//do statement for full program loop
		printf("Please enter an equation:\n\nAvailable operations:\n\n#+#\n#-#\n#*#\n#/#\n#^#\n#%%#\nsin#\nasin#\ncos#\nacos#\ntan#\natan#\nsqr#\nexp#\nsqrt#\nabs#\nlog#\nln#\n\n");	//ask operator to enter an equation

		//PART A - basic math operations only requiring one character for operation 

		if (scanf("%f %c %f", &f1, &c, &f2) == 3){							//if operators enter a float followed by a character followed by a float.  Store each element in a variable
			rewind(stdin);										//reset scanf memory buffer

			//addition
			if (c == '+'){										//determine operation to perform
				fResult = f1 + f2;								//perform operation
				sprintf(results, "%f + %f = %f", f1, f2, fResult);				//store results as a string	
			}

			//subtraction
			else if (c == '-'){									//determine operation to perform
				fResult = f1 - f2;								//perform operation
				sprintf(results, "%f - %f = %f", f1, f2, fResult);				//store results as a string
			}

			//multiplication
			else if (c == '*'){									//determine operation to perform
				fResult = f1 * f2;								//perform operation
				sprintf(results, "%f * %f = %f\n\n", f1, f2, fResult);				//store results as a string
			}

			//division
			else if (c == '/'){									//determine operation to perform
				if (f2 == 0){									//determine if attempting to divide by 0
					sprintf(results, "Invalid Operation\n\n");				//store invalid operation text as a string		
				}

				else{
					fResult = f1 / f2;							//perform operation
					sprintf(results, "%f / %f = %f\n\n", f1, f2, fResult);			//store results as a string
				}
			}

			//y to the power of x
			else if (c == '^'){									//determine operation to perform
				fResult = pow(f1, f2);								//perform operation
				sprintf(results, "%f ^ %f = %f\n\n", f1, f2, fResult);				//store results as a string
			}

			//modulus
			else if (c == '%'){									//determine operation to perform
				fResult = fmod(f1, f2);								//perform operation
				sprintf(results, "%f %c %f = %f\n\n", f1, c, f2, fResult);			//store results as a string
			}
		}

		//PART B - Trig Funtions, logarithms, x squared, and square roots
		
		else if (scanf("%[a-z] %f", str, &f1) == 2){							//if operator enters characters followed by a float, store as a string and a variable
			rewind(stdin);										//reset scanf memory buffer

			//sine	
			if (strcmp(str, "sin") == 0){								//determine what operation based on stored string
				fResult = sin(f1);								//perform operation
				sprintf(results, "sin %f  = %f\n\n", f1, fResult);				//store results as a string
			}

			//arcsine
			else if (strcmp(str, "asin") == 0){							//determine what operation based on stored string
				if (f1 < -1 || f1 > 1){								//determine if operator is attempting to calculate arcsine of value less that -1 or more than 1
					sprintf(results, "Invalid Operation\n\n");				//store invalid operation message as a string
				}
				else {
					fResult = asin(f1);							//perform operation
					sprintf(results, "asin %f = %f\n\n", f1, fResult);			//store results as a string
				}
			}
			//cosine					
			else if (strcmp(str, "cos") == 0){							//determine what operation based on stored string
				fResult = cos(f1);								//perform operation
				sprintf(results, "cos %f = %f\n\n", f1, fResult);				//store results as a string
			}

			//arccosine
			else if (strcmp(str, "acos") == 0){							//determine what operation based on stored string
				if (f1 <-1 || f1 > 1){								//determine if operator is attempting to calculate arcosine of value less that -1 or more than 1
					sprintf(results, "Invalid Operation\n\n");				//store invalid operation message as a string
				}
				else{
					fResult = acos(f1);							//perform operation
					sprintf(results, "acos %f  = %f\n\n", f1, fResult);			//store results as a string
				}
			}
			//tan							
			else if (strcmp(str, "tan") == 0){							//determine what operation based on stored string
				if (f2 == fHalfPI){								//determine if operator is attempting to calculate tan1.5*PI
					sprintf(results, "Invalid Operation\n\n");				//store invalid operation message as a string
				}
				else{
					fResult = tan(f1);							//perform operation
					sprintf(results, "tan %f  = %f\n\n", f1, fResult);			//store results as a string
				}
			}

			//arctan
			else if (strcmp(str, "atan") == 0){							//determine what operation based on stored string
				fResult = atan(f1);								//perform operation
				sprintf(results, "atan %f = %f\n\n", f1, fResult);				//store results as a string
			}

			//x squared	
			else if (strcmp(str, "sqr") == 0){							//determine what operation based on stored string
				fResult = pow(f1, 2);								//perform operation
				sprintf(results, "sqr %f = %f\n\n", f1, fResult);				//store results as a string		
			}

			//e to the power of x
			else if (strcmp(str, "exp") == 0){							//determine what operation based on stored string
				fResult = exp(f1);								//perform operation
				sprintf(results, "e to the power of %f = %f\n\n", f1, fResult);			//store results as a string
			}

			//square root
			else if (strcmp(str, "sqrt") == 0){							//determine what operation based on stored string
				if (f1 < 0){									//determine if operator is attempting to calculate square root of negative number
					sprintf(results, "Invalid Operation\n\n");				//store invalid operation message as a string
				}
				else{
					fResult = sqrt(f1);							//perform operation
					sprintf(results, "sqrt of %f = %f\n\n", f1, fResult);			//store results as a string
				}
			}
			//absolute value
			else if (strcmp(str, "abs") == 0){							//determine what operation based on stored string
				fResult = fabs(f1);								//perform operation
				sprintf(results, "absolute value of %f = %f\n\n", f1, fResult);			//store results as a string
			}

			//logarithm base 10
			else if (strcmp(str, "log") == 0){							//determine what operation based on stored string
				if (f1 == 0){									//dertermine if operator is attempting to calculate log0
					sprintf(results, "Invalid Operation\n\n");				//store invalid operation message as a string	
				}
				else {
					fResult = log10(f1);							//perform operation
					sprintf(results, "log of %f = %f\n\n", f1, fResult);			//store results as a string
				}
			}

			//natural logarithm
			else if (strcmp(str, "ln") == 0){							//determine what operation based on stored string
				if (f1 == 0){									//dertermine if operator is attempting to calculate ln0
					sprintf(results, "Invalid Operation\n\n");				//store invalid operation message as a string
				}
				else {
					fResult = log(f1);							//perform operation
					sprintf(results, "ln of %f = %f\n\n", f1, fResult);			//store results as a string		
				}
			}
		}

		//Invalid entry mesage
		
		else if (strcmp(str, " ") != 0){								//determine if invalid entry	
			rewind(stdin);										//reset scanf memory buffer
			sprintf(results, "Invalid input\n\n");							//store invalid input message as a string
		}

		puts(results);			                                                        	//print results string to console window

		//PART C - quit or continue
		
		printf("Press any key to continue or 'Q' to quit program...\n\n");				//ask for operator input
		cQuit = getchar();										//Have program obtain inputed character
		rewind(stdin);											//Reset getchar memory so it will get the next input correctly
		if (cQuit == 'Q' || cQuit == 'q')								//determine if character entered was q or Q
		{
			printf("\n\nProgram terminated by operator\n\n");					//print program termination message
			system("pause");									//pause so operator can read termination message
			exit(0);										//exit program
		}
		system("cls");											//clear screen for program reset
	} while (cQuit != 'Q' && cQuit != 'q');									//looping condition.  if q or Q then quit program
}
