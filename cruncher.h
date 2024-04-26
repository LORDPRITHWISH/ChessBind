#ifndef cruncher

#include "movement.h"

void printboard(std::vector<piece> board)
{
    // std::cout << "hi\n";

    std::cout << "\t|   ";
    for (int ival = 0; ival < 64; ival++)
    {
        std::cout << board[ival].sndval() << "\t|   ";
        if ((ival + 1) % 8 == 0)
            std::cout << "\n\t|   ";
    }
    std::cout << "\n\n";
}

int getpos(std::vector<int> pos)
{
    // std::cout << "getpos= " << pos[0] << "," << pos[1] << '\n';
    return pos[0] * 8 + pos[1];
}
piece shift(std::vector<piece> &board, std::vector<int> ini, std::vector<int> fin, piece iniset = piece(0))
{
    piece fipo = get(fin, board);
    get(ini, board).move();
    // std::cout << "\nshiftini= " << ini[0] << "," << ini[1] << '\n'
    //           << "shiftfinal= " << fin[0] << "," << fin[1] << "\n\n";

    board[getpos(fin)] = board[getpos(ini)];
    board[getpos(ini)] = iniset;
    return fipo;
}

int last(bool elecon, int player, int mySide, int value, int score)
{
    if (elecon)
    {
        if (player == mySide && score > value)
            return value;
        else if (score < value)
            return value;
    }
    // std::cout << "lst sco=" << score << "\n\n";
    return score;
}

int evaluate()

#endif