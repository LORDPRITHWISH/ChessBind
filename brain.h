#ifndef brain
#include "movement.h"

#include <iostream>

int getpos(std::vector<int> pos)
{
    return pos[0] * 8 + pos[1];
}
piece shift(std::vector<piece> board, std::vector<int> ini, std::vector<int> fin, piece iniset = piece(0))
{
    piece fipo = get(fin, board);
    board[getpos(fin)] = board[getpos(ini)];
    board[getpos(ini)] = iniset;
    return fipo;
}

int last(bool elecon, int player, int mySide, int value, int score)
{

    // if (elecon)
    // {
    //     if (player == mySide)
    //         if (value > score)
    //             return value;
    //         else if (value < score)
    //             return value;
    // }

    if (elecon)
    {
        if (player == mySide && score > value)
            return value;
        else if (score < value)
            return value;
    }
    return score;
}

int recurCalculate(int mySide, int play, int score, int elival, bool elecon, std::vector<piece> board, int lev)
{
    piece::total++;
    if (lev == 0)
        return last(elecon, play, mySide, elival, score);
    std::vector<std::vector<int>> avlpos = avlpce(board, mySide);
    int weight = 0, nweight;
    bool first = false, king_swap = false;
    for (std::vector<int> cord : avlpos)
    {
        std::vector<std::vector<int>> moves = posible(board, cord);
        for (std::vector<int> pos : moves)
        {
            if (get(cord, board).value == 20 && get(cord, board).unmoved)
                if (cord[1] + 2 == pos[1])
                {
                    shift(board, {cord[0], cord[1] + 3}, {pos[0], pos[1] - 1});
                    king_swap = true;
                }

            piece npo = shift(board, cord, pos);
            if (npo.value > 0)
                nweight = recurCalculate(mySide, play * -1, score + npo.value * npo.side * mySide, elival, elecon, board, lev - 1);
            else
                nweight = recurCalculate(mySide, play * -1, score, elival, elecon, board, lev - 1);
            shift(board, pos, cord, npo);
            if (king_swap)
            {
                shift(board, {pos[0], pos[1] - 1}, {cord[0], cord[1] + 3});
                king_swap = false;
            }
            if (elecon)
            {
                if (play == mySide && nweight > elival)
                    return elival;
                else if (nweight < elival)
                    return elival;
            }

            if (first)
            {
                if (play == mySide && nweight > weight)
                    weight = nweight;
                else if (nweight < weight)
                    weight = nweight;
            }
            else
            {
                first = true;
                weight = nweight;
            }
        }
    }
    return weight;
}

std::vector<std::vector<int>> calculate(int mySide, std::vector<piece> board, int lev)
{
    int score = 0;
    std::vector<std::vector<int>> avlpos = avlpce(board, mySide);
    int weight = 0, nweight;
    bool first = false;
    std::vector<std::vector<int>> theMove = {{0, 0}, {0, 0}};
    for (std::vector<int> cord : avlpos)
    {
        std::vector<std::vector<int>> moves = posible(board, cord);
        for (std::vector<int> pos : moves)
        {
            piece npo = shift(board, cord, pos);
            if (npo.value > 0)
                nweight = recurCalculate(mySide, mySide * -1, score + npo.value * npo.side * mySide, weight, first, board, lev);
            else
                nweight = recurCalculate(mySide, mySide * -1, score, weight, first, board, lev);

            shift(board, pos, cord, npo);
            if (first)
            {
                if (nweight > weight)
                {
                    theMove = {cord, pos};
                    weight = nweight;
                }
            }
            else
            {
                first = true;
                theMove = {cord, pos};
                weight = nweight;
            }
        }
    }
    return theMove;
}

std::vector<std::vector<int>> aiMove(int mySide, std::vector<piece> board)
{
    int lev = 2;
    std::vector<std::vector<int>> aptMov = calculate(mySide, board, lev);
    std::cout << piece::total << " no of times\n\n";
    return aptMov;
}

#endif