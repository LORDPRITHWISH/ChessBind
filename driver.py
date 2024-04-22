import build.brain as chess
from setboard import setPieces,setest
from modify import movepiece
import numpy as np

board=[i for i in range(64)]

setPieces(board)
# setest(board)

board = np.array(board)

for i in range(0,64):
    print(f"{board[i].getval():>4}", end=" ")
    if (i+1)%8==0:
        print("\n")

posmov = chess.moves(board,1)


for i in posmov :
    print(i.getpla())
    print(i.getmove())
    print('\n'*2)

aimov=chess.play(1,board)
movepiece(board,aimov)

for i in range(0,64):
    print(f"{board[i].getval():>4}", end=" ")
    if (i+1)%8==0:
        print("\n")


print(aimov)

