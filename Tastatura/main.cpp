#include <iostream>
#include "dinstring.hpp"

using namespace std;

class Tastatura
{
protected:
    DinString proizvodjac;
    int brojTastera;
public:
    virtual void ispis() = 0;
};

class GejmerskaTastatura : public Tastatura
{
private:
    int brojPritisaka;
public:
    GejmerskaTastatura()
    {
        brojPritisaka = 0;
        proizvodjac = "Redragon";
        brojTastera = 104;
    };
    GejmerskaTastatura(int bP, DinString p, int bT)
    {
        brojPritisaka = bP;
        proizvodjac = p;
        brojTastera = bT;
    };
    GejmerskaTastatura(GejmerskaTastatura &kopija)
    {
        brojPritisaka = kopija.brojPritisaka;
        proizvodjac = kopija.proizvodjac;
        brojTastera = kopija.brojTastera;
    };
    void ispis()
    {
        cout<<"proizvodjac: "<<proizvodjac<<endl;
        cout<<"Broj tastera: "<<brojTastera<<endl;
        cout<<"Broj pritisaka: "<<brojPritisaka<<endl;
    }
    void pritisniTaster()
    {
        brojPritisaka++;
    }
    void drziTaster(int sec)
    {
        brojPritisaka+=sec;
    }
    ~GejmerskaTastatura(){};
};

class NumerickaTastatura : public Tastatura
{
private:
    int brojPritisakaBrojeva;
public:
    NumerickaTastatura()
    {
        brojPritisakaBrojeva = 0;
        proizvodjac = "Redragon";
        brojTastera = 104;
    };
    NumerickaTastatura(int bPB, DinString p, int bT)
    {
        brojPritisakaBrojeva = bPB;
        proizvodjac = p;
        brojTastera = bT;
    };
    NumerickaTastatura(NumerickaTastatura &kopija)
    {
        brojPritisakaBrojeva = kopija.brojPritisakaBrojeva;
        proizvodjac = kopija.proizvodjac;
        brojTastera = kopija.brojTastera;
    };
    void ispis()
    {
        cout<<"proizvodjac: "<<proizvodjac<<endl;
        cout<<"Broj tastera: "<<brojTastera<<endl;
        cout<<"Broj pritisaka brojeva: "<<brojPritisakaBrojeva<<endl;
    }
    void pritisniTaster(bool pritisnutBroj)
    {
        if(pritisnutBroj)
            brojPritisakaBrojeva++;
    }
    void drziTaster(int sec, bool pritisnutBroj)
    {
        if(pritisnutBroj)
            brojPritisakaBrojeva+=sec;
    }
    ~NumerickaTastatura(){};
};
int main()
{
    GejmerskaTastatura gejmerska1;
    GejmerskaTastatura gejmerska2(10, "HyperX", 62);
    gejmerska2.pritisniTaster();
    GejmerskaTastatura gejmerska3(gejmerska1);
    gejmerska3.drziTaster(20);
    cout<<"|Gejmerska Tastatura|"<<endl<<"1."<<endl;
    gejmerska1.ispis();
    cout<<endl;
    cout<<"2."<<endl;
    gejmerska2.ispis();
    cout<<endl;
    cout<<"3."<<endl;
    gejmerska3.ispis();
    cout<<endl;
    NumerickaTastatura numericka1;
    NumerickaTastatura numericka2(10, "HyperX", 62);
    numericka2.pritisniTaster(true);
    NumerickaTastatura numericka3(numericka1);
    numericka3.drziTaster(20, true);
    cout<<"|Numericka Tastatura|"<<endl<<"1."<<endl;
    numericka1.ispis();
    cout<<endl;
    cout<<"2."<<endl;
    numericka2.ispis();
    cout<<endl;
    cout<<"3."<<endl;
    numericka3.ispis();
    cout<<endl;
    return 0;
}
