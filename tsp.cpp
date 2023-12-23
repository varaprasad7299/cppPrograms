#include <iostream>
#include <vector>
#include <cstring>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

int tsp(int start, vector<int>& vertices, vector<vector<int>>& distances, vector<vector<int>>& memo) {
    if (memo[start][vertices.size()] != -1) {
        return memo[start][vertices.size()];
    }
    if (vertices.empty()) {
        return distances[start][0];
    }
    int min_distance = INF;
    for (int i = 0; i < vertices.size(); i++) {
        int vertex = vertices[i];
        vector<int> new_vertices;
        for (int j = 0; j < vertices.size(); j++) {
            if (j != i) {
                new_vertices.push_back(vertices[j]);
            }
        }
        int new_distance = distances[start][vertex] + tsp(vertex, new_vertices, distances, memo);
        if (new_distance < min_distance) {
            min_distance = new_distance;
        }
    }
    memo[start][vertices.size()] = min_distance;
    return min_distance;
}

int main() {
    int n;
    cout<<"enter the no of vertices : ";
    cin >> n;
    cout<<"enter the adjacency matrix"<<endl;
    vector<vector<int>> distances(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> distances[i][j];
        }
    }
    vector<int> vertices;
    for (int i = 1; i < n; i++) {
        vertices.push_back(i);
    }
    vector<vector<int>> memo(n, vector<int>(1 << n, -1));
    cout<<endl<<"cost is : ";
    cout << tsp(0, vertices, distances, memo) << endl;
    return 0;
}

