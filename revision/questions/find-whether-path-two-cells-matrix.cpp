/*
  https://www.geeksforgeeks.org/find-whether-path-two-cells-matrix/
*/
// C++ program to find path between two 
// cell in matrix 
#include<bits/stdc++.h> 
using namespace std; 
#define N 4 

class Graph 
{ 
	int V ; 
	list < int > *adj; 
public : 
	Graph( int V ) 
	{ 
		this->V = V ; 
		adj = new list<int>[V]; 
	} 
	void addEdge( int s , int d ) ; 
	bool BFS ( int s , int d) ; 
}; 

// add edge to graph 
void Graph :: addEdge ( int s , int d ) 
{ 
	adj[s].push_back(d); 
	adj[d].push_back(s); 
} 

// BFS function to find path from source to sink 
bool Graph :: BFS(int s, int d) 
{ 
	// Base case 
	if (s == d) 
		return true; 

	// Mark all the vertices as not visited 
	bool *visited = new bool[V]; 
	for (int i = 0; i < V; i++) 
		visited[i] = false; 

	// Create a queue for BFS 
	list<int> queue; 

	// Mark the current node as visited and 
	// enqueue it 
	visited[s] = true; 
	queue.push_back(s); 

	// it will be used to get all adjacent 
	// vertices of a vertex 
	list<int>::iterator i; 

	while (!queue.empty()) 
	{ 
		// Dequeue a vertex from queue 
		s = queue.front(); 
		queue.pop_front(); 

		// Get all adjacent vertices of the 
		// dequeued vertex s. If a adjacent has 
		// not been visited, then mark it visited 
		// and enqueue it 
		for (i = adj[s].begin(); i != adj[s].end(); ++i) 
		{ 
			// If this adjacent node is the destination 
			// node, then return true 
			if (*i == d) 
				return true; 

			// Else, continue to do BFS 
			if (!visited[*i]) 
			{ 
				visited[*i] = true; 
				queue.push_back(*i); 
			} 
		} 
	} 

	// If BFS is complete without visiting d 
	return false; 
} 

bool isSafe(int i, int j, int M[][N]) 
{ 
	if ((i < 0 || i >= N) || 
		(j < 0 || j >= N ) || M[i][j] == 0) 
		return false; 
	return true; 
} 

// Returns true if there is a path from a source (a 
// cell with value 1) to a destination (a cell with 
// value 2) 
bool findPath(int M[][N]) 
{ 
	int s , d ; // source and destination 
	int V = N*N+2; 
	Graph g(V); 

	// create graph with n*n node 
	// each cell consider as node 
	int k = 1 ; // Number of current vertex 
	for (int i =0 ; i < N ; i++) 
	{ 
		for (int j = 0 ; j < N; j++) 
		{ 
			if (M[i][j] != 0) 
			{ 
				// connect all 4 adjacent cell to 
				// current cell 
				if ( isSafe ( i , j+1 , M ) ) 
					g.addEdge ( k , k+1 ); 
				if ( isSafe ( i , j-1 , M ) ) 
					g.addEdge ( k , k-1 ); 
				if (j< N-1 && isSafe ( i+1 , j , M ) ) 
					g.addEdge ( k , k+N ); 
				if ( i > 0 && isSafe ( i-1 , j , M ) ) 
					g.addEdge ( k , k-N ); 
			} 

			// source index 
			if( M[i][j] == 1 ) 
				s = k ; 

			// destination index 
			if (M[i][j] == 2) 
				d = k; 
			k++; 
		} 
	} 

	// find path Using BFS 
	return g.BFS (s, d) ; 
} 

// driver program to check above function 
int main() 
{ 
	int M[N][N] = {{ 0 , 3 , 0 , 1 }, 
		{ 3 , 0 , 3 , 3 }, 
		{ 2 , 3 , 3 , 3 }, 
		{ 0 , 3 , 3 , 3 } 
	}; 

	(findPath(M) == true) ? 
	cout << "Yes" : cout << "No" <<endl ; 

	return 0; 
} 

