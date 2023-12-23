#include <iostream>
#include <limits.h>

using namespace std;

// Function to print the constructed distance array
void printSolution(int distance[], int V)
{
    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 0; i < V; i++)
        cout << i << "\t\t" << distance[i] << endl;
}

// Function that implements Bellman-Ford algorithm
void bellmanFord(int graph[][100], int src, int V)
{
    int distance[V]; // Initializing output array

    // Initializing all distances as INFINITE
    for (int i = 0; i < V; i++)
        distance[i] = INT_MAX;

    // Setting distance of source as 0
    distance[src] = 0;

    // Relaxing all edges V-1 times
    for (int i = 1; i <= V - 1; i++)
    {
        for (int u = 0; u < V; u++)
        {
            for (int v = 0; v < V; v++)
            {
                if (graph[u][v] && distance[u] != INT_MAX &&
                    distance[u] + graph[u][v] < distance[v])
                    distance[v] = distance[u] + graph[u][v];
            }
        }
    }

    // Checking for negative weight cycle
    for (int u = 0; u < V; u++)
    {
        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] && distance[u] != INT_MAX &&
                distance[u] + graph[u][v] < distance[v])
            {
                cout << "Graph contains negative weight cycle" << endl;
                return;
            }
        }
    }

    // Print the constructed distance array
    printSolution(distance, V);
}

// Driver function
int main()
{
    int V, src;
    cout << "Enter the number of vertices: ";
    cin >> V;

    // Example graph (same as Graph in the example diagram above)
    int graph[100][100];

    cout << "Enter the graph matrix (enter 0 if there is no edge):\n";
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cin >> graph[i][j];
        }
    }

    cout << "Enter the source vertex: ";
    cin >> src;

    bellmanFord(graph, src, V);

    return 0;
}
