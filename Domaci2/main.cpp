#include <iostream>
///Meksicka
using namespace std;
enum vrstaMesa{SVINJETINA, JUNETINA, PILETINA, BEZ_MESA};
enum prilog{RIZA, POMFRIT, PASULJ, TESTENINA, BEZ_PRILOGA};
enum stanje{POCETAK_ODABIRA, ODABRANO_MESO, ODABRAN_PRILOG, SPREMAN, ZAGOREO};
class Obrok{
private:
    Meso meso;
    Prilog odabranPrilog;
    stanje stanjeObroka;
public:

};
class Meso{
private:
    int gramaza;
    vrstaMesa vrsta;
public:
    Meso()
    {
        gramaza=0;
    };
    Meso(int g, vrstaMesa v)
    {
        vrsta=v;
        gramaza=g;
    }
    Meso(Meso &kopijaMesa)
    {
        gramaza = kopijaMesa.gramaza;
        vrsta = kopijaMesa.vrsta;
    }
    int getGramaza()
    {
        return gramaza;
    }
    vrstaMesa getVrsta()
    {
        return vrsta;
    }
    bool setGramaza(int g)
    {
        if(g<=1000&&g>=0)
        {
            gramaza=g;
            return true;
        }
        return false;
    }
    void setVrsta(vrstaMesa v)
    {
        vrsta=v;
    }
};
void ispisMeso(Meso& m)
{
    cout<<"-------------"<<endl;
    cout<<m.getGramaza()<<endl;
    switch(m.getVrsta())
    {
    case 0:
        cout<<"Svinjetina"<<endl;
        break;
    case 1:
        cout<<"Junetina"<<endl;
        break;
    case 2:
        cout<<"Piletina"<<endl;
        break;
    case 3:
        cout<<"Bez mesa"<<endl;
        break;
    }
    cout<<"-------------"<<endl;
}
class Prilog{
private:
    prilog odabranPrilog;
public:
    Prilog()
    {
        odabranPrilog = BEZ_PRILOGA;
    };
    Prilog(prilog p)
    {
        odabranPrilog = p;
    };
    Prilog(Prilog& p)
    {
        odabranPrilog = p.odabranPrilog;
    }
    prilog getPrilog()
    {
        return odabranPrilog;
    }
    void setPrilog(prilog p)
    {
        odabranPrilog = p;
    }
};
void ispisiPrilog(Prilog &p)
{
    cout<<"-------------"<<endl;
    switch(p.getPrilog())
    {
    case 0:
        cout<<"Riza"<<endl;
        break;
    case 1:
        cout<<"Pomfrit"<<endl;
        break;
    case 2:
        cout<<"Pasulj"<<endl;
        break;
    case 3:
        cout<<"Testenina"<<endl;
        break;
    case 4:
        cout<<"Bez priloga"<<endl;
        break;
    }
    cout<<"-------------"<<endl;
}
int main()
{

    return 0;
}
