#include <iostream>
#include <math.h>
#define POVRSINAPIRAMIDE(a, h) pow((pow(a, 2)-pow(h, 2))*2)
using namespace std;

class Telo
{
protected:
    int povrsina;
    int zapremina;
public:
    virtual int izracunavanjePovrsina() = 0;
    virtual int izracunavanjeZapremina() = 0;
    virtual void ispisInformacija() = 0;
};

class Kvadar: public Telo
{
private:
    int a, b, c;
public:
    Kvadar()
    {
        a = 10;
        b = 10;
        c = 10;
    };
    Kvadar(int aa , int bb, int cc)
    {
        a = aa;
        b = bb;
        c = cc;
    };
    Kvadar(Kvadar &k)
    {
        a = k.a;
        b = k.b;
        c = k.c;
    };
    int getA()
    {
        return a;
    }
    int getB()
    {
        return b;
    }
    int getC()
    {
        return c;
    }
    int izracunavanjePovrsina()
    {
        povrsina = 2*(a*b+a*c+b*c);
        return povrsina;
    }
    int izracunavanjeZapremina()
    {
        zapremina = a*b*c;
        return zapremina;
    }
    void ispisInformacija()
    {
        cout<<"vrednosti polja: "<<a<<" "<<b<<" "<<c<<endl;
        cout<<"povrsina: "<<povrsina<<endl;
        cout<<"zapremina: "<<zapremina<<endl;
    }
    ~Kvadar(){};
};

class Piramida:public Telo
{
private:
    int a, h;
public:
    Piramida()
    {
        a = 5;
        h = 3;
    }
    Piramida(int aa, int hh)
    {
        a = aa;
        h = hh;
    }
    Piramida(const Piramida &p)
    {
        a = p.a;
        h = p.h;
    }
    int getA()
    {
        return a;
    }
    int getH()
    {
        return h;
    }
    int izracunavanjePovrsina()
    {
        povrsina = a*a + 2*h;
        return povrsina;
    }
    int izracunavanjeZapremina()
    {
        zapremina = (a * a * h)/3;
        return zapremina;
    }
    void ispisInformacija()
    {
        cout<<"vrednosti polja: "<<a<<" "<<h<<endl;
        cout<<"povrsina: "<<povrsina<<endl;
        cout<<"zapremina: "<<zapremina<<endl;
    }
    ~Piramida(){};
};
class Kocka:public Kvadar
{
private:
    int A;
public:
    Kocka():Kvadar(){}
    Kocka(int AA):Kvadar(AA, AA, AA){}
    Kocka(Kocka &k):Kvadar(k){}
    ~Kocka(){};
};
class JSPiramida:public Piramida
{
private:
    int A, H;
public:
    JSPiramida():Piramida(){}
    JSPiramida(int aa, int hh):Piramida(aa, hh){}
    JSPiramida(const JSPiramida &p):Piramida(p){};
    ~JSPiramida(){};
};
class SpecijalnoTelo:public Telo
{
private:
    Kocka kocka;
    JSPiramida piramida1;
    JSPiramida piramida2;
public:
    SpecijalnoTelo():kocka(), piramida1(), piramida2(){};
    SpecijalnoTelo(int stranicaKocke, int stranicaPiramide, int visinaPiramide): kocka(stranicaKocke), piramida1(stranicaPiramide, visinaPiramide), piramida2(stranicaPiramide, visinaPiramide){};
    SpecijalnoTelo(SpecijalnoTelo &SpecTelo):kocka(SpecTelo.kocka), piramida1(SpecTelo.piramida1), piramida2(SpecTelo.piramida2){};
    int izracunavanjePovrsina()
    {
        povrsina = kocka.izracunavanjePovrsina()+piramida1.izracunavanjePovrsina()+piramida2.izracunavanjePovrsina();
        return povrsina;
    }
    int izracunavanjeZapremina()
    {
        zapremina = kocka.izracunavanjeZapremina()+piramida1.izracunavanjeZapremina()+piramida2.izracunavanjeZapremina();
        return zapremina;
    }
    void ispisInformacija()
    {
        cout<<"vrednosti polja kocka: "<<kocka.getA()<<endl;
        cout<<"vrednosti polja piramida1: "<<piramida1.getA()<<" "<<piramida1.getH()<<endl;
        cout<<"vrednosti polja piramida2: "<<piramida2.getA()<<" "<<piramida2.getH()<<endl;
        cout<<"povrsina: "<<povrsina<<endl;
        cout<<"zapremina: "<<zapremina<<endl;
    }
    ~SpecijalnoTelo(){};
};
int main()
{
    Piramida p1;
    Piramida p2(10, 8);

    JSPiramida jsp1;
    JSPiramida jsp2(10, 8);

    Kvadar k1;
    Kvadar k2(3, 4, 5);

    Kocka ko1;
    Kocka ko2(5);

    SpecijalnoTelo specTelo1;
    SpecijalnoTelo specTelo2(5, 5, 3);

    p1.izracunavanjePovrsina();
    p1.izracunavanjeZapremina();
    p1.ispisInformacija();
    p2.izracunavanjePovrsina();
    p2.izracunavanjeZapremina();
    p2.ispisInformacija();

    jsp1.izracunavanjePovrsina();
    jsp1.izracunavanjeZapremina();
    jsp1.ispisInformacija();
    jsp2.izracunavanjePovrsina();
    jsp2.izracunavanjeZapremina();
    jsp2.ispisInformacija();

    k1.izracunavanjePovrsina();
    k1.izracunavanjeZapremina();
    k1.ispisInformacija();
    k2.izracunavanjePovrsina();
    k2.izracunavanjeZapremina();
    k2.ispisInformacija();

    ko1.izracunavanjePovrsina();
    ko1.izracunavanjeZapremina();
    ko1.ispisInformacija();
    ko2.izracunavanjePovrsina();
    ko2.izracunavanjeZapremina();
    ko2.ispisInformacija();

    specTelo1.izracunavanjePovrsina();
    specTelo1.izracunavanjeZapremina();
    specTelo1.ispisInformacija();
    specTelo2.izracunavanjePovrsina();
    specTelo2.izracunavanjeZapremina();
    specTelo2.ispisInformacija();
    return 0;
}
