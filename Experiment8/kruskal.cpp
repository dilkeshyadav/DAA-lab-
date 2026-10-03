#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int from, to, weight;
};

bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

int findParent(vector<int>& parent, int x) {
    if (parent[x] == x)
        return x;

    return parent[x] = findParent(parent, parent[x]);
}

void join(vector<int>& parent, vector<int>& rank, int a, int b) {
    a = findParent(parent, a);
    b = findParent(parent, b);

    if (a == b)
        return;

    if (rank[a] < rank[b])
        parent[a] = b;
    else if (rank[a] > rank[b])
        parent[b] = a;
    else {
        parent[b] = a;
        rank[a]++;
    }
}

int main() {
    int n, m;

    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;

    vector<Edge> edges(m);

    cout << "Enter edges (from to weight):\n";

    for (int i = 0; i < m; i++) {
        cin >> edges[i].from
            >> edges[i].to
            >> edges[i].weight;
    }

    // Arrange edges from smallest weight to largest
    sort(edges.begin(), edges.end(), compare);

    vector<int> parent(n);
    vector<int> rank(n, 0);

    for (int i = 0; i < n; i++)
        parent[i] = i;

    int total = 0;
    int taken = 0;

    cout << "\nEdges in MST:\n";

    for (int i = 0; i < m && taken < n - 1; i++) {

        int a = edges[i].from;
        int b = edges[i].to;

        // Add edge only if it doesn't make a cycle
        if (findParent(parent, a) != findParent(parent, b)) {

            cout << a << " - " << b
                 << "  Weight: " << edges[i].weight << endl;

            total += edges[i].weight;
            taken++;

            join(parent, rank, a, b);
        }
    }

    cout << "Total weight = " << total << endl;

    return 0;
}
