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



// Function to perform Gauss Elimination
void gaussElimination(vector<vector<double>> &matrix, int n)
{
    // Forward Elimination
    for (int i = 0; i < n; i++)
    {
        // Partial Pivoting
        for (int k = i + 1; k < n; k++)
        {
            if (abs(matrix[i][i]) < abs(matrix[k][i]))
            {
                swap(matrix[i], matrix[k]);
            }
        }

        // Make the diagonal element 1 and eliminate below it
        for (int k = i + 1; k < n; k++)
        {
            double factor = matrix[k][i] / matrix[i][i];
            for (int j = i; j <= n; j++)
            {
                matrix[k][j] -= factor * matrix[i][j];
            }
        }
    }

    // Back Substitution
    vector<double> solution(n);
    for (int i = n - 1; i >= 0; i--)
    {
        solution[i] = matrix[i][n];
        for (int j = i + 1; j < n; j++)
        {
            solution[i] -= matrix[i][j] * solution[j];
        }
        solution[i] /= matrix[i][i];
    }

    // Print Solution
    cout << "Solution:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "x" << i + 1 << " = " << fixed << setprecision(4) << solution[i] << endl;
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

    gaussElimination(matrix, n);

    return 0;
}

