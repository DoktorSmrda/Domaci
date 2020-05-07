#ifndef CLAN_HPP_INCLUDED
#define CLAN_HPP_INCLUDED
#include "dinstring.hpp"

using namespace std;

class Clan
{
private:
    DinString imePrezime;
    DinString tip;
    int vestina;
    const DinString tipClanaPosade[5] = { "Komandir", "Nisandzija", "Vozac", "Radio operater", "Punilac" };
public:
    Clan()
    {
        imePrezime = tipClanaPosade[0];
        tip = tipClanaPosade[0];
        vestina = 0;
        povecajVestinu();
    }
    Clan(int t)
    {
        imePrezime = tipClanaPosade[t];
        tip = tipClanaPosade[t];
        vestina = 0;
        povecajVestinu();
    }
    Clan(DinString iP, int t)
    {
        imePrezime = iP;
        tip = tipClanaPosade[t];
        vestina = 0;
        povecajVestinu();
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
        cout <<"     Ime i prezime: "<< imePrezime << endl;
        cout <<"     Tip: " << tip << endl;
        cout <<"     Vestina: " << vestina << "%" << endl;
    }
    friend ostream& operator<<(ostream& out, Clan& clan)
    {
        out <<"     Ime i prezime: "<< clan.imePrezime << endl;
        out <<"     Tip: " << clan.tip << endl;
        out <<"     Vestina: " << clan.vestina << "%" << endl;
        return out;
    }
    int getVestinu()
    {
        return vestina;
    }
    DinString GetImePrezime()
    {
        return imePrezime;
    }
    DinString GetTip()
    {
        return tip;
    }
    void SetIme(DinString i)
    {
        imePrezime = i;
    }
    void SetTip(int index)
    {
        tip = tipClanaPosade[index];
    }
    void SetVestina(int v)
    {
        vestina = v;
    }
};

#endif // CLAN_HPP_INCLUDED
