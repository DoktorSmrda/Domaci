#include <iostream>
#include "dinstring.hpp"
#include "list.hpp"
#include <time.h>
using namespace std;

enum tipTenka { LAKI = 1, SREDNJI, TESKI, ARTILJERIJA, LOVAC };
enum stanjeTenka { SPREMANZABORBU = 1, POTREBNAPOPRAVKA };

class Osobine
{
protected:
    int tezina;
    int level = 0;
public:
    Osobine()
    {
        tezina = 5000;
    }
    Osobine(int t)
    {
        tezina = t;
    }
};

class Servisiranje
{
private:
    const int cenaPotrosneRobe[7] = { 20000, 20000, 20000, 20000, 3000, 3000, 3000 };
    const int cenaMunicije[3] = { 14, 800, 14};
    const DinString PotrosnaRoba[7] =
    {
        "Veliki komplet za opravku",
        "Veiliki komplet prve pomoci",
        "Dodatna borbena sledovanja",
        "Automatski protivpozarni aparat",
        "Rucni protivpozarni aparat",
        "Mali komplet prve pomoci",
        "Mali alat za popravke"
    };
    const DinString Municija[3]
    {
        "45mm P",
        "45mm PP",
        "45mm FG"
    };
    int* potrosnaRoba;
    int* municija;
public:
    Servisiranje()
    {
        potrosnaRoba = (int*) calloc(7, sizeof(int));
        municija = (int*) calloc(3, sizeof(int));
    }
    bool kupiPotrosnuRobu(int index, int kolicina)
    {
        if (potrosnaRoba[index] + kolicina <= 10)
        {
            potrosnaRoba[index] += kolicina;
            return true;
        }
        return false;
    }
    bool kupiMuniciju(int index, int kolicina)
    {
        if (municija[0] + municija[1] + municija[2] + kolicina <= 200)
        {
            municija[index] += kolicina;
            return true;
        }
        return false;
    }
    int getCenaMunicije(int kolicna, int index)
    {
        return cenaMunicije[index] * kolicna;
    }
    int getCenaPotrosneRobe(int kolicina, int index)
    {
        return cenaPotrosneRobe[index] * kolicina;
    }
    int getPotrosnaRoba(int index)
    {
        return potrosnaRoba[index];
    }
    int getMunicija(int index)
    {
        return municija[index];
    }
    void potrosiMuniciju(int kolicina, int index)
    {
        municija[index] -= kolicina;
    }
    void potrosiPotrosnuRobu(int kolicina, int index)
    {
        potrosnaRoba[index] -= kolicina;
    }
    void getInfo()
    {
        cout << "Potornsa roba: " << endl;
        cout << "Veliki komplet za opravku: " << potrosnaRoba[0] << endl;
        cout << "Veiliki komplet prve pomoci: " << potrosnaRoba[1] << endl;
        cout << "Dodatna borbena sledovanja: " << potrosnaRoba[2] << endl;
        cout << "Automatski protivpozarni aparat: " << potrosnaRoba[3] << endl;
        cout << "Rucni protivpozarni aparat: " << potrosnaRoba[4] << endl;
        cout << "Mali komplet prve pomoci: " << potrosnaRoba[5] << endl;
        cout << "Mali alat za popravke: " << potrosnaRoba[6] << endl;
        cout << "Municija: " << endl;
        cout << "45mm P: " << municija[0] << endl;
        cout << "45mm PP: " << municija[1] << endl;
        cout << "45mm FG: " << municija[2] << endl;
    }
    int getBrojPotrosneRobe()
    {
        int temp = 0;
        for (int i = 0; i < 6; i++)
        {
            if (potrosnaRoba[i] > 0)
            {
                temp++;
            }
        }
        return temp;
    }
    int getBrojMunicije()
    {
        return municija[0] + municija[1] + municija[2];
    }
};

class Vesanje : public Osobine
{
private:
    int nosivost;
    int brzinaOkretanja;
public:
    Vesanje() : Osobine(t)
    {
        nosivost = 1;
        brzinaOkretanja = 1;
    }
    void unaprediVesanje()
    {

    }
};

class Motor : public Osobine
{
private:
    int snagaMotora;
    int sansaZaPozar;
public:
    Motor(tipTenka tip, int t) : Osobine(t)
    {
        switch(tip)
        {
        case LAKI:
            snagaMotora = 12;
            sansaZaPozar = 20;
            break;
        case SREDNJI:
            snagaMotora = 30;
            sansaZaPozar = 20;
            break;
        case TESKI:
            snagaMotora = 50;
            sansaZaPozar = 20;
            break;
        case ARTILJERIJA:
            snagaMotora = 70;
            sansaZaPozar = 20;
            break;
        case LOVAC:
            snagaMotora = 40;
            sansaZaPozar = 20;
            break;
        }
    }
    void unaprediMotor()
    {

    }
};

