#ifndef brain
#include "cruncher.h"

int recurCalculate(int side, std::vector<int> mypic, std::vector<int> oppic, mov move, int maximus, int minimus, std::vector<piece> board, int lev)
{
    shift(move, oppic, mypic, board);
    std::cout<<side<<" ";
    printboard(board);

    int weight;
    bool first = false, king_swap = false;

    std::vector<mov> moves = posov(board, mypic);

    for (mov ply : moves)
    {
        if (lev == 0)
            return side * evaluate(board, mypic, oppic);

        weight = -recurCalculate(-side, oppic, mypic, ply, -minimus, -maximus, board, lev - 1);
        if (weight)
        {
            if (maximus && weight > maximus)
                return maximus;

            if (weight > minimus)
                minimus = weight;
        }
    }
    return weight;
}

int i = 0;
std::vector<int> calculate(int mySide, std::vector<piece> board, int lev)
{
    int score = 0;
    std::vector<int> avlpos = avlpce(board, mySide);
    int weight = 0, nweight;
    bool first = false;
    mov theMove = mov();
    const int MAX = 214748364, MIN = -214748364;

    std::vector<int> my = avlpce(board, mySide);
    std::vector<int> op = avlpce(board, -mySide);

    std::vector<mov> moves = posov(board, my);

    for (mov ply : moves)
    {
        nweight = -recurCalculate(-1, op, my, ply, -MIN, -MAX, board, lev - 1);
        if (weight)
        {
            if (nweight > weight)
            {
                nweight = weight;
                theMove = ply;
            }
        }
        else
        {
            weight = nweight;
            theMove = ply;
        }
        //         if (first)
        //         {
        //             if (nweight > weight)
        //             {
        //                 theMove = {cord, pos};
        //                 weight = nweight;
        //             }
        //         }
        //         else
        //         {

        //             first = true;
        //             theMove = {cord, pos};
        //             weight = nweight;
        //         }
        //     }
    }
    return {theMove.ini,theMove.fin};
}

std::vector<int> aiMove(int mySide, std::vector<piece> board)
{
    int lev = 2;
    // std::cout << piece::total << " no of times\n\n";

    std::vector<int> aptMov = calculate(mySide, board, lev);
    // std::cout << piece::total << " no of times\n\n";
    return aptMov;
}

#endif