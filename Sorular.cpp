#include <iostream>
#include <cmath>
using namespace std;

void Hipoten�s(int a, int b);
void S�ralama();
void fibonacci(int n);
void mod(int n);
void tersPiramit(int n);
void ebob(int a,int b);
void ekok(int a, int b);

int main()
{
	setlocale(LC_ALL, "Turkish");
	cout << "Yapmak istedi�iniz i�lemi se�iniz. " << endl;;
	cout << "Dik ��genin Hipoten�s�n� hesaplamak i�in 1'e bas�n�z. " << endl;
	cout << "1-10 say�lar� yazd�rmak i�in 2'e bas�n�z. " << endl;
	cout << "Verilen say�n�n 0-100 aras�nda katlar�n� bulan program i�in 3'e bas�n�z. " << endl;
	cout << "Fibonacci serisini yazd�rmak i�in 4'e bas�n�z. " << endl;
	cout << "Ters Piramit olu�turmak i�in 5'e bas�n�z. " << endl;
	cout << "Ebob hesab� i�in 6'ya bas�n�z. " << endl;
	cout << "Ekok hesab� i�in 7'ye bas�n�z. " << endl;

	int num;
	cin >> num;

	if (num == 1)
	{
		int num1, num2;
		cout << "1.kenar� giriniz : " ;
		cin >> num1;
		cout << "2.kenar� giriniz : " ;
		cin >> num2;
		Hipoten�s(num1, num2);
	}

	else if (num == 2)
	{
		S�ralama();
	}

	else if (num == 3)
	{
		int a;
		cout << "Hangi say�n�n katlar�n� istiyorsunuz? "; 
		cin >> a;
		mod(a);
	}

	else if (num == 4)
	{
		int a;
		cout << "Ka��nc� elemana kadar fibonacci serisini istiyorsunuz? ";
		cin >> a;
		fibonacci(a);
	}

	else if (num == 5)
	{
		int a;
		cout << "Ne kadar b�y�kl�kte bir piramit istiyorsunuz? ";
		cin >> a;
		tersPiramit(a);
	}
	
	else if (num == 6)
	{
		int a,b;
		cout << "Ebob hesab� i�in 1.say�y� giriniz. ";
		cin >> a;
		cout << "Ebob hesab� i�in 2.say�y� giriniz. ";
		cin >> b;
		ebob(a,b);
	}
	
	else if (num == 7)
	{
		int a, b;
		cout << "Ekok hesab� i�in 1.say�y� giriniz. ";
		cin >> a;
		cout << "Ekok hesab� i�in 2.say�y� giriniz. ";
		cin >> b;
		ekok(a, b);
	}
	return 0;
}


void Hipoten�s(int a, int b)
{
	double sonuc = sqrt(a * a + b * b);
	cout << "Hipoten�s de�eriniz : " << sonuc;
}

void S�ralama()
{
	for (int i = 1; i < 11; i++)
	{
		cout << i << " ";
	}
}

void mod(int n)
{
	for (int i = 1; i < 101; i++)
	{
		int sonuc;
		if (i % n == 0)
		{
			cout << i << " " << endl;
		}
	}
}

void fibonacci(int n)
{
	int a, b, c;
	a = 1;
	b = 1;

	cout << "1 \n1" << endl;

	for (int i = 0; i <= n; i++)
	{
		c = a + b;
		a = b;
		b = c;

		cout << c << endl;
	}
}

void tersPiramit(int n)
{
	int satirLen = n * 2 - 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < satirLen; j++)
		{
			if (j < i || j > satirLen-i-1)
			{
				cout << " ";
			}
			else
			{
				cout << "*";
			}
		}
		cout << endl;
	}
}

void ebob(int a,int b)
{
	int b�y�k, k�c�k;

	if (a>b)
	{
		b�y�k = a;
		k�c�k = b;
	}

	else
	{
		b�y�k = b;
		k�c�k = a;
	}

	int b�len = k�c�k;

	while (a % b�len != 0 || b % b�len != 0)
	{
		b�len--;
	}
	cout << "Ebob: " << b�len;
}

void ekok(int a, int b)
{
	int b�y�k, k�c�k;

	if (a > b)
	{
		b�y�k = a;
		k�c�k = b;
	}

	else
	{
		b�y�k = b;
		k�c�k = a;
	}
	
	int kat = k�c�k;
	while (kat % b�y�k != 0 || kat % k�c�k != 0)
	{
		kat = kat + k�c�k;
	}
	cout << "Ekok: " << kat;
}