import build.brain as chess
from setboard import setPieces

board=[i for i in range(64)]

setPieces(board)

for i in range(0,64):
    print(f"{board[i].getval():>4}", end=" ")
    if (i+1)%8==0:
        print("\n")

move = chess.moves(board,1)

# for i in move :
#     print(i.getpla())
#     print(i.getmove())
#     print('\n'*2)



