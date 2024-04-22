import build.brain as chess
from setboard import setPieces,setest

board=[i for i in range(64)]

setPieces(board)
# setest(board)

for i in range(0,64):
    print(f"{board[i].getval():>4}", end=" ")
    if (i+1)%8==0:
        print("\n")

posmov = chess.moves(board,1)

# help =chess.hint(1,board)

for i in posmov :
    print(i.getpla())
    print(i.getmove())
    print('\n'*2)

aimov=chess.play(1,board)

for i in range(0,64):
    print(f"{board[i].getval():>4}", end=" ")
    if (i+1)%8==0:
        print("\n")
# print(help)
print(aimov)

