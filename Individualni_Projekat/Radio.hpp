#ifndef RADIO_H_INCLUDED
#define RADIO_H_INCLUDED
#include "DeoTenka.hpp"

class Radio : public DeoTenka
{
private:
    int dometSignala;
public:
    Radio() : DeoTenka()
    {
        stats(LAKI);
    }
    Radio(tipTenka tip) : DeoTenka()
    {
        stats(tip);
    }
    Radio(int dS)
    {
        dometSignala = dS;
    }
    Radio(Radio& radio)
    {
        dometSignala = radio.dometSignala;
    }
    void stats(tipTenka tip)
    {
        switch(tip)
        {
        case LAKI:
            dometSignala = 650 * level;
            break;
        case SREDNJI:
            dometSignala = 700 * level;
            break;
        case TESKI:
            dometSignala = 800 * level;
            break;
        case ARTILJERIJA:
            dometSignala = 1000 * level;
            break;
        case LOVAC:
            dometSignala = 800 * level;
            break;
        }
    }
    void unapredi(tipTenka tip)
    {
        LevelUp();
        stats(tip);
    }
    friend ostream& operator<<(ostream& out, Radio radio)
    {
        out<<"          Domet signala:"<<radio.dometSignala<<endl;
        return out;
    }
};

#endif // RADIO_H_INCLUDED
