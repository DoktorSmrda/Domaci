#ifndef TEHNICKEKARAKTERISTIKE_HPP_INCLUDED
#define TEHNICKEKARAKTERISTIKE_HPP_INCLUDED

class TehnickeKarakteristike
{
private:
    int vatrenaMoc;
    int izdrzljvost;
    int pokretljivost;
    int sakrivenost;
    int opazanje;
public:
    TehnickeKarakteristike()
    {
        vatrenaMoc = 70;
        izdrzljvost = 200;
        pokretljivost = 30;
        sakrivenost = 20;
        opazanje = 20;
    }
    TehnickeKarakteristike(int vM, int i, int p, int s, int o)
    {
        vatrenaMoc = vM;
        izdrzljvost = i;
        pokretljivost = p;
        sakrivenost = s;
        opazanje = o;
    }
    TehnickeKarakteristike(TehnickeKarakteristike& tehnickeKarakteristike)
    {
        vatrenaMoc = tehnickeKarakteristike.vatrenaMoc;
        izdrzljvost = tehnickeKarakteristike.izdrzljvost;
        pokretljivost = tehnickeKarakteristike.pokretljivost;
        sakrivenost = tehnickeKarakteristike.sakrivenost;
        opazanje = tehnickeKarakteristike.opazanje;
    }
    void IspisiOsnovneKarakteristike()
    {
        cout<<"Vatrena moc: "<<vatrenaMoc<<endl;
        cout<<"Izdrzljvost: "<<izdrzljvost<<endl;
        cout<<"Pokretljvost: "<<pokretljivost<<endl;
        cout<<"Sakrivenost: "<<sakrivenost<<endl;
        cout<<"Opazanje: "<<opazanje<<endl;
    }
    int SetVatrenaMoc(){ return vatrenaMoc;}
    int SetIzdrzljivost(){ return izdrzljvost;}
    int SetPokretljivost(){ return pokretljivost;}
    int SetSakrivenost(){ return sakrivenost;}
    int SetOpazanje(){ return opazanje;}
    void SetVatrenaMoc(int vM){vatrenaMoc = vM;}
    void SetIzdrzljvost(int i){izdrzljvost = i;}
    void SetPokretljivost(int p){pokretljivost = p;}
    void SetSakrivenost(int s){sakrivenost = s;}
    void SetOpazanje(int o){opazanje = o;}
};

#endif // TEHNICKEKARAKTERISTIKE_HPP_INCLUDED
