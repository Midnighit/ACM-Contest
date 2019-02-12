//============================================================================
// Name        : RelationalOperators.cpp
// Author      : ae652720
// Description : 11172 - Relational Operator
//============================================================================

#include <iostream>
using namespace std;

int main()
{
	int i, t;
	cin >> t;
	int a[t], b[t];
	for(i = 0; i < t; i++) cin >> a[i] >> b[i];
	for(i = 0; i < t; i++)
	{
		if(a[i] < b[i]) cout << "<" << endl;
		else if(a[i] > b[i]) cout << ">" << endl;
		else cout << "=" << endl;
	}
	return 0;
}
