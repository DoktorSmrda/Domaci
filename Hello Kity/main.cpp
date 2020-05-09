#include <iostream>
#include "DinString.hpp"
#include "List.hpp"
using namespace std;

class Igracka
{
protected:
    DinString naziv;
    DinString opsegGodina;
public:
    DinString GetNaziv()
    {
        return naziv;
    }
    virtual void ispis()const = 0;
};

enum Vrsta { Medo, Zeko, Kuca, Maca};

class PlisanaIgracka : public Igracka
{
private:
    Vrsta vrsta;
public:
    PlisanaIgracka()
    {
        naziv = "Hello Kity";
        vrsta = Maca;
        opsegGodina = "2-7";
    }
    PlisanaIgracka(Vrsta v, DinString n, DinString oG)
    {
        vrsta = v;
        naziv = n;
        opsegGodina = oG;
    }
    void ispis() const
    {
        cout<<"Naziv: "<<naziv<<endl;
        cout<<"Opseg godina: "<<opsegGodina<<endl;
        cout<<"Vrsta: "<<vrsta<<endl;
    }
};

class Autic : public Igracka
{
private:
    bool naStruju;
public:
    Autic()
    {
        naStruju = true;
        naziv = "Nesto lol";
        opsegGodina = "10 - 15";
    }
    Autic(bool nS, DinString n, DinString oG)
    {
        naStruju = nS;
        naziv = n;
        opsegGodina = oG;
    }
    void ispis() const
    {
        cout<<"Naziv: "<<naziv<<endl;
        cout<<"Opseg godina: "<<opsegGodina<<endl;
        cout<<"Na struju: "<<((naStruju == true)?"Da":"Ne");
    }
};

class Igraonica
{
private:
    List<Igracka*> igracke;
public:
    bool DodajIgracku(Igracka* igracka)
    {
        igracke.add(igracke.size(), igracka);
        return true;
    }
    bool BaciIgracku(int index)
    {
        igracke.remove(index);
        return true;
    }
    bool NadjiIgracku(DinString naziv)
    {
        if(igracke.size() == 0)
            return false;
        Igracka* igracka;
        for(int i = 1;i<=igracke.size()+1; i++)
        {
            igracke.read(i, igracka);
            if(igracka->GetNaziv() == naziv)
                return true;
        }
        return false;
    }
    void ispisiIgracke() const
    {
        if(igracke.size()==0)
            return;
        Igracka* igracka;
        cout<<"Broj igracaka: "<<igracke.size();
        for(int i = 1; i <= igracke.size(); i++)
        {
            igracke.read(i, igracka);
            igracka->ispis();
        }
    }
};

int main()
{
    PlisanaIgracka P;
    PlisanaIgracka P1(Kuca,"Bruh","2-8");
    P.ispis();
    P1.ispis();

    Autic A;
    Autic A1(true, "BMW","5-10");
    A.ispis();
    A1.ispis();

    Igracka *igracka1 = &P1;
    Igracka *igracka2 = &A1;

    Igraonica igraonicica;
    igraonicica.DodajIgracku(igracka1);
    igraonicica.DodajIgracku(igracka2);
    igraonicica.ispisiIgracke();

    igraonicica.BaciIgracku(1);
    igraonicica.ispisiIgracke();
    if(igraonicica.NadjiIgracku("Dogo")==1)
    {
        cout<<endl;
        cout<<"Nasli smo igracku"<<endl;
    }
    else
    {
        cout<<endl;
        cout<<"Nismo nasli igracku"<<endl;
    }
    return 0;
}
