#ifndef OSOBINE_HPP_INCLUDED
#define OSOBINE_HPP_INCLUDED

class Osobine
{
protected:
    int level;
public:
    Osobine()
    {
        level = 1;
    }
    Osobine(int l)
    {
        level = l;
    }
    void LevelUp()
    {
        level++;
    }
};

#endif // OSOBINE_HPP_INCLUDED
