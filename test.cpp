#include "brain.h"
#include <iostream>
#include <vector>

#include <iostream>
#include <vector>

// void setPieces(std::vector<piece> &bor)
// {
//     for (int i = 0; i < 8; ++i)
//     {
//         if (i == 0 || i == 7)
//         {
//             int v = 5;
//             for (int j : {0, 2, 1})
//             {
//                 bor[getpos({i, j})] = piece(v);
//                 bor[getpos({i, 7 - j})] = piece(v);
//                 v -= 1;
//             }
//         }
//         else if (i == 1)
//         {
//             for (int j = 0; j < 8; ++j)
//             {
//                 bor[getpos({i, j})] = piece(1);
//             }
//         }
//         else if (i == 6)
//         {
//             for (int j = 0; j < 8; ++j)
//             {
//                 bor[getpos({i, j})] = piece(-1);
//             }
//         }
//         else
//         {
//             for (int j = 0; j < 8; ++j)
//             {
//                 bor[getpos({i, j})] = piece();
//             }
//         }
//     }
//     bor[3] = piece(9);
//     bor[4] = piece(20);
//     bor[59] = piece(-9);
//     bor[60] = piece(-20);
// }

void setPieces(std::vector<piece> &bor)
{
    bor[getpos({1, 1})] = piece(1);
    bor[getpos({4, 2})] = piece(-1);
}

void play(int sid, std::vector<piece> &board)
{
    std::cout << "tester ==========\n";
    // std::cout << board.size() << "\n";
    printboard(board);
    std::vector<std::vector<int>> mov = aiMove(sid, board);
    shift(board, mov[0], mov[1]);
    std::cout << "tester ==========\n";
    printboard(board);
}

int main()
{
    std::vector<piece> board;
    for (int i = 0; i < 64; i++)
        board.push_back(piece());
    setPieces(board);
    play(1, board);
    play(-1, board);
    play(1, board);
}