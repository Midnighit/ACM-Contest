//============================================================================
// Name        : OptimalArrayMultiplicationSequence.cpp
// Author      : ae652720
// Description : 348 - Optimal Array Multiplication Sequence
//============================================================================

#include <iostream>
#include <sstream>
using namespace std;


string output(long *s, int i, int j, int n)
{
	if(i == j)
	{
		ostringstream ss;
		ss << "A" << i + 1;
		return ss.str();
	}
	else
	{
		int k = *(s + i * n + j);
		string left = "(" + output(s, i, k, n) + " x ";
		string right = output(s, k + 1, j, n) + ")";
		return left + right;
	}
}

int main()
{
	int caseNr = 0;

	while(true)
	{
		int n;
		cin >> n;			// how many matrices should be multiplied
		if(n == 0) break;

		caseNr++;			// read row and column dimensions in the following format:
		int p[n + 1];		// A1row, A1col = A2row, ..., Anrow = An+1col, An+1row
		for(int i = 0; i < n; i++) cin >> p[i] >> p[i + 1];

		long m[n][n];		// number of multiplications required
		long s[n][n];		// where to split between matrices

		for(int i = 0; i < n; i++) m[i][i] = 0;	// reset all multiplication counters to 0

		for(int len = 1; len < n; len++)		// len = length of chain - 1
		{										// e.g. A1 x A2 => len = 1
			for(int i = 0; i < n - len; i++)	// i counts from the left boundary to the splitting point
			{
				int j = i + len;				// j counts from the splitting point to the right boundary
				m[i][j] = -1;					// m[i][j] == -1 means there has been no result yet
				for(int k = i; k < j; k++)		// the splitting point moves from i (left) to j (right)
				{
					int q = m[i][k] + m[k + 1][j] + p[i] * p[k + 1] * p[j + 1];	// calculate the number of required multiplications
					if(m[i][j] < 0 || q < m[i][j])								// if there hasn't been a result yet or the result is lower
					{
						m[i][j] = q;			// keep the number of multiplications as new lowest
						s[i][j] = k;			// keep the splitting point that achieved this number
					}
				}
			}
		}

		cout << "Case " << caseNr << ": " << output(&s[0][0], 0, n - 1, n) << endl;
	}
	return 0;
}
