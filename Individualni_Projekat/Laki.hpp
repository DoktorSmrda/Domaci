#ifndef LAKI_HPP_INCLUDED
#define LAKI_HPP_INCLUDED

class Laki : public Tenk
{
private:
    TehnickeKarakteristike tehnickeKarakteristike;
    OsnovneKarakteristike osnovneKarakteristike;
public:
    Laki():Tenk(LAKI, 3, "AMX Elc bis", 3), tehnickeKarakteristike(), osnovneKarakteristike(){}
    Laki(int d, DinString n, int k, DinString imena[]):Tenk(LAKI, d, n, k, imena), tehnickeKarakteristike(), osnovneKarakteristike() {}
};

#endif // LAKI_HPP_INCLUDED
