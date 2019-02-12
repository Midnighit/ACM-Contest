//============================================================================
// Name        : 8QueensChessProblem.cpp
// Author      : ae652720
// Description : 750 - 8 Queens Chess Problem
//============================================================================

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int queens[8];
int n, fcol, fline;
int solved;

/**
 * prints the solution in the required layout
 */
void output()
{
	cout << endl << setw(2) << ++solved << "     ";
	for(int i = 0; i < 8; i++) cout << setw(2) << queens[i] + 1;
}

/**
 * checks if a queen at the passed line and column would be attackable given the current state of the queens array
 */
bool isAttackable(int line, int col)
{
	for(int i = 0; i < 8; i++)
	{
		if(queens[i] == col) return true;									// is another queen in the same column?
		if(line > i && ((line - i) == abs(queens[i] - col))) return true;	// is another queen diagonally above?
		if(line < i && ((i - line) == abs(queens[i] - col))) return true;	// is another queen diagonally below?
	}
	return false; // if it's neither of the above queen is not attackable
}

/**
 * Backtracking algorithm to find all solutions
 */
void solve(int line)
{
	if(line == fline) line++;		// don't check the line with the user defined queen
	for(int i = 0; i < 8; i++)
	{
		if(!isAttackable(line, i))
		{
			queens[line] = i;										// put a queen at current position
			if(line == 7 || (line == 6 && fline == 7)) output();	// if this has been the last line without queen one valid solution has been found!
			else solve(line + 1);									// otherwise try to find a solution with the given field
			queens[line] = 99;										// if the program comes here it means all valid solutions for this setting have been found
		}
	}
}

int main()
{
	cin >> n;										// get number of data sets to be solved
	for(int i = 0; i < n; i++)						// repeat for every data set
	{
		solved = 0;									// will be increased for every solution that is found
		for(int j = 0; j < 8; j++) queens[j] = 99;	// set all fields of queens to 99 (no queen set)
		cin >> fline >> fcol;						// get position of the queen in format line/column is read
		cout << "SOLN       COLUMN" << endl << " #      1 2 3 4 5 6 7 8" << endl;
		fline--; fcol--;							// array indices start at 0
		queens[fline] = fcol;						// save position in queens array
		solve(0);									// solve the problem starting with line 1
		cout << endl;
	}
	return 0;
}
