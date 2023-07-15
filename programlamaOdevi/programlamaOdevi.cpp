
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include<cmath>
using namespace std;

struct ogrenci
{
	string adi;
	string soyadi;
	int no;
	int kisaSinav1;
	int kisaSinav2;
	int odev1;
	int odev2;
	int proje;
	int vize;
	int finalSinavi;
	float yilIci;
	float basariNotu;
};

struct dogumTarihi
{
	int gun;
	int ay;
	int yil;

};

string harfNotunaCevir(float puan)
{
	string harf;
	if (puan >= 0 && puan < 50)
		harf = "F";

	else if (puan >= 50 && puan < 65)
		harf = "E";

	else if (puan >= 65 && puan < 75)
		harf = "D";

	else if (puan >= 75 && puan < 80)
		harf = "C";

	else if (puan >= 80 && puan < 85)
		harf = "B";

	else if (puan >= 85 && puan < 90)
		harf = "AB";

	else if (puan >= 90 && puan <= 100)
		harf = "AA";

	else
		cout << "Öğrenci Notu Geçerli Değil,Lütfen Kontrol Ediniz..!";

	return harf;
}
//sayısal puanı harf notuna çevirme fonksiyonu(yıl sonu notu için kullanıldı)

void listele(ogrenci ogr)
{

	cout << ogr.adi << "\t" << ogr.soyadi << "\t" << "\t" << ogr.vize << "\t   " << ogr.kisaSinav1 << "\t\t" << ogr.kisaSinav2 << "\t\t" << ogr.odev1 << "\t\t" <<
		ogr.odev2 << "\t\t" << ogr.proje << "\t\t" << ogr.finalSinavi << "\t| " << ogr.yilIci << "\t|  " << ogr.basariNotu;

}
//1.seçenek için şablona uygun şekilde listeleme yapan fonksiyon.

void yazdir(ogrenci ogr[])
{
	cout << "İSİM  SOYİSİM\n" << endl;
	for (int i = 0; i < 100; i++)
	{
		cout << ogr[i].adi << "\t" << ogr[i].soyadi << endl;
	}
}
//2.seçenek için listeleme yapan fonksiyon.

bool notKontrol(int puan)
{
	for (;;) {
		if (puan < 0 || puan>100)
		{
			cout << "Geçersiz not..! Lütfen tekrar giriniz.";
			cin >> puan;

		}
		else if (puan >= 0 && puan <= 100)
			return 1;
	}


}
//manuel olarak girilen notların doğruluğunu kontrol eden fonksiyon(2.seçenek için kullanıldı)

float sinifOrtalama(ogrenci sinif[])
{
	float toplam = 0;
	float ortalama = 0;
	for (int i = 0; i < 100; i++)
	{
		toplam = toplam + sinif[i].basariNotu;
	}
	ortalama = toplam / 100;
	return ortalama;
}
//sınıf ortalamasını hesaplayan fonksiyon

void listeleAralik(ogrenci ogr[], int enDusuk, int enBuyuk)
{

	cout << "İSİM  SOYİSİM\n" << endl;
	for (int i = 0; i < 100; i++)
	{
		if(ogr[i].basariNotu > enDusuk && ogr[i].basariNotu<enBuyuk)
		cout << ogr[i].adi << "\t" << ogr[i].soyadi <<"\t" << ogr[i].basariNotu << endl;
	}

}
//kullanıcının girdiği iki değer arasındaki notları yazdıran fonksiyon

void listeleYuksek(ogrenci ogr[], int altSinir)
{

	cout << "İSİM  SOYİSİM\n" << endl;
	for (int i = 0; i < 100; i++)
	{
		if (ogr[i].basariNotu > altSinir)
			cout << ogr[i].adi << "\t" << ogr[i].soyadi << "\t" << ogr[i].basariNotu << endl;
	}

}
//kullanıcının girdiği değerden yüksek olan notları yazdıran fonksiyon

void listeleDusuk(ogrenci ogr[], int ustSinir)
{

	cout << "İSİM  SOYİSİM\n" << endl;
	for (int i = 0; i < 100; i++)
	{
		if (ogr[i].basariNotu < ustSinir)
			cout << ogr[i].adi << "\t" << ogr[i].soyadi << "\t" << ogr[i].basariNotu << endl;
	}

}
//kullanıcının girdiği değerden düşük olan notları yazdıran fonksiyon

float standartSapma(ogrenci sinif[])
{
	float bol = 1;
	float karesi = 1;
	float toplam = 0;
	for (int i = 0; i < 100; i++)
	{
		float kareleriniAlTopla = sinif[i].basariNotu - sinifOrtalama(sinif);
		float karesi = kareleriniAlTopla * kareleriniAlTopla;
		toplam += karesi;
		bol = toplam / 99;
	}


	float sonuc = sqrt(bol);
	return sonuc;
}
//standat sapmayı hesaplayan fonksiyon

