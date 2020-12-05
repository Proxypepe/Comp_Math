#include <iostream>
#include <stdlib.h>
#include <cmath>

using std::cout;
using std::cin;

double F(double x, double y, double K) {
    return pow(x, 2) + ((K - 1) / 2) * y;
}
double y_point(double x)
{
    return 0.75 * exp(-2 * x) + 0.5 * pow(x, 2) - 0.5 * x + 0.25;
}

void Eulers_method(double K1, double L1)
{
    cout << "\nEulers's method \n";
    //cout << "X [i+1] = X [i] + h  ;     Y [i+1] = Y [i] + h * f(X[i]; Y[i])\n";
    double a = 0; double b = 2; double h = 0.5;
    double K; double L;
    K = K1; L = L1;
    int n = (a + b) / h;
    double* x = new double[n + 1];
    double* y = new double[n + 1];
    x[0] = a; y[0] = L;
    cout << "x0 = " << x[0] << " y0 = " << y[0];
    for (int i = 1; i <= n; i++) {
        cout << "\nx" << i << " = " << x[i - 1] << " + " <<  h;
        x[i] = a + i * h;
        cout << " = " << x[i];
        cout << "\ny" << i << " = " << y[i - 1] << " + " << h << " * ( " << pow(x[i - 1], 2) << " + " << y[i - 1] << " ) = ";
        y[i] = y[i - 1] + h * F(x[i - 1], y[i - 1], K);
        cout << y[i];
    }
    delete[] x;
    delete[] y;
}

void Trapezium_method(double K1, double L1)
{
    cout << "\nTrapezium method\n";

    double a = 0; double b = 2; double h = 0.5;
    double K; double L;
    K = K1; L = L1;
    int n = (a + b) / h;
    double* x = new double[n + 1];
    double* y = new double[n + 1];
    x[0] = a; y[0] = L;
    cout << "x0 = " << x[0] << " y0 = " << y[0];
    for (int i = 1; i <= n; i++) {
        cout << "\nx" << i << " = " << x[i - 1] << " + " << h;
        x[i] = a + i * h;
        cout << " = " << x[i];
        cout << "\ny" << i << " = " << y[i - i] << " + " << h / 2 << " * ( " << pow(x[i - 1], 2) << " + " << y[i - 1] << " + " << pow(x[i], 2) << " + ( " << y[i - 1] << " + " << h << " * ( " << pow(x[i - 1], 2) << " + " << y[i - 1] << " )) = \n";
        cout <<  y[i - i] << " + " << h / 2 << " * ( " << pow(x[i - 1], 2) +  y[i - 1] +  pow(x[i], 2) << " + ( " << y[i - 1] << " + " << h << " * " << pow(x[i - 1], 2) +  y[i - 1] << " )) = ";
        y[i] = y[i - 1] + h / 2 * (F(x[i - 1], y[i - 1], K) + F(x[i], y[i - 1] + h * F(x[i - 1], y[i - 1], K), K));
        cout << y[i]; 
    }
    delete[] x;
    delete[] y;
}

void Runge_Kutta_method(double K1,  double L1)
{
    cout << "\nRunge-Kutta method\n";
    double a = 0; double b = 2; double h = 0.5;
    double K, L, k1, k2, k3, k4, g;
    K = K1; L = L1;
    int n = (a + b) / h;
    g = 0.083;
    double* x = new double[n + 1];
    double* y = new double[n + 1];
    x[0] = a; y[0] = L;
    cout << "x0 = " << x[0] << " y0 = " << y[0];
    for (int i = 1; i <= n; i++) {
        cout << "\nx" << i << " = " << x[i - 1] << " + " << h;
        x[i] = a + i * h;
        cout << " = " << x[i];
        k1 = round(F(x[i - 1], y[i - 1], K) * 1000)/ 1000;
        cout << "\nk1 = " << k1;
        k2 = round(F(x[i - 1] + (h / 2), y[i - 1] + ((h * k1) / 2), K) * 1000) / 1000;
        cout << "\nk2 = " << k2;
        k3 = round(F(x[i - 1] + (h / 2), y[i - 1] + ((h * k2) / 2), K) * 1000) / 1000;
        cout << "\nk3 = " << k3;
        k4 = round(F(x[i - 1] + h, y[0] + h * k3, K) * 1000) / 1000;
        cout << "\nk4 = " << k4;
        cout <<"\ny" << i <<" = " << y[i - 1] << " + " << (h / 6) << " * ( " << k1 << " + " << 2 * k2 << " + " << 2 *k3 << " + " << k4 << " ) = ";
        y[i] = std::ceil((y[i - 1] + g * (k1 + 2 * k2 + 2 * k3 + k4)) * 1000) / 1000;
        cout << y[i];
    }
    delete[] x;
    delete[] y;
}

void accurate(double K1, double L1)
{
    double a = 0; double b = 1; double h = 0.1;
    double K, L;
    K = K1; L = L1;
    int n = (a + b) / h;
    double* x = new double[n + 1];
    x[0] = a;
    cout << "\ny point 0" << " = " << y_point(x[0]);
    for (int i = 1; i <= n; i++)
    {
        x[i] = a + i * h;
        cout <<"x = " << x[i];
        cout << "\ny point " << i << " = " << y_point(x[i]);
    }
    delete[] x;
}


int main() {

    double K; double L;
    cout << "K = ";
    cin >> K;
    cout << "L = ";
    cin >> L;
    Eulers_method(K, L);
    Trapezium_method(K, L);
    Runge_Kutta_method(K, L);
    //accurate(K, L);

    return 0;
}