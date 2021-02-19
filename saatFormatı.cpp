
#include <iostream>		// c++ icin kütüphane
#include <locale.h>		// c++ icin kütüphane
using namespace std;	

struct Zaman				// zaman adinda bir yapı olusturdum
{
	int saat;				// saat degiskenimiz
	int dakika;				// dakika degiskenimiz	
	int saniye;				// saniye degiskenimiz
	long toplam_saniye;		// toplam saniye degiskenimiz
};

int main()
{
	setlocale(LC_ALL, "Turkish");		
	
	Zaman time1;		//structa bir degisken tanımladım
	char ikiNokta;		//char degiskeni
	bool Hata = false;	//Hata adında bir boolean ekledim
	
	cout << "Saat:Dakika:Saniye şeklinde zamanı giriniz : ";							//kullanicidan istedigim inputı ifade ettim
	cin >> time1.saat >> ikiNokta >> time1.dakika >> ikiNokta >> time1.saniye;			//kullanicinin girdigi degerleri degiskenlere atadım

	if (ikiNokta == ':')																//zaman değerleri arasındaki karakteri doğru girip girmediğini kontrol ettim
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

		if (Hata == false)																// Eger herhangi bir hata yapılmamışsa bu blok çalışacak
		{
			{
				time1.toplam_saniye = time1.saat * 3600 + time1.dakika * 60 + time1.saniye;			// toplam saniyeyi hesaplayan formülü tanimladik
				cout << "Saniye olarak hesaplanan deger : " << time1.toplam_saniye;					// toplam saniyeyi ekrana bastirdik
			}
		}
	}

	else																				//zaman değerleri arasındaki karakteri yanlış girdiyse hata mesajı verdim
	{
		cout << "Saat , dakika ve saniye arasına yanlış bir deger girdiniz.";
	}
	return 0;
}
