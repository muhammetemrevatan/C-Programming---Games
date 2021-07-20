#include <stdio.h>
#include <conio.h>
#include <stdlib.h> //exit komutu için eklendi.

int matrix[3][3]; // 3 e 3 lük bir dizi oluþturuldu.

void playground_reset()// oyun alanýný sýfýrlamak, tazelemek ve oluþturmak için method.
{
	int row,column; // satýr ve sütün için yazýlan deðiþkenler
	for(row=0; row<=2; row++) // satýr sayýsý için döngü
	{
		for(column=0; column<=2; column++) // sütün sayýsý için döngü
		{
			matrix[row][column] = 0; // tüm satýr ve sütünlarýn içine '0' degeri atandý.
		}
	}
}

void playground_run()//oyun alaný ekrana yazdýrma methodu.
{
	int row,column; // satýr ve sütün için degisken olusturuldu
	char a = '-'; // boþ olan bloklara '-' koymak için a degiskeni olusturuldu
	char b = 'X'; // X yazmak için b degiskeni oluþuruldu.
	char c = 'O'; // O yazmak için c degiskeni oluþturuldu.
	printf("\n**********\n"); // daha düzgün bir görünüm için yýldýzlar eklendi.
	printf("OYUN ALANI\n"); // kullanýcýya bilgi vermek için oyun alaný yazýsý eklendii.
	
	for(row=0; row<=2; row++) // ekrana x - o yazmak için çok boyutlu dizi içerisinde geziniyoruz.
	{
		for(column=0; column<=2; column++) // ekrana x - o yazmak için çok boyutlu dizi içerisinde geziniyoruz.
		{
			if(matrix[row][column] == 0) // eger belitilen blok 0 a eþitse
			printf(" %c ",a); // ekrana a yani '-' yaz
			else if(matrix[row][column] == 1) // eger belirtilen blok 1 e eþitse
			printf(" %c ",b); // ekrana  b yani 'X' yaz
			else if(matrix[row][column] == 2) // eger belirtilen blok 2 ye eþitse
			printf(" %c ",c); // ekrana c yani 'O' yaz
			else // geriye kalan tüm koþullar için else blogundaki iþlemler yapýlacaktýr.
			continue;// else koþulu sagladýgýnda programa sonraki hiçbir iþlem yapma programa sonraki adýmdan devam et..
			
		}
		printf("\n");// bir alt satýra geçmek için kullandýk.
	}
	
	printf("**********\n");// daha güzel bir görünüm için...
}

int which_user_add() // hangi kullanýcý oyuna baþlayacagýný belirlemek için yazýlan fonksiyon..
{
	int player; // tamsayý türünde bir degisken olusturuldu
	do{ // do while döngüsü komutlarý 1 kez kesin olarak çalýstýrýr ve ardýndan kosul saglandýgý sürüce tekrar çalýþtýrmaya devam eder.
		printf("Hangi oyuncu oyuna basliyacak? ?(1-  2) : "); // kullanýcýya hangi oyuncu ile baslamak istedigini sorduk..
		scanf("%d",&player); // kullanýcýnýn girdiði bilgiyi player isimli degiskenimize atadýk.
	}while(player != 1 && player != 2); //player isimli degiskenin sadece 1 veya 2 degerini almasýný istedigim için koþul olarak bunu ekledik. yani girilen deger 1 veya 2 ye eþit degilse tekrar döngüye girdik.
	return player; // player isimli degiskeni deger olarak döndürdük.
}

int where_user_add(int a) // kullanýcýnýn nereye ekleme yapýcagýný soran method. ayný zamanda hangi kullanýcýlarýn sýra sýra ekleme yapabilmesini saðlar.
{
	int x=1,y=2; // degerleri 1 ve 2 olan x ve y adýnda 2 degisken olusturduk.
	int row,column; // satýr ve sutunlara deger atayabilmek için 2 adet degisken olusturduk.
	
	if(a % 2 == 1) // eger a nýn 2 ile bölümünden kalan 1 se yani sayý çift degilse yani sayý tek ise bu iþlemleri yap
	{
		printf("%d. Kullanici nereye ekleyecek ? : ",x); // user'a soru sorduk..
		scanf("%d %d",&row,&column); // Kullanýcýnýn girdigi degerleri aldýk.
	}
	else if(a % 2 == 0) // çift ise burayý yap
	{
		printf("%d. Kullanici nereye ekleyecek ? : ",y); // user'a soru sorduk..
		scanf("%d %d",&row,&column); // Kullanýcýnýn girdigi degerleri aldýk.
	}
	
	if(a % 2 == 1 && matrix[row][column] == 0) // girilen sayý tek ise ve belirlenen sütün 0 a eþit ise yani boþ ise
	{
		matrix[row][column] = 1; // girilen sütünü 1 e eþitle
	}
	else if(a % 2 == 0 && matrix[row][column] == 0) // girilen sayý çift ise ve o sütün 0 a eþit ise yani boþ ise
	{
		matrix[row][column] = 2; // girilen sütünü 2 ye eþitle
	}
	else // geri kalan tüm koþullar için bý blogu yap
	{
		printf("\nAlan dolu lutfen baska bir alan seciniz.\n"); // ekrana bu bilgileri yaz.
	}	
}

