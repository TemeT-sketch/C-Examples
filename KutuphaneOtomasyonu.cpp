
#include <iostream>
#include <fstream>
#include <ctime>
#include <string>

using namespace std;

string Tc, Ad, Soyad, uyeNo, tel, dogum, gorev, maxKitap;
string ISBN, kitapIsim, yazarAd, yazarSoyad, konu, tür, sayfaSayisi;
string oduncTarih, donusTarih;

void tekrarMenu();
void giris();
void menu();
void saat();
void okuyucuKaydý();
void cikis();
void menuSecim();
void kitapEkleme();
void okuyucuSilme();
void kitapSilme();
void okuyucuGüncelleme();
void kitapDüzeltme();
int tcKontrol(string tc);
int isbnKontrol(string isbn);
void oduncAlma();
void okuyucuKitapListe();
void kitapIade();


int main()
{
	setlocale(LC_ALL, "turkish");
	giris();
	menuSecim();
}

//*****************************MENÜ ÝÞLEMLERÝ*****************************

void giris()
{
	int count = 0;
	string user, pass, u, p;

	cout << "Kitap Ödünç Alma Sistemine girmek için" << endl;
	cout << "Kullanýcý adýnýzý giriniz: ";
	cin >> user;
	cout << "Þifrenizi giriniz: ";
	cin >> pass;

	ifstream input("Kullanýcýlar.txt", ios::app);

	while (input >> u >> p)
	{
		if (u == user && p == pass)
		{
			count += 1;
		}
	}
	input.close();

	if (count == 1)
	{
		system("cls");
		cout << "...Kitap Ödünç alma sistemine hoþ geldiniz..." << endl;
		cout << endl;
		cout << "Sisteme giriþ saatiniz: ";
		saat();
	}

	else
	{
		system("cls");
		cout << "Hatalý kullanýcý adý ya da þifre girdiniz \nLütfen tekrar deneyiniz..." << endl;
		cout << "-----------------------------------------" << endl;
		giris();
	}
}

void menu()
{
	cout << "=============================================" << endl;
	cout << "1- Okuyucu kaydý" << endl;
	cout << "2- Okuyucu kaydý güncelleme" << endl;
	cout << "3- Okuyucu silme" << endl;
	cout << "4- Okuyucu üzerindeki kitaplar listesi" << endl;
	cout << "5- Okuyucu kitap ödünç alma" << endl;
	cout << "6- Okuyucu kitap geri döndürme" << endl;
	cout << "7- Kitap ekleme" << endl;
	cout << "8- Kitap silme" << endl;
	cout << "9- Kitap düzeltme" << endl;
	cout << "0- Çýkýþ" << endl;
	cout << "============================================="<<endl;
}

void menuSecim()
{
	menu();
	int secim;
	cout << "Yapmak istediðiniz iþlemin numarasýný giriniz: ";
	cin >> secim;

	switch (secim)
	{
	case 1:
		okuyucuKaydý();
		break;
	case 2:
		okuyucuGüncelleme();
		break;
	case 3:
		okuyucuSilme();
		break;
	case 4:
		okuyucuKitapListe();
		break;
	case 5:
		oduncAlma();
		break;
	case 6:
		kitapIade();
		break;
	case 7:
		kitapEkleme();
		break;
	case 8:
		kitapSilme();
		break;
	case 9:
		kitapDüzeltme();
		break;
	case 0:
		cikis();
		break;
	default:
		system("cls");
		cout << "Hatali bir islem sectiniz. Lutfen tekrar deneyin!\a" << endl;
		menuSecim();
		break;
	}
}

void tekrarMenu()
{
	string secim;
	cout << "Ana Menüye dönmek ister misiniz?(e/h) ";
	cin >> secim;

	if (secim == "e")
	{
		system("cls");
		menuSecim();
	}
	else
	{
		cikis();
	}
}

void saat()
{
	time_t tarih = time(NULL);
	struct tm* tarih_bilgisi = localtime(&tarih);
	char mTarih[50];

	strftime(mTarih, sizeof(mTarih), "%d-%m-%Y %H:%M:%S", tarih_bilgisi);

	cout << mTarih << endl;
}

