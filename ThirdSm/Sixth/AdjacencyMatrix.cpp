#include <iostream>
#include "AdjacencyMatrix.h"

using namespace std;

Graph::Graph(): size(8), count_nodes(0)
{
	this->matrix = CreateMtx(this->size);
}

Graph::~Graph()
{
	Clear(this->matrix, this->size);
}

int Graph::Completion()
{
	int i, j, weight;
	cout << "Entre two note and weight" << endl;
	while (cin >> i >> j >> weight) {
		int retcode = AddEdge(i-1, j-1, weight);
		if (retcode)
			return -1;
	}
	return 0;
}

int Graph::AddEdge(int vector, int edge, int weight)
{
	int m = (vector < edge) ? vector : edge; // min
	if ((m < 0) || (vector == edge))
		return -1;
	m = (vector > edge) ? vector : edge;  // max
	if ((m >= this->count_nodes)) {
		int m = (vector > edge) ? vector : edge;
		if (m > this->size)
			Increase(m);
		else
			this->count_nodes = m+1;
	}
	this->matrix[vector][edge] = weight;
	this->matrix[edge][vector] = weight;
	return 0;
}

int Graph::RemoveEdge(int vector, int edge)
{
	if ((vector < 0) || (edge < 0))
		return -1;
	this->matrix[vector][edge] = 0;
	this->matrix[edge][vector] = 0;
	return 0;
}

void Graph::Show()
{
  for (int i = 0; i < this->count_nodes; i++) {
	  cout << i+1 << " : ";
	  for (int j = 0; j < this->count_nodes; j++)
			cout << this->matrix[i][j] << " ";
	  cout << "\n";
  }
}

void Graph::ShowEulerCycle()
{
	if (!ExistEulerCycle()) {
		cout << "euler cycle not exist" << endl;
		return;
	}
	int **save_matrix = Extract();
	ShowEulerCycle(0);
	cout << endl;
	Clear(this->matrix, this->size);
	this->matrix = save_matrix;
}

void Graph::ShowSpanningTree()
{
	int **spanning_tree = AlgPrima();
	cout << "Edge" << " : " << "Weight" << endl;
	for (int i = 0; i < this->count_nodes-1; i++) {
		for (int j = i+1; j < this->count_nodes; j++) {
			if ((i != j) && spanning_tree[i][j])
				cout << i+1 << " - " << j+1 << " : " << spanning_tree[i][j] << endl;
		}
	}
	Clear(spanning_tree, this->count_nodes);
}

int** Graph::AlgPrima()
{
	int **spanning_tree = CreateMtx(this->count_nodes);
	int edges = 0;
	bool selected[this->count_nodes];
	for (int i = 1; i < this->count_nodes; i++)
		selected[i] = false;
	selected[0] = true;

	int min;
	int x, y;

	while (edges < this->count_nodes - 1) {
		min = 9999999;
		x = 0;
		y = 0;

		for (int i = 0; i < this->count_nodes; i++) {
			if (selected[i]) {
				for (int j = 0; j < this->count_nodes; j++) {
					if (!selected[j] && this->matrix[i][j]) {
						if (min > this->matrix[i][j]) {
							min = this->matrix[i][j];
							x = i;
							y = j;
						}
					}
				}
			}
		}
		span_tree[x][y] = this->matrix[x][y];
		span_tree[y][x] = this->matrix[x][y];
		selected[y] = true;
		edges++;
	}
	return span_tree;
}

void Graph::Increase(int max)
{
	int old_size = this->size;
	while (this->size < max)
		this->size *= 2;

	int **tmp_mtx = this->matrix;
	this->matrix = new int*[this->size];

	for (int i = 0; i < this->size-1; i++) {
		this->matrix[i] = new int[this->size];
		for (int j = 0; j < this->size; j++) {
			if (i < old_size && j < old_size) {
				this->matrix[i][j] = tmp_mtx[i][j];
			} else {
				this->matrix[i][j] = 0;
			}
		}
		delete [] tmp_mtx[i];
	}
	delete [] tmp_mtx;
}

int *Graph::DegreesVertices()
{
	int *degrees = new int[this->count_nodes];
	for (int i = 0; i < this->count_nodes; i++) {
		degrees[i] = 0;
		for (int j = 0; j < this->count_nodes; j++) {
			if (this->matrix[i][j])
				degrees[i]++;
		}
	}
	return degrees;
}

void Graph::ShowEulerCycle(int edge)
{
	int i = 0;
	while (!this->matrix[edge][i]) {
		i++;
		if (i >= this->count_nodes) {
			cout << edge << " ";
			return;
		}
	}
	RemoveEdge(edge, i);
	ShowEulerCycle(i);
	cout << edge << " ";
}

int Graph::ExistEulerCycle()
{
	int *degrees = DegreesVertices();
	for (int i = 0; i < this->count_nodes; i++) {
		if (degrees[i] % 2 != 0)
			return false;
	}
	return true;
}

int** Graph::CreateMtx(int size)
{
	int **matrix = new int*[size];
	for (int i = 0; i < size; i++) {
		matrix[i] = new int[size];
		for (int j = 0; j < size; j++) {
			matrix[i][j] = 0;
		}
	}
	return matrix;
}

int **Graph::Extract()
{
	int **nw_mtx = new int*[this->size];
	for (int i = 0; i < this->count_nodes; i++) {
		nw_mtx[i] = new int[this->size];
		for (int j = 0; j < this->size; j++) {
			nw_mtx[i][j] = this->matrix[i][j];
		}
	}
	return nw_mtx;
}

void Graph::Clear(int **mtx, int size)
{
	for (int i = 0; i < size; i++) {
		delete [] mtx[i];
	}
	delete [] mtx;
}
