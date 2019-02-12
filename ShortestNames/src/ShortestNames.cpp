//============================================================================
// Name        : ShortestNames.cpp
// Author      : ae652720
// Version     :
// Copyright   : Your copyright notice
// Description : 12506 - Shortest Names
//============================================================================

#include <iostream>
#include <algorithm>
using namespace std;


// compares and returns the minimum required letters to distinguish both
int compare(string name1, string name2)
{
	int length = 1;										// every name needs at least one letter
	for(unsigned int i = 0; i < name1.length(); i++)	// process the first string letter by letter
	{
		if(name1[i] != name2[i]) break;					// if letter is different in both names, the length has been found
		length++;										// else increase the length by one
	}
	return length;
}


int main()
{
	int cases;
	int names;

	cin >> cases;

	for(int i = 0; i < cases; i++)						// outer loop repeats once for every case
	{
		cin >> names;									// read number of names
		string *name = new string[names];

		for(int j = 0; j < names; j++) cin >> name[j];	// read names

		sort(name, name + names);						// sort the list of names alphabetically

		int lastLength = 1;
		int nextLength = 1;
		int sum = 0;

		for(int j = 0; j < names - 1; j++)				// inner loop compares each name with the following one
		{
			lastLength = nextLength;						// compare two neighboring names and keep the result in nextLength
			nextLength = compare(name[j], name[j + 1]);		// the result of last iteration is kept in lastLength
			if(nextLength > lastLength) sum += nextLength;	// the comparison that required most letters is the one necessary to identify the name
			else sum += lastLength;							// this result is added to the sum
		}
		sum += nextLength;								// required length for the last name is always the result of the last comparison

		cout << sum << endl;
		delete [] name;
	}

	return 0;
}
