#ifndef DEOTENKA_H_INCLUDED
#define DEOTENKA_H_INCLUDED
#include "Osobine.hpp"

enum tipTenka { LAKI = 1, SREDNJI, TESKI, ARTILJERIJA, LOVAC };

class DeoTenka : public Osobine
{
public:
    DeoTenka() : Osobine(){}
    virtual void stats(tipTenka) = 0;
    virtual void unapredi(tipTenka) = 0;
};

#endif // DEOTENKA_H_INCLUDED
