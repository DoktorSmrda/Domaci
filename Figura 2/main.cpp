#include <iostream>
#include <math.h>
using namespace std;
class Figura
{
public:
    virtual double Povrsina() = 0;
    virtual double Obim() = 0;
};
class Pravougaonik: public Figura
{
private:
    double a;
    double b;
public:
    Pravougaonik()
    {
        a=10;
        b=15;
    }
    Pravougaonik(double aa, double bb)
    {
        a=aa;
        b=bb;
    }
    Pravougaonik(Pravougaonik &kopija)
    {
        a=kopija.a;
        b=kopija.b;
    }
    double getA()
    {
        return a;
    }
    double getB()
    {
        return b;
    }
    double Povrsina()
    {
        return a*b;
    }
    double Obim()
    {
        return a*2+b*2;
    }
};
class Elipsa: public Figura
{
private:
    double x;
    double y;
public:
    Elipsa()
    {
        x = 2;
        y = 3;
    };
    Elipsa(double xx, double yy)
    {
        x = xx;
        y = yy;
    };
    Elipsa(Elipsa &kopija)
    {
        x = kopija.x;
        y = kopija.y;
    };
    double getX()
    {
        return x;
    }
    double getY()
    {
        return y;
    }
    double Povrsina()
    {
        return 3.14*(3*(x+y)-sqrt((3*x+y)*(x+3*y)));
    }
    double Obim()
    {
        return x*y*3.14;
    }
};

class Kvadrat:public Pravougaonik
{
public:
    Kvadrat(): Pravougaonik(6, 6){};
    Kvadrat(double aa): Pravougaonik(aa, aa){};
    Kvadrat(Kvadrat &kopija): Pravougaonik(6, 6){};
};
class Krug:public Elipsa
{
public:
    Krug():Elipsa(4, 4){};
    Krug(double xx):Elipsa(xx ,xx){};
    Krug(Krug &kopija):Elipsa(4 ,4){};
};

class Oblik
{
private:
    Kvadrat A;
    Krug B;
public:
    Oblik(): A(), B() {};
    Oblik(double a, double x): A(a), B(x) {};
    Oblik(Oblik &kopija): A(), B() {};
    double PovrsinaOblika()
    {
        return A.Povrsina()-B.Povrsina();
    }
    double ObimOblika()
    {
        return A.Obim()+B.Obim();
    }
};
int main()
{
    Kvadrat k;
    Kvadrat k1(5);
    Krug krug;
    Krug krug1(2);
    Oblik o;
    Oblik o1(10, 4);
    cout<<"Kvadrat: "<<endl;
    cout<<k.Povrsina()<<" "<<k.Obim()<<endl;
    cout<<k1.Povrsina()<<" "<<k1.Obim()<<endl;
    cout<<"Krug: "<<endl;
    cout<<krug.Povrsina()<<" "<<krug.Obim()<<endl;
    cout<<krug1.Povrsina()<<" "<<krug1.Obim()<<endl;
    cout<<"Oblik: "<<endl;
    cout<<o.PovrsinaOblika()<<" "<<o.ObimOblika()<<endl;
    cout<<o1.PovrsinaOblika()<<" "<<o1.ObimOblika()<<endl;
    return 0;
}
