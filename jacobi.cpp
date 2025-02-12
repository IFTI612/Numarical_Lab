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


// Function to solve system using Jacobi Method
void jacobiMethod(vector<vector<double>> &matrix, int n, int maxIterations, double tolerance)
{
    vector<double> oldX(n, 0.0), newX(n, 0.0);
    bool converged = false;

    for (int iter = 0; iter < maxIterations; iter++)
    {
        for (int i = 0; i < n; i++)
        {
            double sum = matrix[i][n];  // Start with the constant term
            for (int j = 0; j < n; j++)
            {
                if (i != j)
                {
                    sum -= matrix[i][j] * oldX[j];
                }
            }
            newX[i] = sum / matrix[i][i];
        }

        // Check for convergence
        converged = true;
        for (int i = 0; i < n; i++)
        {
            if (fabs(newX[i] - oldX[i]) > tolerance)
            {
                converged = false;
                break;
            }
        }

        oldX = newX;  // Update values for next iteration

        if (converged) break;  // Stop if converged
    }

    // Print solution
    cout << "Solution (Jacobi Method):" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "x" << i + 1 << " = " << fixed << setprecision(6) << newX[i] << endl;
    }
}

int main()
{
    int n, maxIterations = 100;
    double tolerance = 1e-6;

    cout << "Enter number of equations: ";
    cin >> n;

    vector<vector<double>> matrix(n, vector<double>(n + 1));

    cout << "Enter the augmented matrix (coefficients and constants):" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    jacobiMethod(matrix, n, maxIterations, tolerance);

    return 0;
}
