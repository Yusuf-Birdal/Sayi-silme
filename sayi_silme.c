#include <stdio.h>
#include <stdlib.h>
#include <time.h>// time fonskyonunu barındırır

void silici(int f_adet, int dizi[]) // Parametreler fonksiyon icinde yeniden isimlendirilir 
{
  int sil_sayac = 0; // Listenin basimi sirasinda dongunun dogru calismasi icin silinen sayilarin adedi kaydedilmelidir 
  char secim;
  do // do while dongusunun basi
  {
    printf("\nSilmek istediginiz degerin kendisini mi sirasini mi kullanacaksiniz\n(S)ira \\ (D)eger\n");
    scanf(" %c", &secim);
    if (secim == 'S' || secim == 's')
    {
      int sira;
      printf("Kacinci eleman silinsin : ");
      scanf("%d", &sira);
      /* Silme islemi sayinin sirasi ile yapilirken secilen sayidan bir sonraki sayi, secilen sayinin uzerine yazilir.
      Bu durumda secilen indexten sonraki index listede iki kere bulunur. Bunun cozumu secim degerini bir arttirarak
      dizinin sonuna kadar gelmektir. N elemanli bir dizide en son N-1. eleman N. elemanin degerini alir ve 
      dizinin son halinin N-1 elemani anlamlidir, kalani basilmaz.
      */
      for (int i = sira - 1; i < f_adet - 1; i++)
      {
        dizi[i] = dizi[i + 1];
      }
      sil_sayac++; // Silinen sayi degeri arttirilir
    }
    else if (secim == 'D' || secim == 'd')
    {
      int deger;
      printf("Hangi deger silinsin : ");
      scanf("%d", &deger);
      /* Silme islemi sayinin degerine gore yapilacaksa dizi basindan sonuna kadar tum degerler
      secilen degere esit mi diye bakilir. Esit olan index bulundugunda bulunan degerin sirasi ile
      ustte anlatilan algoritmanin aynisi uygulanir.
      */
      for (int i = 0; i < f_adet - 1; i++)
      {
        if (deger == dizi[i])
        {
          for (int j = i; j < f_adet - 1; j++)
          {
            dizi[j] = dizi[j + 1];
          }
          sil_sayac++;  // Silinen sayi degeri arttirilir

          i--; // Silinmek istenen deger arka arkaya birden fazla kez dizide bulunuyor olabilir.
               // Silme isleminden sonra i bir azaltilarak silinen sayinin yerine gelen sayi da kontrol edilir.
        }
      }
    }
    else
    {
      printf("Hatali giris yaptiniz !!\nTekrar deneyiniz\n"); // Secim yanlissa bunu kullaniciya bildirecek else blogu
    }

  } while (!(secim == 'S' || secim == 's' || secim == 'D' || secim == 'd')); // do while dongusunun sonu
  // Secimin S, s, D ve d karakterlerinden biriyle sonuclandigina emin olur, aksi halde dongu bitmez 

  for (int i = 0; i < f_adet - sil_sayac; i++) // Dizinin son hali silinen her sayi icin 
  // sondan bir elemani gormezden gelerek basilir 
  {
    printf("%d. sayi : %d\n", i + 1, dizi[i]);
  }
}

int main()
{

  srand(time(0));     // Random fonksiyonunun ciktisini zamana bagli kilar 
  int adet, limit;
  printf("Ust limit kac olsun : ");
  scanf("%d", &limit);
  printf("Kac sayi girilsin : ");
  scanf("%d", &adet);
  int rastgelesayi[adet];    // Rastgele sayilari tutacak dizi 
  for (int i = 0; i < adet; i++)    // Sayi adedi kadar donecek bir for acilir
  {
    rastgelesayi[i] = rand() % (limit + 1);
    // Random fonksiyonunun ciktisi "% (limit+1)" isleminden gecer ve diziye kaydedilir.
    // Bu sonucun limit+1'e bolunup kalaniyla devam edilmesini saglar, boylece limit degerinden buyuk sayilar kaydedilmez.
    printf("%d. sayi : %d\n", i + 1, rastgelesayi[i]); // Liste basilir.
  }
  silici(adet, rastgelesayi); // Silme fonksiyonu cagrilir.

  return 0; // Program sonlandirilir. 
}