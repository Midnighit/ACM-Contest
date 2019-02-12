//============================================================================
// Name        : TheTwinTowers.cpp
// Author      : ae652720
// Description : 10066 - The Twin Towers
//============================================================================


#include <iostream>
using namespace std;

int main()
{
	int towerNr = 0;
	int i, j;

	while(true)
	{
		int m, n;
		cin >> m >> n;					// Tower X has m pieces, Tower Y has n pieces
		if(m == 0 && n == 0) break;		// if both m and n are 0, stop the program

		towerNr++;						// count the number of Twin Towers calculated

		int X[m];
		int Y[n];

		for(i = 0; i < m; i++) cin >> X[i];	// Read the actual pieces for Tower X
		for(i = 0; i < n; i++) cin >> Y[i];	// Read the actual pieces for tower Y

		int c[m + 1][n + 1];				// c[a][b] saves the longest distance

		for(i = 1; i <= m; i++) c[i][0] = 0;	// reset the distances to 0
		for(j = 0; j <= n; j++) c[0][j] = 0;	// for all relevant indexes

		for (i = 1; i <= m; i++)
		{
			for (j = 1; j <= n; j++)
			{
				if (X[i - 1] == Y[j - 1]) c[i][j] = c[i - 1][j - 1] + 1;
				else if (c[i - 1][j] >= c[i][j - 1]) c[i][j] = c[i - 1][j];
				else c[i][j] = c[i][j - 1];
			}
		}
		cout << "Twin Towers #" << towerNr << endl << "Number of Tiles : " << c[m][n] << endl << endl;
	}
	return 0;
}
