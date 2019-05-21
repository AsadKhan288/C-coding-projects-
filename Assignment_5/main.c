/*
Asad khan
CS 2211
Asn_5
main.c
*/

#include "matrix.h"
#include <stdio.h>
#include <string.h>


int main()
{
    // Initialization of matrix using matrix_construction() function 
    Matrix temp_matrix = matrix_construction();
    
    // char type pointers for each string in string pair
    char string_1[80];
    char string_2[160];
    
    // char type pointer for each line containing string pair
    char s_pair[200];
    
    // char type pointer for splitting string pair into
    // individual tokens
    char *splitter;


    char file_name[35];
	// Prompt input for the name of the file containing the keys 
	// Input name of the file
	// Input file
	puts("Type name of the text file into input: ");
	scanf("%s", file_name);
	FILE *f = fopen(file_name, "r");

    // While loop, to continue till end of the text file 
    // has been reached
	while (fgets(s_pair, sizeof(s_pair), f))
	{	
		// break loop if line is empty
		if (strlen(s_pair) == 0)
		{
			break;
		}

		// Split the string pair with ' \n' as the delimiter 
		splitter = strtok(s_pair, " \n");

		// Copy first token into 'string_1' and get next substring
		strcpy(string_1, splitter);
		splitter = strtok(NULL, " \n");

		// If second substring is NULL, break the loop
		// if not, copy second token into 'string_2'
		if (splitter == NULL)
		{
			break;
		}
		strcpy(string_2, splitter);
        
        
        // If key is not already in matrix, insert it into the matrix
        // Otherwise, increment the data for the string pair [string_1, string_2]
		if (matrix_get(temp_matrix, string_1, string_2) == NULL)
		{
			matrix_set(temp_matrix, string_1, string_2, 1);
		}
		else
		{
			matrix_set(temp_matrix, string_1, string_2, (*matrix_get(temp_matrix, string_1, string_2) + 1));
			
		}
	}

	// Print the headers and matrix 
	puts("   String 1    String 2          Occurence");
	matrix_list(temp_matrix);
	
	// Free all allocated space for matrix
	matrix_destruction(temp_matrix);
	
	return 0;
}
