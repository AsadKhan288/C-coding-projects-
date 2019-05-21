/*
Asad Khan
akhan625
Cs2211 Assignment3

Program will display integer in seven-segment format
using a Three Dimensioanal array 
*/




#include <stdio.h>


int main(void)
{
//Producing the three-dimensional array
// 0-9

	const char segments[10][3][3] = {{{' ','_',' '},{'|',' ','|'},{'|','_','|'}},
		{{' ',' ',' '},{' ',' ','|'},{' ',' ','|'}}, 
		{{' ','_',' '},{' ','_','|'},{'|','_',' '}},
		{{' ','_',' '},{' ','_','|'},{' ','_','|'}},
		{{' ',' ',' '},{'|','_','|'},{' ',' ','|'}},
		{{' ','_',' '},{'|','_',' '},{' ','_','|'}},
		{{' ','_',' '},{'|','_',' '},{'|','_','|'}},
		{{' ','_',' '},{' ',' ','|'},{' ',' ','|'}},
		{{' ','_',' '},{'|','_','|'},{'|','_','|'}},
		{{' ','_',' '},{'|','_','|'},{' ','_','|'}}};

	char cont = 'Y';
	while (cont == 'Y' || cont == 'y')
	{
		int num[100];
		//the input number
		int input_val; 
		printf("Input the value: \n");
		scanf(" %d", &input_val);
		//'sign' used to represent sign of input
		int sign, length = 0;

		if (input_val < 0) 
		{
			sign = -1;
			input_val = 0 - input_val;
		}else if (input_val == 0)
			sign = 0;
		else
			sign = 1;	
			
        //Split the input value into lone numbers, and count accordingly
		while (input_val != 0)
		{
		    //input_num is represented by integer, so will round accordingly
			num[length] = input_val % 10;
			input_val = input_val / 10;
			length ++;
		}

		//The last number is always a zero, so it is ignored
		length --;
        
        //If the input value is zero: (neither positive or negative)
        //Printing out '0'
		if (sign == 0) 
		{
			int p, q;
			for (p = 0; p < 3; p ++)
			{
				for (q = 0; q < 3; q ++)
					printf("%c", segments[0][p][q]);
				//Break for each of the three parts 	
				printf("\n");
			}
		}
		//If the input value is not zero:
		else
		{
		    //'a' representing each of the three segments
			int a,p,b;
			for (a = 0; a < 3; a ++)
			{
			    //If the input value is negative, put '_'(negative sign) in the second part
			    //And a single space in each of the other lines

				if (sign == -1)
				{	
				    //Input '-' (negative sign) in middle segment, and space in other segments
				    if (a == 1)
						printf("_");
					else 
						printf(" ");
				}	
				
				//Iterate over the array backwards (Due to being inputed from the last number to the first number)
				//Last number is ignored
				for (p = length; p >= 0; p --)
				{
					for (b = 0; b < 3; b ++)
						printf("%c",segments[num[p]][a][b]);
				}
				printf("\n");
			}
		}
		
		//Enter Y to continue or N to exit
		printf("To continue 'Y', to exit 'N'\n");
		scanf(" %c", &cont);
	}
}