float enBuyukNot(ogrenci sinif[])
{
	float enYuksek = 0;

	for (int i = 0; i < 100; i++)
	{
		if (enYuksek < sinif[i].basariNotu)
		{
			enYuksek = sinif[i].basariNotu;
		}
	}
	return enYuksek;

}
//listedeki en büyük notu hesaplayan fonksiyon

float enKucukNot(ogrenci sinif[])
{
	float enDusuk = 100;

	for (int i = 0; i < 100; i++)
	{
		if (enDusuk > sinif[i].basariNotu)
		{
			enDusuk = sinif[i].basariNotu;
		}
	}
	return enDusuk;

}
//listedeki en küçük notu hesaplayan fonksiyon



int main()
{
	setlocale(LC_ALL, "Turkish");
	srand(time(0));

	string adlar[30] = { "Ahmet","Safa","Hüdanur","Berk","Seda","Baran","İrem","Pınar","Polat","Elif","Samet","Beyza","Nazlı","Onur","Sıla","Oğuzhan","Melike","Anıl",
	"Alper","Meryem","Sadık","Sultan","Enes","Ayşe","Mehmet","Zeynep","Rojin","Cüneyt","Özcan","Meral" };

	string soyadlar[30] = { "Fidan","Kaya","Ergin","Karan","Sert","Bayrak","Soya","Kaşık","Yavaş","Kaldı","Akbey","Karataş","Ateş","Manço","Karaca",
	"Koray","İnan","Gürses","Genç","Çalık","Buz","Duman","Çetin","Orge","Canbek","Yolcu","Ilıcalı","Koç","Sabancı","Zorlu" };

	ogrenci ogr;
	int rastgele = 0;
	ogrenci sinif[100];

	char secenek;//listenin oluşturulma şeklini düzenleyen seçenek(otomatik mi manuel mi?)
	char secenek2;//çeşitli fonksiyonları uygulayabileceğimiz seçenekler

	cout << "Hangi seçeneği gerçekleştirmek istiyorsunuz?\nListenin Otomatik Yazdırılması İçin 1,Listeyi Elle Doldurmak İçin 2 Yazınız.\nSeçenek:";
	cin >> secenek;

	switch (secenek)
	{
	case'1':
		cout << "AD\t" << "SOYAD\t\t" << "VİZE\t" << "K.SINAV 1   " << "K.SINAV 2\t  " << "    ODEV 1\t\t" << "ODEV 2\t\t" << "PROJE\t" << "\tFİNAL" << "\t YIL İÇİ" << "  BAŞARI NOTU   " << "HARF NOTU" << endl;
		cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;

		for (int i = 0; i < 100; i++)//100 kişi yazdırabilmek için i'yi 100'e kadar artırdık.
		{
			ogr.adi = adlar[rand() % 30];//30 isim arasından 100 tane rastgele isim seçer.
			ogr.soyadi = soyadlar[rand() % 30];//30 soyisim arasından 100 tane rastgele soyisim seçer.

			if (i < 10)//yüzde 10'un notunun 0-40 arasında olmasını sağlar.
			{
				ogr.vize = rand() % 40;
				ogr.kisaSinav1 = rand() % 40;
				ogr.kisaSinav2 = rand() % 40;
				ogr.odev1 = rand() % 40;
				ogr.odev2 = rand() % 40;
				ogr.proje = rand() % 40;
				ogr.finalSinavi = rand() % 40;
			}

			else if (i >= 10 && i < 60)//yüzde 50'nin notunun 40-70 arasında olmasını sağlar.
			{
				ogr.vize = rand() % (70 - 41) + 40;
				ogr.kisaSinav1 = rand() % (70 - 41) + 40;
				ogr.kisaSinav2 = rand() % (70 - 41) + 40;
				ogr.odev1 = rand() % (70 - 41) + 40;
				ogr.odev2 = rand() % (70 - 41) + 40;
				ogr.proje = rand() % (70 - 41) + 40;
				ogr.finalSinavi = rand() % (70 - 41) + 40;
			}

			else if (i >= 60 && i < 75)//yüzde 15'in notunun 70-80 arasında olmasını sağlar.
			{
				ogr.vize = rand() % (80 - 71) + 70;
				ogr.kisaSinav1 = rand() % (80 - 71) + 70;
				ogr.kisaSinav2 = rand() % (80 - 71) + 70;
				ogr.odev1 = rand() % (80 - 71) + 70;
				ogr.odev2 = rand() % (80 - 71) + 70;
				ogr.proje = rand() % (80 - 71) + 70;
				ogr.finalSinavi = rand() % (80 - 71) + 70;
			}


			else if (i >= 75 && i < 100)//yüzde 25'in notunun 80-100 arasında olmasını sağlar
			{
				ogr.vize = rand() % (100 - 81) + 80;
				ogr.kisaSinav1 = rand() % (100 - 81) + 80;
				ogr.kisaSinav2 = rand() % (80 - 71) + 70;
				ogr.odev1 = rand() % (80 - 71) + 70;
				ogr.odev2 = rand() % (80 - 71) + 70;
				ogr.proje = rand() % (80 - 71) + 70;
				ogr.finalSinavi = rand() % (80 - 71) + 70;
			}
				ogr.yilIci = ogr.vize * 0.5 + ogr.kisaSinav1 * 0.07 + ogr.kisaSinav2 * 0.07 + ogr.odev1 * 0.1 + ogr.odev2 * 0.1 + ogr.proje * 0.16;
				ogr.basariNotu = ogr.yilIci * 0.55 + ogr.finalSinavi * 0.45;
				sinif[i] = ogr;//alınan değerleri listeyebilmek sınıf dizisinin içine aktardık.
				listele(sinif[i]); cout << "\t" << harfNotunaCevir(ogr.basariNotu) << endl;
		}
		break;

	case '2':
		
		cout << "SEÇENEK 2:ÖĞRENCİ BİLGİLERİNİ MAUEL GİRİNİZ..\n";

		for (int i = 0; i < 100; i++) // 100 kişi yazdırabilmek için i'yi 100'e kadar artırdık.
		{
			cout << i + 1 << ".Öğrenci Adı:"; cin >> ogr.adi;
			cout << i + 1 << ".Öğrenci Soyadı:"; cin >> ogr.soyadi;
			cout << i + 1 << ".Öğrenci Vize:"; cin >> ogr.vize; notKontrol(ogr.vize);
			cout << i + 1 << ".Öğrenci Kısa Sınav 1:"; cin >> ogr.kisaSinav1; notKontrol(ogr.kisaSinav1);
			cout << i + 1 << ".Öğrenci Kısa Sınav 2:"; cin >> ogr.kisaSinav2; notKontrol(ogr.kisaSinav2);
			cout << i + 1 << ".Öğrenci Ödev 1:"; cin >> ogr.odev1; notKontrol(ogr.odev1);
			cout << i + 1 << ".Öğrenci Ödev 2:"; cin >> ogr.odev2; notKontrol(ogr.odev2);
			cout << i + 1 << ".Öğrenci Proje:"; cin >> ogr.proje; notKontrol(ogr.proje);
			cout << i + 1 << ".Öğrenci Final:"; cin >> ogr.finalSinavi; notKontrol(ogr.finalSinavi);
			cout << endl;
			ogr.yilIci = ogr.vize * 0.5 + ogr.kisaSinav1 * 0.07 + ogr.kisaSinav2 * 0.07 + ogr.odev1 * 0.1 + ogr.odev2 * 0.1 + ogr.proje * 0.16;
			ogr.basariNotu = ogr.yilIci * 0.55 + ogr.finalSinavi * 0.45;
			sinif[i] = ogr;
		}
		break;
	}
		
	for (;;)//işlemleri tekrar yapabilmek için sonsuz döngü kullandım. 
	{
		cout << "\n\nHangi İşlemi Yapmak İstiyorsunuz?\n";
		cout << "Sınıf Listesi İçin 1'e Basınız.\nEn Büyük Ortalama İçin 2'ye Basınız.\nEn Küçük Ortalama İçin 3'e Basınız.\nSınıf Ortalaması İçin 4'e Basınız.\nStandart Sapma İçin 5'e Basını\n";
		cout << "Belirli Bir Aralıkta Olanlar Listelensin İstiyorsanız 6'ya Basınız.\nGirdiğiniz Nottan Düşük Notları Görmek İstiyorsanız 7'ye Basınız.\nGirdiğiniz Nottan Yüksek Notları Görmek İstiyorsanız 8'e Basınız.\n\n";
		
		cin >> secenek2; cout << endl;

		switch (secenek2)//yazdığımız fonksiyonları kullandığımız bölüm
		{
		case '1':
			yazdir(sinif);
			break;

		case '2':
			cout << enBuyukNot(sinif);
			break;

		case'3':
			cout << enKucukNot(sinif);
			break;

		case '4':
			cout << sinifOrtalama(sinif);
			break;

		case '5':
			cout << standartSapma(sinif);
			break;

		case '6':
			int dusukNot, yuksekNot,gecici;
			cout << "Hangi aralıktaki notları görmek istiyorsunuz? Sırasıyla yazınız.\n";
			cin >> dusukNot; 
			cin>>yuksekNot;
			if (dusukNot > yuksekNot)
			{
				gecici = yuksekNot;
				yuksekNot = dusukNot;
				dusukNot = gecici;
				listeleAralik(sinif, dusukNot, yuksekNot);
			}

			else
			{
				listeleAralik(sinif, dusukNot, yuksekNot);
			}
			break;

		case '7':
			int ustSinir;
			cout << "Hangi nottan düşük notları görmek istiyorsunuz? ";		
			cin >> ustSinir;
			listeleDusuk(sinif, ustSinir);	
			break;

		case '8':
			int altSinir;
			cout << "Hangi nottan yuksek notları görmek istiyorsunuz? ";
			cin >> altSinir;
			listeleYuksek(sinif, altSinir);
			break;

		
		}
	
	}
	
}
