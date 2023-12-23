#include <iostream>
#include <limits.h>

using namespace std;

// Function to find the vertex with minimum distance
int minDist(int dist[], bool sptSet[], int V)
{
    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

// Function to print the constructed distance array
void printSolution(int distance[], int V)
{
    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 0; i < V; i++)
        cout << i << "\t\t" << distance[i] << endl;
}

// Function that implements Dijkstra's algorithm
void dijkstra(int graph[][100], int src, int V)
{
    int distance[V]; // Inititalizing output array
    bool sptSet[V]; // List of visited nodes

    // Initializing all distances as INFINITE and sptSet[] as false
    for (int i = 0; i < V; i++)
        distance[i] = INT_MAX, sptSet[i] = false;

    // Setting distance of source as 0
    distance[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++)
    {
        // Calling minDistance to pick next vertex
        int u = minDist(distance, sptSet, V);

        // Mark the picked vertex as visited
        sptSet[u] = true;

        // Relaxing all neighbours of U
        for (int v = 0; v < V; v++)
        {
            if (!sptSet[v] && graph[u][v] && distance[u] != INT_MAX &&
                distance[u] + graph[u][v] < distance[v])
                distance[v] = distance[u] + graph[u][v];
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

    dijkstra(graph, src, V);

    return 0;
}
