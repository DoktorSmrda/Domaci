#include <iostream>

using namespace std;

class Kamera
{
protected:
    int megaPikseli;
    int freeSpace;
    static int photoCounter;
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
    int get_photoCounter()
    {
        return photoCounter;
    }
    bool slikaj()
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
};
class VideoKamera : public Kamera
{
private:
    static int videoCounter;
public:
    VideoKamera():Kamera()
    {
        videoCounter = 0;
    }
    VideoKamera(int mP, int fS, int pC, int vC):Kamera(mP, fS, pC)
    {
        videoCounter = vC;
    }
    int get_videoCounter()
    {
        return videoCounter;
    }
    bool snimaj(int sekunde)
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
};
class Telefon
{
protected:
    string broj;
public:
    Telefon()
    {
        broj = "06412345678";
    }
    Telefon(string b)
    {
        broj = b;
    }
    bool pozovi(string b)
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
};
class TelefonGen2 : public Telefon
{
protected:
    Kamera k;
public:
    TelefonGen2():Telefon(),k(){}
    TelefonGen2(string b, int mP, int fS, int pC) : Telefon(b), k(mP, fS, pC){}
    bool slikajSliku()
    {
        return k.slikaj();
    }
};
class TelefonGen3 : public TelefonGen2
{
private:
    VideoKamera vk;
public:
    TelefonGen3():TelefonGen2(),vk(){}
    TelefonGen3(string b, int mP, int fS, int pC, int vC):TelefonGen2(b, mP, fS, pC),vk(mP,fS,pC,vC){}
    bool snimiVideo(int sekunde)
    {
        return vk.snimaj(sekunde);
    }
};
int main()
{

    return 0;
}