int control_playground() // martis içindeki alanlarýn dolu mu boþ mu oldugunu öðrenmek için yazýlmýþ fonksiyon eðer alan boþ ise "0" dolu ise "1" deðerini return ediyor.
{
	int row,column,control; // kontrol etmek için satýr ve sütun tanýmladýk ayrýca geri döndüreceðimiz deðeri atamak için bir kontrol isminde bir deðiþken tanýmladýk.
	
	for(row=0; row<=2; row++) // satýr için döngü
	{
		for(column=0; column<=2; column++) // sütun için döngü
		{
			control = matrix[row][column]; // kontrol isimli deðiþkene matrisin degerleri tek tek atanýyor.
			if(control == 0) // kontrol isimli deðiþkenin deðeri "0" a eþit ise 
			{
				return 0; //"0" deðeri return ediliyor.
				break; // ve koþuldan çýkýlýyor. NOT: GEREKSÝZ BÝR SATIR SANIRSAM..
			}
		}
	}
	return 1; // kontrol deðerinin "0" a eþit olmadýðý durumlarda "1" degeri dönüyor.
}

int who_winner() // who won -- kimin kazandýðýný bulmak için oluþturduðum fonksiyon.. // Not:fonksiyon isimlerine takýlmayýnýz kendimi ingilizce yazmak için zorluyorum. :)
{
	int i; // i isminde bir deðiþken tanýmladýk
	for(i=0; i<=2; i++) // matrisi satýr ve sütün olarak kontrol etmek için 0 dan 2 ye kadar deðer alan bir döngü oluþturduk.
	{
		if(matrix[i][0] == 1 && matrix[i][1] == 1 && matrix[i][2] == 1) // 0. satýr için kazanma koþulu oluþturduk eðer bu koþul saðlanýyorsa.
		{
			printf("\n\nKazanan 1. Oyuncu.."); // ekrana yazdýrdýk.
			getch(); // ekranda bir süre bekledik ve herhanbir tuþa basýlýnca
			exit(1); // programý sonlandýrdýk.
		}
		else if(matrix[i][0] == 2 && matrix[i][1] == 2 && matrix[i][2] == 2)// 0. satýr için kazanma koþulu oluþturduk eðer bu koþul saðlanýyorsa.
		{
			printf("\n\nKazanan 2. Oyuncu.."); // ekrana yazdýrdýk.
			getch(); // ekranda bir süre bekledik ve herhanbir tuþa basýlýnca
			exit(1); // programý sonlandýrdýk.
		}
		else if(matrix[0][i] == 1 && matrix[1][i] == 1 && matrix[2][i] == 1)// burda bug
		{
			printf("\n\nKazanan 1. Oyuncu.."); // ekrana yazdýrdýk.
			getch(); // ekranda bir süre bekledik ve herhanbir tuþa basýlýnca
			exit(1); // programý sonlandýrdýk.
		}
		else if(matrix[0][i] == 2 && matrix[1][i] == 2 && matrix[2][i] == 2)
		{
			printf("\n\nKazanan 2. Oyuncu.."); // ekrana yazdýrdýk.
			getch(); // ekranda bir süre bekledik ve herhanbir tuþa basýlýnca
			exit(1); // programý sonlandýrdýk.
		}
		else if(matrix[0][0] == 1 && matrix[1][1] == 1 && matrix[2][2] == 1)
		{
			printf("\n\nKazanan 1. Oyuncu"); // ekrana yazdýrdýk.
			getch(); // ekranda bir süre bekledik ve herhanbir tuþa basýlýnca
			exit(1); // programý sonlandýrdýk.
		}
		else if(matrix[0][0] == 2 && matrix[1][1] == 2 && matrix[2][2] == 2)
		{
			printf("\n\nKazanan 2. Oyuncu"); // ekrana yazdýrdýk.
			getch(); // ekranda bir süre bekledik ve herhanbir tuþa basýlýnca
			exit(1); // programý sonlandýrdýk.
		}
		else if(matrix[0][2] == 1 && matrix[1][1] == 1 && matrix[2][0] == 1)
		{
			printf("\n\nKazanan 1. Oyuncu"); // ekrana yazdýrdýk.
			getch(); // ekranda bir süre bekledik ve herhanbir tuþa basýlýnca
			exit(1); // programý sonlandýrdýk.
		}
		else if(matrix[0][2] == 2 && matrix[1][1] == 2 && matrix[2][0] == 2)
		{
			printf("\n\nKazanan 2. Oyuncu"); // ekrana yazdýrdýk.
			getch(); // ekranda bir süre bekledik ve herhanbir tuþa basýlýnca
			exit(1); // programý sonlandýrdýk.
		}
		else // diðer koþulu saðlanyan durumlar için bu bloktaki iþlemleri yap anlamýnda... fakat biz tüm koþullarý kontrol ettiðimiz için
		// burasý gereksiz yani yazmamýza gerek yok fakat ben yinede yazmak istedim.
		{
			continue; // kodlarý okumaya kaldýðýn yerden devam et anlamýnda... editör bu kýsmý atlayýp kodlarý okumaya devam eder..
		}
	}
	
}

