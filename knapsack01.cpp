#include <iostream>
#include <vector>

using namespace std;

int knapsack01(int W, int N, vector<int>& v, vector<int>& w) {
    int DP[N + 1][W + 1];

    for (int i = 0; i < N + 1; i++) {
        DP[i][0] = 0;
    }

    for (int i = 0; i < W + 1; i++) {
        DP[0][i] = 0;
    }

    for (int i = 1; i < N + 1; i++) {
        for (int j = 1; j < W + 1; j++) {
            if (w[i - 1] <= j) {
                DP[i][j] = max(v[i - 1] + DP[i - 1][j - w[i - 1]], DP[i - 1][j]);
            }
            else {
                DP[i][j] = DP[i - 1][j];
            }
        }
    }

    return DP[N][W];
}

int main() {
    int N, W;
    cout << "Enter the number of items: ";
    cin >> N;
    cout << "Enter the capacity of the knapsack: ";
    cin >> W;

    vector<int> v(N);
    vector<int> w(N);

    cout << "Enter the values of items: ";
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    cout << "Enter the weights of items: ";
    for (int i = 0; i < N; i++) {
        cin >> w[i];
    }

    int max_value = knapsack01(W, N, v, w);
    cout << "Maximum value that can be obtained: " << max_value << endl;

    return 0;
}

