#ifndef LOVAC_HPP_INCLUDED
#define LOVAC_HPP_INCLUDED

class Lovac : public Tenk
{
private:
    TehnickeKarakteristike tehnickeKarakteristike;
    OsnovneKarakteristike osnovneKarakteristike;
public:
    Lovac():Tenk(LOVAC, 0, "StuG III G", 4), tehnickeKarakteristike(), osnovneKarakteristike(){}
    Lovac(int d, DinString n, int k, DinString imena[]):Tenk(LOVAC, d, n, k, imena), tehnickeKarakteristike(), osnovneKarakteristike() {}
    //Lovac(Lovac& lovac):Tenk(LOVAC, ){}
};

#endif // LOVAC_HPP_INCLUDED
