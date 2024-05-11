#ifndef movement
#include <functional>
#include "clasdef.h"

std::vector<mov> posible(std::vector<piece> board, int cord)
{
    piece pla = board[cord];
    std::vector<mov> out;

    std::function<bool(int)> cheak = [&board, &pla, &out, &cord](int pos)
    {
        if (pos < 0 || pos > 63)
            return false;

        if (board[pos].value == 0)
            out.push_back(mov(cord, pos, board));
        else
        {
            if (pla.side != board[pos].side)
                out.push_back(mov(cord, pos, board));
            return false;
        }
        return true;
    };

    std::function<void(int)> digo = [&cheak](int loc)
    {
        int po;

        po = loc - 9;
        while (cheak(po) && (po) % 8)
            po -= 9;

        po = loc + 9;
        while (cheak(po) && (po + 1) % 8)
            po += 9;

        po = loc - 7;
        while (cheak(po) && (po + 1) % 8)
            po -= 7;

        po = loc + 7;
        while (cheak(po) && (po) % 8)
            po += 7;
    };

    std::function<void(int)> hogo = [&cheak](int loc)
    {
        int po;

        po = loc + 1;
        while (cheak(po) && (po + 1) % 8)
            po ++;

        po = loc - 1;
        while (cheak(po) && po % 8)
            po --;

        po = loc + 8;
        while (cheak(po))
            po += 8;

        po = loc - 8;
        while (cheak(po))
            po -= 8;
    };

    std::function<void(int)> hor = [&cheak](int loc)
    {
        int i, j;
        for (int i : {1, -1})
            for (int j : {2, -2})
            {
                cheak(loc + i * 8 + j);
                cheak(loc + j * 8 + i);
                std::cout << (loc + i * 8 + j) << " , ";
                std::cout << (loc + j * 8 + i) << "\n";
            }
        std::cout << "\n\n\n\n";
    };

    std::function<void(int)> pawn = [&board, &pla, &out](int loc)
    {
        int cloc = loc + pla.side * 8; // up is +    down is -
        if (loc >= 0 && loc < 64)
        {
            if (board[cloc].value == 0)
            {
                out.push_back(mov(loc, cloc, board));
                if (pla.unmoved)
                {
                    int aloc = cloc + pla.side * 8;
                    if (aloc >= 0 && aloc < 64)
                    {
                        if (board[aloc].value == 0)
                            out.push_back(mov(loc, aloc, board));
                        pla.move();
                    }
                }
            }
            piece pic;
            int dot = cloc % 8;
            if (dot + 1 < 8)
            {
                pic = board[cloc + 1];
                if (pic.value > 0 && pla.side != pic.side)
                    // cut.push_back({x, y + 1});
                    out.push_back(mov(loc, cloc + 1, board));
            }
            if (dot > 0)
            {
                pic = board[cloc - 1];
                if (pic.value > 0 && pla.side != pic.side)
                    // cut.push_back({x, y - 1});
                    out.push_back(mov(loc, cloc - 1, board));
            }
        }
    };

    std::function<void(int)> king = [&cheak, &board, &out](int loc)
    {
        int po;

        po = loc + 9;
        cheak(po);

        po = loc + 8;
        cheak(po);

        po = loc + 7;
        cheak(po);

        po = loc + 1;
        cheak(po);

        po = loc - 9;
        cheak(po);

        po = loc - 8;
        cheak(po);

        po = loc - 7;
        cheak(po);

        po = loc - 1;
        cheak(po);

        if (board[loc].unmoved)
            if (board[loc + 3].value == 5 && board[loc + 3].unmoved)
                if (board[loc + 1].value == 0 && board[loc + 2].value == 0)
                    out.push_back(mov(loc, loc + 2, board));
    };

    switch (pla.value)
    {
    case 20:
        king(cord);
        break;
    case 9:
        digo(cord);
        hogo(cord);
        break;
    case 5:
        hogo(cord);
        break;
    case 4:
        digo(cord);
        break;
    case 3:
        hor(cord);
        break;
    case 1:
        pawn(cord);
        break;
    default:
        break;
    }
    return out;
}

std::vector<mov> posov(std::vector<piece> board, std::vector<int> posis)
{
    std::vector<mov> moves;
    for (int po : posis)
    {
        for (mov mo : posible(board, po))
            moves.push_back(mo);
    }
    std::sort(moves.begin(), moves.end(), [](const mov &a, const mov &b)
              { return a.val > b.val; });
    return moves;
}

std::vector<allmoves> movegen(std::vector<piece> board, int side)
{
    std::vector<allmoves> movlist;
    allmoves curr;
    std::vector<mov> res;
    for (int i = 0; i < 64; i++)
        if (board[i].side == side)
        {
            res = posible(board, i);
            // std::cout << "\n|" << board[i].value << " - ";
            std::transform(res.begin(), res.end(), std::back_inserter(curr.posmoves), [](mov va)
                           { return va.fin; });
            if (curr.posmoves.size() > 0)
            {
                // std::cout << board[i].value << "\n";
                curr.player = i;
                movlist.push_back(curr);
                curr.posmoves.clear();
            }
        }
    return movlist;
}

std::vector<int> avlpce(std::vector<piece> board, int side)
{
    // std::cout << "move search \n\n";
    std::vector<int> positions;
    for (int i = 0; i < 64; i++)
        if (board[i].side == side)
            positions.push_back(i);
    // std::cout << "move search done \n\n\n\n\n\n\n\n";
    return positions;
}

#endif

// K : 20
// Q :  9
// R :  5
// B :  4
// H :  3
// P :  1
