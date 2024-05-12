#ifndef clasdef

#include <stdlib.h>
#include <vector>

#include <iostream>

class piece
{
public:
    int value, side, position;
    bool unmoved;
    static long long int total;
    piece()
    {
        side = 0;
        value = 0;
    }
    piece(int val, int pos)
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
        position = pos;
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

class mov
{
public:
    int ini, fin, val;
    mov()
    {
        ini = 0;
        fin = 0;
        val = 0;
    }
    mov(int in, int fi, std::vector<piece> board)
    {
        ini = in;
        fin = fi;
        if (board[fi].value > 0)
        {
            if (board[fi].value > board[in].value)
                val = 10 * board[fi].value - board[in].value;
            else
            {
                val = board[fi].value;
            }
        }
        else if (board[in].value == 1 && (fi < 8 || fi > 55 == 7))
            val += 100;
        else
            val = 0;
    }
};
class allmoves
{
public:
    int player;
    std::vector<int> posmoves;
    // moves() {}
};

#endif