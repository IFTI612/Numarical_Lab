#include <bits/stdc++.h>
#define para cout<<endl

using namespace std;




/*
3
2 1 1
1 3 2
1 0 0
*/



// Function to perform Gauss-Jordan Elimination for matrix inversion
bool gaussJordanInverse(vector<vector<double>> &matrix, int n)
{
    vector<vector<double>> identity(n, vector<double>(n, 0));

    // Initialize identity matrix
    for (int i = 0; i < n; i++)
    {
        identity[i][i] = 1.0;
    }

    // Perform row operations to convert matrix into the identity matrix
    for (int i = 0; i < n; i++)
    {
        double pivot = matrix[i][i];

        // Check for zero pivot (singular matrix)
        if (pivot == 0)
        {
            cout << "Matrix is singular and cannot be inverted.\n";
            return false;
        }

        // Normalize the pivot row
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] /= pivot;
            identity[i][j] /= pivot;
        }

        // Make other elements in column zero
        for (int k = 0; k < n; k++)
        {
            if (k != i)
            {
                double factor = matrix[k][i];
                for (int j = 0; j < n; j++)
                {
                    matrix[k][j] -= factor * matrix[i][j];
                    identity[k][j] -= factor * identity[i][j];
                }
            }
        }
    }

    // Print the inverse matrix
    cout << "Inverse Matrix:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout  << identity[i][j] << " ";
        }
        cout << endl;
    }

    return true;
}

int main()
{
    int n;
    cout << "Enter the order of the square matrix: ";
    cin >> n;

    vector<vector<double>> matrix(n, vector<double>(n));

    cout << "Enter the matrix elements row-wise:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
        para;
    }

    gaussJordanInverse(matrix, n);

    return 0;
}

