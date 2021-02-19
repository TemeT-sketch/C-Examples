#include <iostream>
using namespace std;

void Matris()
{
    int matris[5];
    cout << "1-9 aras�nda say�lar giriniz => " << endl;
    for (int i = 0; i < 5; i++)
    {
        cin >> matris[i];
    }
    cout << "Herhangi bir karakter giriniz : " ;
    char sign;
    cin >> sign;
    cout << "�ndex Numaras�    Dizi De�eri" << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << "\t" << i << "\t" << "\t" << matris[i] << "\t" ;
        for (int j = 0; j <matris[i] ; j++)
        {
            cout << sign << " ";
        }
        cout << endl;
    }
}

void DiziYaratma()
{
    int dizi1[4], dizi2[4];
    double dizi3[4];
    cout << "Birinci dizinin elemanlar�n� giriniz: " << endl;

    for (int i = 0; i < 5; i++)
    {
        cin >> dizi1[i];
    }

    cout << "�kinci dizinin elemanlar�n� giriniz: " << endl;

    for (int i = 0; i < 5; i++)
    {
        cin >> dizi2[i];
    }

    for (int i = 0; i < 5; i++)
    {
        dizi3[i] = (double)(dizi1[i] * dizi2[i]) / (dizi1[i] + dizi2[i]);
    }
    cout << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << dizi3[i] << " ";
    }
}

int main()
{
    setlocale(LC_ALL, "Turkish");
    //DiziYaratma();
    Matris();

    return 0;
}
