//============================================================================
// Name        : TheHammingDistanceProblem.cpp
// Author      : ae652720
// Description : 729 - The Hamming Distance Problem
//============================================================================

#include <iostream>
using namespace std;

int main()
{
	char num[17];					// buffer for the binary number string + null terminator
	int i, j, k;
	int n, h;						// number length and hamming distance
	int datasets;					// number of data sets to calculate
	bool newline = false;			// set to true when a newline needs to be printed
	cin >> datasets;				// read number od data sets
	for(i = 0; i < datasets; i++)	// repeat loop until all data sets have been calculated
	{
		if(newline) cout << endl;
		else newline = true;

		cin >> n >> h;								// read length and hamming distance
		num[n] = 0;									// insert null terminator at the end of the binary number string
		for(j = 0; j < (n - h); j++) num[j] = '0';	// fill the first n - h bits with zeros
		while(j < n) num[j++] = '1';				// the other bits filled with ones to finish the starting binary number

		while(true)
		{
			cout << num << endl;		// print the current binary number
			j = n - 1;					// j points to the last digit of the binary number
			while(num[j] == '0') j--;	// find the first one from the end
			k = -1;						// k points in front of the first digit of the binary number
			while(num[j] == '1')		// repeat until j points to the first zero
			{
				j--;
				k++;
			}
			if(j < 0) break;			// if j gets smaller than 0 all permutations have been printed
			num[j] = '1';				// otherwise change this zero to one
			for(j += 1; j < (n - k); j++) num[j] = '0';	// fill the n - k bits after the changed bit to zero
			while(j < n) num[j++] = '1';	// the other bits are filled with ones
		}
	}
	return 0;
}
