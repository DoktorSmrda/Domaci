#ifndef SREDNJI_HPP_INCLUDED
#define SREDNJI_HPP_INCLUDED

class Srednji : public Tenk
{
private:
    TehnickeKarakteristike tehnickeKarakteristike;
    OsnovneKarakteristike osnovneKarakteristike;
public:
    Srednji():Tenk(SREDNJI, 4, "Matilda", 5), tehnickeKarakteristike(), osnovneKarakteristike(){}
    Srednji(int d, DinString n, int k, DinString imena[]):Tenk(SREDNJI, d, n, k, imena), tehnickeKarakteristike(), osnovneKarakteristike() {}
};

#endif // SREDNJI_HPP_INCLUDED
