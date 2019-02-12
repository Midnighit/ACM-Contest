//============================================================================
// Name        : Pi.cpp
// Author      : ae652720
// Description : 412 - Pi
//============================================================================

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int numbers[49]; // as per requirement the program should read between 1 and 49 numbers

/**
 * reads numbers into the numbers array and returns the amount of numbers read this way
 */
int input()
{
	int i, n;
	cin >> n;
	if(n == 0) return 0;
	for(i = 0; i < n; i++) cin >> numbers[i];
	return n;
}

/**
 * calculates the greatest common divisor (GCD) which is synonymous to the greates common factor (GFC) using the Euclidean algorithm
 */
int getGCD(int a, int b)
{
	int m;
	while(a != 0)
	{
		m = a;
		a = b % a;
		b = m;
	}
	return b;
}

int main()
{
	int n, i, j;
	int noCommonFactor;					// number of pairs with common factor
	int total;							// total number of pairs
	while(true)
	{
		n = input();					// read a set of numbers
		if(n == 0) break;				// program end condition
		else total = n * (n - 1) / 2;	// calculate the amount of pairs, that can be generated from the numbers
		noCommonFactor = 0;				// counts up for every pair without a common factor greater than 1
		for(i = 0; i < n; i++)			// generate pairs
		{
			for( j = i + 1; j < n; j++)
			{
				if(getGCD(numbers[i], numbers[j]) == 1) noCommonFactor++;	// if getGCD returns 1 both numbers have only 1 as common factor
			}
		}
		if(noCommonFactor == 0) cout << "No estimate for this data set." << endl;
		else cout << setprecision(6) << fixed << sqrt(6.0 * ((double)total / (double)noCommonFactor)) << endl;
	}
	return 0;
}
