#include <iostream>
#include <cmath>
using namespace std;

void Hipotenüs(int a, int b);
void Sýralama();
void fibonacci(int n);
void mod(int n);
void tersPiramit(int n);
void ebob(int a,int b);
void ekok(int a, int b);

int main()
{
	setlocale(LC_ALL, "Turkish");
	cout << "Yapmak istediðiniz iþlemi seçiniz. " << endl;;
	cout << "Dik üçgenin Hipotenüsünü hesaplamak için 1'e basýnýz. " << endl;
	cout << "1-10 sayýlarý yazdýrmak için 2'e basýnýz. " << endl;
	cout << "Verilen sayýnýn 0-100 arasýnda katlarýný bulan program için 3'e basýnýz. " << endl;
	cout << "Fibonacci serisini yazdýrmak için 4'e basýnýz. " << endl;
	cout << "Ters Piramit oluþturmak için 5'e basýnýz. " << endl;
	cout << "Ebob hesabý için 6'ya basýnýz. " << endl;
	cout << "Ekok hesabý için 7'ye basýnýz. " << endl;

	int num;
	cin >> num;

	if (num == 1)
	{
		int num1, num2;
		cout << "1.kenarý giriniz : " ;
		cin >> num1;
		cout << "2.kenarý giriniz : " ;
		cin >> num2;
		Hipotenüs(num1, num2);
	}

	else if (num == 2)
	{
		Sýralama();
	}

	else if (num == 3)
	{
		int a;
		cout << "Hangi sayýnýn katlarýný istiyorsunuz? "; 
		cin >> a;
		mod(a);
	}

	else if (num == 4)
	{
		int a;
		cout << "Kaçýncý elemana kadar fibonacci serisini istiyorsunuz? ";
		cin >> a;
		fibonacci(a);
	}

	else if (num == 5)
	{
		int a;
		cout << "Ne kadar büyüklükte bir piramit istiyorsunuz? ";
		cin >> a;
		tersPiramit(a);
	}
	
	else if (num == 6)
	{
		int a,b;
		cout << "Ebob hesabý için 1.sayýyý giriniz. ";
		cin >> a;
		cout << "Ebob hesabý için 2.sayýyý giriniz. ";
		cin >> b;
		ebob(a,b);
	}
	
	else if (num == 7)
	{
		int a, b;
		cout << "Ekok hesabý için 1.sayýyý giriniz. ";
		cin >> a;
		cout << "Ekok hesabý için 2.sayýyý giriniz. ";
		cin >> b;
		ekok(a, b);
	}
	return 0;
}


void Hipotenüs(int a, int b)
{
	double sonuc = sqrt(a * a + b * b);
	cout << "Hipotenüs deðeriniz : " << sonuc;
}

void Sýralama()
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
	int büyük, kücük;

	if (a>b)
	{
		büyük = a;
		kücük = b;
	}

	else
	{
		büyük = b;
		kücük = a;
	}

	int bölen = kücük;

	while (a % bölen != 0 || b % bölen != 0)
	{
		bölen--;
	}
	cout << "Ebob: " << bölen;
}

void ekok(int a, int b)
{
	int büyük, kücük;

	if (a > b)
	{
		büyük = a;
		kücük = b;
	}

	else
	{
		büyük = b;
		kücük = a;
	}
	
	int kat = kücük;
	while (kat % büyük != 0 || kat % kücük != 0)
	{
		kat = kat + kücük;
	}
	cout << "Ekok: " << kat;
}