void cikis()
{
	cout << "Sistemden çýkýþ saatiniz : ";
	saat();
	exit(0);
}

//*****************************OKUYUCU ÝÞLEMLERÝ*****************************
int tcKontrol(string tc)
{
	bool tcKontrol = 0;
	ifstream dosyaOku("Okuyucu.txt");
	while (!dosyaOku.eof())
	{
		dosyaOku >> Tc >> Ad >> Soyad >> uyeNo >> tel >> dogum >> gorev >> maxKitap;

		if (tc == Tc)
		{
			tcKontrol = 1;
		}
	}
	return tcKontrol;
}

void okuyucuKaydý()
{
	string tc;
	cout << "TC No:";
	cin >> tc;

	ofstream DosyaYaz;
	DosyaYaz.open("Okuyucu.txt", ios::app);

	if (tcKontrol(tc) == 1) 
	{
		cout << "Bu TC kimlik numarasina ait bir okuyucu zaten var!" << endl;
		cout << "Tekrar deneyiniz." << endl;
		DosyaYaz.close();
		okuyucuKaydý();
	}

	else
	{
		Tc = tc;
		cout << "Ad:";
		cin >> Ad;
		cout << "Soyad:";
		cin >> Soyad;
		cout << "Üye No:";
		cin >> uyeNo;
		cout << "Telefon No:";
		cin >> tel;
		cout << "Doðum Tarihiniz:";
		cin >> dogum;
		cout << "Görev:";
		cin >> gorev;
		cout << "Alabileceðiniz Kitap Sayýsý:";
		cin >> maxKitap;

		DosyaYaz << Tc << " " << Ad << ' ' << Soyad << ' ' << uyeNo << ' ' << tel << ' ' << dogum << " " << gorev << " " << maxKitap << "\n";
		DosyaYaz.close();
		cout << "Yeni Okuyucu Kaydedildi. " << endl;
		tekrarMenu();
	}
}

void okuyucuSilme()
{
	string tcSil;
	cout << "Silinecek okuyucunun TC numarasýný giriniz: ";
	cin >> tcSil;
	bool sayac = 0;

	ifstream dosyaOku("Okuyucu.txt");
	ofstream dosyaYaz("okuyucuSil.txt");

	if (tcKontrol(tcSil) == 0)
	{
		cout << "Girdiginiz TC numarasý sistemde kayýtlý deðildir!" << endl;
		cout << "Tekrar deneyiniz." << endl;
		dosyaOku.close();
		dosyaYaz.close();
		okuyucuSilme();
	}

	else
	{
		sayac = 1;
		while (!dosyaOku.eof())
		{
			dosyaOku >> Tc >> Ad >> Soyad
				>> uyeNo >> tel
				>> dogum >> gorev >> maxKitap;

			if (tcSil != Tc)
			{
				if (dosyaOku.eof())	break;
				dosyaYaz << Tc << ' ' << Ad << ' '
					<< Soyad << ' ' << uyeNo << ' '
					<< tel << ' ' << dogum << ' ' << gorev
					<< ' ' << maxKitap << "\n";
			}
		}
	}

	dosyaOku.close();
	dosyaYaz.close();

	if (sayac == 1) // Programda kayýt varsa yapýlan deðiþikliklerin dosya üzerine yazýlmasý saðlandý.
	{
		remove("Okuyucu.txt");
		rename("okuyucuSil.txt", "Okuyucu.txt");
		cout << "\nOkuyucu Silinmiþtir...\n";
		tekrarMenu();
	}
	else
	{
		remove("okuyucuSil.txt");
	}
}

