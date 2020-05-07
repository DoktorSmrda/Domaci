#ifndef KUPOLA_H_INCLUDED
#define KUPOLA_H_INCLUDED
#include "DeoTenka.hpp"

class Kupola : public DeoTenka
{
private:
    int oklop; /// milimetara
    int brzinaOkretanja; /// stepeni/sekundi
    int vidokrug; /// metara
public:
    Kupola() : DeoTenka()
    {
        stats(LAKI);
    }
    Kupola(tipTenka tip) : DeoTenka()
    {
        stats(tip);
    }
    Kupola(int o, int bO, int v)
    {
        oklop = o;
        brzinaOkretanja = bO;
        vidokrug = v;
    }
    Kupola(Kupola& kupola)
    {
        oklop = kupola.oklop;
        brzinaOkretanja = kupola.brzinaOkretanja;
        vidokrug = kupola.vidokrug;
    }
    void stats(tipTenka tip)
    {
        switch (tip)
        {
        case LAKI:
            oklop = 10*level;
            brzinaOkretanja = 60 * level;
            vidokrug = 220 * level;
            break;
        case SREDNJI:
            oklop = 15*level;
            brzinaOkretanja = 50 * level;
            vidokrug = 230 * level;
            break;
        case TESKI:
            oklop = 20*level;
            brzinaOkretanja = 40 * level;
            vidokrug = 250 * level;
            break;
        case ARTILJERIJA:
            oklop = 7*level;
            brzinaOkretanja = 20 * level;
            vidokrug = 290 * level;
            break;
        case LOVAC:
            oklop = 18*level;
            brzinaOkretanja = 60 * level;
            vidokrug = 300 * level;
            break;
        }
    }
    void unapredi(tipTenka tip)
    {
        LevelUp();
        stats(tip);
    }
    friend ostream& operator<<(ostream& out, Kupola& kupola)
    {
        out<<"         Oklop: "<<kupola.oklop<<endl;
        out<<"         Brzina okretanja: "<<kupola.brzinaOkretanja<<endl;
        out<<"         Vidokrug: "<<kupola.vidokrug<<endl;
        return out;
    }
};

#endif // KUPOLA_H_INCLUDED
