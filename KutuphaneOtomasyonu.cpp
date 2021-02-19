
#include <iostream>
#include <fstream>
#include <ctime>
#include <string>

using namespace std;

string Tc, Ad, Soyad, uyeNo, tel, dogum, gorev, maxKitap;
string ISBN, kitapIsim, yazarAd, yazarSoyad, konu, t�r, sayfaSayisi;
string oduncTarih, donusTarih;

void tekrarMenu();
void giris();
void menu();
void saat();
void okuyucuKayd�();
void cikis();
void menuSecim();
void kitapEkleme();
void okuyucuSilme();
void kitapSilme();
void okuyucuG�ncelleme();
void kitapD�zeltme();
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

//*****************************MEN� ��LEMLER�*****************************

void giris()
{
	int count = 0;
	string user, pass, u, p;

	cout << "Kitap �d�n� Alma Sistemine girmek i�in" << endl;
	cout << "Kullan�c� ad�n�z� giriniz: ";
	cin >> user;
	cout << "�ifrenizi giriniz: ";
	cin >> pass;

	ifstream input("Kullan�c�lar.txt", ios::app);

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
		cout << "...Kitap �d�n� alma sistemine ho� geldiniz..." << endl;
		cout << endl;
		cout << "Sisteme giri� saatiniz: ";
		saat();
	}

	else
	{
		system("cls");
		cout << "Hatal� kullan�c� ad� ya da �ifre girdiniz \nL�tfen tekrar deneyiniz..." << endl;
		cout << "-----------------------------------------" << endl;
		giris();
	}
}

void menu()
{
	cout << "=============================================" << endl;
	cout << "1- Okuyucu kayd�" << endl;
	cout << "2- Okuyucu kayd� g�ncelleme" << endl;
	cout << "3- Okuyucu silme" << endl;
	cout << "4- Okuyucu �zerindeki kitaplar listesi" << endl;
	cout << "5- Okuyucu kitap �d�n� alma" << endl;
	cout << "6- Okuyucu kitap geri d�nd�rme" << endl;
	cout << "7- Kitap ekleme" << endl;
	cout << "8- Kitap silme" << endl;
	cout << "9- Kitap d�zeltme" << endl;
	cout << "0- ��k��" << endl;
	cout << "============================================="<<endl;
}

