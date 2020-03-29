#include <iostream>

using namespace std;
int meni()
{
    int i;
    do
    {
        cout<<"1) Turn off"<<endl;
        cout<<"2) Turn on"<<endl;
        cout<<"3) Sleep"<<endl;
        cout<<"4) Wake up"<<endl;
        cout<<"5) Finish Update"<<endl;
        cout<<"6) Start Update"<<endl;
        cout<<"7) Download Batch"<<endl;
        cout<<"8) Ispisi"<<endl;
        cout<<"9) Exit"<<endl;
        cout<<">>";
        cin>>i;
    }
    while(i<0||i>10);
    return i;
}
enum operativniSistem {ANDROID = 1, IOS};
enum Stanje {UKLJUCEN = 1, ISKLJUCEN, STANDBY, AZURIRA_SE};
class Osistem
{
private:
    operativniSistem sistem;
    int verzija;
public:
    Osistem()
    {
        sistem = ANDROID;
        verzija = 1;
    };
    Osistem(operativniSistem s, int v)
    {
        sistem = s;
        verzija = v;
    };
    operativniSistem getOperativniSistem()
    {
        return sistem;
    }
    int getVerzija()
    {
        return verzija;
    }
    void setVerzija(int v)
    {
        verzija = v;
    }
    void setOperativniSistem(operativniSistem s)
    {
        sistem = s;
    }
};
class Smartphone
{
private:
    Stanje stanje;
    int downloadProgress;
    Osistem sistem;
public:
    Smartphone():sistem()
    {
        stanje = ISKLJUCEN;
        downloadProgress = -1;
    };
    Smartphone(Stanje s, int dP):sistem()
    {
        stanje = s;
        downloadProgress = dP;
    };
    bool turnOff()
    {
        if(stanje == UKLJUCEN)
        {
            downloadProgress = -1;
            stanje = ISKLJUCEN;
            return true;
        }
        return false;
    }
    bool turnOn()
    {
        if(stanje == ISKLJUCEN)
        {
            stanje = UKLJUCEN;
            return true;
        }
        return false;
    }
    bool sleep()
    {
        if(stanje == UKLJUCEN)
        {
            downloadProgress = -1;
            stanje = STANDBY;
            return true;
        }
        return false;
    }
    bool wakeUp()
    {
        if(stanje == STANDBY)
        {
            stanje = UKLJUCEN;
            return true;
        }
        return false;
    }
    bool finishUpdate()
    {
        if(downloadProgress == 100&&stanje == AZURIRA_SE)
        {
            stanje = UKLJUCEN;
            downloadProgress = -1;
            return true;
        }
        return false;
    }
    bool startUpdate(operativniSistem oS, int verzija)
    {
        if(stanje == UKLJUCEN)
        {
            stanje = AZURIRA_SE;
            downloadProgress = 0;
            sistem.setOperativniSistem(oS);
            sistem.setVerzija(verzija);
            return true;
        }
        return false;
    }
    bool downloadBatch()
    {
        if(downloadProgress!=100&&stanje == AZURIRA_SE)
        {
            downloadProgress+=20;
            cout<<"-----------"<<endl<<downloadProgress<<endl<<"-----------"<<endl;
            return true;
        }
        return false;
    }
    Stanje getStanje()
    {
        return stanje;
    }
    Osistem getOsistem()
    {
        return sistem;
    }
};
void ispisi(Smartphone& smartPhone)
{
    cout<<"-------------"<<endl;
    cout<<"Stanje: ";
    switch(smartPhone.getStanje())
    {
    case 1:
        cout<<"Ukljucen";
        break;
    case 2:
        cout<<"Iskljucen";
        break;
    case 3:
        cout<<"Stand by";
        break;
    case 4:
        cout<<"Azurira se";
        break;
    }
    cout<<endl;
    cout<<"Operativni sistem: ";
    switch(smartPhone.getOsistem().getOperativniSistem())
    {
    case 1:
        cout<<"Android"<<endl;
        break;
    case 2:
        cout<<"IOS"<<endl;
        break;
    }
    cout<<"Verzija: "<<smartPhone.getOsistem().getVerzija()<<endl;
    cout<<"-------------"<<endl;
}
int main()
{
    Smartphone smartPhone;
    do
    {
        switch(meni())
        {
        case 1:
            smartPhone.turnOff();
            break;
        case 2:
            smartPhone.turnOn();
            break;
        case 3:
            smartPhone.sleep();
            break;
        case 4:
            smartPhone.wakeUp();
            break;
        case 5:
            smartPhone.finishUpdate();
            break;
        case 6:
            if(smartPhone.getStanje()==UKLJUCEN)
            {
                int odabir, odabirVerzije;
                do
                {
                    cout<<"1. Android"<<endl<<"2. IOS"<<endl;
                    cout<<">>";
                    cin>>odabir;
                    cout<<"Verzija: ";
                    cin>>odabirVerzije;
                }
                while(odabir!=1&&odabir!=2);
                smartPhone.startUpdate((operativniSistem)odabir, odabirVerzije);
            }
            break;
        case 7:
            smartPhone.downloadBatch();
            break;
        case 8:
            ispisi(smartPhone);
            break;
        case 9:
            return 0;
        }
    }
    while(true);
}
