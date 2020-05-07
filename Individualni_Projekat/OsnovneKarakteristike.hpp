#ifndef OSNOVNEKARAKTERISTIKE_HPP_INCLUDED
#define OSNOVNEKARAKTERISTIKE_HPP_INCLUDED

class OsnovneKarakteristike
{
private:
    float specificnaSnaga;
    int maksimalnaBrzina;
    int brzinaUnazad;
    float brzinaOkretanja;
    int vidokrug;
public:
    OsnovneKarakteristike()
    {
        specificnaSnaga = 100;
        maksimalnaBrzina = 50;
        brzinaUnazad = 16;
        brzinaOkretanja = 60;
        vidokrug = 250;
    }
    OsnovneKarakteristike(float sS, int mB, float bO, int v)
    {
        specificnaSnaga = sS;
        maksimalnaBrzina = mB;
        brzinaUnazad = mB/3;
        brzinaOkretanja = bO;
        vidokrug = v;
    }
    OsnovneKarakteristike(OsnovneKarakteristike& osnovneKarakteristike)
    {
        specificnaSnaga = osnovneKarakteristike.specificnaSnaga;
        maksimalnaBrzina = osnovneKarakteristike.maksimalnaBrzina;
        brzinaOkretanja = osnovneKarakteristike.brzinaOkretanja;
        brzinaUnazad = osnovneKarakteristike.brzinaUnazad;
        vidokrug = osnovneKarakteristike.vidokrug;
    }
    void IspisiOsnovneKarakteristike()
    {
        cout<<"Specificna snaga: "<<specificnaSnaga<<endl;
        cout<<"Maksimalna brzina: "<<maksimalnaBrzina<<endl;
        cout<<"Brzina unazad: "<<brzinaUnazad<<endl;
        cout<<"Brzina okretanja: "<<brzinaOkretanja<<endl;
        cout<<"Vidokrug: "<<vidokrug<<endl;
    }
    float GetSpecificnaSnaga(){ return specificnaSnaga; }
    int GetMaksimalnaBrzina(){ return maksimalnaBrzina; }
    int GetBrzinaUnazad(){ return brzinaUnazad; }
    int GetBrzinaOkretanja(){ return brzinaOkretanja; }
    int GetVidokrug(){ return vidokrug; }
    void SetSpecificaSnaga(float sS){ specificnaSnaga = sS; }
    void SetMaksimalnaBrzina(int mB){ maksimalnaBrzina = mB; }
    void SetBrzinaUnazad(int bU){ brzinaUnazad = bU; }
    void SetBrzinaOkretanja(int bO){ brzinaOkretanja = bO; }
    void SetVidokrug(int v){ vidokrug = v; }


};


#endif // OSNOVNEKARAKTERISTIKE_HPP_INCLUDED
