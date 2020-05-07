#include <iostream>
#include "dinstring.hpp"
#include "list.hpp"
#include <time.h>
#include "Account.hpp"
#include "Teski.hpp"
#include "Laki.hpp"
#include "Srednji.hpp"
#include "Lovac.hpp"
#include "Artiljerija.hpp"

using namespace std;

int meni(Account& account)
{
    int odabir;
    do
    {
        cout<<account;
        cout<<"|1) Kupi tenk"<<endl;
        cout<<"|2) Prodaj tenk"<<endl;
        cout<<"|3) Kupi slot"<<endl;
        cout<<"|4) U borbu"<<endl;
        cout<<"|5) Popravi tenk"<<endl;
        cout<<"|6) Kupi potrosnu robu"<<endl;
        cout<<"|7) Kupi municiju"<<endl;
        cout<<"|8) Napuni tenk"<<endl;
        cout<<"|9) Servisiraj tenk"<<endl;
        cout<<"|10) Ispis tenkova"<<endl;
        cout<<"|11) Ispis tenka po indexu"<<endl;
        cout<<"|12) Ispis servisiranja "<<endl;
        cout<<"|13) Ispis servisiranja tenka"<<endl;
        cout<<"|14) Unapredi tenk"<<endl;
        cout<<"|>>>";
        cin>>odabir;
        fflush(stdin);
        if(odabir==20||odabir==21)
            return odabir;
    }
    while(odabir<1||odabir>15);
    return odabir;
}

