# import build.brain as chess
from .build import brain as chess

def getpos(pos):
    return pos[0]*8+pos[1]

# def getref(pos, board):
#     return board[getpos(pos)]

def getcord(pos):

    return [pos//8,pos%8]

mov=[]

def movepiece(board,play,iniset=chess.set(0,0)):
    ini=play[0]
    fin=play[1]
    if (board[ini].value() == 20 and board[ini].unmoved):
        if (ini[1] + 2 == fin[1]):
            board[fin] = board[ini]
            board[ini] = iniset
            board[ini+3].move()
    fipo = board[fin]
    board[ini].move()
    board[fin] = board[ini]
    board[ini] = iniset
    mov.append((fin,ini))

def show(board):
    for i in range(0,64):
        print(f"{board[i].getval():>4}", end=" ")
        if (i+1)%8==0:
            print("\n")
    print('-'*70,"\n")
