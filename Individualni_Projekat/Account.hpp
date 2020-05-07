#ifndef ACCOUNT_HPP_INCLUDED
#define ACCOUNT_HPP_INCLUDED
#include "Tenk.hpp"

class Account
{
private:
    DinString username;
    DinString password;
    int krediti;
    int zlato;
    int brojSlobodnihMesta;
    int brojTenkova;
    List<Tenk> garaza;
    Servisiranje servisiranje;
public:
    Account()
    {
        username = "Freeze";
        password = "Uredu je";
        krediti = 1000000;
        zlato = 600;
        brojSlobodnihMesta = 2;
        brojTenkova = 0;
    }
    Account(DinString Username, DinString Password, int Krediti, int Zlato, int BrojSlobodnihMesta, int BrojTenkova)
    {
        username = Username;
        password = Password;
        krediti = Krediti;
        zlato = Zlato;
        brojSlobodnihMesta = BrojSlobodnihMesta;
        brojTenkova = BrojTenkova;
    };
    Account(Account& account)
    {
        username = account.username;
        password = account.password;
        krediti = account.krediti;
        zlato = account.zlato;
        brojSlobodnihMesta = account.brojSlobodnihMesta;
        brojTenkova = account.brojTenkova;
    }
    friend ostream& operator<<(ostream& out, Account& account)
    {
        out<<"| "<<account.username;
        out<<" | Krediti: "<<account.krediti;
        out<<" | Zlato: "<<account.zlato;
        out<<" | Broj slobodnih mesta: "<<account.brojSlobodnihMesta;
        out<<" | Broj tenkova: "<<account.brojTenkova<<" |"<<endl<<endl;
        return out;
    }
    Account& operator+=(Tenk& tenk)
    {
        if(brojSlobodnihMesta !=0 && (krediti - tenk.getCena()) >= 0)
        {
            garaza.Add(&tenk);
            krediti-=tenk.getCena();
            brojTenkova++;
            brojSlobodnihMesta--;
        }
        return *this;
    }
    Account& operator+=(Tenk* tenk)
    {
        if(brojSlobodnihMesta !=0 && (krediti - tenk->getCena()) >= 0)
        {
            garaza.Add(tenk);
            krediti-=tenk->getCena();
            brojTenkova++;
            brojSlobodnihMesta--;
        }
        return *this;
    }
    bool kupiTenk(Tenk* tenkZaKupovinu)
    {
        if (brojSlobodnihMesta != 0 && (krediti - tenkZaKupovinu->getCena()) >= 0)
        {
            brojSlobodnihMesta--;
            garaza.Add(tenkZaKupovinu);
            krediti -= garaza[brojTenkova].getCena();
            brojTenkova++;
            return true;
        }
        else
        {
            return false;
        }
    }
    bool prodajTenk(int indexTenka)
    {
        if (garaza[indexTenka].getStanje() == SPREMANZABORBU)
        {
            brojSlobodnihMesta++;
            brojTenkova--;
            krediti += garaza[indexTenka].getCena() / 2;
            garaza.RemoveAt(indexTenka);
            return true;
        }
        else
        {
            cout<<endl<< "*Tenk mora biti spreman za borbu!*"<<endl;
            return false;
        }
    }
    bool kupiSlot()
    {
        if (zlato >= 300)
        {
            brojSlobodnihMesta++;
            zlato -= 300;
            return true;
        }
        else
            return false;
    }
    void dodajKredit()
    {
        krediti += 50000;
    }
    void dodajZlato()
    {
        zlato += 500;
    }
    void uBorbu(int indexTenka)
    {
        if(garaza[indexTenka].getStanje()==SPREMANZABORBU)
        {
            int sansa = rand() % 100 + 1;
            if (garaza[indexTenka].getSansaZaPobedu() > sansa)
            {
                cout<<"*Pobeda!*"<<endl<<endl;
                krediti += rand() % 100000 + 40000;
            }
            else
            {
                cout<<"*Poraz!*"<<endl<<endl;
                krediti -= rand() % 10000+1;
            }
            garaza[indexTenka].promeniStanje();
        }
        else
        {
            cout<<"Tenk nije spreman za borbu!"<<endl<<endl;
        }
    }
    int popraviTenk(int indexTenka)
    {
        if(garaza[indexTenka].getStanje()==SPREMANZABORBU)
        {
            cout<<endl<<"*Tenk je spreman za borbu!*"<<endl;
            return 0;
        }
        int temp=rand()%10000+1;
        if (krediti-temp>=0)
        {
            krediti -= temp;
            garaza[indexTenka].popraviTenk();
            cout<<"*Tenk je popraljen!*"<<endl<<endl;
            return temp;
        }
        else
        {
            return 0;
            cout<<endl << "*Nedostatak kredita!*"<<endl;
        }
    }
    bool kupiPotrosnuRobu(int kolicina, int index)
    {
        if (krediti - servisiranje.getCenaPotrosneRobe(kolicina, index) >= 0)
        {
            servisiranje.DodajPotrosnuRobu(index, kolicina);
            krediti -= servisiranje.getCenaPotrosneRobe(kolicina, index);
            return true;
        }
        else
        {
            return false;
        }
    }
    bool kupiMuniciju(int kolicina, int index)
    {
        if (krediti - servisiranje.getCenaMunicije(kolicina, index) >= 0)
        {
            servisiranje.DodajMuniciju(index, kolicina);
            krediti -= servisiranje.getCenaMunicije(kolicina, index);
            return true;
        }
        else
        {
            return false;
        }
    }
    bool napuniTenk(int indexTenka, int kolicina, int indexMunicije)
    {
        if (servisiranje.getMunicija(indexMunicije) >= kolicina)
        {
            bool provera = garaza[indexTenka].municija(kolicina, indexMunicije);
            if(provera)
                servisiranje.potrosiMuniciju(kolicina, indexMunicije);
            return true;
        }
        else
        {
            return false;
        }
    }
    bool servisirajTenk(int indexTenka, int kolicina, int indexPotrosneRobe)
    {
        if (servisiranje.getPotrosnaRoba(indexPotrosneRobe) >= kolicina)
        {
            bool provera = garaza[indexTenka].potrosnaRoba(kolicina, indexPotrosneRobe);
            if(provera)
                servisiranje.potrosiPotrosnuRobu(kolicina, indexPotrosneRobe);
            return true;
        }
        else
        {
            return false;
        }
    }
    void ispisTenka(int index)
    {
        cout<<garaza[index];
    }
    void izlistajNazive()
    {
        cout<<endl;
        for(int i = 0;i<brojTenkova;i++)
        {
            cout<<"|"<<i+1<<". "<<garaza[i].GetNaziv()<<endl;
        }
    }
    int GetBrojTenkova()
    {
        return brojTenkova;
    }
    void ispisServisiranja()
    {
        servisiranje.GetInfoPotrosnaRoba();
        servisiranje.GetInfoMunicija();
    }
    void ispisPotrosnaRoba()
    {
        servisiranje.GetInfoPotrosnaRoba();
    }
    void ispisMunicija()
    {
        servisiranje.GetInfoMunicija();
    }
    List<Tenk> GetGaraza()
    {
        return garaza;
    }
    void ispisServisiranjaTenkaPotrosnaRoba(int index)
    {
        garaza[index].GetInfoPotrosnaRoba();
    }
    void ispisServisiranjaTenkaMunicija(int index)
    {
        garaza[index].GetInfoMunicija();
    }
    Servisiranje GetServisiranje()
    {
        return servisiranje;
    }
    void UnaprediTenk(int indexTenka, int odabir)
    {
        switch(odabir)
        {
        case 1:
            garaza[indexTenka].unaprediTop();
            break;
        case 2:
            garaza[indexTenka].unaprediKupolu();
            break;
        case 3:
            garaza[indexTenka].unaprediMotor();
            break;
        case 4:
            garaza[indexTenka].unaprediRadio();
            break;
        case 5:
            garaza[indexTenka].unaprediVesanje();
            break;
        }
    }
};

#endif // ACCOUNT_HPP_INCLUDED
