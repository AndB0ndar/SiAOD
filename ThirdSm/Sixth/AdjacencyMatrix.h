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
private:
	int* DegreesVertices();
	int ExistEulerCycle();
	void ShowEulerCycle(int edge);
	int** AlgPrima();
	int** CreateMtx(int size);
	void Increase(int max);
	int** Extract();
	static void Clear(int **mtx, int size);
};

#endif
