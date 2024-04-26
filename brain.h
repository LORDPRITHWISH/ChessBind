#ifndef brain
#include "cruncher.h"

int recurCalculate(int mySide, int play, int score, int elival, bool elecon, std::vector<piece> board, int lev)
{
    // std::cout << "level value :" << lev << "\n";
    if (lev == 0)
        return last(elecon, play, mySide, elival, score);
    std::vector<std::vector<int>> avlpos = avlpce(board, play);
    int weight = 0, nweight;
    bool first = false, king_swap = false;

    if (movegen(board, play).size() == 0)
        return score;
    for (std::vector<int> cord : avlpos)
    {
        std::vector<std::vector<int>> moves = posible(board, cord);
        // std::cout << "recal moves size " << moves.size() << '\n';

        for (std::vector<int> pos : moves)
        {
            if (get(cord, board).value == 20 && get(cord, board).unmoved)
                if (cord[1] + 2 == pos[1])
                {
                    shift(board, {cord[0], cord[1] + 3}, {pos[0], pos[1] - 1});
                    king_swap = true;
                }

            piece npo = shift(board, cord, pos);

            // if (npo.value > 0 && mySide == play)
            // {
            //     printboard(board);
            //     std::cout << npo.value << " val,score " << score << "\n";
            // }
            // std::cout  << npo.value << "\n";

            if (npo.value > 0)
                nweight = recurCalculate(mySide, play * -1, score + npo.value * npo.side * play * -1, elival, elecon, board, lev - 1);
            else
                nweight = recurCalculate(mySide, play * -1, score, elival, elecon, board, lev - 1);
            // std::cout << nweight << '\n';
            if (npo.value > 0 && mySide == play)
            {
                printboard(board);
                std::cout << "recal ->| weight=" << weight << "  | nweight=" << nweight << "  | score=" << score << "  | recival=" << elival << "  | level=" << lev * play << " \n\n\n";
            }
            else if (nweight == 1 || weight == 1)
                std::cout << "recalout ->| weight=" << weight << "  | nweight=" << nweight << "  | score=" << score << "  | level=" << lev * play << " \n";

            shift(board, pos, cord, npo);

            if (nweight)
                // std::cout << "nw ->" << nweight << "  of level" << lev << "\n";
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

int i = 0;
std::vector<std::vector<int>> calculate(int mySide, std::vector<piece> board, int lev)
{
    int score = 0;
    std::vector<std::vector<int>> avlpos = avlpce(board, mySide);
    int weight = 0, nweight;
    bool first = false;
    std::vector<std::vector<int>> theMove = {{0, 0}, {0, 0}};
    for (std::vector<int> cord : avlpos)
    {
        // std::cout << "\n\n\n\n\nsearching for :  " << get(cord, board).value << "\n";
        std::vector<std::vector<int>> moves = posible(board, cord);
        // std::cout  << "moves size " << moves.size() << '\n';
        for (std::vector<int> pos : moves)
        {
            // std::cout << "\n  got for :  " << get(pos, board).value << "\n";
            piece npo = shift(board, cord, pos);
            std::cout << "calcCur val" << npo.value << "   from- " << cord[0] << ',' << cord[1] << "   to- " << pos[0] << ',' << pos[1] << "\n";
            if (npo.value > 0)
                nweight = recurCalculate(mySide, mySide * -1, score + npo.value * npo.side * mySide * -1, weight, first, board, lev);
            else
                nweight = recurCalculate(mySide, mySide * -1, score, weight, first, board, lev);

            shift(board, pos, cord, npo);
            std::cout << "cal -> weight " << weight << "   nweight " << nweight << "   val " << npo.value << " \n\n\n\n\n\n\n\n\n\n\n\n\n";
            // i++;
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
    int lev = 3;
    // std::cout << piece::total << " no of times\n\n";
    std::vector<std::vector<int>> aptMov = calculate(mySide, board, lev);
    // std::cout << piece::total << " no of times\n\n";
    return aptMov;
}

#endif