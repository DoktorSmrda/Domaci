#include <iostream>
#include <cstdlib>
#include <time.h>
///Meksicka
using namespace std;
enum vrstaMesa {SVINJETINA=1, JUNETINA, PILETINA, BEZ_MESA};
enum prilog {RIZA=1, POMFRIT, PASULJ, TESTENINA, BEZ_PRILOGA};
enum stanje {POCETAK_ODABIRA=1, ODABRANO_MESO, ODABRAN_PRILOG, SPREMAN, ZAGOREO};
class Prilog
{
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
class Meso
{
private:
    int gramaza;
    vrstaMesa vrsta;
public:
    Meso()
    {
        gramaza=0;
        vrsta = BEZ_MESA;
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
class Obrok
{
private:
    Meso meso;
    Prilog odabranPrilog;
    stanje stanjeObroka;
public:
    Obrok():meso(), odabranPrilog()
    {
        stanjeObroka = POCETAK_ODABIRA;
    };
    Obrok(vrstaMesa vm, int gramaza, prilog vp):meso(), odabranPrilog()
    {
        if(gramaza>=0&&gramaza<=1000)
        {
            meso.setGramaza(gramaza);
            meso.setVrsta(vm);
            odabranPrilog.setPrilog(vp);
            stanjeObroka = ODABRAN_PRILOG;
        }
        else
        {

        }
    };
    bool odaberiMeso(vrstaMesa v, int g)
    {
        if(g>=0&&g<=1000)
        {
            meso.setGramaza(g);
            meso.setVrsta(v);
            stanjeObroka = ODABRANO_MESO;
            return true;
        }
        return false;
    };
    bool odaberiPrilog(prilog p)
    {
        if(odabranPrilog.getPrilog()==BEZ_PRILOGA&&meso.getVrsta()==BEZ_MESA)
            return false;
        else
        {
            odabranPrilog.setPrilog(p);
            stanjeObroka = ODABRAN_PRILOG;
            return true;
        }
    };
    void spremi()
    {
        if(rand()%10+1==1)
        {
            stanjeObroka = ZAGOREO;
        }
        else
            stanjeObroka = SPREMAN;
    };
    Meso& getMeso()
    {
        return meso;
    };
    Prilog& getPrilog()
    {
        return odabranPrilog;
    };
    stanje getStanje()
    {
        return stanjeObroka;
    };
};
void ispisMeso(Meso& m)
{
    cout<<"-------------"<<endl;
    cout<<"Gramaza: ";
    cout<<m.getGramaza()<<endl;
    switch(m.getVrsta())
    {
    case 1:
        cout<<"Svinjetina"<<endl;
        break;
    case 2:
        cout<<"Junetina"<<endl;
        break;
    case 3:
        cout<<"Piletina"<<endl;
        break;
    case 4:
        cout<<"Bez mesa"<<endl;
        break;
    }
}
void ispisiPrilog(Prilog& p)
{
    cout<<"-------------"<<endl;
    switch(p.getPrilog())
    {
    case 1:
        cout<<"Riza"<<endl;
        break;
    case 2:
        cout<<"Pomfrit"<<endl;
        break;
    case 3:
        cout<<"Pasulj"<<endl;
        break;
    case 4:
        cout<<"Testenina"<<endl;
        break;
    case 5:
        cout<<"Bez priloga"<<endl;
        break;
    }
}
void ispisiObrok(Obrok &o)
{
    cout<<"-------------"<<endl;
    cout<<"Stanje obroka: ";
    switch(o.getStanje())
    {
    case 1:
        cout<<"Pocetak odabira"<<endl;
        break;
    case 2:
        cout<<"Odabrano meso"<<endl;
        break;
    case 3:
        cout<<"Odaran prilog"<<endl;
        break;
    case 4:
        cout<<"Spreman"<<endl;
        break;
    case 5:
        cout<<"Zagoreo"<<endl;
        break;
    }
    ispisMeso(o.getMeso());
    ispisiPrilog(o.getPrilog());
    cout<<"-------------"<<endl;
};
int meni()
{
    int i;
    do
    {
        cout<< "1. Odaberi meso" << endl;
        cout<< "2. Odaberi prilog" << endl;
        cout<< "3. Spremi" << endl;
        cout<< "4. Prikazi obrok" << endl;
        cout<< "5. Exit" << endl;
        cin>>i;
    }while(i<0);
    return i;
}
int main()
{
    Obrok obrok;
    srand(time(NULL));
    do
    {
        switch(meni())
        {
        case 1:
            int vrsta;
            int gramaza;
            cout<<"Unesite vrstu mesa(1-SVINJETINA, 2-JUNETINA, 3-PILETINA, 4-BEZ_MESA): ";
            cin>>vrsta;
            cout<<"Unesite gramazu: ";
            cin>>gramaza;
            obrok.odaberiMeso((vrstaMesa)vrsta, gramaza);
            break;
        case 2:
            int p;
            if(obrok.getStanje()==ODABRANO_MESO)
            {
                cout<<"Odaberite prilog (1-RIZA, 2-POMFRIT, 3-PASULJ, 4-TESTENINA, 5-BEZ_PRILOGA): ";
                cin>>p;
                obrok.odaberiPrilog((prilog)p);
            }
            break;
        case 3:
            obrok.spremi();
            break;
        case 4:
            ispisiObrok(obrok);
            break;
        case 5:
            return 0;
            break;
        }
    }while(true);
}

