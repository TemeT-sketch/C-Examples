#include <iostream>
using namespace std;

int num = 10;

void multi(int n)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << j << "x" << i << "=" << i * j << "\t";
		}
		cout << endl;
	}
}

void add(int n)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << j << "+" << i << "=" << i + j << "\t";
		}
		cout << endl;
	}
}

int main()
{
	setlocale(LC_ALL, "turkish");

	string islem;
	cout << "Çarpým tablosu için 1'e \nToplam Tablosu için 2'ye basýnýz => " ;
	cin >> islem;
	
	if (islem == "1")
	{
		multi(num);
		cout << endl;
	}
	else if (islem == "2")
	{
		add(num);
		cout << endl;
	}
}