int main()
{
    DinString posada[5] = {"Saban", "Miroljub", "Pavle", "Rada", "Radmila"};
    enum drzave {Nemacka, SSSR, SAD, Francuska, VelikaBritanija, Kina, Japan, Cehoslovacka, Poljska, Svedska, Italija};
    srand(time(0));
    ///Testiranje konstruktora bez parametra sa parametrima i kopije
    Account account1;
    Account account("Doktor Smrda", "Password", 500000, 1000, 10, 0);
    Account account2(account1);

    Tenk* lakiTenk = new Laki();
    Tenk* lakiTenk1 = new Laki(VelikaBritanija, "Churchill I", 5, posada);
    Tenk* srednjiTenk = new Srednji();
    Tenk* srednjiTenk1 = new Srednji(Francuska, "G1 R", 3, posada);
    Tenk* teskiTenk = new Teski();
    Tenk* teskiTenk1 = new Teski(Kina, "Chi-To", 5, posada);
    Tenk* lovac = new Lovac();
    Tenk* lovac1 = new Lovac(Nemacka, "Panther", 5 , posada);
    Tenk* artiljerija = new Artiljerija();
    Tenk* artiljerija1 = new Artiljerija(Nemacka, "Nashor", 5, posada);

    Laki lakiTenk2();
    Srednji srednjiTenk2();
    Teski teskiTenk2();
    Lovac lovac2();
    Artiljerija artiljerija2();

    Tenk tenk;
    Tenk tenk1(LAKI, SSSR, "Tenk", 2);
    Tenk tenk2 = tenk;

    Top top;
    Top top1(30, 300, 150, 4);
    Top top2(top);

    Motor motor;
    Motor motor1(1500,30);
    Motor motor2(motor);

    Radio radio;
    Radio radio1(1000);
    Radio radio2(radio);

    Vesanje vesanje;
    Vesanje vesanje1(50000, 80);
    Vesanje vesanje2(vesanje);

    Kupola kupola;
    Kupola kupola1(1000, 80, 3);
    Kupola kupola2(kupola);

    OsnovneKarakteristike oK;
    OsnovneKarakteristike oK1(100, 50, 60, 250);
    OsnovneKarakteristike oK2(oK);

    TehnickeKarakteristike tK;
    TehnickeKarakteristike tK1(70, 200, 30, 20, 20);
    TehnickeKarakteristike tK2(tK);

    Posada p;
    Posada p1(5, posada);
    Posada p2(p);

    Clan c;
    Clan c1("Smrda", 4);
    Clan c2(c);

    List<int> pR;
    List<int> m;

    Servisiranje servisiranje;
    Servisiranje servisiranje1(pR, m);
    Servisiranje servisiranje2(servisiranje);

    account+=lakiTenk1;
    account+=srednjiTenk1;
    account+=teskiTenk1;
    account+=lovac1;
    account+=artiljerija1;

    account+=tenk2;

    int odabir;
    int izbor;
    int izbor2;
    int kolicina;
    bool kupljen;
    bool prodat;

    do
    {
        odabir = meni(account);
        switch(odabir)
        {
        case 1:
            cout<<endl<<"|(1-Laki, 2-Srednji, 3-Teski, 4-Artiljerija, 5-Lovac): ";
            cin>>izbor;
            switch(izbor)
            {
            case 1:
                kupljen=account.kupiTenk(lakiTenk);
                break;
            case 2:
                kupljen=account.kupiTenk(srednjiTenk);
                break;
            case 3:
                kupljen=account.kupiTenk(teskiTenk);
                break;
            case 4:
                kupljen=account.kupiTenk(artiljerija);
                break;
            case 5:
                kupljen=account.kupiTenk(lovac);
                break;
            }
            if(kupljen)
                cout<<endl<<"*Tenk je kupljen!*"<<endl<<endl;
            else
                cout<<endl<<"*Tenk nije kupljen!*"<<endl<<endl;
            break;
        case 2:
            if(account.GetBrojTenkova()==0)
            {
                cout<<"*Garaza je prazna!*"<<endl;
            }
            else
            {
                account.izlistajNazive();
                cin>>izbor;
                prodat=account.prodajTenk(izbor-1);
            }
            if(prodat)
                cout<<endl<<"*Tenk je prodat!*"<<endl<<endl;
            else
                cout<<endl<<"*Tenk nije prodat!*"<<endl<<endl;
            break;
        case 3:
            kupljen = account.kupiSlot();
            if(kupljen)
                cout<<endl<<"*Kupljeno -300 zlata!*"<<endl<<endl;
            else
                cout<<endl<<"*Nemate dovoljno zlata!*"<<endl<<endl;
            break;
        case 4:
            if(account.GetBrojTenkova()==0)
            {
                cout<<endl<<"*Garaza je prazna!*"<<endl<<endl;
            }
            else
            {
                account.izlistajNazive();
                cout<<"|>>>";
                cin>>izbor;
                cout<<endl;
                account.uBorbu(izbor-1);
            }
            break;
        case 5:
            if(account.GetBrojTenkova()==0)
            {
                cout<<endl<<"*Garaza je prazna!*"<<endl<<endl;
            }
            else
            {
                account.izlistajNazive();
                cout<<"|>>>";
                cin>>izbor;
                cout<<endl;
                account.popraviTenk(izbor-1);
            }
            break;
        case 6:
            account.ispisPotrosnaRoba();
            cout<<"|>>>";
            cin>>izbor;
            cout<<"|Kolicina: ";
            cin>>kolicina;
            cout<<endl;
            kupljen = account.kupiPotrosnuRobu(kolicina, izbor-1);
            if(kupljen)
                cout<<"*Kupljeno!*"<<endl<<endl;
            break;
        case 7:
            account.ispisMunicija();
            cout<<"|>>>";
            cin>>izbor;
            cout<<"|Kolicina: ";
            cin>>kolicina;
            cout<<endl;
            kupljen = account.kupiMuniciju(kolicina, izbor-1);
            if(kupljen)
                cout<<"*Kupljeno!*"<<endl<<endl;
            break;
        case 8:
            if(account.GetBrojTenkova()==0)
            {
                cout<<endl<<"*Garaza je prazna!*"<<endl<<endl;
            }
            else
            {
                account.izlistajNazive();
                cout<<"|>>>";
                cin>>izbor;
                account.ispisServisiranjaTenkaMunicija(izbor-1);
                cout<<"|>>>";
                cin>>izbor2;
                cout<<"|Kolicina: ";
                cin>>kolicina;
                cout<<endl;
                account.napuniTenk(izbor-1, kolicina, izbor2-1);
            }
            break;
        case 9:
            if(account.GetBrojTenkova()==0)
            {
                cout<<endl<<"*Garaza je prazna!*"<<endl<<endl;
            }
            else
            {
                account.izlistajNazive();
                cout<<"|>>>";
                cin>>izbor;
                account.ispisServisiranjaTenkaPotrosnaRoba(izbor-1);
                cout<<"|>>>";
                cin>>izbor2;
                cout<<"|Kolicina: ";
                cin>>kolicina;
                cout<<endl;
                account.servisirajTenk(izbor-1, kolicina, izbor2-1);
            }
            break;
        case 10:
            account.izlistajNazive();
            cout<<endl;
            break;
        case 11:
            account.izlistajNazive();
            cout<<"|>>>";
            cin>>izbor;
            cout<<endl;
            account.ispisTenka(izbor-1);
            break;
        case 12:
            account.ispisServisiranja();
            break;
        case 13:
            if(account.GetBrojTenkova()==0)
            {
                cout<<endl<<"*Garaza je prazna!*"<<endl<<endl;
            }
            else
            {
                account.izlistajNazive();
                cout<<"|>>>";
                cin>>izbor;
                account.ispisServisiranjaTenkaPotrosnaRoba(izbor-1);
                account.ispisServisiranjaTenkaMunicija(izbor-1);
            }
            break;
        case 14:
            if(account.GetBrojTenkova()==0)
            {
                cout<<endl<<"*Garaza je prazna!*"<<endl<<endl;
            }
            else
            {
                account.izlistajNazive();
                cout<<"|>>>";
                cin>>izbor;
                cout<<endl;
                cout<<"|Izaberi modul: "<<endl;
                cout<<"|1. Top"<<endl;
                cout<<"|2. Kupola"<<endl;
                cout<<"|3. Motor"<<endl;
                cout<<"|4. Radio"<<endl;
                cout<<"|5. Vesanje"<<endl;
                cout<<"|>>>";
                cin>>izbor2;
                cout<<endl;
                account.UnaprediTenk(izbor-1, izbor2);
            }
            break;
        case 20:
            account.dodajKredit();
            break;
        case 21:
            account.dodajZlato();
            break;
        }
    }
    while(1);
    return 0;
}
