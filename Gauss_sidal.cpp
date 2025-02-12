#include <bits/stdc++.h>
#define para cout<<endl

using namespace std;

//gauss elimination......

/*
3
2 1 -1 8
-3 -1 2 -11
-2 1 2 -3
*/


// Function to solve system using Gauss-Seidel Method
void gaussSeidelMethod(vector<vector<double>> &matrix, int n, int maxIterations, double tolerance) {
    vector<double> x(n, 0.0);
    bool converged = false;

    for (int iter = 0; iter < maxIterations; iter++) {
        converged = true;
        for (int i = 0; i < n; i++) {
            double sum = matrix[i][n];  // Start with the constant term
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    sum -= matrix[i][j] * x[j];
                }
            }
            double newValue = sum / matrix[i][i];

            if (fabs(newValue - x[i]) > tolerance) {
                converged = false;
            }

            x[i] = newValue;  // Update value immediately
        }

        if (converged) break;  // Stop if converged
    }

    // Print solution
    cout << "Solution (Gauss-Seidel Method):" << endl;
    for (int i = 0; i < n; i++) {
        cout << "x" << i + 1 << " = " << fixed << setprecision(6) << x[i] << endl;
    }
}

int main() {
    int n, maxIterations = 100;
    double tolerance = 1e-6;

    cout << "Enter number of equations: ";
    cin >> n;

    vector<vector<double>> matrix(n, vector<double>(n + 1));

    cout << "Enter the augmented matrix (coefficients and constants):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            cin >> matrix[i][j];
        }
    }

    gaussSeidelMethod(matrix, n, maxIterations, tolerance);

    return 0;
}

