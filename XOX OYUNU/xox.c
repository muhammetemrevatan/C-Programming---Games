#include <stdio.h>
#include <conio.h>
#include <stdlib.h> //exit komutu i�in eklendi.

int matrix[3][3]; // 3 e 3 l�k bir dizi olu�turuldu.

void playground_reset()// oyun alan�n� s�f�rlamak, tazelemek ve olu�turmak i�in method.
{
	int row,column; // sat�r ve s�t�n i�in yaz�lan de�i�kenler
	for(row=0; row<=2; row++) // sat�r say�s� i�in d�ng�
	{
		for(column=0; column<=2; column++) // s�t�n say�s� i�in d�ng�
		{
			matrix[row][column] = 0; // t�m sat�r ve s�t�nlar�n i�ine '0' degeri atand�.
		}
	}
}

void playground_run()//oyun alan� ekrana yazd�rma methodu.
{
	int row,column; // sat�r ve s�t�n i�in degisken olusturuldu
	char a = '-'; // bo� olan bloklara '-' koymak i�in a degiskeni olusturuldu
	char b = 'X'; // X yazmak i�in b degiskeni olu�uruldu.
	char c = 'O'; // O yazmak i�in c degiskeni olu�turuldu.
	printf("\n**********\n"); // daha d�zg�n bir g�r�n�m i�in y�ld�zlar eklendi.
	printf("OYUN ALANI\n"); // kullan�c�ya bilgi vermek i�in oyun alan� yaz�s� eklendii.
	
	for(row=0; row<=2; row++) // ekrana x - o yazmak i�in �ok boyutlu dizi i�erisinde geziniyoruz.
	{
		for(column=0; column<=2; column++) // ekrana x - o yazmak i�in �ok boyutlu dizi i�erisinde geziniyoruz.
		{
			if(matrix[row][column] == 0) // eger belitilen blok 0 a e�itse
			printf(" %c ",a); // ekrana a yani '-' yaz
			else if(matrix[row][column] == 1) // eger belirtilen blok 1 e e�itse
			printf(" %c ",b); // ekrana  b yani 'X' yaz
			else if(matrix[row][column] == 2) // eger belirtilen blok 2 ye e�itse
			printf(" %c ",c); // ekrana c yani 'O' yaz
			else // geriye kalan t�m ko�ullar i�in else blogundaki i�lemler yap�lacakt�r.
			continue;// else ko�ulu saglad�g�nda programa sonraki hi�bir i�lem yapma programa sonraki ad�mdan devam et..
			
		}
		printf("\n");// bir alt sat�ra ge�mek i�in kulland�k.
	}
	
	printf("**********\n");// daha g�zel bir g�r�n�m i�in...
}

int which_user_add() // hangi kullan�c� oyuna ba�layacag�n� belirlemek i�in yaz�lan fonksiyon..
{
	int player; // tamsay� t�r�nde bir degisken olusturuldu
	do{ // do while d�ng�s� komutlar� 1 kez kesin olarak �al�st�r�r ve ard�ndan kosul sagland�g� s�r�ce tekrar �al��t�rmaya devam eder.
		printf("Hangi oyuncu oyuna basliyacak? ?(1-  2) : "); // kullan�c�ya hangi oyuncu ile baslamak istedigini sorduk..
		scanf("%d",&player); // kullan�c�n�n girdi�i bilgiyi player isimli degiskenimize atad�k.
	}while(player != 1 && player != 2); //player isimli degiskenin sadece 1 veya 2 degerini almas�n� istedigim i�in ko�ul olarak bunu ekledik. yani girilen deger 1 veya 2 ye e�it degilse tekrar d�ng�ye girdik.
	return player; // player isimli degiskeni deger olarak d�nd�rd�k.
}

int where_user_add(int a) // kullan�c�n�n nereye ekleme yap�cag�n� soran method. ayn� zamanda hangi kullan�c�lar�n s�ra s�ra ekleme yapabilmesini sa�lar.
{
	int x=1,y=2; // degerleri 1 ve 2 olan x ve y ad�nda 2 degisken olusturduk.
	int row,column; // sat�r ve sutunlara deger atayabilmek i�in 2 adet degisken olusturduk.
	
	if(a % 2 == 1) // eger a n�n 2 ile b�l�m�nden kalan 1 se yani say� �ift degilse yani say� tek ise bu i�lemleri yap
	{
		printf("%d. Kullanici nereye ekleyecek ? : ",x); // user'a soru sorduk..
		scanf("%d %d",&row,&column); // Kullan�c�n�n girdigi degerleri ald�k.
	}
	else if(a % 2 == 0) // �ift ise buray� yap
	{
		printf("%d. Kullanici nereye ekleyecek ? : ",y); // user'a soru sorduk..
		scanf("%d %d",&row,&column); // Kullan�c�n�n girdigi degerleri ald�k.
	}
	
	if(a % 2 == 1 && matrix[row][column] == 0) // girilen say� tek ise ve belirlenen s�t�n 0 a e�it ise yani bo� ise
	{
		matrix[row][column] = 1; // girilen s�t�n� 1 e e�itle
	}
	else if(a % 2 == 0 && matrix[row][column] == 0) // girilen say� �ift ise ve o s�t�n 0 a e�it ise yani bo� ise
	{
		matrix[row][column] = 2; // girilen s�t�n� 2 ye e�itle
	}
	else // geri kalan t�m ko�ullar i�in b� blogu yap
	{
		printf("\nAlan dolu lutfen baska bir alan seciniz.\n"); // ekrana bu bilgileri yaz.
	}	
}

