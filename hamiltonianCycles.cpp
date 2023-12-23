#include <iostream>
#include <vector>

using namespace std;
void NextValue(int);
int n;
vector<int> x;
vector<vector<int>> g;

void Hamiltonian(int k) {
    while (true) {
        // Find the next value of x[k]
        NextValue(k);

        if (x[k] == 0) {
            return; // Backtrack
        }

        if (k == n - 1) {
            // We have found a Hamiltonian cycle

            for (int i = 0; i < n; i++) {
                cout << x[i] << " ";
            }
            cout << endl;
        } else {
            Hamiltonian(k + 1); // Continue the search
        }
    }
}

void NextValue(int k) {
    while (true) {
        x[k] = (x[k] + 1) % n;

        if (x[k] == 0) {
            return; // Backtrack
        }

        // Check if there is an edge between x[k-1] and x[k] in g
        if (g[x[k-1]][x[k]] != 0) {
            // Check if x[k] is already in the path x[0:k-1]
            bool found = false;
            for (int j = 0; j < k; j++) {
                if (x[j] == x[k]) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                return; // Found a valid value for x[k]
            }
        }
    }
}

int main() {
    // Take input for n and g
    cout<<"enter the n value : ";
    cin >> n;
    x.resize(n);
    g.resize(n, vector<int>(n));
    cout<<"enter the graph"<<endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> g[i][j];
        }
    }

    // Initialize x to a list of n zeros
    fill(x.begin(), x.end(), 0);

    // Start the search from position 1
    cout<<endl<<"the hamiltonian cycles are : "<<endl;
    Hamiltonian(1);

    return 0;
}
