#ifndef clasdef
#include <stdlib.h>
#include <vector>

class piece
{
public:
    int value, side;
    bool unmoved;
    static long long int total;
    piece()
    {
        side = 0;
        value = 0;
    }
    piece(int val)
    {
        if (val == 0)
        {
            side = 0;
            value = 0;
            return;
        }
        value = abs(val);
        side = val / value;
        unmoved = true;
    }
    void move()
    {
        if (unmoved)
            unmoved = false;
        total++;
    }
    int sndval()
    {
        return value * side;
    }
};

long long int piece::total = 0;

class moves
{
public:
    std::vector<int> player;
    std::vector<std::vector<int>> posmoves;
    moves() {}
};

#endif