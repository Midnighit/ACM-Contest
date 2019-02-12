//============================================================================
// Name        : TaxCalculator.cpp
// Author      : ae652720
// Version     :
// Copyright   : Your copyright notice
// Description : 12342 - Tax Calculator
//============================================================================

#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main()
{
	int max;
	long amount;
	double tax = 0;
	cout << setprecision(0);

	cin >> max;
	for(int i = 0; i < max; i++)
	{
		cin >> amount;

		// First 180k are free
		if(amount > 180000) amount -= 180000;
		else amount = 0;

		// Next 300k have 10% tax
		if(amount > 300000)
		{
			amount -= 300000;
			tax += 30000;
		}
		else if(amount > 0)
		{
			tax += amount * 0.1;
			amount = 0;
		}

		// Next 400k have 15% tax
		if(amount > 400000)
		{
			amount -= 400000;
			tax += 60000;
		}
		else if(amount > 0)
		{
			tax += amount * 0.15;
			amount = 0;
		}

		// Next 300k have 20% tax
		if(amount > 300000)
		{
			tax += 60000;
			amount -= 300000;
		}
		else if(amount > 0)
		{
			tax += amount * 0.2;
			amount = 0;
		}

		// Rest amount has 25% tax
		if(amount > 0)
		{
			tax += amount * 0.25;
			amount = 0;
		}

		// if any tax has been paid it has to be at least 2000
		if(tax > 0 && tax < 2000) tax = 2000;

		cout << "Case " << i + 1 << ": " << fixed << ceil(tax) << endl;
		tax = 0;
	}
	return 0;
}
