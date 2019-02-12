//============================================================================
// Name        : SuDoku.cpp
// Author      : ae652720
// Description : 989 - Su Doku
//============================================================================

#include <iostream>

using namespace std;

const int B[10] = {0, 1, 2, 4, 8, 16, 32, 64, 128, 256};	// used for the bitwise manipulations of sl, sc and sb
int n, b;			// b = number of blocks, n = dimension of the matrix
int in[81];			// sequence of the 81 fields of the su doko top to bottom, left to right
int v[9][9];		// v[a][b] = Su Doku matrix (a = line, b = column)
int sl[9];			// sl[a] = set lines (a = line, first bit of int = 1 is set, second bit = 2 is set...)
int sc[9];			// sc[a] = set columns (a = column, first bit of int = 1 is set, second bit = 2 is set...)
int sb[3][3];		// sb[a][b] = set block (a = block line, b = block column, first bit of int = 1 is set, second bit = 2 is set...)
bool solution;		// is set to true if a solution is found

// sets the given value at line l and column c if it doesn't break Su Doku rules
bool set(int l, int c, int value)
{	// if the given value is already set in the line, column or block return false
	if((sl[l] | sc[c] | sb[(int)(l / b)][(int)(c / b)]) & B[value]) return false;
	else
	{
		sl[l] = sl[l] | B[value];	// sets the corresponding bit in sl, sc and sb
		sc[c] = sc[c] | B[value];	// e.g. the first bit is 2^0=1, the fifth bit which is 2^4=16 if value is 5
		sb[(int)(l / b)][(int)(c / b)] = sb[(int)(l / b)][(int)(c / b)] | B[value];
		v[l][c] = value;			// the value is set in the field of the su doku
		return true;				// if the value has been set the function returns true
	}
}

// unsets the given value at line l and column c
void unset(int l, int c, int value)
{
	sl[l] = sl[l] ^ B[value];		// xor always results in 0 if both bits are set
	sc[c] = sc[c] ^ B[value];		// which they have to be in order for unset to be called
	sb[(int)(l / b)][(int)(c / b)] = sb[(int)(l / b)][(int)(c / b)] ^ B[value];
	v[l][c] = 0;					// value of the field in the su doku is set to 0 again
}

// puts out the whole matrix saved in v
void output()
{
	for(int l = 0; l < n; l++)
	{
		for(int c = 0; c < n; c++)
		{
			cout << v[l][c];
			if(c < (n - 1)) cout << " ";
			else cout << endl;

		}
	}
	cout << endl;
}

// transforms the sequential input in the in array to the matrix format of v and sets the bits in sl, sc and sb
void transform()
{
	int k = 0;
	for(int l = 0; l < n; l++)
	{
		for(int c = 0; c < n; c++)
		{
			v[l][c] = in[k];	// l = line index, c = column index
			if(in[k] > 0)		// save non empty entries to corresponding
			{
				sl[l] = sl[l] | B[in[k]];	// set lines,
				sc[c] = sc[c] | B[in[k]];	// columns and
				sb[(int)(l / b)][(int)(c / b)] = sb[(int)(l / b)][(int)(c / b)] | B[in[k]];	// blocks
			}
			k++;
		}
	}
}

// reads the su doko from stdin
bool input()
{
	cin >> b;					// b = number of blocks in x and y direction
	if(b == 0) return false;	// if 0 is entered the program ends.
	n = b * b;					// A 9x9 Su Doku consists has 3x3 (n=3) rows and columns.
	solution = false;			// solution is set to true once the first valid solution has been found

	for(int l = 0; l < n; l++)
	{
		for(int c = 0; c < n; c++)
		{
			cin >> in[l * n + c];
		}
	}

	for(int k = 0; k < n; k++)
	{
		sl[k] = 0;									// reset lines,
		sc[k] = 0;									// reset columns and
	}
	for(int k = 0; k < b; k++)
		for(int l = 0; l < b; l++) sb[k][l] = 0;	// reset blocks

	transform();				// set v, sl, sc and sb according to input
	return true;
}

// returns the solution if there is only one valid one for the field (e.g. all but 1 of the first n bits are set to 1)
int hasOneSolution(int x)
{
	char num = 0;
	char solution = 0;
	for(int i = 1; i <= n; i++)
	{
		if(!(x & B[i]))			// if the bit in question is not set in x, i is a valid solution
		{
			num++;				// increase the number of solutions by one
			solution = i;		// remember the found solution
		}
		if(num > 1) return 0;	// if num > 1, more than one solution has been found and hasOneSolution returns 0
	}
	if(solution == 1) return solution;	// if exactly one solution has been found hasOneSolution returns that solution
	else return 0;				// if no solutions have been found it returns 0
}

// solves as much of the Su Doku as possible with fields where the solution is definite (e.g. fields that only have one solution)
void smartSolve()
{
	int l = 0;
	int c = 0;
	int k = 0;
	int s = 0;

	/* loop from top to bottom and left to right until all fields of the su doku have been checked once
	 * since the last field with exactly one solution had been found.
	 */
	while(k < (n*n))
	{
		if(v[l][c] == 0 && (s = hasOneSolution((sl[l] | sc[c] | sb[(int)(l / b)][(int)(c / b)]))))
		{
			set(l, c, s);	// hasOneSolution has found definite solution s which is set at position l and c
			k = 0;			// k is reset to 0, if no solutions are found for the next n*n fields there are no more definite solutions
		}
		c++;
		if(c == n)
		{
			c = 0;
			l++;
			if(l == n) l = 0;
		}
		k++;				// regardless of the result, each time the algorith continues to the next field k is increased by one
	}

}

// recursive backtracking function to find valid values for all zeros and put out the first solution to the whole Su Doku
void solve(int l, int c)
{
	do
	{
		c++;
		if(c == n)
		{
			c = 0;
			l++;
			if(l == n)
			{
				output();
				solution = true;
				return;
			}
		}
	}
	while(v[l][c] != 0);	// repeat until either the next zero is found or there are no zeros left (in which case a solution has been found)

	for(int value = 1; value <= n; ++value)	// if a zero has been found, try all values from 1 to n (dimension)
	{
		if(set(l, c, value))	// for each value check if it can be set and do so if true
		{
			solve(l, c);			// try to solve the rest of the Su Doku (starting with the next column)
			if(solution) return;	// if a solution has already been found (after returning here), don't continue
			unset(l, c, value);		// if no solution has been found, unset the last set value and go on with the for loop
		}
	}
}

int main()
{
	while(true)
	{
		if(!input()) break;			// get input
		smartSolve();				// solve all definite fields (those with only one solution)
		solve(0, -1);				// solve the rest via backtracking algorithm
		if(!solution) cout << "NO SOLUTION" << endl;
		break;
	}

	return 0;
}
