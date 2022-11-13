#include <iostream>
#include "AdjacencyMatrix.h"

using namespace std;

int main()
{
	Graph gph;
	gph.Completion();
	/*
0 1 1
0 2 1
0 3 1
0 4 1
1 2 1
2 3 1
2 4 1
	 */
	gph.Show();
	gph.ShowEulerCycle();
	gph.ShowSpanningTree();
	return 0;
}
