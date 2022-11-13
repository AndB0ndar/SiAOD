#ifndef ADJACENCY_MATRIX_H
#define ADJACENCY_MATRIX_H

class Graph
{
	int **matrix;
	int size;
	int count_nodes;
public:
	Graph();
	~Graph();
	int Completion();
	int AddEdge(int vector, int edge, int weight=1);
	int RemoveEdge(int vector, int edge);
	void Show();
	void ShowEulerCycle();
	void ShowSpanningTree();
	int** AlgPrima();
private:
	void Increase(int max);
	int** Extract();
	int *DegreesVertices();
	void ShowEulerCycle(int edge);
	int ExistEulerCycle();
	static void Clear(int **mtx, int size);
};

#endif
