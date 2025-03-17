#include <iostream>
#include <cfloat>

using namespace std;
class Cokgen
{
protected:
    size_t kenarsayisi;
    float *kenaruzunluklari;
    float cevre;

public:
    Cokgen(size_t kenarsayisi, float *kenaruzunluklari)
    {
        this->kenarsayisi = kenarsayisi;
        this->kenaruzunluklari = new float[kenarsayisi];
        for (size_t i = 0; i < kenarsayisi; i++)
        {

            this->kenaruzunluklari[i] = kenaruzunluklari[i];
        }
        setCevre();
    }
    Cokgen(const Cokgen& other){
    this->kenarsayisi=other.kenarsayisi;
    delete[] this->kenaruzunluklari;
    this->kenaruzunluklari=new float[kenarsayisi ];
    for(size_t i=0;i<other.kenarsayisi;i++){
        this->kenaruzunluklari[i]=other.kenaruzunluklari[i];
    }
    }
    void set_kenarsayisi(size_t set_kenarsayisi)
    {
    }
    void genislet(size_t kenarsayisi, float *kenaruzunluklari)
    {
        if (this->kenarsayisi < kenarsayisi)
        {
            float *temp = new float[kenarsayisi];
            for (size_t i = 0; i < kenarsayisi; i++)
            {
                temp[i] = this->kenaruzunluklari[i] + kenaruzunluklari[i];
            }
            delete[] this->kenaruzunluklari;
            this->kenaruzunluklari = temp;
        }
        else
        {
            for (size_t i = 0; i < kenarsayisi; i++)
            {
                this->kenaruzunluklari[i] += kenaruzunluklari[i];
            }
        }
    }
    size_t get_kenarsayisi(){
        return kenarsayisi;
    }
   const float * get_kenaruzunluklari(){
return kenaruzunluklari;
    }
    float get_Cevre(){
        return cevre;
    }
    ~Cokgen(){
        delete[] kenaruzunluklari;
    }

protected:
    void setCevre()
    {
        float temp = 0;

        for (size_t i = 0; i < this->kenarsayisi; i++)
        {
            temp += this->kenaruzunluklari[i];
        }
        this->cevre=temp;
    }
};
class DuzgunCokgen: public Cokgen{
    
    DuzgunCokgen(size_t kenarsayisi,float* kenaruzunluklari): Cokgen(kenarsayisi,kenaruzunluklari ){}

};

int main(){
    
}
/*
#include <iostream>
#include <cfloat>

class Cokgen
{
protected:
    size_t kenarSayisi;
    float *kenarUzunluklari;
    float cevre;

public:
    // Parametreli constructor
    Cokgen(size_t kenarSayisi, const float *kenarUzunluklari)
    {
        this->kenarSayisi = kenarSayisi;
        this->kenarUzunluklari = new float[kenarSayisi];
        for (size_t i = 0; i < kenarSayisi; i++)
        {
            this->kenarUzunluklari[i] = kenarUzunluklari[i];
        }
        setCevre();
    }

    // Copy constructor
    Cokgen(const Cokgen &other) : kenarSayisi(other.kenarSayisi), cevre(other.cevre)
    {
        this->kenarUzunluklari = new float[kenarSayisi];
        for (size_t i = 0; i < kenarSayisi; i++)
        {
            this->kenarUzunluklari[i] = other.kenarUzunluklari[i];
        }
    }

    // Destructor
    ~Cokgen()
    {
        delete[] kenarUzunluklari;
    }

    // Setter
    void setKenarSayisi(size_t newKenarSayisi)
    {
        kenarSayisi = newKenarSayisi;
    }

    // Getter
    size_t getKenarSayisi() const
    {
        return kenarSayisi;
    }

    const float *getKenarUzunluklari() const
    {
        return kenarUzunluklari;
    }

    float getCevre() const
    {
        return cevre;
    }

    // Genişletme fonksiyonu
    void genislet(size_t ekKenarSayisi, const float *ekKenarUzunluklari)
    {
        if (kenarSayisi + ekKenarSayisi > 0)
        {
            float *temp = new float[kenarSayisi + ekKenarSayisi];
            for (size_t i = 0; i < kenarSayisi; i++)
            {
                temp[i] = kenarUzunluklari[i];
            }
            for (size_t i = 0; i < ekKenarSayisi; i++)
            {
                temp[kenarSayisi + i] = ekKenarUzunluklari[i];
            }
            delete[] kenarUzunluklari;
            kenarUzunluklari = temp;
            kenarSayisi += ekKenarSayisi;
            setCevre();
        }
    }

private:
    // Cevre hesaplama fonksiyonu
    void setCevre()
    {
        float temp = 0;
        for (size_t i = 0; i < kenarSayisi; i++)
        {
            temp += kenarUzunluklari[i];
        }
        cevre = temp;
    }
};

int main()
{
    const size_t kenarSayisi = 3;
    const float kenarUzunluklari[kenarSayisi] = {3.0, 4.0, 5.0};

    // Cokgen nesnesi oluşturuluyor
    Cokgen cokgen(kenarSayisi, kenarUzunluklari);

    std::cout << "Kenar Sayisi: " << cokgen.getKenarSayisi() << std::endl;
    std::cout << "Kenar Uzunluklari: ";
    const float *kenarUzunluklariCokgen = cokgen.getKenarUzunluklari();
    for (size_t i = 0; i < cokgen.getKenarSayisi(); i++)
    {
        std::cout << kenarUzunluklariCokgen[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Cevre: " << cokgen.getCevre() << std::endl;

    // Cokgen nesnesi genişletiliyor
    const size_t ekKenarSayisi = 2;
    const float ekKenarUzunluklari[ekKenarSayisi] = {6.0, 7.0};
    cokgen.genislet(ekKenarSayisi, ekKenarUzunluklari);

    std::cout << "Yeni Kenar Sayisi: " << cokgen.getKenarSayisi() << std::endl;
    std::cout << "Yeni Kenar Uzunluklari: ";
    kenarUzunluklariCokgen = cokgen.getKenarUzunluklari();
    for (size_t i = 0; i < cokgen.getKenarSayisi(); i++)
    {
        std::cout << kenarUzunluklariCokgen[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Yeni Cevre: " << cokgen.getCevre() << std::endl;

    return 0;
}











*/