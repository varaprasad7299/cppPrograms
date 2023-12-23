#include <iostream>
#include <climits>
using namespace std;

const int Size = 100;

// Function to find the minimum cost edge in E
void min_cost_edge(int E[][Size], float cost[][Size], int n, int& k, int& l) {
    float min_cost = INT_MAX;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (cost[i][j] < min_cost) {
                min_cost = cost[i][j];
                k = i;
                l = j;
            }
        }
    }
}

// Prim's algorithm for minimum spanning tree
float prim(int E[][Size], float cost[][Size], int n) {
    int near[Size] = {0}, j, k, l;
    min_cost_edge(E, cost, n, k, l);
    float min_cost = cost[k][l];
    for (int i = 1; i <= n; i++) {
        if (cost[i][l] < cost[i][k]) {
            near[i] = l;
        } else {
            near[i] = k;
        }
    }
    near[k] = near[l] = 0;
    for (int i = 2; i <= n-1; i++) {
        int j;
        for (j = 1; near[j] == 0; j++) {}
        for (int k = j+1; k <= n; k++) {
            if (near[k] != 0 && cost[k][near[k]] < cost[j][near[j]]) {
                j = k;
            }
        }
        min_cost += cost[j][near[j]];
        near[j] = 0;
        for (int k = 1; k <= n; k++) {
            if (near[k] != 0 && cost[k][near[k]] > cost[k][j]) {
                near[k] = j;
            }
        }
    }
    return min_cost;
}

int main() {
    int E[Size][Size];
    float cost[Size][Size];
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the adjacency matrix:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> E[i][j];
            if (E[i][j] == 0) {
                cost[i][j] = INT_MAX;
            } else {
                cost[i][j] = (float)E[i][j];
            }
        }
    }
    float min_cost = prim(E, cost, n);
    cout << "Minimum cost of the spanning tree: " << min_cost << endl;
    return 0;
}
