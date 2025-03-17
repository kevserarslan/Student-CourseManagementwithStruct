#include "Proje1.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* 
* @file main.c
* @description main kısmında fonksiyonlarımı test ettim ve çıktı aldım. 
* @assignment BP3 1.Proje
* @date 10.12.23 deadline
* @author KEVSER ARSLAN and kevser_arslan@stu.fsm.edu.tr 
*/
int main(int argc, char* argv[]){
 
   if(argc !=2){
    printf("%s <ogrenci_bilgileri.txt>\n",argv[0]);
    return 1;
   }
    
    
    Ders ders_1= dersolustur("matematik",4,92);
    Ders ders_2= dersolustur("matematik",4,80);
    Ders ders_3= dersolustur("fizik",3,67);
    Ders ders_4= dersolustur("fizik",3,58);
    Ders ders_5= dersolustur("proglama",4,57);
    Ders ders_6 =dersolustur("proglama",4,30);
    Ders ders_7=dersolustur("tarih",2,98);
    Ders ders_8=dersolustur("tarih",2,45);
    Ders ders_9=dersolustur("kimya",4,56);
    //Ders ders_10=dersolustur("kimya",4,78);

    printf("%s\n",ders_1.Ders_Adi);// (Ders oluşup oluşmadığını kontrol)

    Ders aldigidersler[]={ders_1,ders_3,ders_5,ders_7};
    Ders aldigidersler1[]={ders_2,ders_4,ders_6,ders_8};
    Ders aldigidersler2[]={ders_2,ders_3,ders_6,ders_9};
    Ogrenci ogrenci_1= ogrenciolustur("Kevser","Arslan","Bilgisayar",3.5, aldigidersler);
   Ogrenci ogrenci_2= ogrenciolustur("Asya","Arslan","Biyomedikal",3.45,aldigidersler1);
    printf("Ogrencinin bilgiler:\n");
   // ogrenciyazdir(ogrenci_1);// (Bilgileri yazıp yazmama kontrol)
  
   
    Ogrenci ogrenciArray[3];
    ogrenciArray[0]= ogrenci_1;
    ogrenciArray[1]= ogrenci_2;
   ogrenciArray[2]= ogrenciolustur("Bahar","Cavus","Endustiri",2.47,aldigidersler2);
   
    ogrenciyazdirArray(ogrenciArray,3);
   


    float ortalamaMat= ortalamahesaplama("matematik", ogrenciArray, 3);
    printf("Matematik dersinin ARTortalamasi:%.2f\n",ortalamaMat);
    float ortalamafizik= ortalamahesaplama("fizik", ogrenciArray, 3);
    printf("Fizik dersinin ARTortalamasi:%.2f\n",ortalamafizik);

float standartsapma= standartsapmaders("fizik",ogrenciArray,3);
printf("Fizik standartsapma:%f\n",standartsapma);

float kovaryanshesap = kovaryanshesaplama(ders_1,ders_3,ogrenciArray,3);
printf("matandfizk kovaryans:%.1f\n",kovaryanshesap);
printf("ortalamdanyuksek ogrenciler.\n");
ortalamadanyüksek_ogrenci("matematik",ogrenciArray,ortalamaMat,3); 

ogrencibilgileriyazan_dosya(ogrenciArray, 3,"ogrenci_bilgileri.txt");//öğrencibilgilerini dosyaya yazma

ogrencidosyasini_Okuma(ogrenciArray,3,argv[1]);



free(ders_1.Ders_Adi);
free(ders_2.Ders_Adi);
free(ogrenci_1.ogrenci_adi);
free(ogrenci_1.ogrenci_soyadi);
free(ogrenci_1.bolumu);
free(ogrenci_2.ogrenci_adi);
free(ogrenci_2.ogrenci_soyadi);
free(ogrenci_2.bolumu);
free(ogrenciArray[2].ogrenci_adi);
free(ogrenciArray[2].ogrenci_soyadi);
free(ogrenciArray[2].bolumu);

    return 0;
}