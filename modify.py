import build.brain as chess

def getpos(pos):
    return pos[0]*8+pos[1]

def getref(pos, board):
    return board[getpos(pos)]

def getcord(pos):
    return [pos//8,pos%8]

def movepiece(board,play,iniset=chess.set()):
    ini=play[0]
    fin=play[1]
    if (getref(ini, board).value() == 20 and getref(ini, board).unmoved):
        if (ini[1] + 2 == fin[1]):
            board[getpos(fin)] = board[getpos(ini)]
            board[getpos(ini)] = iniset
            board[getpos([ini[0], ini[1] + 3])].move()
    fipo = getref(fin, board)
    getref(ini, board).move()
    board[getpos(fin)] = board[getpos(ini)]
    board[getpos(ini)] = iniset
    return fipo

def show(board):
    for i in range(0,64):
        print(f"{board[i].getval():>4}", end=" ")
        if (i+1)%8==0:
            print("\n")
