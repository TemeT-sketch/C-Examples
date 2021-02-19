
#include<iostream> //c++ k�t�phaneleri
#include <conio.h>
#include<Windows.h>
#include <iomanip>

using namespace std;

int genislik, y�kseklik, catiY�kseklik; //degiskenler

void gotoxy(int x, int y) //odev dosyas�ndan almis oldugum fonksiyon
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
	void roof(int genislik, int catiY�kseklik,int x,int y) //catiyi cizdirmek icin kullandigim fonksiyon
	{
		for (int i = 1; i <= catiY�kseklik; i++) //gotoxy fonksiyonu yardimi ile birlikte, verilen y�kseklik ve genislik degeri ile cizdirdigim cati fonksiyonum 
		{
			for (int k = genislik; k >= i; k -= 1)
			{
				gotoxy(x + k, y + catiY�kseklik - i);
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
	char karakter = char(219); // kat icin kulladigim ASCII kodumu tan�mlad�m
public:
	void floor(int genislik, int y�kseklik,int x,int y) //kati olusturmak icin kullandigim fonksiyon
	{
		for (int i = 0; i < genislik; i++) //tavan� cizdirdigim dongu
		{
			gotoxy(x + i + 1, y + catiY�kseklik);
			cout << karakter;
		}
		for (int i = 0; i < y�kseklik - 1; i++) //sag duvar� cizdirdigim dongu
		{
			gotoxy(x + genislik, y + i + catiY�kseklik + 1);
			cout << karakter;
		}
		for (int i = 0; i < genislik; i++)		//taban� cizdirdigim dongu
		{
			gotoxy(x + genislik - i, y + y�kseklik + catiY�kseklik);
			cout << karakter;
		}
		for (int i = 0; i < y�kseklik - 1; i++)		//sol duvar� cizdirdigim dongu
		{
			gotoxy(x + 1, y - i + catiY�kseklik - 1 + y�kseklik);
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
		for (int i = 0; i < height; i++) // verilen y�kseklik ve genislik degerine gore degisebilen kapiyi cizdirdigim fonksiyon
		{
			for (int j = 0; j < width; j++)
			{
				gotoxy(x + j + genislik / 2, y + y�kseklik - i + catiY�kseklik-1);
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
		cin >> y�kseklik;
		cout << "Cati Yukseklik\t: ";
		cin >> catiY�kseklik;
		cout << "X\t: ";
		cin >> y;
		cout << "Y\t: ";
		cin >> x;
		system("cls");

		if (catiY�kseklik >= genislik / 2) // cati yuksekligini verilen genislik baz alinarak hatali cizdirmemesi icin olusturdugum if yapisi
		{
			cout << setw(80) << "Cati yuksekligi Genislik/2 degerinden fazla olamaz!" << endl;
			cout << setw(67) << "Verileri Tekrar giriniz." << endl;
			Cizdir();
		}
		else if(x<0 || y<0 || genislik <3 || y�kseklik <3 ) // degerlerimin 0 dan kucuk veya cok kucuk olmas� durumunda hata verecek else if yapisi
		{
			cout << setw(70) << "Gecersiz bir deger girdiniz!" << endl;
			cout << setw(67) << "Verileri Tekrar giriniz." << endl;
			Cizdir();
		}
		else // b�t�n istenenler dogru sekilde girildiyse evi cizdirecek kisim
		{
			cati.roof(genislik, catiY�kseklik,x,y);
			kat.floor(genislik, y�kseklik - 1,x,y);
			kapi.door(genislik / 3, (y�kseklik) / 2,x,y);
		}
	}
}home;

int main() //ana fonksiyonum
{
	home.Cizdir(); // ev sinifinda olusturdugum fonksiyona cagri
	return 0;
}