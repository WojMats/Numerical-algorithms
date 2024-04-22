#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int rozmiar;
    fstream czytaj;
    czytaj.open("MN2.txt");
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

    float x;
    cout << "Podaj x, dla ktorego chcesz obliczyc wartosc:";
    cin >> x;

    float Wn = M[0][1];

   // cout << "bk w " << 0 << " = " << M[0][1] << endl;  //bk w 0 = -1

    float bkpk = 0;

    for (int k = 1; k < rozmiar; k++)
    {
        float pk = 1;

        for (int i = 0; i < k; i++)
        {
            pk = pk * (x - M[i][0]);
        }

        float bk = 0;
        for (int i = 0; i <= k; i++)
        {
            float denominator = 1;
            for (int j = 0; j <= k; j++)
            {
                if (j == i) continue;
                denominator = denominator * (M[i][0] - M[j][0]);
            }
            bk = bk + M[i][1] / denominator;
        }
       // cout << "bk w " << k << " = " << bk << endl;
        bkpk += pk * bk;
    }
    Wn += bkpk;

    cout << "wynik: " << Wn;
    return 0;
}