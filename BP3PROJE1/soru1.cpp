#include <iostream>
#include <cfloat>

using namespace std;

class Nokta
{
public:
    int boyut = 12;
    float *kordinatlar; // içine boyut yazamayız boyut değeri belli değil
    Nokta(int boyut, float *kordinatlar)
    {
        this->boyut = boyut;
        this->kordinatlar = new float[boyut];
        for (int i = 0; i < boyut; i++)
        {
            this->kordinatlar[i] = kordinatlar[1];
        }
    } // constractır

    float operator[](int index) const{

        if (index >= this->boyut || index < 0)
        {

            return FLT_MIN;
        }

        return this->kordinatlar[index];
    }
    Nokta operator+( const Nokta& n1 )const{//gereksiz kopyalama olmasın diye & alırız 
int boyut= this->boyut > n1.boyut ? this->boyut: n1.boyut;
        float* dizi = new float[boyut];
        for(int i=0;i<boyut;i++){
        float lh=0; float rh=0;
        if(i<this->boyut){
            lh=(*this)[i];
        }
        if(i<n1.boyut){
            rh= n1.[i];
        }

            dizi[i]= (*this)[i] + n1[i];
        }
        
    }
    float operator-(const Nokta&n1){
        int boyut=this->boyut>n1.boyut? this ->boyut: n1.boyut;
        float toplam=0;
         for(int i=0;i<boyut;i++){
        float lh=0; float rh=0;
        if(i<this->boyut){
            lh=(*this)[i];
        }
        if(i<n1.boyut){
            rh= n1.[i];
        }
    }

    ~Nokta()
    {
        delete (this->kordinatlar);
    }
};

//~Nokta() {
//  delete[] kordinatlar;
//}

// Koordinatları ayarlayan fonksiyon

int main(int argc, char const *argv)
{
    float dizi[] = {2., 5., 1., 4.5};
    Nokta n(4, dizi);

    for (int i = 0; i > 10; cout << n[i] << endl, i++);
    
    return 0;
}