/********************************************************************
**
** C program for CS2315 Algorithms StMU Fall 2021
**
** By Mohammed Hani Shaik and Ayden Soliz
**
** Professor: Dr. Art Hanna
**
** last modified on:  November 8, 2021
**
**                    /)
**           /\___/\ ((
**           \`@_@'/ ))
**          {_:Y:.}_//
** ---------{_}^-'{_}----------
*********************************************************************/

#include<stdio.h>
#include<stdbool.h>
#include<math.h>
#include<stdlib.h>

int totalVariations = 0, totalWeakVariations = 0, totalStrongVariations = 0;


void strongConjecture(int x);
void weakConjecture(int y);
bool isPrime(const int x);
/////////////////////////////////////////////////////////////////////
int main(void)
{
	int LB, UB, i;	

	printf("LB? ");
	scanf("%i", &LB);

	do
	{
		printf("UB? ");
		scanf("%i", &UB);

		printf("\n");
		
		for (i = LB; i <= UB; i++)
		{
			if (i % 2 == 0)
			{
				strongConjecture(i);
			}
			else
			{
				weakConjecture(i);
			}
		}

		printf("SUMMARY\n");
		printf("-------------------------------------------------------------\n");

		printf("Total number of variations from %i through %i: %i\n", LB, UB, totalVariations);
		printf("Total number of Weak Goldbach Conjecture: %i (%lf%%)\n", totalWeakVariations, 
		((double)totalWeakVariations / totalVariations));
		printf("Total number of Strong Goldbach Conjecture: %i (%lf%%)\n\n", totalStrongVariations, 
		((double)totalStrongVariations / totalVariations));
		

		totalVariations = 0;
		totalWeakVariations = 0;
		totalStrongVariations = 0;
		printf("LB? ");

	} while (scanf("%d", &LB) != EOF);
	
	return 0;
}
/////////////////////////////////////////////////////////////////////
void strongConjecture(const int x)
{
	int numberOfPrimes = 1;
	bool isExpressable = false;
	int i;
	
	for (i = 2; i < x; i++)
	{
		if (isPrime(i))
		{
			numberOfPrimes++;
		}
	}
	
	int *primes = (int*)malloc(sizeof(int) * numberOfPrimes);

	int count = 1;

	for (i = 2; i < x; i++)
	{

		if (isPrime(i))
		{
			primes[count] = i;
			count++;
		}
	}
	
	int a, b;
	int variations = 0;
	
	for (a = 1; a <= numberOfPrimes; a++)
	{
		for (b = a; b <= numberOfPrimes; b++)
		{
			if ((primes[a] + primes[b]) == x)
			{
				printf("(Strong)");
				printf("\t%i = %i + %i\n", x, primes[a], primes[b]);
				isExpressable = true;
				variations++;
				totalVariations++;
				totalStrongVariations++;
			}
		}
	}
	
	if (isExpressable == false)
	{
		printf("NO EXPRESSION FOR %i\n", x);
	}
	
	printf("\t%i has %i variation(s).\n", x, variations);
	
	free(primes);

	printf("\n");
}
/////////////////////////////////////////////////////////////////////
void weakConjecture(const int x)
{
	int numberOfPrimes = 1;
	bool isExpressable = false;
	int i;

	for (i = 2; i < x; i++)
	{
		if (isPrime(i))
		{
			numberOfPrimes++;
		}
	}

	int* primes = (int*)malloc(sizeof(int) * numberOfPrimes);

	int count = 1;

	for (i = 2; i < x; i++)
	{

		if (isPrime(i))
		{
			primes[count] = i;
			count++;
		}
	}

	int a, b, c;
	int variations = 0;

	for (a = 1; a <= numberOfPrimes; a++)
	{
		for (b = a; b < numberOfPrimes; b++)
		{
			for (c = b; c < numberOfPrimes; c++)
			{
				if ((primes[a] + primes[b] + primes[c]) == x)
				{
					printf("(Weak)");
					printf("   \t%i = %i + %i + %i\n", x, primes[a], primes[b], primes[c]);
					isExpressable = true;
					variations++;
					totalVariations++;
					totalWeakVariations++;
				}
			}
		}
	}
	
	if (isExpressable == false)
	{
		printf("NO EXPRESSION FOR %i\n", x);
	}
	
	printf("\t%i has %i variation(s).\n", x, variations);
	
	free(primes);

	printf("\n");
}
/////////////////////////////////////////////////////////////////////
bool isPrime(const int x)
{
	bool r = true;
	int i;

	for (i = 2; (i <= (int)sqrt(x)) && r; i++)
	{
		r = r && ((x % i) != 0);
	}		
	return(r);
}
