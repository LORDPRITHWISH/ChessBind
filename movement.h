#ifndef movement
#include <vector>
#include <functional>
#include "clasdef.h"

piece get(int i, int j, std::vector<piece> board)
{
    return board[i * 8 + j];
}

std::vector<std::vector<int>> posible(std::vector<piece> board, piece pla, int x, int y)
{
    std::vector<std::vector<int>> out;

    std::function<bool(int, int)> cheak = [&board, &pla, &out](int i, int j)
    {
        if (i < 0 || i > 7 || j > 7 || j < 0)
            return false;

        if (get(i, j, board).value == 0)
            out.push_back({i, j});
        else
        {
            if (pla.side != get(i, j, board).side)
                out.push_back({i, j});
            return false;
        }
        return true;
    };

    std::function<void(int, int)> digo = [&cheak](int x, int y)
    {
        int i, j;

        i = x - 1;
        j = y - 1;
        while (cheak(i, j))
        {
            i -= 1;
            j -= 1;
        }

        i = x - 1;
        j = y + 1;
        while (cheak(i, j))
        {
            i -= 1;
            j += 1;
        }

        i = x + 1;
        j = y - 1;
        while (cheak(i, j))
        {
            i += 1;
            j -= 1;
        }

        i = x + 1;
        j = y + 1;
        while (cheak(i, j))
        {
            i += 1;
            j += 1;
        }
    };

    std::function<void(int, int)> hogo = [&cheak](int x, int y)
    {
        int i, j;

        i = x - 1;
        j = y;
        while (cheak(i, j))
            i -= 1;

        i = x;
        j = y + 1;
        while (cheak(i, j))
            j += 1;

        i = x;
        j = y - 1;
        while (cheak(i, j))
            j -= 1;

        i = x + 1;
        j = y;
        while (cheak(i, j))
            i += 1;
    };

    std::function<void(int, int)> hor = [&cheak](int x, int y)
    {
        int i, j;
        for (int i : {1, -1})
            for (int j : {2, -2})
            {
                cheak(x + i, y + j);
                cheak(x + j, y + i);
            }
    };

    std::function<void(int, int)> pawn = [&board, &pla, &out](int x, int y)
    {
        x += pla.side; // up is +    down is -

        if (get(x, y, board).value == 0)
            out.push_back({x, y});
        if (pla.unmoved)
        {
            x += pla.side;
            if (get(x, y, board).value == 0)
                out.push_back({x, y});
        }
    };

    std::function<void(int, int)> king = [&cheak](int x, int y)
    {
        int i, j;

        i = x - 1;
        j = y - 1;
        cheak(i, j);

        i = x - 1;
        j = y + 1;
        cheak(i, j);

        i = x + 1;
        j = y - 1;
        cheak(i, j);

        i = x + 1;
        j = y + 1;
        cheak(i, j);

        i = x - 1;
        j = y;
        cheak(i, j);

        i = x;
        j = y + 1;
        cheak(i, j);

        i = x;
        j = y - 1;
        cheak(i, j);

        i = x + 1;
        j = y;
        cheak(i, j);
    };

    switch (pla.value)
    {
    case 20:
        king(x, y);
        break;
    case 9:
        digo(x, y);
        hogo(x, y);
        break;
    case 5:
        hogo(x, y);
        break;
    case 4:
        digo(x, y);
        break;
    case 3:
        hor(x, y);
        break;
    case 1:
        pawn(x, y);
        break;
    default:
        break;
    }
    return out;
}

std::vector<moves> movegen(std::vector<piece> board, int side)
{
    std::vector<moves> movlist;
    moves curr;
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            if (get(i, j, board).side == side)
            {
                curr.posmoves = posible(board, get(i, j, board), i, j);
                if (curr.posmoves.size() > 0)
                {
                    curr.player = {i, j};
                    movlist.push_back(curr);
                }
            }
    return movlist;
}

#endif
