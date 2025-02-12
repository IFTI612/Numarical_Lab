#include<bits/stdc++.h>
using namespace std;
#define para cout<<endl
#define e 0.01

int d;
vector<double> coV;

// Function to evaluate the polynomial at a given x
double fun(double x) {
    double res = 0;
    int degree = coV.size() - 1;

    for (int i = 0; i < coV.size(); i++) {
        res += (coV[i] * pow(x, degree));
        degree--;
    }

    return res;
}

// Function to compute the derivative of the polynomial at a given x
double dif_fun(double x) {
    double dres = 0;
    int degree = coV.size() - 1;

    for (int i = 0; i < coV.size() - 1; i++) {
        dres += (degree * coV[i] * pow(x, degree - 1));
        degree--;
    }

    return dres;
}

// Newton-Raphson method to find a single root
double newton(double a) {
    int it = 0;
    while (fabs(fun(a)) > e) {
        double derivative = dif_fun(a);
        if (fabs(derivative) < 1e-6) { // Avoid division by near-zero derivative
            cout << "Derivative too small; method may fail." << endl;
            break;
        }
        a = a - (fun(a) / derivative);
        it++;
        cout << "Iteration " << it << ": Current root approximation = " << a << endl;
    }

    return a;
}

int main() {
    int degree;
    cout << "Enter degree of the polynomial: " << endl;
    cin >> degree;

    d = degree;

    for (int i = degree; i >= 0; i--) {
        double temp;
        cout << "Enter x^" << i << " coefficient: ";
        cin >> temp;
        coV.push_back(temp);
        para;
    }

    vector<double> roots;
    double lower_bound = -1000, upper_bound = 1000, step = 0.5;

    cout << "Finding possible roots using Newton-Raphson..." << endl;
    for (double x0 = lower_bound; x0 <= upper_bound; x0 += step) {
        double root = newton(x0);
        bool is_new_root = true;

        // Check if the root is unique (within tolerance)
        for (double found_root : roots) {
            if (fabs(found_root - root) < 0.01) {
                is_new_root = false;
                break;
            }
        }

        if (is_new_root && !isnan(root) && isfinite(root)) {
            roots.push_back(root);
        }
    }

    cout << "\nFound roots: " << endl;
    for (double root : roots) {
        cout << fixed << setprecision(8) << root << endl;
    }

    return 0;
}
