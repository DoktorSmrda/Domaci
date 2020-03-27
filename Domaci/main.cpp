#include <iostream>
///KOLAC
using namespace std;
enum TipPreliva {COKOLADNI, COKOLADNI_SA_SLAGOM};
enum KolacStanje {U_PRIPREMI, PECE_SE, ZAGOREO, PRIPREMLJEN};
class Preliv
{
private:
    TipPreliva tip = COKOLADNI;
public:
    Preliv() {};
    Preliv(TipPreliva t)
    {
        tip=t;
    }
    void setTip(TipPreliva t)
    {
        tip=t;
    };
    TipPreliva getTip()const
    {
        return tip;
    }
    bool dodajSlag()
    {
        if(tip==COKOLADNI)
        {
            tip=COKOLADNI_SA_SLAGOM;
            return true;
        }
        return false;
    }
    bool ukloniSlag()
    {
        if(tip==COKOLADNI_SA_SLAGOM)
        {
            tip=COKOLADNI;
            return true;
        }
        return false;
    }

};
class Kolac
{
private:
    KolacStanje stanje = U_PRIPREMI;
    int temperatura = 20;
    Preliv preliv;
public:
    Kolac():preliv() {};
    Kolac(KolacStanje ks, int t, TipPreliva tip):preliv(tip)
    {
        stanje = ks;
        temperatura = t;
    };
    Kolac(const Kolac &kolacKopija)
    {
        stanje = kolacKopija.stanje;
        temperatura = kolacKopija.temperatura;
        preliv = kolacKopija.preliv;
    };
    KolacStanje getStanje()const
    {
        return stanje;
    }
    int getTemperatura()const
    {
        return temperatura;
    }
    Preliv getPreliv()const
    {
        return preliv;
    }
    bool staviDaSePece()
    {
        if(preliv.getTip() != COKOLADNI_SA_SLAGOM)
        {
            stanje = PECE_SE;
            temperatura += 20;
            return true;
        }
        return false;
    };
    bool ispeciKolac()
    {
        if(stanje == PECE_SE)
        {
            stanje = U_PRIPREMI;
            temperatura = 20;
            return true;
        }
        return false;
    };
    bool zavrsiKolac()
    {
        if(stanje == U_PRIPREMI)
        {
            stanje = PRIPREMLJEN;
            return true;
        }
        return false;
    };
    bool pevecajTemperaturu()
    {
        if(stanje == PECE_SE)
        {
            if(temperatura != 100)
            {
                temperatura += 20;
            }
            else
            {
                stanje = ZAGOREO;
                temperatura = 20;
            }
            return true;
        }
        return false;
    };
    bool smanjiTemperaturu()
    {
        if(stanje == PECE_SE)
        {
            if(temperatura>40)
            {
                temperatura -= 20;
                return true;
            }
        }
        return false;
    };
    bool dodajSlag()
    {
        if(stanje == U_PRIPREMI)
        {
            if(preliv.getTip()==COKOLADNI)
            {
                preliv.setTip(COKOLADNI_SA_SLAGOM);
                return true;
            }
        }
        return false;
    };
    bool ukloniSlag()
    {
        if(stanje == U_PRIPREMI)
        {
            if(preliv.getTip()==COKOLADNI_SA_SLAGOM)
            {
                preliv.setTip(COKOLADNI);
                return true;
            }
        }
        return false;
    };
};
void ispisiPreliv(const Preliv &p)
{
    switch(p.getTip())
    {
    case 0:
        cout<<"------------------"<<endl;
        cout<<"Preliv: COKOLADNI"<<endl;
        cout<<"------------------"<<endl;
        break;
    case 1:
        cout<<"------------------"<<endl;
        cout<<"Preliv: COKOLADNI_SA_SLAGOM"<<endl;
        cout<<"------------------"<<endl;
        break;
    }
}
void ispisiKolac(const Kolac &k)
{
    cout<<"------------------"<<endl;
    cout<<"Stanje: ";
    switch(k.getStanje())
    {
    case 0:
        cout<<"U pripremi"<<endl;
        break;
    case 1:
        cout<<"Pece se"<<endl;
        break;
    case 2:
        cout<<"Zagoreo"<<endl;
        break;
    case 3:
        cout<<"Pripremljen"<<endl;
        break;
    }
    cout<<"Temperatura: "<<k.getTemperatura()<<endl;
    ispisiPreliv(k.getPreliv());
}
int meni()
{
    int i;
    do
    {
        cout<<"1. Stavi da se pece"<<endl;
        cout<<"2. Ispeci kolac"<<endl;
        cout<<"3. Zavrsi kolac"<<endl;
        cout<<"4. Povecaj temperaturu"<<endl;
        cout<<"5. Smanji temperaturu"<<endl;
        cout<<"6. Dodaj slag"<<endl;
        cout<<"7. Ukloni slag"<<endl;
        cout<<"8. Ispis kolac"<<endl;
        cout<<"9. Ispis preliv"<<endl;
        cout<<"10. Exit"<<endl;
        cin>>i;
    }
    while(i<0&&i>10);
    return i;
}
int main()
{
    Kolac kolac;
    int provera;
    do
    {
        provera=meni();
        switch(provera)
        {
        case 1:
            kolac.staviDaSePece();
            break;
        case 2:
            kolac.ispeciKolac();
            break;
        case 3:
            kolac.zavrsiKolac();
            break;
        case 4:
            kolac.pevecajTemperaturu();
            break;
        case 5:
            kolac.smanjiTemperaturu();
            break;
        case 6:
            kolac.dodajSlag();
            break;
        case 7:
            kolac.ukloniSlag();
            break;
        case 8:
            ispisiKolac(kolac);
            break;
        case 9:
            ispisiPreliv(kolac.getPreliv());
            break;
        }
    }
    while(provera!=10);
        Preliv p;
    return 0;
}
