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

std::string printpo(int po)
{
    std::cout << " " << po / 8 << " , " << po % 8 << " ";
    return " ";
}

void shift(mov move, std::vector<int> &my, std::vector<int> &op, std::vector<piece> &board)
{

    my.push_back(move.fin);
    op.erase(std::remove(op.begin(), op.end(), 10), op.end());
    board[move.fin] = board[move.ini];
    board[move.ini] = piece(0, move.ini);
    std::cout << "ini: " << printpo(move.ini) << "  fin: " << printpo(move.fin) << "\n";
}

// piece unshift(std::vector<piece> &board, int ini, int fin, piece iniset)
// {
//     piece fipo = board[fin];
//     board[ini].move();
//     // std::cout << "\nshiftini= " << ini[0] << "," << ini[1] << '\n'
//     //           << "shiftfinal= " << fin[0] << "," << fin[1] << "\n\n";

//     board[fin] = board[ini];
//     board[ini] = iniset;
//     return fipo;
// }

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

int sum(std::vector<piece> board, std::vector<int> pcs)
{
    int total = 0;
    for (int i : pcs)
        total += board[i].value;
    return total;
}

int evaluate(std::vector<piece> board, std::vector<int> mypcs, std::vector<int> oppcs)
{
    int mysum = sum(board, mypcs);
    int opsum = sum(board, oppcs);

    return mysum - opsum;
}

#endif