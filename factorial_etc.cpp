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
    printf("%d say�s�n�n faktoriyeli : %d", n, islem);
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
        cout << "Girdi�iniz say� m�kemmel say�d�r" << endl;
    }

    else
    {
    cout << "Girdi�iniz say� m�kemmel say� de�ildir" << endl;
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
        cout << "Girdi�iniz say� armstrong say�d�r. ";
    }
    else 
    {
        cout << "Girdi�iniz say� Armstrong say� de�ildir. ";
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

    cout << "Toplamlar� --> \t"<< toplam  <<endl;
    cout << "Farklar� --> \t" <<fark<< endl;
    cout << "�arp�mlar� --> \t"<<carp<< endl;
    cout << "B�l�mleri --> \t" << div << endl;
}

void ArdisikSayi(int a, int b)
{
    if (abs(a - b) == 1)
    {
        cout << "Girdi�iniz say�lar Ard���kt�r" << endl;
    }
    else
    {
        cout << "Girdi�iniz say�lar Ard���k de�ildir" << endl;
    }
}

int main()
{
    setlocale(LC_ALL, "Turkish");

    cout << "Faktoriyel hesab� i�in 1'e bas�n�z" << endl;
    cout << "M�kemmel say� bulmak i�in 2'ye bas�n�z" << endl;
    cout << "Armstrong say� sorgulamak i�in 3'e bas�n�z" << endl;
    cout << "Armstrong say� listesi i�in 4'e bas�n�z" << endl;
    cout << "Hesap Makinesi i�in 5'e bas�n�z" << endl;
    cout << "Ard���k say� sorgusu i�in i�in 6'ya bas�n�z" << endl;
    cout << "Yapmak istedi�iniz i�lemi se�iniz : ";
    
    int sonuc;
    cin>> sonuc;

    
        if (sonuc ==1)
        {
            cout << "Faktoriyel hesab� i�in say� giriniz: ";
            cin >> num;
            fac(num);
        }
        else if (sonuc == 2)
        {
            cout << "M�kemmel say� sorgusu i�in say� giriniz: ";
            cin >> num;
            mukemmel(num);
        }
        else if (sonuc == 3)
        {
            cout << "�� basamakl� herhangi bir say� giriniz: ";
            cin >> num;
            arms(num);
        }
        else if (sonuc == 4)
        {
            cout << "�� basamakl� armstrong say�lar� : \n";
            arms2();
        }
        else if (sonuc == 5)
        {
            int sayi1, sayi2;
            cout << "��lem yapmak istedi�iniz 1.say�y� giriniz: ";
            cin >> sayi1 ;
            cout << "��lem yapmak istedi�iniz 2.say�y� giriniz: ";
            cin >> sayi2;
            HesapMakinesi(sayi1,sayi2);
        }
        else if (sonuc == 6)
        {
            int sayi1, sayi2;
            cout << "1.say�y� giriniz: ";
            cin >> sayi1;
            cout << "2.say�y� giriniz: ";
            cin >> sayi2;
            ArdisikSayi(sayi1, sayi2);
        }
        return 0;
}
