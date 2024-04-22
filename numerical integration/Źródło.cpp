#include <iostream>
#include <cmath>
#include <random>
using namespace std;

// Funkcja obliczaj�ca warto�� funkcji dla danego x
double funkcja(double x) {
    return sin(x);
}



// Funkcja wykonuj�ca ca�kowanie numeryczne metod� prostok�t�w
double calkowanie_prostokatow(double xp, double xk, int n) {
    double dx = (xk - xp) / n;
    double suma = 0;

    for (int i = 1; i <= n; ++i) {   
        suma += funkcja(xp + i * dx);
    }

    return dx * suma;
}

double calkowanie_trapezu(double xp, double xk, int n) {
    double dx = (xk - xp) / n;
    double suma = 0;
    xk = xp + dx;
    for (int i = 0; i < n; i++) { 
       
        suma += (funkcja(xp) + funkcja(xk))/2;
        xp = xp + dx;
        xk = xk + dx;

    }

    return dx * suma;
}
double calkowanie_simpsona(double xp, double xk, int n) {
    double dx = (xk - xp) / n;
    double suma = funkcja(xp) + funkcja(xk);

    for (int i = 1; i < n; i++) {
        double x = xp + i * dx; // Warto�� x w punkcie �rodkowym podprzedzia�u
        if (i % 2 == 0) {
            suma += 2 * funkcja(x); // Warto�� funkcji dla punkt�w parzystych
        }
        else {
            suma += 4 * funkcja(x); // Warto�� funkcji dla punkt�w nieparzystych
        }
    }

    return (dx / 3) * suma; // Obliczenie ca�ki metod� Simpsona
}

double calkowanie_monte_carlo(double xp, double xk, int n) {
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(xp, xk);

    double suma = 0;
    for (int i = 0; i < n; ++i) {
        double x = dis(gen);
        suma += funkcja(x);
    }

    return (xk - xp) * suma / n;
}

int main() {
    // Wczytanie danych wej�ciowych
    double xp, xk;
    int n;
    /*cout << "Podaj poczatek przedzialu (xp): ";
    cin >> xp;
    cout << "Podaj koniec przedzialu (xk): ";
    cin >> xk;
    cout << "Podaj liczbe prostokatow (n): ";
    cin >> n;*/

 
    double wynik = calkowanie_prostokatow(0, 2.356, 400);
    cout << "Przyblizona wartosc calki (metoda prostokatow): " << wynik << endl;

    double wynik1= calkowanie_trapezu(0, 2.356, 400);
    cout << "Przyblizona wartosc calki (metoda trapezow): " << wynik1 << endl;

    double wynik_simpsona = calkowanie_simpsona(0, 2.356, 400);
    cout << "Przyblizona wartosc calki (metoda Simpsona): " << wynik_simpsona << endl;

    double wynik_monte_carlo = calkowanie_monte_carlo(0, 2.356, 400);
    cout << "Przyblizona wartosc calki (metoda Monte Carlo): " << wynik_monte_carlo << endl;

    return 0;
}
