#include <iostream>
using namespace std;

void Baklava(int n)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n - 1; j++)
		{
			cout << "  ";
		}

		for (int j = 1; j <= i; j++)
		{
			cout << "* ";
		}

		for (int j = 1; j <= i - 1; j++)
		{
			cout << "* ";
		}

		cout << endl;
	}
	for (int i = n-1; i >= 1; i--)
	{
		for (int j = i; j <= n - 1; j++)
		{
			cout << "  ";
		}

		for (int j = 1; j <= i; j++)
		{
			cout << "* ";
		}

		for (int j = 1; j <= i - 1; j++)
		{
			cout << "* ";
		}

		cout << endl;
	}
}

void Kelebek(int n)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cout << "* ";
		}

		for (int k = i ; k <= n-1; k++)
		{

			cout << "  ";
		}

		for (int k = i; k <= n - 1; k++)
		{

			cout << "  ";
		}

		for (int j = 1; j <= i ; j++)
		{
			cout << "* ";
		}
		cout << endl;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n-1; j++)
		{
			cout << "* ";
		}

		for (int j = 1; j <= i; j++)
		{
			cout << "  ";
		}

		for (int j = 1; j <= i; j++)
		{
			cout << "  ";
		}

		for (int j = i; j <= n - 1; j++)
		{
			cout << "* ";
		}
		cout << endl;
	}
}



int main()
{
	setlocale(LC_ALL, "Turkish");

	string islem;
	cout << "Baklava dilimi için 1'e \nKelebek için 2'ye basınız: ";
	cin >> islem;


	if (islem == "1")
	{ 
		int num;
		cout << "satir sayisini giriniz: ";
		cin >> num;
		cout << endl;
		Baklava(num);
		cout << endl;
	}

	else
	{
		int num;
		cout << "satir sayisini giriniz: ";
		cin >> num;
		cout << endl;
		Kelebek(num);
		cout << endl;
	}

    return 0;
}