int main() // Kodlarýmýzýn çalýþtýðý main bloðumuz..
{
	playground_reset(); // oyunu alanýný oluþturmak veya sýfýrlamak için oluþturduðumuz fonksiyonu çaðýrýyruz..
	printf("1. Oyuncu : X \n2. Oyuncu : O\n\n"); // Kullanýcýya gerekli bilgileri veriyoruz.. 1. oyuncunun "x" 2. oyuncunun 'o' oldugunu belirttik.
	printf("Kurallar..\n-Oyuna secim yaptiginiz oyuncu baslar.\n-Oyuncular sira sira ekleme yapar.\n-Capraz, satir veya sutun olarak 3 tane 'X' yan yana gelirse oyunu 1. kullanici kazanir.\n-Capraz, satir veya sutun olarak 3 tane 'O' yan yana gelirse oyunu 2. kullanici kazanir.\n-Dolu bir alana ekleme yaparsaniz sira diger oyuncuya gecer.\n");
	printf("-Oyuna baslayan kullanici 5 adet ekleme yapabilir.\n-Oyuna ikinci baslayan kullanici 4 adet ekleme yapabilir.\n");
	printf("-Eger oyuna baslayan kullanici hatali ekleme yaparsa ve sira diger kullaniciya gecerse eklemeleri gereken adet degisecegi icin kural ihlalinden oyunu hata yapmayan kullanici kazanir.\n\n");
	//yukarýdaki printf'lerde kullanýcýya oyun kurallarýný anlatýp gerekli bilgileri verdik..
	
	playground_run(); // oyun alanýný konrtol edip 0 ,1 ve 2 leri "-", "x" ve "o" ile deðiþtirdik. þuan hepsini "-" yaptýk. çünkü baslangýcta her blok "0" idi.
	
	int a = which_user_add(); // hangi kullanýcýnýn oyuna baþlayacaðýný öðrenip bunu "a" isimli bir deðiþkende tuttuk.
	
	while(control_playground() == 0) // burada yapmak isteðimiz þey tüm bloklarý tek tek kontrol ediyor ve hala "0" a eþit olan bir blok varsa döngümüz devam ediyor.
	{
		where_user_add(a); // hangi kullanýcýnýn nereye ekleme yapacaðýný soruyoruz.. ve belirtilen yere kullanýcýnýn deðerini atýyoruz. (x veya o)
	
		playground_run(); // kullanýcý her seferinde nereye ekleme yapabildiðini görsün diye oyun alanýný ekrana yazdýrýyoruz..
		
		who_winner();  // kullanýcýlar ekleme yaptýktan sonra eðer bir blokta kazanan varsa belirleyip oyunu bitiriyoruz..
		a++; // oyuna bir sonraki kullanýcýnýn devam edebilmesi için a deðerini bir arttýrdýk.
	}
	
	printf("\n\nKazanan Yok :)\n"); // yukarýdaki fonksiyonlar sadece kazanan'ý belirlemek için yazýlmýþtýr. Eðer bir kazanan yoksa döngüden çýkýp kazananýn olmadýðý bilgisini verdik.
}
