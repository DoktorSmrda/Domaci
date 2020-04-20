#include <iostream>
#include "dinstring.hpp"

using namespace std;

class Alat
{
protected:
    DinString proizvodjac;
    DinString serijskiBroj;
public:
    virtual void ispis() = 0;
};
class Cekic : public Alat
{
private:
    double tezina;
    unsigned int upotrebljivost;
public:
    Cekic()
    {
        tezina = 5;
        upotrebljivost = 3;
        proizvodjac = "neki proizvodjac";
        serijskiBroj = "2.0";
    };
    Cekic(double t, unsigned int u, DinString p, DinString s)
    {
        tezina = t;
        upotrebljivost = u;
        proizvodjac = p;
        serijskiBroj = s;
    };
    Cekic(Cekic &kopija)
    {
        tezina = kopija.tezina;
        upotrebljivost = kopija.upotrebljivost;
        proizvodjac = kopija.proizvodjac;
        serijskiBroj = kopija.serijskiBroj;
    };
    void ispis()
    {
        cout<<"Proizvodjac: "<<proizvodjac<<endl;
        cout<<"Serijski broj: "<<serijskiBroj<<endl;
        cout<<"Tezina: "<<tezina<<endl;
        cout<<"Upotrebiljvost: "<<upotrebljivost<<endl;
    }
    bool upotrebi()
    {
        if(upotrebljivost>0)
        {
            upotrebljivost--;
            return true;
        }
        else
        {
            return false;
        }
    }
    ~Cekic(){};
};
class Testera : public Alat
{
private:
    double otupljenost;
public:
    Testera()
    {
        otupljenost = 0;
        proizvodjac = "neki proizvodjac";
        serijskiBroj = "2.0";
    };
    Testera(double o, DinString s, DinString p)
    {
        otupljenost = o;
        proizvodjac = p;
        serijskiBroj = s;
    };
    Testera(Testera &kopija)
    {
        otupljenost = kopija.otupljenost;
        serijskiBroj = kopija.serijskiBroj;
        proizvodjac = kopija.proizvodjac;
    };
    void ispis()
    {
        cout<<"Proizvodjac: "<<proizvodjac<<endl;
        cout<<"Serijski broj: "<<serijskiBroj<<endl;
        cout<<"Otupljenost: "<<otupljenost<<endl;
    }
    bool upotrebi()
    {
        if(otupljenost<1)
        {
            otupljenost+=0.05;
            return true;
        }
        else
        {
            return false;
        }
    }
    bool naostri()
    {
        if(otupljenost>0)
        {
            otupljenost-=0.05;
            return true;
        }
        else
        {
            return false;
        }
    }
    ~Testera(){};
};

int main()
{
    Cekic c1;
    Cekic c2(3, 10, "Vitorog", "3.0");
    Cekic c3(c1);
    cout<<"Cekic"<<endl;
    cout<<"1."<<endl;
    c1.ispis();
    cout<<"2."<<endl;
    c2.ispis();
    cout<<"3."<<endl;
    c3.upotrebi();
    c3.ispis();
    Testera t1;
    Testera t2(0.5, "4.0", "Vitorog");
    Testera t3(t1);
    cout<<"Testera"<<endl;
    cout<<"1."<<endl;
    t1.ispis();
    cout<<"2."<<endl;
    t2.ispis();
    cout<<"3."<<endl;
    t3.upotrebi();
    t3.upotrebi();
    t3.upotrebi();
    t3.ispis();
    cout<<endl;
    t3.naostri();
    t3.naostri();
    t3.ispis();
    return 0;
}
