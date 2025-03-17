#ifndef PROJE1_H
#define PROJE1_H
/* 
* @file Proje1.h
* @description bizden istenen Struct oluşturulması ve fonksiyonların parametleri . 
* @assignment BP3 1.Proje
* @date 10.12.23 deadline
* @author KEVSER ARSLAN and kevser_arslan@stu.fsm.edu.tr 
*/
typedef struct 
{
   char * Ders_Adi;
   unsigned short int kredi;
   unsigned short int puan;
} Ders;

typedef struct 
{
    char* ogrenci_adi;
    char* ogrenci_soyadi;
    char* bolumu;
    float ortalama;
    Ders* aldigidersler;
}Ogrenci;
Ders dersolustur(char* Ders_Adi,unsigned short int kredi,unsigned short int puan);
Ogrenci ogrenciolustur(char* ogrenci_adi, char* ogrenci_soyadi, char* bolumu, float ortalama, Ders* aldigidersler );
void ogrenciyazdir(Ogrenci ogrenci);
void ogrenciyazdirArray(Ogrenci* ogrenciArray, int size);
float ortalamahesaplama(char* Ders_adi, Ogrenci* ogrenciArray, int size);
float standartsapmaders(char* Ders_Adi, Ogrenci* ogrenciArray, int size);
float kovaryanshesaplama(Ders ders_1, Ders ders_3, Ogrenci* ogrenciArray, int size);
void ortalamadanyüksek_ogrenci(char* Ders_adi , Ogrenci* ogrenciArray, float ortalama, int size);
void ogrencibilgileriyazan_dosya(Ogrenci* ogrenciArray, int size, char* dosyaAdi );
void  ogrencidosyasini_Okuma(Ogrenci* ogrenciArray, int size, char* dosyaAdi);
#endif