int control_playground() // martis i�indeki alanlar�n dolu mu bo� mu oldugunu ��renmek i�in yaz�lm�� fonksiyon e�er alan bo� ise "0" dolu ise "1" de�erini return ediyor.
{
	int row,column,control; // kontrol etmek i�in sat�r ve s�tun tan�mlad�k ayr�ca geri d�nd�rece�imiz de�eri atamak i�in bir kontrol isminde bir de�i�ken tan�mlad�k.
	
	for(row=0; row<=2; row++) // sat�r i�in d�ng�
	{
		for(column=0; column<=2; column++) // s�tun i�in d�ng�
		{
			control = matrix[row][column]; // kontrol isimli de�i�kene matrisin degerleri tek tek atan�yor.
			if(control == 0) // kontrol isimli de�i�kenin de�eri "0" a e�it ise 
			{
				return 0; //"0" de�eri return ediliyor.
				break; // ve ko�uldan ��k�l�yor. NOT: GEREKS�Z B�R SATIR SANIRSAM..
			}
		}
	}
	return 1; // kontrol de�erinin "0" a e�it olmad��� durumlarda "1" degeri d�n�yor.
}

int who_winner() // who won -- kimin kazand���n� bulmak i�in olu�turdu�um fonksiyon.. // Not:fonksiyon isimlerine tak�lmay�n�z kendimi ingilizce yazmak i�in zorluyorum. :)
{
	int i; // i isminde bir de�i�ken tan�mlad�k
	for(i=0; i<=2; i++) // matrisi sat�r ve s�t�n olarak kontrol etmek i�in 0 dan 2 ye kadar de�er alan bir d�ng� olu�turduk.
	{
		if(matrix[i][0] == 1 && matrix[i][1] == 1 && matrix[i][2] == 1) // 0. sat�r i�in kazanma ko�ulu olu�turduk e�er bu ko�ul sa�lan�yorsa.
		{
			printf("\n\nKazanan 1. Oyuncu.."); // ekrana yazd�rd�k.
			getch(); // ekranda bir s�re bekledik ve herhanbir tu�a bas�l�nca
			exit(1); // program� sonland�rd�k.
		}
		else if(matrix[i][0] == 2 && matrix[i][1] == 2 && matrix[i][2] == 2)// 0. sat�r i�in kazanma ko�ulu olu�turduk e�er bu ko�ul sa�lan�yorsa.
		{
			printf("\n\nKazanan 2. Oyuncu.."); // ekrana yazd�rd�k.
			getch(); // ekranda bir s�re bekledik ve herhanbir tu�a bas�l�nca
			exit(1); // program� sonland�rd�k.
		}
		else if(matrix[0][i] == 1 && matrix[1][i] == 1 && matrix[2][i] == 1)// burda bug
		{
			printf("\n\nKazanan 1. Oyuncu.."); // ekrana yazd�rd�k.
			getch(); // ekranda bir s�re bekledik ve herhanbir tu�a bas�l�nca
			exit(1); // program� sonland�rd�k.
		}
		else if(matrix[0][i] == 2 && matrix[1][i] == 2 && matrix[2][i] == 2)
		{
			printf("\n\nKazanan 2. Oyuncu.."); // ekrana yazd�rd�k.
			getch(); // ekranda bir s�re bekledik ve herhanbir tu�a bas�l�nca
			exit(1); // program� sonland�rd�k.
		}
		else if(matrix[0][0] == 1 && matrix[1][1] == 1 && matrix[2][2] == 1)
		{
			printf("\n\nKazanan 1. Oyuncu"); // ekrana yazd�rd�k.
			getch(); // ekranda bir s�re bekledik ve herhanbir tu�a bas�l�nca
			exit(1); // program� sonland�rd�k.
		}
		else if(matrix[0][0] == 2 && matrix[1][1] == 2 && matrix[2][2] == 2)
		{
			printf("\n\nKazanan 2. Oyuncu"); // ekrana yazd�rd�k.
			getch(); // ekranda bir s�re bekledik ve herhanbir tu�a bas�l�nca
			exit(1); // program� sonland�rd�k.
		}
		else if(matrix[0][2] == 1 && matrix[1][1] == 1 && matrix[2][0] == 1)
		{
			printf("\n\nKazanan 1. Oyuncu"); // ekrana yazd�rd�k.
			getch(); // ekranda bir s�re bekledik ve herhanbir tu�a bas�l�nca
			exit(1); // program� sonland�rd�k.
		}
		else if(matrix[0][2] == 2 && matrix[1][1] == 2 && matrix[2][0] == 2)
		{
			printf("\n\nKazanan 2. Oyuncu"); // ekrana yazd�rd�k.
			getch(); // ekranda bir s�re bekledik ve herhanbir tu�a bas�l�nca
			exit(1); // program� sonland�rd�k.
		}
		else // di�er ko�ulu sa�lanyan durumlar i�in bu bloktaki i�lemleri yap anlam�nda... fakat biz t�m ko�ullar� kontrol etti�imiz i�in
		// buras� gereksiz yani yazmam�za gerek yok fakat ben yinede yazmak istedim.
		{
			continue; // kodlar� okumaya kald���n yerden devam et anlam�nda... edit�r bu k�sm� atlay�p kodlar� okumaya devam eder..
		}
	}
	
}

