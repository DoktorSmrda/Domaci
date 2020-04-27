#include <iostream>
using namespace std;

class Osobine
{
protected:
    int nivo;
    int tezina; /// kg
public:
    Osobine(int n, int t)
    {
        nivo = n;
        tezina = t;
    }
    bool SetTezina()
    {
        return true;
    }
};

enum tipTenka {LAKI = 1, SREDNJI, TESKI, ARTILJERIJA, LOVAC};

class Vesanje : public Osobine
{
private:
    int nosivost;
    int brzinaOkretanja;
public:
    Vesanje(int lvl, tipTenka tip, int t)
    {

    }
};

class Motor : public Osobine
{
private:
    int snagaMotora;
    int sansaZaPozar;
public:
    Motor(int lvl, tipTenka tip, int t)
    {

    }
};

class Radio : public Osobine
{
private:
    int dometSignala;
public:
    Radio(int lvl, tipTenka tip, int t) : Osobine(lvl, t)
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
    Kupola(int lvl, tipTenka tip, int t) : Osobine(lvl, t)
    {
        switch(tip)
        {
        case 1:
            brzinaOkretanja = 60
            vidokrug = 220
            break;
        case 2:
            brzinaOkretanja = 50
            vidokrug = 230
            break;
        case 3:
            brzinaOkretanja = 40
            vidokrug = 250
            break;
        case 4:
            brzinaOkretanja = 20
            vidokrug = 290
            break;
        case 5:
            brzinaOkretanja = 60
            vidokrug = 300
            break;
        }
    }
};

class Top : public Osobine
{
private:
    float brzinaPucanja; /// granata/minuti
    int prosecnaProbojnost;/// milimetara
    int prosecnaSteta;/// HP
    float vremeNisanjenja;/// sekunde
public:
    Top(int lvl, tipTenka tip, int t) : Osobine(lvl, t)
    {
        switch(tip)
        {
        case 1: /// LAKI
            brzinaPucanja = 20;
            prosecnaProbojnost = 20;
            vremeNisanjenja = 2;
            break;
        case 2: /// SREDNJI
            brzinaPucanja = 15;
            vremeNisanjenja = 3;
            break;
        case 3: /// TESKI
            brzinaPucanja = 6;
            vremeNisanjenja = 4;
            break;
        case 4: ///ARTILJERIJA
            brzinaPucanja = 3;
            vremeNisanjenja = 12;
            break;
        case 5: /// LOVAC
            brzinaPucanja = 10;
            vremeNisanjenja = 7;
            break;
        }
    }
};

class TehnickeKarakteristike
{
private:
    int vatrenaMoc; /// steta/granata
    int izdrzljvost; /// HP
    int pokretljivost; /// km/h
    int sakrivenost; /// %
    int opazanje; /// metara
public:
    TehnickeKarakteristike(int lvl)
    {
        vatrenaMoc = 10+50*lvl;
        ///izdrzljvost = 40*lvl;
        ///pokretljivost = ;
        sakrivenost = 9*lvl;
        opazanje = 150+100*lvl;
    }
};

class OsnovneKarakteristike
{
private:
    float specificnaSnaga; /// snaga
    int maksimalnaBrzina; /// km/h
    int brzinaUnazad; /// km/h
    float brzinaOkretanja; /// stepeni/sekundi
    int vidokrug; /// metara
public:
    OsnovneKarakteristike(int lvl)
    {
        specificnaSnaga = 5 * lvl;
        maksimalnaBrzina = 10 + 9 * lvl;
        brzinaUnazad = maksimalnaBrzina / 3;
        brzinaOkretanja = 24 + 6 * lvl;
        vidokrug = 160 + 40 * lvl;
    }
    OsnovneKarakteristike(float sS, int mB, int bU, float bO, int v)
    {
        specificnaSnaga = sS;
        maksimalnaBrzina = mB;
        brzinaUnazad = bU;
        brzinaOkretanja = bO;
        vidokrug = v;
    }
};

class Clan
{
private:
    string imePrezime;
    string tip;
    const string tipClanaPosade[5] = {"Komandir", "Nisandzija", "Vozac", "Radio operater", "Punilac"};
public:
    Clan(string iP, int t)
    {
        imePrezime = iP;
        tip = tipClanaPosade[t];
    }
};

class Posada
{
private:
    Clan *clanovi;
    int kolicina;
    int vestina;
public:
    Posada(int k, int v)
    {
        kolicina = k;
        vestina = v;
        clanovi = (Clan*) malloc(sizeof(Clan)*k);
    }
    Clan &operator[](int index)
    {
        return clanovi[index];
    }
};

class Tenk : public Osobine
{
protected:
    const string drzave[11] = {"Nemacka", "SSSR", "SAD", "Francuska", "Velika Britanija", "Kina", "Japan", "Cehoslovacka vozila", "Poljska", "Svedska", "Italija"};
    string drzava;
    string naziv;
    tipTenka tip;
    Top top;
    Kupola kupola;
    Motor motor;
    Radio radio;
    Vesanje vesanje;
    Posada posada;
    TehnickeKarakteristike tehnickeKarakteristike;
    OsnovneKarakteristike osnovneKarakteristike;
public:
    Tenk(int d, string n, int lvl, tipTenka t, int tez) : Osobine(lvl, tez), top(lvl, t, tez/27.5), kupola(lvl, t, tez/2.75), motor(lvl, t, tez/22), radio(lvl, t, tez/110), vesanje(lvl, t, tez/1.6), posada(), tehnickeKarakteristike(lvl), osnovneKarakteristike()
    {
        drzava = drzave[d];
        naziv = n;
        tip = t;
    }
};

class PremiumTenk : public Tenk
{

};

class ObicanTenk : public Tenk
{

};

int main()
{

    return 0;
}