void menuSecim()
{
	menu();
	int secim;
	cout << "Yapmak istedi�iniz i�lemin numaras�n� giriniz: ";
	cin >> secim;

	switch (secim)
	{
	case 1:
		okuyucuKayd�();
		break;
	case 2:
		okuyucuG�ncelleme();
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
		kitapD�zeltme();
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
	cout << "Ana Men�ye d�nmek ister misiniz?(e/h) ";
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
	cout << "Sistemden ��k�� saatiniz : ";
	saat();
	exit(0);
}

//*****************************OKUYUCU ��LEMLER�*****************************
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

void okuyucuKayd�()
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
		okuyucuKayd�();
	}

	else
	{
		Tc = tc;
		cout << "Ad:";
		cin >> Ad;
		cout << "Soyad:";
		cin >> Soyad;
		cout << "�ye No:";
		cin >> uyeNo;
		cout << "Telefon No:";
		cin >> tel;
		cout << "Do�um Tarihiniz:";
		cin >> dogum;
		cout << "G�rev:";
		cin >> gorev;
		cout << "Alabilece�iniz Kitap Say�s�:";
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
	cout << "Silinecek okuyucunun TC numaras�n� giriniz: ";
	cin >> tcSil;
	bool sayac = 0;

	ifstream dosyaOku("Okuyucu.txt");
	ofstream dosyaYaz("okuyucuSil.txt");

	if (tcKontrol(tcSil) == 0)
	{
		cout << "Girdiginiz TC numaras� sistemde kay�tl� de�ildir!" << endl;
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

	if (sayac == 1) // Programda kay�t varsa yap�lan de�i�ikliklerin dosya �zerine yaz�lmas� sa�land�.
	{
		remove("Okuyucu.txt");
		rename("okuyucuSil.txt", "Okuyucu.txt");
		cout << "\nOkuyucu Silinmi�tir...\n";
		tekrarMenu();
	}
	else
	{
		remove("okuyucuSil.txt");
	}
}

void okuyucuG�ncelleme()
{
	string tcD�zenle;
	cout << "G�ncellenecek okuyucunun TC numaras�n� giriniz: ";
	cin >> tcD�zenle;
	bool sayac = 0;

	ifstream dosyaOku("Okuyucu.txt");
	ofstream dosyaYaz("okuyucuGuncelleme.txt", ios::app);

	if (tcKontrol(tcD�zenle) == 0)
	{
		cout << "Girdiginiz TC numaras� sistemde kay�tl� de�ildir!" << endl;
		cout << "Tekrar deneyiniz." << endl;
		dosyaOku.close();
		dosyaYaz.close();
		okuyucuG�ncelleme();
	}
	else
	{
		sayac = 1;
		while (true)
		{
			dosyaOku >> Tc >> Ad >> Soyad
				>> uyeNo >> tel
				>> dogum >> gorev >> maxKitap;

			if (dosyaOku.eof())	break; // En son kayd�n 2 kere okuyup yaz�lmamas� i�in eklendi.
			if (tcD�zenle == Tc)
			{
				cout << "Okuyucu TC : " << Tc << "\nOkuyucu adi : " << Ad << "\nOkuyucu soyadi : " << Soyad << "\nOkuyucu �ye No : " << uyeNo
					<< "\nTelefon : " << tel << "\nDogum tarihi : " << dogum << "\nG�revi : " << gorev << "\nAlabilece�i Maksimum kitap Say�s� : " << maxKitap << "\n\nYeni bilgiler;\n";

				cout << "Okuyucu TC : ";
				cin >> Tc;
				cout << "Okuyucu adi : ";
				cin >> Ad;
				cout << "Okuyucu soyadi : ";
				cin >> Soyad;
				cout << "Okuyucu �ye No : ";
				cin >> uyeNo;
				cout << "Telefon : ";
				cin >> tel;
				cout << "Dogum tarihi : ";
				cin >> dogum;
				cout << "G�revi : ";
				cin >> gorev;
				cout << "Alabilece�i Maksimum kitap Say�s� : ";
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
		cout << "Okuyucu bilgileri g�ncellendi!\n";
		tekrarMenu();
	}
	else
	{
		remove("okuyucuGuncelleme.txt");
	}
}

//*****************************�D�N� ��LEMLER�*****************************

void oduncAlma()
{
	string oduncTarih, donusTarih;

	string oduncTc, oduncIsbn;
	cout << "TC numaran�z� giriniz : ";
	cin >> oduncTc;
	cout << "Almak istediginiz kitab�n ISBN numaras�n� giriniz : ";
	cin >> oduncIsbn;

	ofstream DosyaYaz;
	DosyaYaz.open("Odunc.txt", ios::app);
	
	if (tcKontrol(oduncTc) ==0 || isbnKontrol(oduncIsbn) == 0)
	{
		cout << "Girdi�iniz Tc numaras� ya da ISBN numaras� yanl��t�r." << endl;
		cout << "Tekrar Deneyiniz" << endl;
		DosyaYaz.close();
		oduncAlma();
	}
	else
	{
		cout << "�d�n� Tarihi : ";
		cin >> oduncTarih;
		cout << "D�n�� Tarihi : ";
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
	cout << "TC numaran�z� giriniz : ";
	cin >> oduncTc;

	ifstream dosyaOku;
	dosyaOku.open("Odunc.txt", ios::app);

	if (tcKontrol(oduncTc) == 0 )
	{
		cout << "Girdi�iniz Tc numaras� hatal�d�r." << endl;
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
				cout << Tc << " TC numaras�na ait okuyucunun �zerindeki kitaplar�n listesi :";
				cout << "\nISBN numaras� : " << ISBN << "\n�d�n� Tarihi : " << oduncTarih << "\nD�n�� Tarihi : " << donusTarih << endl ;
			}
			else
			{
				cout << "Girmi� oldugunuz TC numaral� okuyucu hen�z �d�n� kitap almam��t�r." << endl;
			}
		}
	}
	dosyaOku.close();
	tekrarMenu();
}

void kitapIade()
{
	string iadeSil;
	cout << "�ade edilecek kitaplara kay�tl� TC numaras�n� giriniz : ";
	cin >> iadeSil;

	bool sayac = 0;

	ifstream dosyaOku("Odunc.txt");
	ofstream dosyaYaz("oduncSil.txt");

	if (tcKontrol(iadeSil) == 0)
	{
		cout << "Girdiginiz TC numaras� sistemde kay�tl� de�ildir!" << endl;
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

	if (sayac == 1) // Programda kay�t varsa yap�lan de�i�ikliklerin dosya �zerine yaz�lmas� sa�land�.
	{
		remove("Odunc.txt");
		rename("oduncSil.txt", "Odunc.txt");
		cout << "\n�ade kitaplar Silinmi�tir...\n";
		tekrarMenu();
	}
	else
	{
		remove("Odunc.txt");
	}
}

//*****************************K�TAP ��LEMLER�*****************************

int isbnKontrol(string isbn)
{
	bool isbnKontrol = 0;
	ifstream dosyaOku("Kitaplar.txt");
	while (!dosyaOku.eof())
	{
		dosyaOku >> ISBN >> kitapIsim >> yazarAd >> yazarSoyad >> konu >> t�r >> sayfaSayisi;

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
		cout << "Kitap Ad�:";
		cin >> kitapIsim;
		cout << "Yazar Ad�:";
		cin >> yazarAd;
		cout << "Yazar Soyad�:";
		cin >> yazarSoyad;
		cout << "Konu:";
		cin >> konu;
		cout << "T�r:";
		cin >> t�r;
		cout << "Sayfa Say�s�:";
		cin >> sayfaSayisi;

		DosyaYaz << ISBN << " " << kitapIsim << ' ' << yazarAd << ' '
			<< yazarSoyad << ' ' << konu << ' '
			<< t�r << " " << sayfaSayisi << "\n";

		DosyaYaz.close();
		cout << "Yeni Kitap Kaydedildi. " << endl;
		tekrarMenu();
	}
}

void kitapSilme()
{
	string isbnSil;
	cout << "Silinecek kitab�n ISBN numaras�n� giriniz: ";
	cin >> isbnSil;
	bool sayac = 0;

	ifstream dosyaOku("Kitaplar.txt");
	ofstream dosyaYaz("kitapSil.txt");

	if (isbnKontrol(isbnSil) == 0)
	{
		cout << "Girdiginiz ISBN numaras� sistemde kay�tl� de�ildir!" << endl;
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
				>> t�r >> sayfaSayisi;

			if (isbnSil != ISBN)
			{
				if (dosyaOku.eof())	break;
				dosyaYaz << ISBN << " " << kitapIsim << ' ' << yazarAd << ' '
					<< yazarSoyad << ' ' << konu << ' '
					<< t�r << " " << sayfaSayisi << "\n";
			}

			else
			{
				cout << "\nKitap Silinmi�tir...\n";
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

void kitapD�zeltme()
{
	string isbnD�zenle;
	cout << "D�zenlenecek kitab�n ISBN numaras�n� giriniz: ";
	cin >> isbnD�zenle;
	bool sayac = 0;

	ifstream dosyaOku("Kitaplar.txt");
	ofstream dosyaYaz("kitapGuncelleme.txt", ios::app);

	if (isbnKontrol(isbnD�zenle) == 0)
	{
		cout << "Girdiginiz ISBN numaras� sistemde kay�tl� de�ildir!" << endl;
		cout << "Tekrar deneyiniz." << endl;
		dosyaOku.close();
		dosyaYaz.close();
		kitapD�zeltme();
	}

	else
	{
		sayac = 1;
		while (true)
		{
			dosyaOku >> ISBN >> kitapIsim >> yazarAd
				>> yazarSoyad >> konu
				>> t�r >> sayfaSayisi;

			if (dosyaOku.eof())	break; // En son kayd�n 2 kere okuyup yaz�lmamas� i�in eklendi.
			if (isbnD�zenle == ISBN)
			{
				cout << "ISBN No : " << ISBN << "\nKitap adi : " << kitapIsim << "\nYazar Ad� : " << yazarAd << "\nYazar Soyad� : " << yazarSoyad
					<< "\nKonu : " << konu << "\nT�r : " << t�r << "\nSayfa Say�s� : " << sayfaSayisi << "\n\nYeni bilgiler;\n";
				cout << "ISBN No:";
				cin >> ISBN;
				cout << "Kitap Ad�:";
				cin >> kitapIsim;
				cout << "Yazar Ad�:";
				cin >> yazarAd;
				cout << "Yazar Soyad�:";
				cin >> yazarSoyad;
				cout << "Konu:";
				cin >> konu;
				cout << "T�r:";
				cin >> t�r;
				cout << "Sayfa Say�s�:";
				cin >> sayfaSayisi;
				dosyaYaz << ISBN << " " << kitapIsim << ' ' << yazarAd << ' '
					<< yazarSoyad << ' ' << konu << ' '
					<< t�r << " " << sayfaSayisi << "\n";
			}
			else
			{
				dosyaYaz << ISBN << " " << kitapIsim << ' ' << yazarAd << ' '
					<< yazarSoyad << ' ' << konu << ' '
					<< t�r << " " << sayfaSayisi << "\n";
			}
		}
	}
	dosyaOku.close();
	dosyaYaz.close();

	if (sayac == 1)
	{
		remove("Kitaplar.txt");
		rename("kitapGuncelleme.txt", "Kitaplar.txt");
		cout << "Kitap bilgileri D�zeltildi!\n";
		tekrarMenu();
	}
	else
	{
		remove("kitapGuncelleme.txt");
	}
}