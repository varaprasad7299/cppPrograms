#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of keys: ";
    cin >> n;

    int p[n+1], q[n+1];
    cout << "Enter the probabilities for " << n << " keys:" << endl;
    for(int i=1; i<=n; i++)
        cin >> p[i];
    cout << "Enter the dummy probabilities for " << n+1 << " keys:" << endl;
    for(int i=0; i<=n; i++)
        cin >> q[i];

    int c[n+1][n+1] = {0}, w[n+1][n+1] = {0}, r[n+1][n+1] = {0};
    for(int i=0; i<n; i++) {
        // Initialization of w, c, and r
        w[i][i] = q[i];
        r[i][i] = 0;
        c[i][i] = 0;

        // Consider one-node trees
        w[i][i+1] = q[i] + p[i+1] + q[i+1];
        r[i][i+1] = i+1;
        c[i][i+1] = w[i][i+1];
    }

    // Consider trees of size 2, 3, ..., n nodes
    for(int m=2; m<=n; m++) {
        for(int i=0; i<=n-m; i++) {
            int j = i + m;
            w[i][j] = p[j] + q[j] + w[i][j-1];
            int minimum = 9999;
            for(int k=i+1; k<=j; k++) {
                if(c[i][k-1] + c[k][j] < minimum) {
                    minimum = c[i][k-1] + c[k][j];
                    r[i][j] = k;
                }
            }
            c[i][j] = w[i][j] + minimum;
        }
    }

    // Output the weight, cost, and root tables
    for(int i=0; i<=n; i++) {
        for(int j=i; j<=n; j++)
            cout << "w[" << i << "][" << j << "] = " << w[i][j] << " | ";
        cout << endl;
        for(int j=i; j<=n; j++)
            cout << "c[" << i << "][" << j << "] = " << c[i][j] << " | ";
        cout << endl;
        for(int j=i; j<=n; j++)
            cout << "r[" << i << "][" << j << "] = " << r[i][j] << " | ";
        cout << endl;
        for(int j=0; j<(n-i+1)*15; j++)
            cout << "-";
        cout << endl;
    }

    return 0;
}
