#include <iostream>
#include <vector>
using namespace std;

void DFS(int vertex, vector<vector<int>> &graph, vector<bool> &visited)
{
    visited[vertex] = true;
    cout << vertex << " ";

    for (int i = 0; i < graph[vertex].size(); i++)
    {
        int neighbour = graph[vertex][i];

        if (!visited[neighbour])
        {
            DFS(neighbour, graph, visited);
        }
    }
}

int main()
{
    int vertices, edges;

    cout << "Enter number of vertices: ";
    cin >> vertices;

    cout << "Enter number of edges: ";
    cin >> edges;

    vector<vector<int>> graph(vertices);
    vector<bool> visited(vertices, false);

    cout << "Enter the edges:\n";

    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    cout << "\nConnected Components:\n";

    int component = 1;

    for (int i = 0; i < vertices; i++)
    {
        if (!visited[i])
        {
            cout << "Component " << component << ": ";
            DFS(i, graph, visited);
            cout << endl;

            component++;
        }
    }

    return 0;
}
