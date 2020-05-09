#include <iostream>
#include "list.hpp"
#include "dinstring.hpp"
using namespace std;

class Karta
{
protected:
    DinString mestoPolaska;
    DinString mestoDolaska;
    float duzinaPutovanja;
    float cenaKarte;
    int identifikatorKarte;
public:
    Karta()
    {
        mestoPolaska = "Srbija";
        mestoDolaska = "Madjarska";
        duzinaPutovanja = 1;
        cenaKarte = 0.5;
        identifikatorKarte = 123;
    }
    Karta(DinString mP, DinString mD, float dP, float cK, int i)
    {
        mestoPolaska = mP;
        mestoDolaska = mD;
        duzinaPutovanja = dP;
        cenaKarte = cK;
        identifikatorKarte = i;
    }
    virtual bool jeftinaKarta() = 0;
    DinString GetMestoPolaska()
    {
        return mestoPolaska;
    }
    DinString GetMestoDolaska()
    {
        return mestoDolaska;
    }
    float GetDuzinaPutovanja()
    {
        return duzinaPutovanja;
    }
    float GetCenaKarte()
    {
        return cenaKarte;
    }
    int GetIdentifikatorKarte()
    {
        return identifikatorKarte;
    }
};

class AvionskaKarta : public Karta
{
public:
    bool jeftinaKarta()
    {
        if(cenaKarte < 1)
        {
            return true;
        }
        return false;
    }
    void ispis()
    {
        cout<<"Mesto polaska: "<<mestoPolaska<<endl;
        cout<<"Mesto dolaska: "<<mestoDolaska<<endl;
        cout<<"Duzina putovanja"<<duzinaPutovanja<<endl;
        cout<<"Cena karte"<<cenaKarte<<endl;
        cout<<"Identifikator karte:"<<identifikatorKarte<<endl;
    }
};

class Putovanje
{
private:
    DinString nazivPutovanja;
    int maksimalnaCenaPutovanja;
    List<AvionskaKarta> karte;
public:
    Putovanje()
    {

    }
    Putovanje(DinString nP, int mCP, List<AvionskaKarta> k)
    {
        nazivPutovanja = nP;
        maksimalnaCenaPutovanja = mCP;
        karte = k;
    }
    DinString GetNazivPutovanja()
    {
        return nazivPutovanja;
    }
    int GetMaksimalnaCena()
    {
        return maksimalnaCenaPutovanja;
    }
    bool DodajKartu(AvionskaKarta& avionskaKarta)
    {
        AvionskaKarta aK;
        karte.read(karte.size(), aK);
        if(aK.GetMestoDolaska()!=avionskaKarta.GetMestoDolaska())
        {
            karte.add(karte.size()+1, avionskaKarta);
            return true;
        }
        return false;
    }
    bool IzbaciKartu(int index)
    {
        AvionskaKarta kartica;
        for(int i = 1;i <= karte.size();i++)
        {
            karte.read(i,kartica);
            if(kartica.GetIdentifikatorKarte() == index)
            {
                karte.remove(i);
                return true;
            }
            return false;
        }
    }
    void ispisPutovanja()
    {
        cout<<"Maksimalna cena puta: "<<maksimalnaCenaPutovanja<<endl;
        cout<<"Naziv putovanja: "<<nazivPutovanja<<endl;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
