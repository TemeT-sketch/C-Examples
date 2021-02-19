#include <iostream>
using namespace std;


int num;

void fac(int n)
{
    int islem = 1;
    for (int i = 2; i <= n; i++)
    {
        islem = islem * i;
    }
    printf("%d sayýsýnýn faktoriyeli : %d", n, islem);
    cout << endl;
}

void mukemmel(int n)
{
    int toplam=0;
    for (int i = 1; i < n; i++)
    {
        if (n % i == 0)
        {
            toplam = toplam + i;
        }
    }

    if (toplam == n)
    {
        cout << "Girdiðiniz sayý mükemmel sayýdýr" << endl;
    }

    else
    {
    cout << "Girdiðiniz sayý mükemmel sayý deðildir" << endl;
    }
}

void arms(int n)
{
    int b, o, y;
    int toplam = 0;

    b = n % 10; 
    o =(n / 10)%10;
    y = n/100;

    if (b * b * b + o * o * o + y * y * y == n)
    {
        cout << "Girdiðiniz sayý armstrong sayýdýr. ";
    }
    else 
    {
        cout << "Girdiðiniz sayý Armstrong sayý deðildir. ";
    }
    
}

int arms2()
{
    int b, o, y;

    for (int i = 100; i <= 999; i++)
    {
        b = i % 10;
        o = (i / 10) % 10;
        y = i / 100;
        if (b * b * b + o * o * o + y * y * y == i)
        { 
            cout << i << endl ;
        }
    }
    return 0;
}

void HesapMakinesi(int a, int b)
{
    int toplam = a + b;
    int fark = a - b;
    int carp = a * b;
    int div = a / b;

    cout << "Toplamlarý --> \t"<< toplam  <<endl;
    cout << "Farklarý --> \t" <<fark<< endl;
    cout << "Çarpýmlarý --> \t"<<carp<< endl;
    cout << "Bölümleri --> \t" << div << endl;
}

void ArdisikSayi(int a, int b)
{
    if (abs(a - b) == 1)
    {
        cout << "Girdiðiniz sayýlar Ardýþýktýr" << endl;
    }
    else
    {
        cout << "Girdiðiniz sayýlar Ardýþýk deðildir" << endl;
    }
}

int main()
{
    setlocale(LC_ALL, "Turkish");

    cout << "Faktoriyel hesabý için 1'e basýnýz" << endl;
    cout << "Mükemmel sayý bulmak için 2'ye basýnýz" << endl;
    cout << "Armstrong sayý sorgulamak için 3'e basýnýz" << endl;
    cout << "Armstrong sayý listesi için 4'e basýnýz" << endl;
    cout << "Hesap Makinesi için 5'e basýnýz" << endl;
    cout << "Ardýþýk sayý sorgusu için için 6'ya basýnýz" << endl;
    cout << "Yapmak istediðiniz iþlemi seçiniz : ";
    
    int sonuc;
    cin>> sonuc;

    
        if (sonuc ==1)
        {
            cout << "Faktoriyel hesabý için sayý giriniz: ";
            cin >> num;
            fac(num);
        }
        else if (sonuc == 2)
        {
            cout << "Mükemmel sayý sorgusu için sayý giriniz: ";
            cin >> num;
            mukemmel(num);
        }
        else if (sonuc == 3)
        {
            cout << "Üç basamaklý herhangi bir sayý giriniz: ";
            cin >> num;
            arms(num);
        }
        else if (sonuc == 4)
        {
            cout << "Üç basamaklý armstrong sayýlarý : \n";
            arms2();
        }
        else if (sonuc == 5)
        {
            int sayi1, sayi2;
            cout << "Ýþlem yapmak istediðiniz 1.sayýyý giriniz: ";
            cin >> sayi1 ;
            cout << "Ýþlem yapmak istediðiniz 2.sayýyý giriniz: ";
            cin >> sayi2;
            HesapMakinesi(sayi1,sayi2);
        }
        else if (sonuc == 6)
        {
            int sayi1, sayi2;
            cout << "1.sayýyý giriniz: ";
            cin >> sayi1;
            cout << "2.sayýyý giriniz: ";
            cin >> sayi2;
            ArdisikSayi(sayi1, sayi2);
        }
        return 0;
}
