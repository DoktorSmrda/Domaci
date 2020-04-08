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
class Oblik
{
private:
    Pravougaonik A;
    Elipsa B;
public:
    Oblik(): A(), B() {};
    Oblik(double a, double b, double x ,double y): A(a, b), B(x, y) {};
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
class PravilanOblik: public Oblik
{
private:
    double a, x;
public:
    PravilanOblik(){};
    PravilanOblik(double aa, double xx): Oblik(aa, aa, xx, xx) {};
    PravilanOblik(PravilanOblik &kopija): Oblik(){};
};
int main()
{
    Pravougaonik p;
    Pravougaonik p1(6,10);
    Elipsa e;
    Elipsa e1(3,5);
    Oblik o;
    Oblik o1(10, 9, 2 , 3);
    PravilanOblik po;
    PravilanOblik po1(10, 5);
    cout<<"Pravougaonik: "<<endl;
    cout<<p.Povrsina()<<" "<<p.Obim()<<endl;
    cout<<p1.Povrsina()<<" "<<p1.Obim()<<endl;
    cout<<"Elipsa: "<<endl;
    cout<<e.Povrsina()<<" "<<e.Obim()<<endl;
    cout<<e1.Povrsina()<<" "<<e1.Obim()<<endl;
    cout<<"Oblik: "<<endl;
    cout<<o.PovrsinaOblika()<<" "<<o.ObimOblika()<<endl;
    cout<<o1.PovrsinaOblika()<<" "<<o1.ObimOblika()<<endl;
    cout<<"Pravilan Oblik: "<<endl;
    cout<<po.PovrsinaOblika()<<" "<<po.ObimOblika()<<endl;
    cout<<po1.PovrsinaOblika()<<" "<<po1.ObimOblika()<<endl;
    return 0;
}
