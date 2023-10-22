#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph
{
    int V;
    vector<int> *adj;

public:
    Graph(int V);
    ~Graph(); // Destructor to release memory
    void addEdge(int v, int w);
    int degree(int v);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new vector<int>[V];
}

Graph::~Graph()
{
    delete[] adj; // Release memory for the adjacency list
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}

int Graph::degree(int v)
{
    return adj[v].size();
}

int main()
{
    int V, E, K;
    cin >> V >> E;
    cin >> K;

    Graph g(V);

    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    cout << g.degree(K) << endl;

    return 0;
}
