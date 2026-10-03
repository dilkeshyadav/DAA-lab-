#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));

    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    vector<int> key(n, INT_MAX);
    vector<bool> used(n, false);
    vector<int> parent(n, -1);

    key[0] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = -1;

        // Find the vertex having the minimum edge weight
        for (int i = 0; i < n; i++) {
            if (!used[i] && (u == -1 || key[i] < key[u]))
                u = i;
        }

        used[u] = true;

        // Check all neighbours of u
        for (int v = 0; v < n; v++) {
            if (graph[u][v] != 0 && !used[v] &&
                graph[u][v] < key[v]) {

                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    int total = 0;

    cout << "\nEdges in MST:\n";

    for (int i = 1; i < n; i++) {
        cout << parent[i] << " - " << i
             << "  Weight: " << graph[i][parent[i]] << endl;

        total += graph[i][parent[i]];
    }

    cout << "Total weight = " << total << endl;

    return 0;
}