class Radio : public Osobine
{
private:
    int dometSignala;
public:
    Radio(tipTenka tip, int t) : Osobine(t)
    {
        switch(tip)
        {
        case LAKI:
            dometSignala = 650;
            break;
        case SREDNJI:
            dometSignala = 700;
            break;
        case TESKI:
            dometSignala = 800;
            break;
        case ARTILJERIJA:
            dometSignala = 1000;
            break;
        case LOVAC:
            dometSignala = 800;
            break;
        }
    }
    void unaprediRadio()
    {

    }
};

class Kupola : public Osobine
{
private:
    int oklop; /// milimetara
    int brzinaOkretanja; /// stepeni/sekundi
    int vidokrug; /// metara
public:
    Kupola(tipTenka tip, int t) : Osobine(t)
    {
        stats(tip);
    }
    void stats(tipTenka tip)
    {
        switch (tip)
        {
        case LAKI:
            brzinaOkretanja = 60;
            vidokrug = 220;
            break;
        case SREDNJI:
            brzinaOkretanja = 50;
            vidokrug = 230;
            break;
        case TESKI:
            brzinaOkretanja = 40;
            vidokrug = 250;
            break;
        case ARTILJERIJA:
            brzinaOkretanja = 20;
            vidokrug = 290;
            break;
        case LOVAC:
            brzinaOkretanja = 60;
            vidokrug = 300;
            break;
        }
    }
    void unaprediKupolu()
    {

    }
};

class Top : public Osobine
{
private:
    int brzinaPucanja; /// granata/minuti
    int prosecnaProbojnost;/// milimetara
    int prosecnaSteta;/// HP
    int vremeNisanjenja;/// sekunde
public:
    Top() : Osobine(t)
    {
        brzinaPucanja = 1;
        prosecnaProbojnost = 1;
        prosecnaSteta = 1;
        vremeNisanjenja = 1;
    }
    void unaprediTop(int stat)
    {
        switch(stat)
        {
        case 1:
            brzinaPucanja++;
            break;
        case 2:
            prosecnaProbojnost++;
            break;
        case 3:
            prosecnaSteta++;
            break;
        case 4:
            vremeNisanjenja++;
            break;
        }
    }
};

class TehnickeKarakteristike
{
private:
    int vatrenaMoc;
    int izdrzljvost;
    int pokretljivost;
    int sakrivenost;
    int opazanje;
public:
    TehnickeKarakteristike()
    {
        vatrenaMoc = 1;
        izdrzljvost = 1;
        pokretljivost = 1;
        sakrivenost = 1;
        opazanje = 1;
    }
};

class Clan
{
private:
    DinString imePrezime;
    DinString tip;
    int vestina;
    const DinString tipClanaPosade[5] = { "Komandir", "Nisandzija", "Vozac", "Radio operater", "Punilac" };
public:
    Clan(int t)
    {
        imePrezime = tipClanaPosade[t];
        tip = tipClanaPosade[t];
        vestina = 0;
    }
    Clan(DinString iP, int t)
    {
        imePrezime = iP;
        tip = tipClanaPosade[t];
        vestina = 0;
    }
    void povecajVestinu()
    {
        if (vestina < 100)
        {
            vestina += rand() % 20 + 1;
            if (vestina > 100)
            {
                vestina = 100;
            }
        }
    }
    void getInfo()
    {
        cout <<"Ime i prezime: "<< imePrezime << endl;
        cout << "Tip: " << tip << endl;
        cout << "Vestina: " << vestina << "%" << endl;
    }
    int getVestinu()
    {
        return vestina;
    }
};

class Posada
{
private:
    List<Clan> clanovi;
    int kolicina;
public:
    Posada()
    {
        kolicina = 5;
        for (int i = 0; i < kolicina; i++)
        {
            clanovi.Add(Clan(i));
        }
    }
    Posada(int k, DinString imena[])
    {
        kolicina = k;
        for (int i = 0; i < kolicina; i++)
        {
            clanovi.Add(Clan(imena[i], i));
        }
    }
    Clan& operator[](int index)
    {
        return clanovi[index];
    }
    void povecajVestinu()
    {
        for (int i = 0; i < kolicina; i++)
        {
            clanovi[i].povecajVestinu();
        }
    }
    void getClanovi()
    {
        for (int i = 0; i < kolicina; i++)
        {
            clanovi[i].getInfo();
        }
    }
    int getVestinu()
    {
        int temp;
        for (int i = 0; i < kolicina; i++)
        {
            temp += clanovi[i].getVestinu();
        }
        return temp / kolicina;
    }
    int getBrojPosade()
    {
        return kolicina;
    }
};

