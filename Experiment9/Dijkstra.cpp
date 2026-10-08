#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n, e;
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> e;

    vector<vector<pair<int, int>>> graph(n);

    cout << "Enter edges (source destination weight):\n";
    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    int source;
    cout << "Enter source vertex: ";
    cin >> source;

    vector<int> dist(n, INT_MAX);
    vector<bool> visited(n, false);

    dist[source] = 0;

    for (int count = 0; count < n; count++) {
        int u = -1;

        for (int i = 0; i < n; i++) {
            if (!visited[i] && dist[i] != INT_MAX &&
                (u == -1 || dist[i] < dist[u])) {
                u = i;
            }
        }

        if (u == -1)
            break;

        visited[u] = true;

        for (auto edge : graph[u]) {
            int v = edge.first;
            int w = edge.second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    cout << "\nShortest distances from vertex " << source << ":\n";

    for (int i = 0; i < n; i++) {
        cout << source << " -> " << i << " = ";

        if (dist[i] == INT_MAX)
            cout << "INF";
        else
            cout << dist[i];

        cout << endl;
    }

    return 0;
}
