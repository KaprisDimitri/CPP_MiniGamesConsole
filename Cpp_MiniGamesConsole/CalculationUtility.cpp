#include <stdlib.h>
using namespace std;
#include <cmath>

#ifndef CalculationUtility_INCLUDED
#define CalculationUtility_INCLUDED

     class CalculationRandom
	{
	public:
		static int FindRandomBetweenInclusif(int min, int max)
		{
			return min + (rand() % max);
		}

		static int FindRandomBetween(int min, int max) 
		{
			return (min + 1) + (rand() % (max - 1));
		}

		static int FindRandomBetweenInclusifUnknow(int number1, int number2)
		{
			return FindRandomBetweenInclusif( FindMin(number1, number2), FindMax(number1, number2));
		}

		static int FindMin(int number1, int number2)
		{
			if (number1 == number2 || number1 < number2) { return number1; }
			return number2;
		}

		static int FindMax(int number1, int number2)
		{
			if (number1 == number2 || number1 > number2) { return number1; }
			return number2;
		}
	};

	 class CheckNumbers
	{
	public:

		static bool IsEqual(int number1, int number2)
		{
			return number1 == number2;
		}

		static bool IsLess(int numberCompared, int numberRef = 0)
		{
			return numberCompared < numberRef;
		}

		static bool IsMore(int numberCompared, int numberRef = 0)
		{
			return numberCompared > numberRef;
		}

		static bool IsBetweenInclusif(int numberCompared, int min, int max)
		{
			return numberCompared < max && numberCompared > min;
		}

		static bool IsBetween(int numberCompared, int min, int max)
		{
			return numberCompared <= max && numberCompared >= min;
		}
	};

	 static int Difference(int number1, int number2)
	 {
		return std::abs(number1 - number2);
	 }

#endif
