#include <bits/stdc++.h>
#define para cout<<endl

using namespace std;


/*
3
2 1 -1 8
-3 -1 2 -11
-2 1 2 -3
*/


// Function to perform Gauss-Jordan Elimination
void gaussJordan(vector<vector<double>> &matrix, int n)
{
    for (int i = 0; i < n; i++)
    {
        // Make the pivot element 1
        double pivot = matrix[i][i];
        for (int j = 0; j <= n; j++)
        {
            matrix[i][j] /= pivot;
        }

        // Make other elements in column zero
        for (int k = 0; k < n; k++)
        {
            if (k != i)
            {
                double factor = matrix[k][i];
                for (int j = 0; j <= n; j++)
                {
                    matrix[k][j] -= factor * matrix[i][j];
                }
            }
        }
    }

    // Print Solution
    cout << "Solution:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "x" << i + 1 << " = " << fixed << setprecision(4) << matrix[i][n] << endl;
    }
}








int main()
{
    int n;
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
        para;
    }

    gaussJordan(matrix, n);

    return 0;
}

