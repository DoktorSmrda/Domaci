#ifndef TENK_HPP_INCLUDED
#define TENK_HPP_INCLUDED
#include "Servisiranje.hpp"
#include "Radio.hpp"
#include "Posada.hpp"
#include "Vesanje.hpp"
#include "Kupola.hpp"
#include "Top.hpp"
#include "dinstring.hpp"
#include "Servisiranje.hpp"
#include "Motor.hpp"
#include <iostream>

using namespace std;

enum stanjeTenka { SPREMANZABORBU = 1, POTREBNAPOPRAVKA };

class Tenk
{
private:
    const DinString drzave[11] = { "Nemacka", "SSSR", "SAD", "Francuska", "Velika Britanija", "Kina", "Japan", "Cehoslovacka vozila", "Poljska", "Svedska", "Italija" };
    const DinString Tipovi[5] = { "Laki", "Srenjdi", "Teski", "Artiljerija", "Lovac" };
    DinString drzava;
    DinString naziv;
    stanjeTenka stanje;
    Top top;
    Kupola kupola;
    Motor motor;
    Radio radio;
    Vesanje vesanje;
    Posada posada;
    tipTenka tip;
    DinString Tip;
    float sansaZaPobedu;
    int cena;
    Servisiranje servisiranje;
public:
    Tenk() : servisiranje(), top(LAKI), kupola(LAKI), motor(LAKI), radio(LAKI), vesanje(LAKI), posada()
    {
        drzava = drzave[0];
        naziv = "Leihttraktor";
        tip = LAKI;
        Tip = Tipovi[(int)LAKI-1];
        stanje = SPREMANZABORBU;
        cena = 50000;
        sansaZaPobedu = 0;
        sansaZaPobedu += posada.getVestinu()/2;
    }
    Tenk(tipTenka TipTenka, int d, DinString n, int k, DinString imena[]) : servisiranje(),top(TipTenka), kupola(TipTenka), motor(TipTenka), radio(TipTenka), vesanje(TipTenka), posada(k, imena)
    {
        drzava = drzave[d];
        naziv = n;
        stanje = SPREMANZABORBU;
        cena = rand() % 100000 + 50000;
        sansaZaPobedu = 0;
        sansaZaPobedu += posada.getVestinu()/2;
        tip = TipTenka;
        Tip = Tipovi[(int)tip-1];
    }
    Tenk(tipTenka TipTenka, int d, DinString n, int k) : servisiranje(),top(TipTenka), kupola(TipTenka), motor(TipTenka), radio(TipTenka), vesanje(TipTenka), posada(k)
    {
        drzava = drzave[d];
        naziv = n;
        stanje = SPREMANZABORBU;
        cena = rand() % 100000 + 50000;
        sansaZaPobedu = 0;
        sansaZaPobedu += posada.getVestinu() / 2;
        tip = TipTenka;
        Tip = Tipovi[(int)tip-1];
    }
    Tenk(Tenk& tenk) : servisiranje(), top(tenk.tip), kupola(tenk.tip), motor(tenk.tip), radio(tenk.tip), vesanje(tenk.tip), posada()
    {
        drzava = tenk.drzava;
        naziv = tenk.naziv;
        stanje = tenk.stanje;
        cena = tenk.cena;
        sansaZaPobedu = tenk.sansaZaPobedu;
        tip = tenk.tip;
        Tip = tenk.Tip;
    }
    friend ostream& operator<<(ostream& out, Tenk& tenk)
    {
        out<<"----------------------------------------------------------------------------------------------------"<<endl;
        out<<"Naziv tenka: "<<tenk.naziv<<endl;
        out<<"Drzava: "<<tenk.drzava<<endl;
        out<<"Tip tenka: "<<tenk.Tip<<endl;
        out<<"Sansa sa pobedu: "<<tenk.sansaZaPobedu<<"%"<<endl;
        out<<"Stanje: "<<((tenk.stanje == SPREMANZABORBU)?"Spreman za borbu":"Potrebna popravka")<<endl;
        out<<"Delovi tenka: "<<endl;
        out<<"     Top:"<<endl;
        out<<tenk.top;
        out<<"     Kupola:"<<endl;
        out<<tenk.kupola;
        out<<"     Motor:"<<endl;
        out<<tenk.motor;
        out<<"     Vesanje:"<<endl;
        out<<tenk.vesanje;
        out<<"     Radio:"<<endl;
        out<<tenk.radio;
        out<<"Posada: "<<endl;
        out<<tenk.posada;
        out<<"----------------------------------------------------------------------------------------------------"<<endl;
        return out;
    }
    Tenk& operator=(Tenk& tenk)
    {
        drzava = tenk.drzava;
        naziv = tenk.naziv;
        stanje = tenk.stanje;
        top = tenk.top;
        kupola = tenk.kupola;
        motor = tenk.motor;
        vesanje = tenk.vesanje;
        radio = tenk.radio;
        posada = tenk.posada;
        tip = tenk.tip;
        Tip = tenk.Tip;
        sansaZaPobedu = tenk.sansaZaPobedu;
        cena = tenk.cena;
        return *this;
    }
    void unaprediTop()
    {
        top.unapredi(tip);
    }
    void unaprediVesanje()
    {
        vesanje.unapredi(tip);
    }
    void unaprediKupolu()
    {
        kupola.unapredi(tip);
    }
    void unaprediRadio()
    {
        radio.unapredi(tip);
    }
    void unaprediMotor()
    {
        motor.unapredi(tip);
    }
    void promeniStanje()
    {
        int indexMunicije = rand()%3;
        int indexPotrosneRobe = rand()%7;
        stanje = POTREBNAPOPRAVKA;
        posada.povecajVestinu();
        potrosiMuniciju(getMunicija(indexMunicije) / 3, indexMunicije);
        potrosiPotrosnuRobu(1, indexPotrosneRobe);
        sansaZaPobedu = 0;
        sansaZaPobedu += posada.getVestinu() / 2;
    }
    void popraviTenk()
    {
        stanje = SPREMANZABORBU;
    }
    bool municija(int kolicina, int index)
    {
        return kupiMuniciju(index, kolicina);
    }
    bool potrosnaRoba(int kolicina,int index)
    {
        return kupiPotrosnuRobu(index, kolicina);
    }
    int getSansaZaPobedu()
    {
        sansaZaPobedu = 0;
        sansaZaPobedu += posada.getVestinu() / 2;
        sansaZaPobedu += getBrojPotrosneRobe()*3.57f;
        sansaZaPobedu += getBrojMunicije() * 0.125f;
        if(sansaZaPobedu>100)
            sansaZaPobedu = 100;
        return sansaZaPobedu;
    }
    DinString GetNaziv()
    {
        return naziv;
    }
    int getCena()
    {
        return cena;
    }
    stanjeTenka getStanje()
    {
        return stanje;
    }
    DinString GetTip()
    {
        return Tip;
    }
    tipTenka Gettip()
    {
        return tip;
    }
    Kupola GetKupola()
    {
        return kupola;
    }
    Top GetTop()
    {
        return top;
    }
    Vesanje GetVesanje()
    {
        return vesanje;
    }
    Radio GetRadio()
    {
        return radio;
    }
    Motor GetMotor()
    {
        return motor;
    }
    Posada GetPosada()
    {
        return posada;
    }
};

#endif // TENK_HPP_INCLUDED
