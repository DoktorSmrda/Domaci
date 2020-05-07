#ifndef MOTOR_H_INCLUDED
#define MOTOR_H_INCLUDED
#include "DeoTenka.hpp"

class Motor : public DeoTenka
{
private:
    int snagaMotora;
    int sansaZaPozar;
public:
    Motor() : DeoTenka()
    {
        stats(LAKI);
    }
    Motor(tipTenka tip) : DeoTenka()
    {
        stats(tip);
    }
    Motor(int sM, int sZP)
    {
        snagaMotora = sM;
        sansaZaPozar = sZP;
    }
    Motor(Motor& motor)
    {
        snagaMotora = motor.snagaMotora;
        sansaZaPozar = motor.sansaZaPozar;
    }
    void stats(tipTenka tip)
    {
        switch(tip)
        {
        case LAKI:
            snagaMotora = 12 * level;
            sansaZaPozar = 10 * level;
            break;
        case SREDNJI:
            snagaMotora = 30 * level;
            sansaZaPozar = 10 * level;
            break;
        case TESKI:
            snagaMotora = 50 * level;
            sansaZaPozar = 10 * level;
            break;
        case ARTILJERIJA:
            snagaMotora = 70 * level;
            sansaZaPozar = 10 * level;
            break;
        case LOVAC:
            snagaMotora = 40 * level;
            sansaZaPozar = 10 * level;
            break;
        }
    }
    void unapredi(tipTenka tip)
    {
        LevelUp();
        stats(tip);
    }
    friend ostream& operator<<(ostream& out, Motor& motor)
    {
        out<<"         Snaga motora: "<<motor.snagaMotora<<endl;
        out<<"         Sansa za pozar: "<<motor.sansaZaPozar<<endl;
        return out;
    }
    int GetSansaZaPozar()
    {
        return sansaZaPozar;
    }
    int GetSnagaMotora()
    {
        return snagaMotora;
    }
    void SetSansaZaPozar(int sZP)
    {
        sansaZaPozar = sZP;
    }
    void SetSnagaMotora(int sM)
    {
        snagaMotora = sM;
    }
};

#endif // MOTOR_H_INCLUDED
