#ifndef ARTILJERIJA_HPP_INCLUDED
#define ARTILJERIJA_HPP_INCLUDED

class Artiljerija : public Tenk
{
private:
    TehnickeKarakteristike tehnickeKarakteristike;
    OsnovneKarakteristike osnovneKarakteristike;
public:
    Artiljerija():Tenk(ARTILJERIJA, 3,"AMX 13 AM", 4), tehnickeKarakteristike(), osnovneKarakteristike(){}
    Artiljerija(int d, DinString n, int k, DinString imena[]):Tenk(ARTILJERIJA, d, n, k, imena),
        tehnickeKarakteristike(),
        osnovneKarakteristike() {}
};

#endif // ARTILJERIJA_HPP_INCLUDED