void okuyucuGüncelleme()
{
	string tcDüzenle;
	cout << "Güncellenecek okuyucunun TC numarasýný giriniz: ";
	cin >> tcDüzenle;
	bool sayac = 0;

	ifstream dosyaOku("Okuyucu.txt");
	ofstream dosyaYaz("okuyucuGuncelleme.txt", ios::app);

	if (tcKontrol(tcDüzenle) == 0)
	{
		cout << "Girdiginiz TC numarasý sistemde kayýtlý deðildir!" << endl;
		cout << "Tekrar deneyiniz." << endl;
		dosyaOku.close();
		dosyaYaz.close();
		okuyucuGüncelleme();
	}
	else
	{
		sayac = 1;
		while (true)
		{
			dosyaOku >> Tc >> Ad >> Soyad
				>> uyeNo >> tel
				>> dogum >> gorev >> maxKitap;

			if (dosyaOku.eof())	break; // En son kaydýn 2 kere okuyup yazýlmamasý için eklendi.
			if (tcDüzenle == Tc)
			{
				cout << "Okuyucu TC : " << Tc << "\nOkuyucu adi : " << Ad << "\nOkuyucu soyadi : " << Soyad << "\nOkuyucu Üye No : " << uyeNo
					<< "\nTelefon : " << tel << "\nDogum tarihi : " << dogum << "\nGörevi : " << gorev << "\nAlabileceði Maksimum kitap Sayýsý : " << maxKitap << "\n\nYeni bilgiler;\n";

				cout << "Okuyucu TC : ";
				cin >> Tc;
				cout << "Okuyucu adi : ";
				cin >> Ad;
				cout << "Okuyucu soyadi : ";
				cin >> Soyad;
				cout << "Okuyucu Üye No : ";
				cin >> uyeNo;
				cout << "Telefon : ";
				cin >> tel;
				cout << "Dogum tarihi : ";
				cin >> dogum;
				cout << "Görevi : ";
				cin >> gorev;
				cout << "Alabileceði Maksimum kitap Sayýsý : ";
				cin >> maxKitap;

				dosyaYaz << Tc << " " << Ad << " " << Soyad << " " << uyeNo << " " << tel << " " << dogum << " " << gorev << " " << maxKitap << "\n";
			}
			else
			{
				dosyaYaz << Tc << " " << Ad << " " << Soyad << " " << uyeNo << " " << tel << " " << dogum << " " << gorev << " " << maxKitap << "\n";
			}

		}
	}

	if (sayac == 1)
	{
		dosyaOku.close();
		dosyaYaz.close();
		remove("Okuyucu.txt");
		rename("okuyucuGuncelleme.txt", "Okuyucu.txt");
		cout << "Okuyucu bilgileri güncellendi!\n";
		tekrarMenu();
	}
	else
	{
		remove("okuyucuGuncelleme.txt");
	}
}

//*****************************ÖDÜNÇ ÝÞLEMLERÝ*****************************

void oduncAlma()
{
	string oduncTarih, donusTarih;

	string oduncTc, oduncIsbn;
	cout << "TC numaranýzý giriniz : ";
	cin >> oduncTc;
	cout << "Almak istediginiz kitabýn ISBN numarasýný giriniz : ";
	cin >> oduncIsbn;

	ofstream DosyaYaz;
	DosyaYaz.open("Odunc.txt", ios::app);
	
	if (tcKontrol(oduncTc) ==0 || isbnKontrol(oduncIsbn) == 0)
	{
		cout << "Girdiðiniz Tc numarasý ya da ISBN numarasý yanlýþtýr." << endl;
		cout << "Tekrar Deneyiniz" << endl;
		DosyaYaz.close();
		oduncAlma();
	}
	else
	{
		cout << "Ödünç Tarihi : ";
		cin >> oduncTarih;
		cout << "Dönüþ Tarihi : ";
		cin >> donusTarih;
		DosyaYaz << oduncTc << " " << oduncIsbn << ' ' << oduncTarih << ' ' << donusTarih << "\n";
		DosyaYaz.close();
		cout << "Yeni Odunc Kitap Kaydedildi.\n" << endl;
		tekrarMenu();
	}
}

