#ifndef SERVISIRANJE_H_INCLUDED
#define SERVISIRANJE_H_INCLUDED

class Servisiranje
{
private:
    const int cenaPotrosneRobe[7] = { 20000, 20000, 20000, 20000, 3000, 3000, 3000 };
    const int cenaMunicije[3] = { 14, 800, 14};
    List<int> potrosnaRoba;
    List<int> municija;
public:
    Servisiranje()
    {
        for(int i = 0;i<7;i++)
        {
            potrosnaRoba.Add(0);
        }
        for(int i = 0;i<3;i++)
        {
            municija.Add(0);
        }
    }
    Servisiranje(List<int> pR, List<int> m)
    {
        potrosnaRoba = pR;
        municija = m;
    }
    Servisiranje(Servisiranje& servisiranje)
    {
        potrosnaRoba = servisiranje.potrosnaRoba;
        municija = servisiranje.municija;
    }
    void DodajPotrosnuRobu(int index, int kolicna)
    {
        potrosnaRoba[index]+=kolicna;
    }
    void DodajMuniciju(int index, int kolicna)
    {
        municija[index]+=kolicna;
    }
    bool kupiPotrosnuRobu(int index, int kolicina)
    {
        if (potrosnaRoba[index] + kolicina <= 10)
        {
            potrosnaRoba[index] += kolicina;
            return true;
        }
        return false;
    }
    bool kupiMuniciju(int index, int kolicina)
    {
        if (municija[0] + municija[1] + municija[2] + kolicina <= 200)
        {
            municija[index] += kolicina;
            return true;
        }
        return false;
    }
    int getCenaMunicije(int kolicna, int index)
    {
        return cenaMunicije[index] * kolicna;
    }
    int getCenaPotrosneRobe(int kolicina, int index)
    {
        return cenaPotrosneRobe[index] * kolicina;
    }
    int getPotrosnaRoba(int index)
    {
        return potrosnaRoba[index];
    }
    int getMunicija(int index)
    {
        return municija[index];
    }
    void potrosiMuniciju(int kolicina, int index)
    {
        municija[index] -= kolicina;
    }
    void potrosiPotrosnuRobu(int kolicina, int index)
    {
        if(potrosnaRoba[index]-kolicina < 0)
            potrosnaRoba[index] = 0;
        else
            potrosnaRoba[index] -= kolicina;
    }
    void GetInfoPotrosnaRoba()
    {
        cout <<endl<< "| Potornsa roba: " << endl;
        cout << "|1. Veliki komplet za opravku: " << potrosnaRoba[0] << endl;
        cout << "|2. Veiliki komplet prve pomoci: " << potrosnaRoba[1] << endl;
        cout << "|3. Dodatna borbena sledovanja: " << potrosnaRoba[2] << endl;
        cout << "|4. Automatski protivpozarni aparat: " << potrosnaRoba[3] << endl;
        cout << "|5. Rucni protivpozarni aparat: " << potrosnaRoba[4] << endl;
        cout << "|6. Mali komplet prve pomoci: " << potrosnaRoba[5] << endl;
        cout << "|7. Mali alat za popravke: " << potrosnaRoba[6] << endl;
    }
    void GetInfoMunicija()
    {
        cout << "|Municija: " << endl;
        cout << "|1. 45mm P: " << municija[0] << endl;
        cout << "|2. 45mm PP: " << municija[1] << endl;
        cout << "|3. 45mm FG: " << municija[2] << endl<<endl;
    }
    friend ostream& operator<<(ostream& out, Servisiranje& servisiranje)
    {
        out <<endl<< "| Potornsa roba: " << endl;
        out << "|1. Veliki komplet za opravku: " << servisiranje.potrosnaRoba[0] << endl;
        out << "|2. Veiliki komplet prve pomoci: " << servisiranje.potrosnaRoba[1] << endl;
        out << "|3. Dodatna borbena sledovanja: " << servisiranje.potrosnaRoba[2] << endl;
        out << "|4. Automatski protivpozarni aparat: " << servisiranje.potrosnaRoba[3] << endl;
        out << "|5. Rucni protivpozarni aparat: " << servisiranje.potrosnaRoba[4] << endl;
        out << "|6. Mali komplet prve pomoci: " << servisiranje.potrosnaRoba[5] << endl;
        out << "|7. Mali alat za popravke: " << servisiranje.potrosnaRoba[6] << endl;
        out << "|Municija: " << endl;
        out << "|1. 45mm P: " << servisiranje.municija[0] << endl;
        out << "|2. 45mm PP: " << servisiranje.municija[1] << endl;
        out << "|3. 45mm FG: " << servisiranje.municija[2] << endl<<endl;
        return out;
    }
    int getBrojPotrosneRobe()
    {
        int temp = 0;
        for (int i = 0; i < 6; i++)
        {
            if (potrosnaRoba[i] > 0)
            {
                temp++;
            }
        }
        return temp;
    }
    int getBrojMunicije()
    {
        return municija[0] + municija[1] + municija[2];
    }
};

#endif // SERVISIRANJE_H_INCLUDED
