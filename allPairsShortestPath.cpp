#include <iostream>
#include <limits.h>

using namespace std;

// Number of vertices in the graph
#define V 100

// A function to print the solution matrix
void printSolution(int dist[][V], int n)
{
    cout << " shortest distances"
            " between every pair of vertices \n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dist[i][j] == INT_MAX)
                cout << "INF ";
            else
                cout << dist[i][j] << "   ";
        }
        cout << endl;
    }
}

// The main function that finds the shortest distances between every pair of vertices
void floydWarshall(int graph[][V], int n)
{
    int dist[V][V], i, j, k;

    // Initialize the solution matrix same as input graph matrix.
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            dist[i][j] = graph[i][j];

    // Add all vertices one by one to the set of intermediate vertices.
    // Before start of an iteration, we have shortest distances between all pairs of vertices
    // such that the shortest distances consider only the vertices in the set {0, 1, 2, .. k-1} as intermediate vertices.
    for (k = 0; k < n; k++)
    {
        // Pick all vertices as source one by one
        for (i = 0; i < n; i++)
        {
            // Pick all vertices as destination for the above picked source
            for (j = 0; j < n; j++)
            {
                // If vertex k is on the shortest path from i to j,
                // then update the value of dist[i][j]
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX
                    && dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    // Print the shortest distance matrix
    printSolution(dist, n);
}

int main()
{
    int n, graph[V][V];

    cout << "Enter the number of vertices: ";
    cin >> n;

    cout << "Enter the adjacency matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == -1) {
                // If the input is -1, set it to INF
                graph[i][j] = INT_MAX;
            }
        }
    }

    // Print the input matrix
    cout << "Input matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] == INT_MAX) {
                cout << "INF ";
            } else {
                cout << graph[i][j] << " ";
            }
        }
        cout << endl;
    }

    // Run the Floyd-Warshall algorithm
    floydWarshall(graph, n);
    return 0;
}


