#include "Proje1.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* 
* @file Proje1.c
* @description fonksiyonlarım ve fonksiyonların işlevleri. 
* @assignment BP3 1.Proje
* @date 10.12.23 deadline
* @author KEVSER ARSLAN and kevser_arslan@stu.fsm.edu.tr 
*/

Ders dersolustur(char* Ders_Adi,unsigned short int kredi,unsigned short int puan){
   Ders yeniders;
yeniders.Ders_Adi=(char*) malloc ((strlen(Ders_Adi) + 1)*(sizeof(char)));
strcpy(yeniders.Ders_Adi,Ders_Adi); 
yeniders.kredi=kredi;
yeniders.puan=puan;
//free(Ders_Adi);
return yeniders;
}
Ogrenci ogrenciolustur(char* ogrenci_adi, char* ogrenci_soyadi, char* bolumu, float ortalama, Ders* aldigidersler ){
   Ogrenci yeniogrenci;
   yeniogrenci.ogrenci_adi= (char*) malloc ((strlen(ogrenci_adi)+1)*(sizeof(char)));
   strcpy(yeniogrenci.ogrenci_adi,ogrenci_adi);
   yeniogrenci.ogrenci_soyadi= (char*) malloc ((strlen(ogrenci_soyadi)+1)*(sizeof(char)));
   strcpy(yeniogrenci.ogrenci_soyadi,ogrenci_soyadi);
   yeniogrenci.bolumu= (char*) malloc ((strlen(bolumu)+1)*(sizeof(char)));
   strcpy(yeniogrenci.bolumu,bolumu);
   yeniogrenci.ortalama=ortalama;
   yeniogrenci.aldigidersler= (Ders*) malloc(10* sizeof(Ders));
   for(int i=0; i<10;i++){
      yeniogrenci.aldigidersler[i]= aldigidersler[i];
     
   }
   
   return yeniogrenci;

}
void ogrenciyazdir(Ogrenci ogrenci){
   printf("Ogrencinin Adi:%s\n",ogrenci.ogrenci_adi);
   printf("Ogrencinin Soyadi:%s\n",ogrenci.ogrenci_soyadi);
   printf("Ogrencinin Bolumu:%s\n",ogrenci.bolumu);
   printf("Ogrencinin ortalamasi:%.2f\n",ogrenci.ortalama);
   printf("Ogrencinin Aldigi dersler:\n");
for(int i=0; i<10;i++){
   if (ogrenci.aldigidersler[i].Ders_Adi!=NULL){
      printf("%s\n",ogrenci.aldigidersler[i].Ders_Adi);
      printf("Kredisi:%d\n",ogrenci.aldigidersler[i].kredi);
      printf("Puan:%d\n",ogrenci.aldigidersler[i].puan);

   }


}

   
      
   
 
   
}
void ogrenciyazdirArray(Ogrenci* ogrenciArray, int size){//size kaç tane öğrenci varsa 
   for(int i=0;i<size;i++){
      ogrenciyazdir(ogrenciArray[i]);
      printf("\n");
   }
}
float ortalamahesaplama(char* Ders_adi, Ogrenci* ogrenciArray, int size){
   float toplampuan=0;
   int ogrencisayisi=0;
   for(int i=0;i<size;i++){
      for(int j =0;j<10;j++){
         if(strcmp(ogrenciArray[i].aldigidersler[j].Ders_Adi, Ders_adi) == 0){
            toplampuan+=ogrenciArray[i].aldigidersler[j].puan;
            ogrencisayisi++;
         break;
         }
      }
   }
   if(ogrencisayisi==0){
      printf("DERSİ ALAN YOK");
      return 0;
   }
   return toplampuan / ogrencisayisi;
}

