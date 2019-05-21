/*
Asad Khan
Assignment 3
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


//Functions
float s_exp(float sub_exp, char op);
float m_exp(float sub_exp, char op);
char get_op();
float get_num();

//Main
int main(void)
{
	char cont = 'Y';
	while (cont == 'Y' || cont == 'y')
	{
		printf("Enter a simple arithmetic expression: ");
		float result = s_exp(0,'+');
		/* Use the recursive function to calculate the result */

		printf(" The result is %f\n", result);

		printf("Do you want to continue? Y/N\n");
		scanf(" %c",&cont);
		/* Enter Y or y to continue, otherwise to quit */
	}
}


// Input: ’sub_exp’: the value of the sub s_expression to the left of ’op’
//        location in stdin.
//        ’op’ : an operator, ’+’ or ’-’. ’op’ could also be
//              ’\n’ indicating the end of the s_expression
//        the rest of the expression will be read in from stdin
// Effect:  the whole s_expression is evaluated using recursion:
//          get next_num with m_exp() and then get next_op with get_op()
//          use ’sub_exp op next_num’ and ’next_op’ to do recursive call
// Output:  this function returns the value of the s_expression

float s_exp(float sub_exp, char op)
{
    float f1;
    char ch;
    float f2;
    
    if (op == '\n'){
        return sub_exp;
    }

    else if (op == '+'){
        f1 = get_num();
        ch = get_op();
        f2 = m_exp(f1, ch);
 
       
        
        return s_exp(sub_exp + f2, get_op());
    }
    else if (op == '-'){
        f1 = get_num();
        ch = get_op();
        f2 = m_exp(f1, ch);
        return s_exp(sub_exp - f2, get_op());
    }
    else{
			if (op != '*' && op != '/'){
        printf("Invalid Operator \n");
        return 0;
			}
    }

		return 0;
}

// Input: ’sub_exp’: the value of the current sub m_expression
//                  to the left of ’op’ location in stdin.
//        ’op’ : an operator, ’*’ or ’/’. ’op’ could also be
//              ’+’, ’-’, or ’\n’ indicating the end of the m_expression.
//              "+’, ’-’, or ’\n’ should be pushed back to stdin.
//       the rest of the m_expression will be read in from stdin
//
// Effect: the m_expression is evaluated using recursion:
//        get next_num with get_num() and then get next_op with get_op()
//        use ’sub_exp op next_num’ and ’next_op’ to do recursive call
//
// Output: this function returns the value of the current m_expression

float m_exp(float sub_exp, char op){
    
    float f1;
    char ch;

    if (op == '\n' || op == '-' || op == '+')
    {
        ungetc(op, stdin);
        return sub_exp;
    }

    else if (op == '*')
    {
        f1 = get_num();
        ch = get_op();
        f1 = f1*sub_exp;
        return m_exp(f1, ch);
    }

    else if (op == '/')
    {
        f1 = get_num();
        ch = get_op();
        f1 = sub_exp/f1;
        return m_exp(f1, ch);
    }

    else{
        printf("Invalid Operator \n");
        return 0;
    }
}

// Input: none, read from stdin
// Effect: get the next operator of the expression
// this operator can be +, -, *, /, or �\n�
// �\n� indicates the end of the expression input
// leading spaces should skipped
// Output: return the next operator of the expression.
char get_op()
{
	char op = ' ';
	while (op == ' ')
		scanf("%c", &op);
	return op;
}

// Input: none, read from stdin
// Effect: get the next numeric value of the expression
// Output: return the next numeric value of the expression.
float get_num()
{
	float num;
	scanf(" %f", &num);
	return num;
}
