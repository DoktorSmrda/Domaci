#ifndef VESANJE_HPP_INCLUDED
#define VESANJE_HPP_INCLUDED
#include "DeoTenka.hpp"

class Vesanje : public DeoTenka
{
private:
    int nosivost;
    int brzinaOkretanja;
public:
    Vesanje() : DeoTenka()
    {
        stats(LAKI);
    }
    Vesanje(tipTenka tip) : DeoTenka()
    {
        stats(tip);
    }
    Vesanje(int n, int bO)
    {
        nosivost = n;
        brzinaOkretanja = bO;
    }
    Vesanje(Vesanje& vesanje)
    {
        nosivost = vesanje.nosivost;
        brzinaOkretanja = vesanje.brzinaOkretanja;
    }
    void stats(tipTenka tip)
    {
        switch(tip)
        {
        case LAKI:
            nosivost = 5000 * level;
            brzinaOkretanja = 70 * level;
            break;
        case SREDNJI:
            nosivost = 5000 * level;
            brzinaOkretanja = 60 * level;
            break;
        case TESKI:
            nosivost = 5000 * level;
            brzinaOkretanja = 50 * level;
            break;
        case ARTILJERIJA:
            nosivost = 5000 * level;
            brzinaOkretanja = 30 * level;
            break;
        case LOVAC:
            nosivost = 5000 * level;
            brzinaOkretanja = 40 * level;
            break;
        }
    }
    void unapredi(tipTenka tip)
    {
        LevelUp();
        stats(tip);
    }
    friend ostream& operator<<(ostream& out, Vesanje& vesanje)
    {
        out<<"          Nosivost: "<<vesanje.nosivost<<endl;
        out<<"          Brzina okretanja: "<<vesanje.brzinaOkretanja<<endl;
        return out;
    }
    int GetNosivost()
    {
        return nosivost;
    }
    int GetBrzinaOkretanja()
    {
        return brzinaOkretanja;
    }
    void SetNosivost(int n)
    {
        nosivost = n;
    }
    void SetBrzinaOkretanja(int bO)
    {
        brzinaOkretanja = bO;
    }
};

#endif // VESANJE_HPP_INCLUDED
