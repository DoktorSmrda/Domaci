#include <iostream>
#include "dinstring.hpp"
using namespace std;

class Abs
{
public:
    virtual int getTemperaturu() const = 0;
    virtual void setTemperatura(int) = 0;
};

enum Modovi {HLADNO, TOPLO};

class Grejac : public Abs
{
private:
    int temperatura;
public:
    Grejac()
    {
        temperatura = 0;
    }
    Grejac(int t)
    {
        temperatura = t;
    }
    Grejac(Grejac& grejac)
    {
        temperatura = grejac.temperatura;
    }
    void setTemperatura(int t)
    {
        if(t>0&&t<=100)
        {
            temperatura = t;
        }
    }
    int getTemperaturu() const
    {
        return temperatura;
    }
};

class Fen
{
private:
    DinString marka;
    Modovi mod;
    Grejac grejac;
public:
    Fen(DinString Marka, Modovi Mod) : grejac((int)Mod)
    {
        marka = Marka;
        mod = Mod;
    }
    Fen(Fen& fen) : grejac((int)(fen.mod))
    {
        marka = fen.marka;
        mod = fen.mod;
    }
    DinString GetMarka() const
    {
        return marka;
    }
    Modovi GetMod() const
    {
        return mod;
    }
    Grejac& GetGrejac()
    {
        return grejac;
    }
    void SetMod(Modovi m)
    {
        mod = m;
    }
    Fen& operator=(const Fen& fen)
    {
        marka = fen.marka;
        mod = fen.mod;
        grejac.setTemperatura((int)fen.GetMod());
        return *this;
    }
    friend ostream& operator<<(ostream& out, const Fen& fen)
    {
        out<<"Marka: "<<fen.marka<<endl;
        out<<"Mod: "<<fen.mod<<endl;
        out<<"Temperatura: "<<fen.grejac.getTemperaturu()<<endl;
        return out;
    }
};

int main()
{
    Fen f1("Philips", HLADNO);
    Fen f2("Philips2", TOPLO);
    Fen f3("Philips3", HLADNO);
    cout<<f1<<endl;
    f2.GetGrejac().setTemperatura(30);
    cout<<f2<<endl;
    f1 = f2 = f3;
    cout<<f1;
    return 0;
}
