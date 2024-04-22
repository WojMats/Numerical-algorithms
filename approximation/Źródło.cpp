#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

void linear_approx(double** M, int rozmiar, double& a0, double& a1) {
    double sum_x = 0, sum_y = 0, sum_x2 = 0, sum_xy = 0;

    // Obliczanie sum potrzebnych do obliczenia wspó³czynników a0 i a1
    for (int i = 0; i < rozmiar; i++) {
        double x = M[i][0];
        double y = M[i][1];
        sum_x += x;
        sum_y += y;
        sum_x2 += x * x;
        sum_xy += x * y;
    }

    // Obliczanie wspó³czynnika a1
    a1 = (rozmiar * sum_xy - sum_x * sum_y) / (rozmiar * sum_x2 - sum_x * sum_x);

    // Obliczanie wspó³czynnika a0
    a0 = (sum_y * sum_x2 - sum_x * sum_xy) / (rozmiar * sum_x2 - sum_x * sum_x);
}

double correlation_coefficient(double** M, int rozmiar, double a0, double a1) {
    double sum_x = 0, sum_y = 0, sum_xy = 0, sum_x_squared = 0, sum_y_squared = 0;
    for (int i = 0; i < rozmiar; i++) {
        double x = M[i][0];
        double y = M[i][1];
        sum_x += x;
        sum_y += y;
        sum_xy += x * y;
        sum_x_squared += x * x;
        sum_y_squared += y * y;
    }
    double r_numerator = rozmiar * sum_xy - sum_x * sum_y;
    double r_denominator = sqrt((rozmiar * sum_x_squared - sum_x * sum_x) * (rozmiar * sum_y_squared - sum_y * sum_y));
    double r = r_numerator / r_denominator;
    return r;
}

int main() {
    int rozmiar;
    ifstream czytaj; // Zmieniamy na ifstream dla pliku tekstowego
    czytaj.open("MN3.txt");
    czytaj >> rozmiar;
    cout << rozmiar;

    double** M = new double* [rozmiar]; // Zmieniamy typ danych na double
    for (int i = 0; i < rozmiar; i++)
        M[i] = new double[2]; // Teraz przyjmujemy dwie kolumny

    cout << endl;
    for (int i = 0; i < rozmiar; i++) {
        for (int j = 0; j < 2; j++) {
            czytaj >> M[i][j];
            cout << M[i][j] << " ";
        }
        cout << endl;
    }

    double a0, a1;
    linear_approx(M, rozmiar, a0, a1);

    cout << "\nWyniki aproksymacji:\n";
    cout << "a1 = " << a1 << ", a0 = " << a0 << endl;

    double r = correlation_coefficient(M, rozmiar, a0, a1);
    cout << "Wspolczynnik korelacji: " << r << endl;

    // Zwolnij pamiêæ
    for (int i = 0; i < rozmiar; ++i) {
        delete[] M[i];
    }
    delete[] M;

    return 0;
}
