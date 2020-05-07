#ifndef TESKI_HPP_INCLUDED
#define TESKI_HPP_INCLUDED
#include "TehnickeKarakteristike.hpp"
#include "OsnovneKarakteristike.hpp"
class Teski : public Tenk
{
private:
    TehnickeKarakteristike tehnickeKarakteristike;
    OsnovneKarakteristike osnovneKarakteristike;
public:
    Teski():Tenk(TESKI, 1, "KV-1", 4), tehnickeKarakteristike(), osnovneKarakteristike(){}
    Teski(int d, DinString n, int k, DinString imena[]):Tenk(TESKI, d, n, k, imena), tehnickeKarakteristike(), osnovneKarakteristike() {}
};

#endif // TESKI_HPP_INCLUDED
