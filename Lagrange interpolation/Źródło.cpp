#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main()
{
    int rozmiar;
    fstream czytaj;
    czytaj.open("TXT5.txt");
    czytaj >> rozmiar;
    cout << rozmiar;

    int** M = new int* [rozmiar];

    for (int i = 0; i < rozmiar; i++)
        M[i] = new int[rozmiar];
    cout << endl;

    for (int i = 0; i < rozmiar; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            czytaj >> M[i][j];
            cout << M[i][j] << " ";
        }
        cout << endl;
    }

    auto start = high_resolution_clock::now(); // Rozpoczêcie pomiaru czasu

    float argument;
    cout << "Podaj argument wielomianu dla, ktorego chesz znalezc wartosc: " << endl;
    cin >> argument;

    float wynik = 0;

    for (int i = 0; i < rozmiar; i++)
    {
        float wielomian = 1;
        for (int j = 0; j < rozmiar; j++)
        {
            if (j != i)
            {
                wielomian = wielomian * (argument - M[j][0]) / (M[i][0] - M[j][0]);
            }
        }
        wynik = wynik + M[i][1] * wielomian;
    }

    auto stop = high_resolution_clock::now(); // Zakoñczenie pomiaru czasu
    auto duration = duration_cast<milliseconds>(stop - start); // Obliczenie czasu trwania w milisekundach

    cout << "Wynik = " << wynik << endl;
    //cout << "Czas trwania algorytmu: " << duration.count() / 1000.0 << " sekund" << endl; // Wyœwietlenie czasu trwania w sekundach i milisekundach

    for (int i = 0; i < rozmiar; i++) {   // Zwolnienie miejsca w pamiêci
        delete[] M[i];
    }
    delete[] M;

    return 0;
}




//czasy pomiarowe dla przypadku testowego:
// 0.0004804 sekund
// 0.0004430 sekund
// 0.0003923 sekund
// 0.0004847 sekund
