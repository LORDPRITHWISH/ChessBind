#ifndef brain
#include "movement.h"

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
void sel(){}
// def sel(a,b,v) :
//     v=abs(v)
//     if a==b :
//         return v
//     else :
//         return -v

int last(bool tamp, piece player, int value, int score)
{
}

// def last(tamp,pl,myside,value,score):
//     if tamp :
//         if pl == myside:
//             if value>score :
//                 return value
//         else :
//             if value<score :
//                 return value
//     return score

int recurCalculate(int mySide,int play, std::vector<piece> board, int lev)
{
    if (lev==0)
        return last(tamp,pl,myside,value,score);
    int score = 0;
    std::vector<std::vector<int>> avlpos = avlpce(board, mySide);
    int weight = 0, nweight;
    return 0;
}

// def recal(pl,bor,score,myside,level,tamp,value) :
//     global COU
//     if level==0 :
//         return last(tamp,pl,myside,value,score)
//     sol=poss(pl,bor)
//     ret=0
//     fst=False;rv=0

//     for i in sol :
//         mov=posible(i[0],i[1],bor)
//         for j in mov :
//             val=shift(i,j,bor)
//             if val != 0 :
//                 score += sel(pl,myside,val)
//             ret = recal(-pl,bor,score,myside,level-1,fst,rv)
//             COU+=1
//             shift(j,i,bor,val)
//             if tamp :
//                 # print(99)
//                 if pl == myside:
//                     if ret>value :
//                         # print('>')
//                         return value
//                 else :
//                     if ret<value :
//                         # print('<')
//                         return value

//             # print(fst)
//             if fst :
//                 if pl == myside:
//                     if ret>rv :
//                         rv=ret
//                 else :
//                     if ret<rv :
//                         rv=ret
//             else :
//                 fst=True
//                 rv=ret
//     return rv

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
                // score += npo.value;                  //---------------------------------------------------------------------------------------------
                score += npo.value * npo.side * mySide;
            nweight = recurCalculate(mySide, mySide*-1, board, lev); //---------------------------------------------------------------------------------------------
            if (npo.value > 0)
                // score -= npo.value;                  //---------------------------------------------------------------------------------------------
                score -= npo.value * npo.side * mySide;
            shift(board, pos, cord, npo);
            if (first)
                if (nweight > weight)
                {
                    theMove = {cord, pos};
                    weight = nweight;
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

//  score += sel(pl,myside,val)
//  ret = recal(-pl,board,score,myside,level-1,fst,rv[0])

std::vector<std::vector<int>> aiMove(int mySide, std::vector<piece> board, int lev = 5)
{
    std::vector<std::vector<int>> aptMov = calculate(mySide, board, lev);
    return aptMov;
}

#endif