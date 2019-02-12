//============================================================================
// Name        : Combinations.cpp
// Author      : ae652720
// Description : 369 - Combinations
//============================================================================

#include <iostream>
using namespace std;

unsigned long triangle[101];

/**
 * find constructs a pascal's triangle by iteratively adding up neighboring numbers within the triangle
 * 	level 0:					1
 * 	level 1:				1		1
 *	level 2: 			1		2		1
 *	level 3:		1		3		3		1
 *	level 4:	1		4		6		4		1
 *			depth 1	depth 2	depth 3	depth 2	depth 1
 */
unsigned long find(int n, int m)
{
	int depth, level;
	for(depth = 0; depth <= m ; depth++) triangle[depth] = 1;	// fill the border of the triangle with ones (depth = 0)
	for(depth = 1; depth <= (n - m); depth++)					// the depth of the triangle is determined by the difference between n and m
	{															// the next level of the triangle is calculated by adding the value of...
																// ...current depth and previous level + previous depth and current level
		for(level = 1; level <= n; level++) triangle[level] = triangle[level] + triangle[level - 1];
	}
	return triangle[m];
}

int main()
{
	int m, n;
	while(true)
	{
		cin >> n >> m;
		if( m == 0 && n == 0 ) break;
		cout << n << " things taken " << m << " at a time is "     << find(n, m) << " exactly." << endl;
	}
	return 0;
}
