#include "brain.h"

piece movePiece(std::vector<piece> board, std::vector<int> ini, std::vector<int> fin, piece iniset = piece(0))
{
    if (get(ini, board).value == 20 && get(ini, board).unmoved)
        if (ini[1] + 2 == fin[1])
        {
            shift(board, {ini[0], ini[1] + 3}, {fin[0], fin[1] - 1});
            get({ini[0], ini[1] + 3}, board).move();
        }
    piece fipo = get(fin, board);
    get(ini, board).move();
    board[getpos(fin)] = board[getpos(ini)];
    board[getpos(ini)] = iniset;
    return fipo;
}

std::vector<std::vector<int>> aiPlay(int mySide, std::vector<piece> &board)
{
    std::vector<std::vector<int>> respon = aiMove(mySide, board);
    movePiece(board, respon[0], respon[1]);
    return respon;
}