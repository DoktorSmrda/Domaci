#ifndef TOP_H_INCLUDED
#define TOP_H_INCLUDED
#include "DeoTenka.hpp"

class Top : public DeoTenka
{
private:
    int brzinaPucanja; /// granata/minuti
    int prosecnaProbojnost;/// milimetara
    int prosecnaSteta;/// HP
    int vremeNisanjenja;/// sekunde
public:
    Top() : DeoTenka()
    {
        stats(LAKI);
    }
    Top(tipTenka tip) : DeoTenka()
    {
        stats(tip);
    }
    Top(int bP, int pP, int pS, int vN)
    {
        brzinaPucanja = bP;
        prosecnaProbojnost = pP;
        prosecnaSteta = pS;
        vremeNisanjenja = vN;
    }
    Top(Top& top)
    {
        brzinaPucanja = top.brzinaPucanja;
        prosecnaProbojnost = top.prosecnaProbojnost;
        prosecnaSteta = top.prosecnaSteta;
        vremeNisanjenja = top.vremeNisanjenja;
    }
    void stats(tipTenka tip)
    {
        switch(tip)
        {
        case LAKI:
            brzinaPucanja = 30 * level;
            prosecnaProbojnost = 300 * level;
            prosecnaSteta = 150 * level;
            vremeNisanjenja = 4 * level;
            break;
        case SREDNJI:
            brzinaPucanja = 25 * level;
            prosecnaProbojnost = 500 * level;
            prosecnaSteta = 200 * level;
            vremeNisanjenja = 6 * level;
            break;
        case TESKI:
            brzinaPucanja = 10 * level;
            prosecnaProbojnost = 700 * level;
            prosecnaSteta = 350 * level;
            vremeNisanjenja = 7 * level;
            break;
        case ARTILJERIJA:
            brzinaPucanja = 2 * level;
            prosecnaProbojnost = 1000 * level;
            prosecnaSteta = 600 * level;
            vremeNisanjenja = 13 * level;
            break;
        case LOVAC:
            brzinaPucanja = 6 * level;
            prosecnaProbojnost = 1000 * level;
            prosecnaSteta = 400 * level;
            vremeNisanjenja = 8 * level;
            break;
        }
    }
    void unapredi(tipTenka tip)
    {
        LevelUp();
        stats(tip);
    }
    friend ostream& operator<<(ostream& out, Top& top)
    {
        out<<"         Brzina pucanja: "<<top.brzinaPucanja<<endl;
        out<<"         Prosecna probojnost: "<<top.prosecnaProbojnost<<endl;
        out<<"         Prosecna steta: "<<top.prosecnaSteta<<endl;
        out<<"         Vreme nisanjenja: "<<top.vremeNisanjenja<<endl;
        return out;
    }
    void SetBrzinaPucanja(int bP){ brzinaPucanja = bP ;}
    void SetProsecnaProbojnost(int pP){ prosecnaProbojnost = pP;}
    void SetProsecnaSteta(int pS){ prosecnaSteta = pS;}
    void SetVremeNisanjenja(int vN){ vremeNisanjenja = vN ;}
    int GetBrzinaPucanja(){return brzinaPucanja;}
    int GetProsecnaProbojnost(){return prosecnaProbojnost;}
    int GetProsecnaSteta(){return prosecnaSteta;}
    int GetVremeNisanjenja(){return vremeNisanjenja;}
};

#endif // TOP_H_INCLUDED
