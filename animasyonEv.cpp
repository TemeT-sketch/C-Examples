
#include<iostream> //c++ kütüphaneleri
#include <conio.h>
#include<Windows.h>
#include <iomanip>

using namespace std;

int genislik, yükseklik, catiYükseklik; //degiskenler

void gotoxy(int x, int y) //odev dosyasýndan almis oldugum fonksiyon
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

class Cati // cati sinifim
{
private:
	char karakter = '*';
public:
	void roof(int genislik, int catiYükseklik,int x,int y) //catiyi cizdirmek icin kullandigim fonksiyon
	{
		for (int i = 1; i <= catiYükseklik; i++) //gotoxy fonksiyonu yardimi ile birlikte, verilen yükseklik ve genislik degeri ile cizdirdigim cati fonksiyonum 
		{
			for (int k = genislik; k >= i; k -= 1)
			{
				gotoxy(x + k, y + catiYükseklik - i);
				cout << "*";
			}
			genislik -= 1;
		}
		cin.get();
	}
}cati;

class Kat //kat sinifim
{
private:
	char karakter = char(219); // kat icin kulladigim ASCII kodumu tanýmladým
public:
	void floor(int genislik, int yükseklik,int x,int y) //kati olusturmak icin kullandigim fonksiyon
	{
		for (int i = 0; i < genislik; i++) //tavaný cizdirdigim dongu
		{
			gotoxy(x + i + 1, y + catiYükseklik);
			cout << karakter;
		}
		for (int i = 0; i < yükseklik - 1; i++) //sag duvarý cizdirdigim dongu
		{
			gotoxy(x + genislik, y + i + catiYükseklik + 1);
			cout << karakter;
		}
		for (int i = 0; i < genislik; i++)		//tabaný cizdirdigim dongu
		{
			gotoxy(x + genislik - i, y + yükseklik + catiYükseklik);
			cout << karakter;
		}
		for (int i = 0; i < yükseklik - 1; i++)		//sol duvarý cizdirdigim dongu
		{
			gotoxy(x + 1, y - i + catiYükseklik - 1 + yükseklik);
			cout << karakter;
		}
	}
}kat;

class Kapi  //kapi sinifim
{
private:
	char karakter = '#';
public:
	void door(int width, int height,int x,int y) //kapiyi olusturmak icin kullandigim fonksiyon
	{
		for (int i = 0; i < height; i++) // verilen yükseklik ve genislik degerine gore degisebilen kapiyi cizdirdigim fonksiyon
		{
			for (int j = 0; j < width; j++)
			{
				gotoxy(x + j + genislik / 2, y + yükseklik - i + catiYükseklik-1);
				cout << karakter;
			}
			cout << endl;
		}
		cin.get();
	}
}kapi;

class Ev //ev sinifim
{
private:
	int x, y; //evin pozisyonu icin degiskenlerim
public:
	void Cizdir() // kullanicidan aldigim bilgiler dogrultusunda cizim islemini yapacak fonksiyonum
	{
		cout << "Genislik\t: ";
		cin >> genislik;
		cout << "Yukseklik\t: ";
		cin >> yükseklik;
		cout << "Cati Yukseklik\t: ";
		cin >> catiYükseklik;
		cout << "X\t: ";
		cin >> y;
		cout << "Y\t: ";
		cin >> x;
		system("cls");

		if (catiYükseklik >= genislik / 2) // cati yuksekligini verilen genislik baz alinarak hatali cizdirmemesi icin olusturdugum if yapisi
		{
			cout << setw(80) << "Cati yuksekligi Genislik/2 degerinden fazla olamaz!" << endl;
			cout << setw(67) << "Verileri Tekrar giriniz." << endl;
			Cizdir();
		}
		else if(x<0 || y<0 || genislik <3 || yükseklik <3 ) // degerlerimin 0 dan kucuk veya cok kucuk olmasý durumunda hata verecek else if yapisi
		{
			cout << setw(70) << "Gecersiz bir deger girdiniz!" << endl;
			cout << setw(67) << "Verileri Tekrar giriniz." << endl;
			Cizdir();
		}
		else // bütün istenenler dogru sekilde girildiyse evi cizdirecek kisim
		{
			cati.roof(genislik, catiYükseklik,x,y);
			kat.floor(genislik, yükseklik - 1,x,y);
			kapi.door(genislik / 3, (yükseklik) / 2,x,y);
		}
	}
}home;

int main() //ana fonksiyonum
{
	home.Cizdir(); // ev sinifinda olusturdugum fonksiyona cagri
	return 0;
}