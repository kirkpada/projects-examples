//*********************************************************************
//** Author: Daniel Kirkpatrick
//** Program Name: sieve.c
//** Date: June 30, 2014
//** Description: Print out prime numbers using Sieve of Eratosthenes
//**			  algorithm.
//**
//*********************************************************************

#include <stdio.h>			//for input/output
#include <stdlib.h>
#include <ctype.h>			//for isdigit
#include <limits.h>			//for INT_MAX


/*********************************************************************
** Function: seive
** Description: Prints out prime numbers and how many there are 
**				using Sieve of Eratosthenes algorithm
** Parameters: int num
** Pre-Conditions: The number of digits to check
** Post-Conditions: List of prime numbers
*********************************************************************/
void sieve(int num)
{
	int i=0, j=0, count=0;
	int list[num];

	//fill array with num-elements and fill it from 2 -> num
	//we can start at 2 since 2 is the smallest prime number
	for(i=2; i<=num; i++)
	{
		list[i] = i;
	}

	//prime number check
	for(i=2; i<=num; i++)
	{
		for(j=2; j<=num; j++)
		{
			if(i!=j)
			{
				if(j%i == 0)
				{
					list[j] = 0;
				}
			}
		}
	}

	//print list
	for(i=2; i<=num; i++)
	{
		if(list[i]!=0)
		{
			count++;
			printf("%d ", list[i]);
		}
	}
	printf("\nTotal number of primes: %d", count);

	printf("\n\n");
}//********** end sieve **********


/*********************************************************************
** Function: main
** Description: Drives the program
** Parameters: Command line arguments
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/
int main(int argc, char* argv[])
{
	int num = 0;

	//make sure correct argument is inputted
	if(strcmp(argv[1], "-n") == 0)
	{
		//check to make sure there are enough arguments
		if(argc < 3)
		{
			printf("\nNot enough arguments entered!!\n");
			printf("Quitting program\n\n");
			exit(EXIT_FAILURE);
		}
		else if(argc > 3)
		{
			printf("\nToo many arguments entered!!\n");
			printf("Quitting program!\n\n");
			exit(EXIT_FAILURE);
		}

		//make sure our input for sieve is a number
		if(isdigit((*argv[2])))
		{
			num = atoi(argv[2]);
			sieve(num);
		}
		else
		{
			printf("\nIncorrect input! Either a character or negative number was entered!\n");
			printf("Quitting program!\n\n");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		printf("\nInvalid argument entered!\n");
		printf("Quitting program\n\n");
		exit(EXIT_FAILURE);
	}

return 0;
}//********** end main **********