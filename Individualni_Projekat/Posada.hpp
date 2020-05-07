#ifndef POSADA_HPP_INCLUDED
#define POSADA_HPP_INCLUDED
#include "Clan.hpp"
#include "list.hpp"

class Posada
{
private:
    List<Clan> clanovi;
    int brojClanova;
public:
    Posada()
    {
        brojClanova = 5;
        for (int i = 0; i < brojClanova; i++)
        {
            clanovi.Add(Clan(i));
        }
    }
    Posada(int k, DinString imena[])
    {
        brojClanova = k;
        for (int i = 0; i < brojClanova; i++)
        {
            clanovi.Add(Clan(imena[i], i));
        }
    }
    Posada(int k)
    {
        brojClanova = k;
        for(int i = 0;i<brojClanova;i++)
        {
            clanovi.Add(Clan(i));
        }
    }
    Clan& operator[](int index)
    {
        return clanovi[index];
    }
    friend ostream& operator<<(ostream& out, Posada& posada)
    {
        for(int i = 0;i < posada.brojClanova;i++)
            out<<posada.clanovi[i];
        return out;
    }
    void povecajVestinu()
    {
        for (int i = 0; i < brojClanova; i++)
        {
            clanovi[i].povecajVestinu();
        }
    }
    void getClanovi()
    {
        for (int i = 0; i < brojClanova; i++)
        {
            cout<<"     %i. Clan"<<i+1<<endl;
            clanovi[i].getInfo();
        }
    }
    int getVestinu()
    {
        int temp = 0;
        for (int i = 0; i < brojClanova; i++)
        {
            temp += clanovi[i].getVestinu();
        }
        return temp / brojClanova;
    }
    int getBrojPosade()
    {
        return brojClanova;
    }
};

#endif // POSADA_HPP_INCLUDED
