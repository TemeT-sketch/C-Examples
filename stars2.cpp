#include <iostream>
using namespace std;

void YanYana(int n)
{
	for (int i = 1; i <= n; i++) {
		cout << "* ";
	}
	cout << endl;
}

void Kare(int n)
{
	for (int j = 1; j<=n; j++)
	{
		for (int i = 1; i <= n; i++) {
			cout << "* ";
		}
		cout << endl;
	}
}

void SolaYatık(int n)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cout << "* ";
		}
		cout << endl;
	}
}


void TersDik(int n)
{
	for (int i = n ; i >= 1; i--)
	{
		for (int j = i; j>0 ; j--)
		{
			cout << "* ";
		}
		cout << endl;
	}
}

void TersDik2(int n)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n - (i - 1); j++)
		{
			cout << "* ";
		}
		cout << endl;
	}
}

void TersDik3(int n)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j++)
		{
			cout << "* ";
		}
		cout << endl;
	}
}


void Piramit(int n)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n-1; j++)
		{
			cout << "  ";
		}

		for (int j = 1; j <= i; j++)
		{
			cout << "* ";
		}

		for (int j = 1; j <= i-1; j++)
		{
			cout << "* ";
		}

		cout << endl;
	}
}



int main() 
{
	string islem;

	cout << "Yildizlari yan yana basmak icin 1 e " << endl;
	cout << "Yildizlardan kare yapmak icin 2 ye  " << endl;
	cout << "Yildizlardan dik ucgen yapmak icin  3 e  " << endl;
	cout << "Yildizlardan ters dik ucgen yapmak icin 4 e  " << endl;
	cout << "Yildizlardan piramit yapmak icin 5 e basiniz "<<endl;
	

	cout << "islem numaranizi giriniz : " ;

	cin >> islem;


	if (islem == "1")
	{
		int num;

		cout << "sayiyi giriniz : ";
		cin >> num;

		YanYana(num);
		cout << endl;
	}
	if (islem == "2")
	{
		int num;
		cout << "sayiyi giriniz : ";

		cin >> num;
		Kare(num);
		cout << endl;
	}
	if (islem == "3")
	{
		int num;
		cout << "sayiyi giriniz : ";

		cin >> num;
		SolaYatık(num);
		cout << endl;
	}
	if (islem == "4")
	{
		int num;
		cout << "sayiyi giriniz : ";

		cin >> num;
		TersDik3(num);
		cout << endl;
	}
	if (islem == "5")
	{
		int num;
		cout << "sayiyi giriniz : ";

		cin >> num;
		Piramit(num);
		cout << endl;
	}


	return 0;
}