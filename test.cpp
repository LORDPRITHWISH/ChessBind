#include "brain.h"
#include <iostream>
#include <vector>
#include <algorithm>

int eva(int i, int j)
{
    return i * 8 + j;
}
void setPieces(std::vector<piece> &bor)
{
    for (int i = 0; i < 8; ++i)
    {
        if (i == 0 || i == 7)
        {
            int v = 5;
            for (int j : {0, 2, 1})
            {
                bor[eva(i, j)] = piece(v, eva(i, j));
                bor[eva(i, 7 - j)] = piece(v, eva(i, 7 - j));
                v -= 1;
            }
        }
        else if (i == 1)
        {
            for (int j = 0; j < 8; ++j)
            {
                bor[eva(i, j)] = piece(1, eva(i, j));
            }
        }
        else if (i == 6)
        {
            for (int j = 0; j < 8; ++j)
            {
                bor[eva(i, j)] = piece(-1, eva(i, j));
            }
        }
        else
        {
            for (int j = 0; j < 8; ++j)
            {
                bor[eva(i, j)] = piece();
            }
        }
    }
    bor[3] = piece(9, 3);
    bor[4] = piece(20, 4);
    bor[59] = piece(-9, 59);
    bor[60] = piece(-20, 60);
}

// void setPieces(std::vector<piece> &bor)
// {
//     bor[eva({1, 1})] = piece(1, eva({1, 1}));
//     bor[eva({4, 2})] = piece(-1, eva({4, 2}));
// }

void play(int sid, std::vector<piece> &board)
{
    std::cout << "tester ==========\n";
    // std::cout << board.size() << "\n";
    printboard(board);
    std::vector<int> mov = aiMove(sid, board);
    for(int i:mov)
    std::cout<<i<<" ,";;
    // shift(board, mov[0], mov[1], piece(0, mov[1]));
    // std::cout << "tester ==========\n";
    printboard(board);
}

void run()
{
    std::vector<piece> board;
    for (int i = 0; i < 64; i++)
        board.push_back(piece(0, i));
    setPieces(board);
    
    play(1, board);
    // play(-1, board);
    // play(1, board);
}


int main()
{
    // run();
    // std::vector<int> a={1,5,4,8,7,9,4,10,5,4,3,77};
    // a.pop_back(std::remove(a.b))
    // test(a);
    // run();
    int po =38;
    while ((po + 1) % 8)
        std::cout<<po--<<" ";
    // writeBinary(13);
}