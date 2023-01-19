código Dijkstra c++

#include <iostream> 
#include <vector> 
#include <limits.h> 

using namespace std; 

# define INF 0x3f3f3f3f 

class Grafo 
{ 
	int V; 
	vector< vector<int> > distancia; 

public: 
	Grafo(int V); 
	void agregarEntrada(int u, int v, int w); 
	void Dijkstra(int s); 
}; 

Grafo::Grafo(int V) 
{ 
	this->V = V; 
	distancia.resize(V); 
	for (int i = 0; i < V; i++) 
		distancia[i].resize(V); 
} 

void Grafo::agregarEntrada(int u, int v, int w) 
{ 
	distancia[u][v] = w; 
} 

void Grafo::Dijkstra(int src) 
{ 
	vector<int> distancia_minima(V, INF); 

	distancia_minima[src] = 0; 

	vector<bool> visitados(V, false); 

	for (int i = 0; i < V - 1; i++) 
	{ 
		int u = -1; 
		int distancia_minima_u = INF; 
		for (int j = 0; j < V; j++) 
		{ 
			if (visitados[j] == false && 
				distancia_minima[j] < 
								distancia_minima_u) 
			{ 
				distancia_minima_u = distancia_minima[j]; 
				u = j; 
			} 
		} 

		visitados[u] = true; 

		for (int v = 0; v < V; v++) 
		{ 
			if (visitados[v] == false && 
				distancia[u][v] && 
				distancia_minima[u] != INF && 
				distancia_minima[u] + distancia[u][v] < 
								distancia_minima[v]) 
			{ 
				distancia_minima[v] = distancia_minima[u] + 
									distancia[u][v]; 
			} 
		} 
	} 

	cout << "Distancia más corta desde el nodo " << src << " a los otros nodos es:" << endl; 
	for (int i = 0; i < V; i++) 
	{ 
		char letra = i + 65; 
		cout << letra << " \t\t " << distancia_minima[i] << endl; 
	} 
} 

int main() 
{ 
	int V = 9; 
	Grafo g(V); 

	g.agregarEntrada(0, 1, 4); 
	g.agregarEntrada(0, 7, 8); 
	g.agregarEntrada(1, 2, 8); 
	g.agregarEntrada(1, 7, 11); 
	g.agregarEntrada(2, 3, 7); 
	g.agregarEntrada(2, 8, 2); 
	g.agregarEntrada(2, 5, 4); 
	g.agregarEntrada(3, 4, 9); 
	g.agregarEntrada(3, 5, 14); 
	g.agregarEntrada(4, 5, 10); 
	g.agregarEntrada(5, 6, 2); 
	g.agregarEntrada(6, 7, 1); 
	g.agregarEntrada(6, 8, 6); 
	g.agregarEntrada(7, 8, 7); 

	g.Dijkstra(0); 

	return 0; 
}