void okuyucuKitapListe()
{
	string oduncTc;
	cout << "TC numaranýzý giriniz : ";
	cin >> oduncTc;

	ifstream dosyaOku;
	dosyaOku.open("Odunc.txt", ios::app);

	if (tcKontrol(oduncTc) == 0 )
	{
		cout << "Girdiðiniz Tc numarasý hatalýdýr." << endl;
		cout << "Tekrar Deneyiniz." << endl;
		dosyaOku.close();
		okuyucuKitapListe();
	}
	else
	{
		while (!dosyaOku.eof())
		{
			dosyaOku >> Tc >> ISBN >> oduncTarih >> donusTarih;

			if (dosyaOku.eof())	break;

			if (oduncTc == Tc)
			{
				cout << Tc << " TC numarasýna ait okuyucunun üzerindeki kitaplarýn listesi :";
				cout << "\nISBN numarasý : " << ISBN << "\nÖdünç Tarihi : " << oduncTarih << "\nDönüþ Tarihi : " << donusTarih << endl ;
			}
			else
			{
				cout << "Girmiþ oldugunuz TC numaralý okuyucu henüz ödünç kitap almamýþtýr." << endl;
			}
		}
	}
	dosyaOku.close();
	tekrarMenu();
}

void kitapIade()
{
	string iadeSil;
	cout << "Ýade edilecek kitaplara kayýtlý TC numarasýný giriniz : ";
	cin >> iadeSil;

	bool sayac = 0;

	ifstream dosyaOku("Odunc.txt");
	ofstream dosyaYaz("oduncSil.txt");

	if (tcKontrol(iadeSil) == 0)
	{
		cout << "Girdiginiz TC numarasý sistemde kayýtlý deðildir!" << endl;
		cout << "Tekrar Deneyiniz" << endl;
		dosyaOku.close();
		dosyaYaz.close();
		kitapIade();
	}

	else
	{
		sayac = 1;
		while (!dosyaOku.eof())
		{
			dosyaOku >> Tc >> ISBN >> oduncTarih >> donusTarih;

			if (iadeSil != Tc)
			{
				if (dosyaOku.eof())	break;
				dosyaYaz << Tc << " " << ISBN << ' ' << oduncTarih << ' ' << donusTarih << "\n";
			}
		}
	}

	dosyaOku.close();
	dosyaYaz.close();

	if (sayac == 1) // Programda kayýt varsa yapýlan deðiþikliklerin dosya üzerine yazýlmasý saðlandý.
	{
		remove("Odunc.txt");
		rename("oduncSil.txt", "Odunc.txt");
		cout << "\nÝade kitaplar Silinmiþtir...\n";
		tekrarMenu();
	}
	else
	{
		remove("Odunc.txt");
	}
}

//*****************************KÝTAP ÝÞLEMLERÝ*****************************

int isbnKontrol(string isbn)
{
	bool isbnKontrol = 0;
	ifstream dosyaOku("Kitaplar.txt");
	while (!dosyaOku.eof())
	{
		dosyaOku >> ISBN >> kitapIsim >> yazarAd >> yazarSoyad >> konu >> tür >> sayfaSayisi;

		if (isbn == ISBN)
		{
			isbnKontrol = 1;
		}
	}
	return isbnKontrol;
}

void kitapEkleme()
{
	string isbn;
	cout << "ISBN No:";
	cin >> isbn;

	ofstream DosyaYaz;
	DosyaYaz.open("Kitaplar.txt", ios::app);

	if (isbnKontrol(isbn) == 1)
	{
		cout << "Bu ISBN numarasina ait bir kitap zaten var!\n";
		cout << "Tekrar Deneyiniz" << endl;
		DosyaYaz.close();
		kitapEkleme();
	}

	else
	{
		ISBN = isbn;
		cout << "Kitap Adý:";
		cin >> kitapIsim;
		cout << "Yazar Adý:";
		cin >> yazarAd;
		cout << "Yazar Soyadý:";
		cin >> yazarSoyad;
		cout << "Konu:";
		cin >> konu;
		cout << "Tür:";
		cin >> tür;
		cout << "Sayfa Sayýsý:";
		cin >> sayfaSayisi;

		DosyaYaz << ISBN << " " << kitapIsim << ' ' << yazarAd << ' '
			<< yazarSoyad << ' ' << konu << ' '
			<< tür << " " << sayfaSayisi << "\n";

		DosyaYaz.close();
		cout << "Yeni Kitap Kaydedildi. " << endl;
		tekrarMenu();
	}
}

