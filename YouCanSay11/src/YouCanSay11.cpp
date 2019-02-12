//============================================================================
// Name        : YouCanSay11.cpp
// Author      : ae652720
// Description : 10929 - You can say 11
//============================================================================

#include <iostream>
#include <string>
using namespace std;

int main()
{
	int crosstotal, digit;
	string number;

	do
	{
		cin >> number;
		if(number == "0") break;
		crosstotal = 0;
		for(unsigned int i = 0; i < number.length(); i++)
		{
			digit = number[i] - 48;
			if((i % 2) == 0) crosstotal += digit;
			else crosstotal -= digit;
		}
		if((crosstotal % 11) == 0) cout << number << " is a multiple of 11." << endl;
		else cout << number + " is not a multiple of 11." << endl;
	}
	while(true);

	return 0;
}
