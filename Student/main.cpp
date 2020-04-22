#include <iostream>
#include "dinstring.hpp"
using namespace std;

class Osoba
{
protected:
    DinString ime;
    DinString prezime;
public:
    Osoba(const char* i = "", const char* p = "")
    {
        ime = i;
        prezime = p;
    }
    Osoba(const DinString& i, const DinString& p)
    {
        ime = i;
        prezime = p;
    }
    Osoba(const Osoba& osoba)
    {
        ime = osoba.ime;
        prezime = osoba.prezime;
    }
    virtual void predstaviSe() const
    {
        cout<<"Ime: "<<ime<<endl;
        cout<<"Prezime: "<<prezime<<endl;
    }
};

class Student : public Osoba
{
protected:
    int brojIndeksa;
public:
    Student(const char* i = "", const char* p = "", int bI = 0):Osoba(i ,p)
    {
        brojIndeksa = bI;
    }
    Student(const Osoba& os, int bI) : Osoba(os)
    {
        brojIndeksa = bI;
    }
    Student(const DinString& i, const DinString& p, int bI):Osoba(i, p)
    {
        brojIndeksa = bI;
    }
    Student(const Student& student) : Osoba(Osoba(student))
    {
        brojIndeksa = student.brojIndeksa;
    }
    void predstaviSe()
    {
        predstaviSe();
        cout<<"Broj indeksa: "<<brojIndeksa<<endl;
    }
};
class PhDStudent : public Student
{
private:
    double prosecnaOcena;
public:
    PhDStudent(const char* i, const char* p, int bI, double pO):Student(i, p, bI)
    {
        prosecnaOcena = pO;
    }
    PhDStudent(const DinString& i, const DinString& p, int bI, double pO):Student(i, p, bI)
    {
        prosecnaOcena = pO;
    }
    PhDStudent(const Osoba& o, int bI, double pO):Student(o, bI)
    {
        prosecnaOcena = pO;
    }
    PhDStudent(const Student& student, double pO):Student(student)
    {
        prosecnaOcena = pO;
    }
    PhDStudent(const PhDStudent& phds):Student(Student(phds))
    {
        prosecnaOcena = phds.prosecnaOcena;
    }
    void predstaviSe()
    {
        predstaviSe();
        cout<<"Prosecna ocena: "<<prosecnaOcena;
    }
};

void predstavljanje1(Osoba osoba)
{
    cout<<"1. "<<endl;
    osoba.predstaviSe();
}
void predstavljanje2(const Osoba& osoba)
{
    cout<<"2. "<<endl;
    osoba.predstaviSe();
}

int main()
{
    const char *i = "Viktor";
    const char *p = "Cordas";
    Osoba os1(i,p);
    Student st1(i, p, 1234);
    PhDStudent phds1(i, p, 1234, 8.56);
    phds1.predstaviSe();
    cout<<"Predstavljanje objekata preko funkcije"<<endl;
    cout<<endl;
    cout<<"Osoba:"<<endl;
    predstavljanje1(os1);
    predstavljanje2(os1);
    cout<<endl;
    cout<<"Student:"<<endl;
    predstavljanje1(st1);
    predstavljanje2(st1);
    cout<<endl;
    cout<<"PhDStudent:"<<endl;
    predstavljanje1(phds1);
    predstavljanje2(phds1);
    return 0;
}