int main() // Kodlar�m�z�n �al��t��� main blo�umuz..
{
	playground_reset(); // oyunu alan�n� olu�turmak veya s�f�rlamak i�in olu�turdu�umuz fonksiyonu �a��r�yruz..
	printf("1. Oyuncu : X \n2. Oyuncu : O\n\n"); // Kullan�c�ya gerekli bilgileri veriyoruz.. 1. oyuncunun "x" 2. oyuncunun 'o' oldugunu belirttik.
	printf("Kurallar..\n-Oyuna secim yaptiginiz oyuncu baslar.\n-Oyuncular sira sira ekleme yapar.\n-Capraz, satir veya sutun olarak 3 tane 'X' yan yana gelirse oyunu 1. kullanici kazanir.\n-Capraz, satir veya sutun olarak 3 tane 'O' yan yana gelirse oyunu 2. kullanici kazanir.\n-Dolu bir alana ekleme yaparsaniz sira diger oyuncuya gecer.\n");
	printf("-Oyuna baslayan kullanici 5 adet ekleme yapabilir.\n-Oyuna ikinci baslayan kullanici 4 adet ekleme yapabilir.\n");
	printf("-Eger oyuna baslayan kullanici hatali ekleme yaparsa ve sira diger kullaniciya gecerse eklemeleri gereken adet degisecegi icin kural ihlalinden oyunu hata yapmayan kullanici kazanir.\n\n");
	//yukar�daki printf'lerde kullan�c�ya oyun kurallar�n� anlat�p gerekli bilgileri verdik..
	
	playground_run(); // oyun alan�n� konrtol edip 0 ,1 ve 2 leri "-", "x" ve "o" ile de�i�tirdik. �uan hepsini "-" yapt�k. ��nk� baslang�cta her blok "0" idi.
	
	int a = which_user_add(); // hangi kullan�c�n�n oyuna ba�layaca��n� ��renip bunu "a" isimli bir de�i�kende tuttuk.
	
	while(control_playground() == 0) // burada yapmak iste�imiz �ey t�m bloklar� tek tek kontrol ediyor ve hala "0" a e�it olan bir blok varsa d�ng�m�z devam ediyor.
	{
		where_user_add(a); // hangi kullan�c�n�n nereye ekleme yapaca��n� soruyoruz.. ve belirtilen yere kullan�c�n�n de�erini at�yoruz. (x veya o)
	
		playground_run(); // kullan�c� her seferinde nereye ekleme yapabildi�ini g�rs�n diye oyun alan�n� ekrana yazd�r�yoruz..
		
		who_winner();  // kullan�c�lar ekleme yapt�ktan sonra e�er bir blokta kazanan varsa belirleyip oyunu bitiriyoruz..
		a++; // oyuna bir sonraki kullan�c�n�n devam edebilmesi i�in a de�erini bir artt�rd�k.
	}
	
	printf("\n\nKazanan Yok :)\n"); // yukar�daki fonksiyonlar sadece kazanan'� belirlemek i�in yaz�lm��t�r. E�er bir kazanan yoksa d�ng�den ��k�p kazanan�n olmad��� bilgisini verdik.
}
