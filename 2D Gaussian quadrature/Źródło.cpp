#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

void kwadraturyGaussa() {
    double M[4][2]; // Przeniesione zmiennych do cia³a funkcji

    // Odczyt wspó³rzêdnych z pliku
    ifstream read("MN5.txt");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 2; j++) {
            read >> M[i][j];
            cout << M[i][j] << " ";
        }
        cout << endl;
    }

    double punkt[2] = { -0.5773502692, 0.5773502692 };
    double waga = 1.0;
    double poch_ksi[2][4];
    double poch_ni[2][4];

    // Obliczenie pochodnych
    for (int j = 0; j <= 1; j++) {
        poch_ksi[j][0] = -0.25 * (1.0 - punkt[j]);
        poch_ksi[j][1] = 0.25 * (1.0 - punkt[j]);
        poch_ksi[j][2] = 0.25 * (1.0 + punkt[j]);
        poch_ksi[j][3] = -0.25 * (1.0 + punkt[j]);
        poch_ni[j][0] = -0.25 * (1.0 - punkt[j]);
        poch_ni[j][1] = -0.25 * (1.0 + punkt[j]);
        poch_ni[j][2] = 0.25 * (1.0 + punkt[j]);
        poch_ni[j][3] = 0.25 * (1.0 - punkt[j]);
    }

    double dxdKsi, dydKsi, dxdNi, dydNi;
    double fun_detj[2][2];
    double powierzchnia = 0;

    // Obliczenie powierzchni
    for (int i = 0; i <= 1; i++) {
        dxdKsi = poch_ksi[i][0] * M[0][0] + poch_ksi[i][1] * M[1][0] + poch_ksi[i][2] * M[2][0] + poch_ksi[i][3] * M[3][0];
        dydKsi = poch_ksi[i][0] * M[0][1] + poch_ksi[i][1] * M[1][1] + poch_ksi[i][2] * M[2][1] + poch_ksi[i][3] * M[3][1];
        dxdNi = poch_ni[i][0] * M[0][0] + poch_ni[i][1] * M[1][0] + poch_ni[i][2] * M[2][0] + poch_ni[i][3] * M[3][0];
        dydNi = poch_ni[i][0] * M[0][1] + poch_ni[i][1] * M[1][1] + poch_ni[i][2] * M[2][1] + poch_ni[i][3] * M[3][1];
        fun_detj[i][0] = dxdKsi * dydNi - dxdNi * dydKsi;
        fun_detj[i][1] = dxdKsi * dydNi - dxdNi * dydKsi;
    }

    for (int i = 0; i <= 1; i++) {
        powierzchnia += abs(fun_detj[i][0] * waga * waga) + abs(fun_detj[i][1] * waga * waga);
    }
    cout << "Powierzchnia: " << powierzchnia << endl;
}

int main() {
    kwadraturyGaussa(); 
    return 0; 
}