void kitapSilme()
{
	string isbnSil;
	cout << "Silinecek kitabýn ISBN numarasýný giriniz: ";
	cin >> isbnSil;
	bool sayac = 0;

	ifstream dosyaOku("Kitaplar.txt");
	ofstream dosyaYaz("kitapSil.txt");

	if (isbnKontrol(isbnSil) == 0)
	{
		cout << "Girdiginiz ISBN numarasý sistemde kayýtlý deðildir!" << endl;
		cout << "Tekrar deneyiniz." << endl;
		dosyaOku.close();
		dosyaYaz.close();
		kitapSilme();
	}
	else
	{
		sayac = 1;
		while (!dosyaOku.eof())
		{
			dosyaOku >> ISBN >> kitapIsim >> yazarAd
				>> yazarSoyad >> konu
				>> tür >> sayfaSayisi;

			if (isbnSil != ISBN)
			{
				if (dosyaOku.eof())	break;
				dosyaYaz << ISBN << " " << kitapIsim << ' ' << yazarAd << ' '
					<< yazarSoyad << ' ' << konu << ' '
					<< tür << " " << sayfaSayisi << "\n";
			}

			else
			{
				cout << "\nKitap Silinmiþtir...\n";
			}
		}
	}

	dosyaOku.close();
	dosyaYaz.close();

	if (sayac == 1)
	{

		remove("Kitaplar.txt");
		rename("kitapSil.txt", "Kitaplar.txt");
		tekrarMenu();
	}
	else
	{
		remove("kitapSil.txt");
	}
}

void kitapDüzeltme()
{
	string isbnDüzenle;
	cout << "Düzenlenecek kitabýn ISBN numarasýný giriniz: ";
	cin >> isbnDüzenle;
	bool sayac = 0;

	ifstream dosyaOku("Kitaplar.txt");
	ofstream dosyaYaz("kitapGuncelleme.txt", ios::app);

	if (isbnKontrol(isbnDüzenle) == 0)
	{
		cout << "Girdiginiz ISBN numarasý sistemde kayýtlý deðildir!" << endl;
		cout << "Tekrar deneyiniz." << endl;
		dosyaOku.close();
		dosyaYaz.close();
		kitapDüzeltme();
	}

	else
	{
		sayac = 1;
		while (true)
		{
			dosyaOku >> ISBN >> kitapIsim >> yazarAd
				>> yazarSoyad >> konu
				>> tür >> sayfaSayisi;

			if (dosyaOku.eof())	break; // En son kaydýn 2 kere okuyup yazýlmamasý için eklendi.
			if (isbnDüzenle == ISBN)
			{
				cout << "ISBN No : " << ISBN << "\nKitap adi : " << kitapIsim << "\nYazar Adý : " << yazarAd << "\nYazar Soyadý : " << yazarSoyad
					<< "\nKonu : " << konu << "\nTür : " << tür << "\nSayfa Sayýsý : " << sayfaSayisi << "\n\nYeni bilgiler;\n";
				cout << "ISBN No:";
				cin >> ISBN;
				cout << "Kitap Adý:";
				cin >> kitapIsim;
				cout << "Yazar Adý:";
				cin >> yazarAd;
				cout << "Yazar Soyadý:";
				cin >> yazarSoyad;
				cout << "Konu:";
				cin >> konu;
				cout << "Tür:";
				cin >> tür;
				cout << "Sayfa Sayýsý:";
				cin >> sayfaSayisi;
				dosyaYaz << ISBN << " " << kitapIsim << ' ' << yazarAd << ' '
					<< yazarSoyad << ' ' << konu << ' '
					<< tür << " " << sayfaSayisi << "\n";
			}
			else
			{
				dosyaYaz << ISBN << " " << kitapIsim << ' ' << yazarAd << ' '
					<< yazarSoyad << ' ' << konu << ' '
					<< tür << " " << sayfaSayisi << "\n";
			}
		}
	}
	dosyaOku.close();
	dosyaYaz.close();

	if (sayac == 1)
	{
		remove("Kitaplar.txt");
		rename("kitapGuncelleme.txt", "Kitaplar.txt");
		cout << "Kitap bilgileri Düzeltildi!\n";
		tekrarMenu();
	}
	else
	{
		remove("kitapGuncelleme.txt");
	}
}