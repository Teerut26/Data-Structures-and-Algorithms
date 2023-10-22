#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph
{
    int V;
    vector<int> *adj;

public:
    Graph(int V)
    {
        this->V = V;
        adj = new vector<int>[V];
    }
    ~Graph()
    {
        delete[] adj;
    }
    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
        adj[w].push_back(v);
    }
    int degree(int v)
    {
        return adj[v].size();
    }
    int isTree()
    {
        bool *visited = new bool[V];
        for (int i = 0; i < V; i++)
        {
            visited[i] = false;
        }
        int *parent = new int[V];
        for (int i = 0; i < V; i++)
        {
            parent[i] = -1;
        }
        int *level = new int[V];
        for (int i = 0; i < V; i++)
        {
            level[i] = -1;
        }
        queue<int> q;
        q.push(0);
        visited[0] = true;
        level[0] = 0;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (int i = 0; i < adj[u].size(); i++)
            {
                int v = adj[u][i];
                if (!visited[v])
                {
                    visited[v] = true;
                    parent[v] = u;
                    level[v] = level[u] + 1;
                    q.push(v);
                }
                else if (parent[u] != v)
                {
                    return 0;
                }
            }
        }
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                return 0;
            }
        }
        return 1;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;

    Graph g(n);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        g.addEdge(u, v);
    }

    if (g.isTree())
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}