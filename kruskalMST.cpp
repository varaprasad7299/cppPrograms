#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 100;

struct Edge {
    int u, v;
    float w;
};

struct DisjointSet {
    int parent[MAX_N];
    int rank[MAX_N];

    DisjointSet(int n) {
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int find(int u) {
        if (u != parent[u]) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    void merge(int x, int y) {
        x = find(x);
        y = find(y);

        if (rank[x] > rank[y]) {
            parent[y] = x;
        } else {
            parent[x] = y;
        }

        if (rank[x] == rank[y]) {
            rank[y]++;
        }
    }
};

float kruskal(vector<Edge>& edges, int n) {
    float min_cost = 0.0;
    int num_edges = 0;
    DisjointSet dsu(n);

    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.w < b.w;
    });

    for (auto& e : edges) {
        int u = e.u, v = e.v;
        float w = e.w;

        if (dsu.find(u) != dsu.find(v)) {
            dsu.merge(u, v);
            min_cost += w;
            num_edges++;

            if (num_edges == n - 1) {
                break;
            }
        }
    }

    if (num_edges < n - 1) {
        cout << "No spanning tree exists!" << endl;
        return -1;
    }

    return min_cost;
}

int main() {
    int n;
    vector<Edge> edges;
    float cost[MAX_N][MAX_N];

    cout << "Enter the number of vertices: ";
    cin >> n;

    cout << "Enter the adjacency matrix: " << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> cost[i][j];
            if (cost[i][j] > 0) {
                edges.push_back({i, j, cost[i][j]});
            }
        }
    }

    float min_cost = kruskal(edges, n);
    cout << "Minimum cost of the spanning tree: " << min_cost << endl;

    return 0;
}