class Tenk : public Osobine, public Servisiranje
{
private:
    const DinString drzave[11] = { "Nemacka", "SSSR", "SAD", "Francuska", "Velika Britanija", "Kina", "Japan", "Cehoslovacka vozila", "Poljska", "Svedska", "Italija" };
    DinString drzava;
    DinString naziv;
    stanjeTenka stanje;
    Top top;
    Kupola kupola;
    Motor motor;
    Radio radio;
    Vesanje vesanje;
    Posada posada;
    float sansaZaPobedu;
    int cena;
public:
    Tenk() : Osobine(), Servisiranje(), top(LAKI, 1500), kupola(LAKI, 500), motor(LAKI, 500), radio(LAKI, 500), vesanje(LAKI, 2000), posada()
    {
        drzava = drzave[0];
        naziv = "Leihttraktor";
        tip = LAKI;
        stanje = SPREMANZABORBU;
        cena = 50000;
        sansaZaPobedu = 0;
        sansaZaPobedu += posada.getVestinu()/5;
    }
    Tenk(int d, DinString n, int t, int k, DinString imena[]) : Osobine(t), top(tezina / 3.3), kupola(tezina / 10), motor(tezina / 10), radio(tezina / 10), vesanje(tezina / 2.5), posada(k, imena)
    {
        drzava = drzave[d];
        naziv = n;
        stanje = SPREMANZABORBU;
        cena = rand() % 100000 + 50000;
        sansaZaPobedu = 0;
        sansaZaPobedu += posada.getVestinu() / posada.getBrojPosade();
    }
    void unaprediTop(int stat)
    {
        top.
    }
    void unaprediVesanje()
    {
        vesanje.unaprediVesanje();
    }
    void unaprediKupolu()
    {
        kupola.unaprediKupolu();
    }
    void unaprediRadio()
    {
        radio.unaprediRadio();
    }
    void unaprediMotor()
    {
        motor.unaprediMotor();
    }
    void promeniStanje()
    {
        int indexMunicije = rand() % 2;
        int indexPotrosneRobe = rand() % 6;
        stanje = POTREBNAPOPRAVKA;
        posada.povecajVestinu();
        potrosiMuniciju(getMunicija(indexMunicije) / 3, indexMunicije);
        potrosiPotrosnuRobu(getPotrosnaRoba(indexPotrosneRobe)-1, indexPotrosneRobe);
        sansaZaPobedu = 0;
        sansaZaPobedu += posada.getVestinu() / posada.getBrojPosade();
    }
    int getCena()
    {
        return cena;
    }
    void popraviTenk()
    {
        stanje = SPREMANZABORBU;
    }
    stanjeTenka getStanje()
    {
        return stanje;
    }
    void municija(int kolicina, int index)
    {
        kupiMuniciju(index, kolicina);
    }
    void potrosnaRoba(int kolicina,int index)
    {
        kupiPotrosnuRobu(index, kolicina);
    }
    int getSansaZaPobedu()
    {
        sansaZaPobedu += getBrojPotrosneRobe()*5.7f;
        sansaZaPobedu += getBrojMunicije() * 0.2f;
        return sansaZaPobedu;
    }
};

class Laki : public Tenk
{
public:
};

class Srednji : public Tenk
{

};

class Teski : public Tenk
{

};

class Lovac : public Tenk
{

};

class Artiljerija : public Tenk
{

};

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
    Account(DinString Username, DinString Password)
    {
        username = Username;
        password = Password;
        krediti = 1000000;
        zlato = 600;
        brojSlobodnihMesta = 2;
        brojTenkova = 0;
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
            cout << "Tenk mora biti spreman za borbu";
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
        int sansa = rand() % 100 + 1;
        if (garaza[indexTenka].getSansaZaPobedu() > sansa)
        {
            cout << "Vicotry";
            krediti += rand() % 100000 + 40000;
        }
        else
        {
            cout << "Lose";
            krediti += rand() % 50000 + 20000;
        }
        garaza[indexTenka].promeniStanje();
    }
    bool popraviTenk(int indexTenka)
    {
        int temp=rand()%10000+1;
        if (garaza[indexTenka].getStanje() == POTREBNAPOPRAVKA && krediti-temp>=0)
        {
            krediti -= temp;
            garaza[indexTenka].popraviTenk();
            return true;
        }
        else
        {
            if (krediti - temp < 0)
            {
                cout << "Nedostatak kredita";
            }
            else
            {
                cout << "Tenk je vec popravljen";
            }
        }
    }
    bool kupiPotrosnuRobu(int kolicina, int index)
    {
        if (krediti - servisiranje.getCenaPotrosneRobe(kolicina, index) >= 0 && servisiranje.kupiPotrosnuRobu(index, kolicina))
        {
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
        if (krediti - servisiranje.getCenaPotrosneRobe(kolicina, index) >= 0 && servisiranje.kupiMuniciju(index, kolicina))
        {
            krediti -= servisiranje.getCenaPotrosneRobe(kolicina, index);
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
            garaza[indexTenka].municija(kolicina, indexMunicije);
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
            garaza[indexTenka].potrosnaRoba(kolicina, indexPotrosneRobe);
            servisiranje.potrosiPotrosnuRobu(kolicina, indexPotrosneRobe);
            return true;
        }
        else
        {
            return false;
        }
    }

};

class OsnovneKarakteristike
{
private:
    float specificnaSnaga;
    int maksimalnaBrzina;
    int brzinaUnazad;
    float brzinaOkretanja;
    int vidokrug;
public:
    OsnovneKarakteristike()
    {
        specificnaSnaga = 1;
        maksimalnaBrzina = 1;
        brzinaUnazad = 1;
        brzinaOkretanja = 1;
        vidokrug = 1;
    }
};

int main()
{
    srand(time(0));
    return 0;
}
