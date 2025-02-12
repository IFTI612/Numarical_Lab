#include<bits/stdc++.h>
using namespace std;
#define para cout<<endl
#define e 0.00000001



/*
5
1
0
0
0
-5
3
-10
10
*/


vector<double> coV;

// Function to evaluate the polynomial at a given x
double fun(double x)
{
    double res = 0;
    int degree = coV.size() - 1;

    for (int i = 0; i < coV.size(); i++)
    {
        res += (coV[i] * pow(x, degree));
        degree--;
    }

    return res;
}

// Synthetic division to reduce the polynomial degree and find roots
bool synthetic_division(double root)
{
    int n = coV.size();
    vector<double> new_coeff(n);
    new_coeff[0] = coV[0];

    for (int i = 1; i < n; i++)
    {
        new_coeff[i] = new_coeff[i - 1] * root + coV[i];
    }

    if (fabs(new_coeff[n - 1]) < e)   // Check if the remainder is approximately zero
    {
        coV = vector<double>(new_coeff.begin(), new_coeff.end() - 1); // Update coefficients
        return true;
    }

    return false;
}

// Bisection method implementation
double bisc(double a, double b)
{
    if (fun(a) * fun(b) >= 0)
    {
        cout << "Incorrect value" << endl;
        return 0.0;
    }
    double c = a;
    int it = 0;

    while (fabs((b - a) / a) > e)   // Stopping criterion for relative tolerance
    {
        c = (a + b) / 2;

        if (fun(c) == 0) break;
        else if (fun(a) * fun(c) < 0) b = c;
        else a = c;

        it++;
        cout << "Change of a and b: " << a << "   " << b << "     " << b - a << endl;
        cout << it << " iteration assumption root " << c << endl;
        cout << endl;
    }

    return c;
}

int main()
{
    int degree;
    cout << "Input degree: ";
    para;
    cin >> degree;

    for (int i = degree; i >= 0; i--)
    {
        double temp;
        cout << "Enter x^" << i << " coefficient: ";
        cin >> temp;
        coV.push_back(temp);
        para;
    }

    vector<double> roots;
    double lower_bound = -1000, upper_bound = 1000, step = 0.5;

    cout << "Finding possible root intervals using synthetic division and bisection..." << endl;
    for (double x0 = lower_bound; x0 <= upper_bound; x0 += step)
    {
        double x1 = x0 + step;
        if (fun(x0) * fun(x1) < 0)   // Root exists in the interval
        {
            double root = bisc(x0, x1);
            roots.push_back(root);
            if (synthetic_division(root))
            {
                cout << "Synthetic division successful. Reduced polynomial degree." << endl;
            }
        }
    }

    cout << "\nFound roots: " << endl;
    for (double root : roots)
    {
        cout << fixed << setprecision(8) << root << endl;
    }

    return 0;
}