float standartsapmaders(char* Ders_adi, Ogrenci* ogrenciArray,int size){//size öğrencisayisi
   float ortalama= ortalamahesaplama(Ders_adi, ogrenciArray,size);
   float toplamKarefark=0;
   int ogrencisayisi=0;
   for(int i=0; i<size;i++){
      for(int j=0;j<10;j++){
         if(strcmp(ogrenciArray[i].aldigidersler[j].Ders_Adi, Ders_adi)==0){
            float fark = ogrenciArray[i].aldigidersler[j].puan - ortalama;
            toplamKarefark= toplamKarefark + fark*fark;
            ogrencisayisi++;
            break;
         }
      }
   }
   return sqrt(toplamKarefark / ogrencisayisi);
}
//kovaryans formülü (dersin puanı eksi dersin ortalaması)*(2.dersin puanı eksi dersin ortalaması) / n-1
float kovaryanshesaplama(Ders ders_1, Ders ders_3, Ogrenci* ogrenciArray, int size){
   float kovaryans=0;
   float ortalamaders1= ortalamahesaplama(ders_1.Ders_Adi, ogrenciArray, size);
   float ortalamaders2= ortalamahesaplama(ders_3.Ders_Adi, ogrenciArray, size);
   int ogrenci_sayisi=0;

   for(int i =0;i<size;i++){
      float farkDers1= ogrenciArray[i].aldigidersler[0].puan - ortalamaders1;
      float farkDers2= ogrenciArray[i].aldigidersler[1].puan - ortalamaders2;
      kovaryans+= farkDers1 * farkDers2;
      ogrenci_sayisi++;
   }
   if(ogrenci_sayisi > 1){
      kovaryans /= (ogrenci_sayisi - 1);//kovaryansın formülünden geliyor

   }else{
      printf("HATA");
   }
   return kovaryans;

}
void ortalamadanyüksek_ogrenci(char* Ders_adi , Ogrenci* ogrenciArray, float ortalama, int size){
  
   for( int i=0; i<size ; i++){
     
      for(int j=0; j<10;j++){
         if(strcmp(ogrenciArray[i].aldigidersler[j].Ders_Adi,Ders_adi)==0 && ogrenciArray[i].aldigidersler[j].puan >ortalama){
             
            printf("ADI:%s SOYADI:%s BOLUMU:%s PUANI:%d\n",ogrenciArray[i].ogrenci_adi,ogrenciArray[i].ogrenci_soyadi,ogrenciArray[i].bolumu,ogrenciArray[i].aldigidersler[j].puan);
         }
      }
   }
  
}
void ogrencibilgileriyazan_dosya(Ogrenci* ogrenciArray, int size, char* dosyaAdi){
   
   FILE* dosya = fopen(dosyaAdi,"w");

   if(dosya == NULL){
      fprintf(stderr,"Dosya acilmadi: %s\n",dosyaAdi);
      return;
   }
   for(int i=0; i< size;i++){
      fprintf(dosya, "Ogrencinin Adi: %s\n", ogrenciArray[i].ogrenci_adi);
      fprintf(dosya, "Ogrencinin Soyadi: %s\n", ogrenciArray[i].ogrenci_soyadi);
      fprintf(dosya, "Ogrencinin Bolumu: %s\n", ogrenciArray[i].bolumu);
      fprintf(dosya, "Ogrencinin Ortalamasi: %.2f\n", ogrenciArray[i].ortalama);
      fprintf(dosya, "Ogrencinin Aldigi Dersler:\n");
      for(int j=0; j<10;j++){
         fprintf(dosya, "%s\nKredisi: %hu\nPuan: %hu\n", ogrenciArray[i].aldigidersler[j].Ders_Adi,ogrenciArray[i].aldigidersler[j].kredi,ogrenciArray[i].aldigidersler[j].puan);
      }
      fprintf(dosya, "\n");
   } 
   fclose(dosya);
   
}
void  ogrencidosyasini_Okuma(Ogrenci* ogrenciArray, int size, char* dosyaAdi){
   FILE* dosya = fopen(dosyaAdi,"r");
   int i=0;
   if(dosya == NULL){
      fprintf(stderr,"Dosya acilmadi: %s\n",dosyaAdi);
      return;
   }
    while (!feof(dosya))
    {
      fscanf(dosya,"%s %s %s %f",
      &ogrenciArray[i].ogrenci_adi,&ogrenciArray[i].ogrenci_soyadi,&ogrenciArray[i].bolumu,&ogrenciArray[i].ortalama);
      printf("DOSYADA ogrenci bilgileri okunuyor\n");
      for(int j=0;j<10;j++){
         if(ogrenciArray[i].aldigidersler[j].Ders_Adi!=NULL){
            fscanf(dosya,"%s %hu %hu", &ogrenciArray[i].aldigidersler[j].Ders_Adi,&ogrenciArray[i].aldigidersler[j].kredi,&ogrenciArray[i].aldigidersler[j].puan);

         }
      }
      i++;
    }
    fclose(dosya);
    printf("DOSYAOKUNDU\n");
  
}
    
