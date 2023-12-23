#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max(); // infinity value

void floydWarshall(vector<vector<int>>& dist) {
    int n = dist.size();
    // Apply Floyd-Warshall algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

int main() {
    // Create graph adjacency matrix
    vector<vector<int>> graph = {
        {0, INF, -2, INF},
        {4, 0, 3, INF},
        {INF, INF, 0, 2},
        {INF, -1, INF, 0}
    };

    // Apply Floyd-Warshall algorithm
    floydWarshall(graph);

    // Output shortest distances
    int n = graph.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] == INF) {
                cout << "INF ";
            } else {
                cout << graph[i][j] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
