#include <iostream>
#include <list>
using namespace std;

class Graph
{
	int V;// количество вертикалей

	list<int>* adj;//указатель на массив содержащий смежные списки

	//функция для DFS
	void DFSUtil(int v, bool visited[]);

public :
	Graph(int V);
	~Graph();
	void addEdge(int v, int w);
	void connectedComponents();
};
//Способ вывода компонентов связности в ненаправленном графе
void Graph::connectedComponents()
{
	//отмечаем все вершины как непройденные 
	bool* visited = new bool[V];
	for (int v = 0; v < V; v++)
	{
		if (visited[v] == false)
		{
			//выводим все достижиме вершины от v
			DFSUtil(v, visited);

			cout << "\n";
		}
	}
	delete[] visited;
}

void  Graph::DFSUtil(int v, bool visited[])
{
	//отмечаем все вершины как пройденные  и выводим их
	visited[v] = true;
	cout << v << " ";

	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); i++)
		if (!visited[*i])
			DFSUtil(*i, visited);
}

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}
Graph::~Graph()
{
	delete[] adj;
}

//расписываем добавление ребра
void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
	adj[w].push_back(v);
}

int main()
{
	Graph g(5);
	g.addEdge(1, 0);
	g.addEdge(2, 1);
	g.addEdge(3, 4);

	cout << "Connected components \n";
	g.connectedComponents();
	
	return 0;
}

