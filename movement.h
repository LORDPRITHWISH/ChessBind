#ifndef movement
#include <functional>
#include "clasdef.h"

piece get(std::vector<int> pos, std::vector<piece> board)
{
    // std::cout << "get-> " << pos[0] << "," << pos[1] << '\n';
    return board[pos[0] * 8 + pos[1]];
}

std::vector<std::vector<int>> posible(std::vector<piece> board, std::vector<int> cord)
{
    piece pla = get(cord, board);
    std::vector<std::vector<int>> out;
    std::vector<std::vector<int>> cut;

    std::function<bool(int, int)> cheak = [&board, &pla, &out, &cut](int i, int j)
    {
        if (i < 0 || i > 7 || j > 7 || j < 0)
            return false;

        if (get({i, j}, board).value == 0)
            out.push_back({i, j});
        else
        {
            if (pla.side != get({i, j}, board).side)
                // cut.push_back({i, j});
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

    std::function<void(int, int)> pawn = [&board, &pla, &out, &cut](int x, int y)
    {
        x += pla.side; // up is +    down is -
        if (x < 8 && x > 0)
        {
            if (get({x, y}, board).value == 0)
            {
                out.push_back({x, y});
                if (pla.unmoved)
                {
                    int ax = x + pla.side;
                    if (ax < 8 && ax > 0)
                    {
                        if (get({ax, y}, board).value == 0)
                            out.push_back({ax, y});
                        pla.move();
                    }
                }
            }
            piece pic;
            if (y + 1 < 8)
            {
                pic = get({x, y + 1}, board);
                if (pic.value > 0 && pla.side != pic.side)
                    // cut.push_back({x, y + 1});
                    out.push_back({x, y + 1});
            }
            if (y + 1 < 8)
            {
                pic = get({x, y - 1}, board);
                if (pic.value > 0 && pla.side != pic.side)
                    // cut.push_back({x, y - 1});
                    out.push_back({x, y - 1});
            }
        }
    };

    std::function<void(int, int)> king = [&cheak, &board, &out](int x, int y)
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

        if (get({x, y}, board).unmoved)
            if (get({x, y + 3}, board).value == 5 && get({x, y + 3}, board).unmoved)
                if (get({x, y + 1}, board).value == 0 && get({x, y + 2}, board).value == 0)
                    out.push_back({x, y + 2});
    };
    
    int x = cord[0];
    int y = cord[1];
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
    for (std::vector<int> po : cut)
        out.insert(out.begin(), po);
    return out;
}

std::vector<moves> movegen(std::vector<piece> board, int side)
{
    std::vector<moves> movlist;
    moves curr;
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            if (get({i, j}, board).side == side)
            {
                std::vector<int> pos = {i, j};
                curr.posmoves = posible(board, pos);
                if (curr.posmoves.size() > 0)
                {
                    curr.player = pos;
                    movlist.push_back(curr);
                }
            }
    return movlist;
}

std::vector<std::vector<int>> avlpce(std::vector<piece> board, int side)
{
    // std::cout << "move search \n\n";
    std::vector<std::vector<int>> positions;
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            if (get({i, j}, board).side == side)
                positions.push_back({i, j});
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
