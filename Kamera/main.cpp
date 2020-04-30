#include <iostream>
#include "dinstring.hpp"
using namespace std;

class Kamera
{
protected:
    int megaPikseli;
    int freeSpace;
    int photoCounter;
public:
    Kamera()
    {
        megaPikseli = 108;
        freeSpace = 108000;
        photoCounter = 0;
    }
    Kamera(int mP, int fS, int pC)
    {
        megaPikseli = mP;
        freeSpace = fS;
        photoCounter = pC;
    }
    Kamera(Kamera &kopija)
    {
        megaPikseli = kopija.megaPikseli;
        freeSpace = kopija.freeSpace;
        photoCounter = kopija.photoCounter;
    }
    int GetPhotoCounter()
    {
        return photoCounter;
    }
    bool Slikaj()
    {
        if((freeSpace-megaPikseli)>=0)
        {
            freeSpace -= megaPikseli;
            photoCounter++;
            return true;
        }
        else
        {
            return false;
        }
    }
    void GetInfo()
    {
        cout<<"Mega pikseli: "<<megaPikseli<<endl;
        cout<<"Free space: "<<freeSpace<<endl;
        cout<<"Photo counter: "<<photoCounter<<endl;
    }
};
class VideoKamera : public Kamera
{
private:
    int videoCounter;
public:
    VideoKamera():Kamera()
    {
        videoCounter = 0;
    }
    VideoKamera(int mP, int fS, int pC, int vC):Kamera(mP, fS, pC)
    {
        videoCounter = vC;
    }
    int GetVideoCounter()
    {
        return videoCounter;
    }
    bool Snimaj(int sekunde)
    {
        if(freeSpace-(megaPikseli*sekunde)>=0)
        {
            freeSpace -= megaPikseli*sekunde;
            videoCounter++;
            return true;
        }
        else
        {
            return false;
        }
    }
    void GetInfo()
    {
        Kamera::GetInfo();
        cout<<"Video counter: "<<videoCounter<<endl;
    }
};
class Telefon
{
protected:
    DinString broj;
public:
    Telefon()
    {
        broj = "06412345678";
    }
    Telefon(DinString b)
    {
        broj = b;
    }
    bool Pozovi(DinString b)
    {
        if(b!=broj)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void GetInfo()
    {
        cout<<"Broj: "<<broj<<endl;
    }
};
class TelefonGen2 : public Telefon
{
protected:
    Kamera k;
public:
    TelefonGen2():Telefon(),k(){}
    TelefonGen2(DinString b, int mP, int fS, int pC) : Telefon(b), k(mP, fS, pC){}
    bool SlikajSliku()
    {
        return k.Slikaj();
    }
    void GetInfo()
    {
        Telefon::GetInfo();
        k.GetInfo();
    }
};
class TelefonGen3 : public TelefonGen2
{
private:
    VideoKamera vk;
public:
    TelefonGen3():TelefonGen2(),vk(){}
    TelefonGen3(DinString b, int mP, int fS, int pC, int vC):TelefonGen2(b, mP, fS, pC),vk(mP,fS,pC,vC){}
    bool SnimiVideo(int sekunde)
    {
        return vk.Snimaj(sekunde);
    }
    void GetInfo()
    {
        Telefon::GetInfo();
        vk.GetInfo();
    }
};
int main()
{
    Kamera k;
    k.GetInfo();
    cout<<endl;
    VideoKamera VK;
    VK.GetInfo();
    cout<<endl;
    Telefon t;
    t.GetInfo();
    cout<<endl;
    TelefonGen2 tg2;
    tg2.GetInfo();
    cout<<endl;
    TelefonGen3 tg3;
    tg3.SnimiVideo(30);
    tg3.GetInfo();
    return 0;
}
