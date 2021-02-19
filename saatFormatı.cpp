
#include <iostream>		// c++ icin k�t�phane
#include <locale.h>		// c++ icin k�t�phane
using namespace std;	

struct Zaman				// zaman adinda bir yap� olusturdum
{
	int saat;				// saat degiskenimiz
	int dakika;				// dakika degiskenimiz	
	int saniye;				// saniye degiskenimiz
	long toplam_saniye;		// toplam saniye degiskenimiz
};

int main()
{
	setlocale(LC_ALL, "Turkish");		
	
	Zaman time1;		//structa bir degisken tan�mlad�m
	char ikiNokta;		//char degiskeni
	bool Hata = false;	//Hata ad�nda bir boolean ekledim
	
	cout << "Saat:Dakika:Saniye �eklinde zaman� giriniz : ";							//kullanicidan istedigim input� ifade ettim
	cin >> time1.saat >> ikiNokta >> time1.dakika >> ikiNokta >> time1.saniye;			//kullanicinin girdigi degerleri degiskenlere atad�m

	if (ikiNokta == ':')																//zaman de�erleri aras�ndaki karakteri do�ru girip girmedi�ini kontrol ettim
	{
		if (time1.saat < 0 || time1.saat > 23)											// Eger girilen saat belirttigim deger araligindan farkliysa hata mesaji verilecek
		{
			cout << "Girilen saat degeri " << time1.saat << " yanlis girilmistir." << endl;
			Hata = true;
		}

		if (time1.dakika < 0 || time1.dakika >= 60)										// Eger girilen dakika belirttigim deger araligindan farkliysa hata mesaji verilecek
		{
			cout << "Girilen dakika degeri " << time1.dakika << " yanlis girilmistir." << endl;
			Hata = true;
		}

		if (time1.saniye < 0 || time1.saniye >= 60)										// Eger girilen saat belirttigim deger araligindan farkliysa hata mesaji verilecek
		{
			cout << "Girilen saniye degeri " << time1.saniye << " yanlis girilmistir." << endl;
			Hata = true;
		}

		if (Hata == false)																// Eger herhangi bir hata yap�lmam��sa bu blok �al��acak
		{
			{
				time1.toplam_saniye = time1.saat * 3600 + time1.dakika * 60 + time1.saniye;			// toplam saniyeyi hesaplayan form�l� tanimladik
				cout << "Saniye olarak hesaplanan deger : " << time1.toplam_saniye;					// toplam saniyeyi ekrana bastirdik
			}
		}
	}

	else																				//zaman de�erleri aras�ndaki karakteri yanl�� girdiyse hata mesaj� verdim
	{
		cout << "Saat , dakika ve saniye aras�na yanl�� bir deger girdiniz.";
	}
	return 0;
}
