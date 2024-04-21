import build.brain as chess
import numpy as np

def setpi(bor):
    for i in range(0,8):
        if i==0 :
            v=5
            for j in (0,2,1):
                bor[i*8+j]=chess.set(v)
                bor[i*8+(7-j)]=chess.set(v)
                v-=1
        elif i==7 :
            v=5
            for j in (0,2,1):
                bor[i*8+j]=chess.set(-v)
                bor[i*8+(7-j)]=chess.set(-v)
                v-=1
        elif i==1 :
            for j in range(0,8):
                bor[i*8+j]=chess.set(1)
        elif i==6 :
            for j in range(0,8):
                bor[i*8+j]=chess.set(-1)
        else :
            for j in range(0,8):
                bor[i*8+j]=chess.set()
    bor[3]=chess.set(20)
    bor[4]=chess.set(9)
    bor[59]=chess.set(-20)
    bor[60]=chess.set(-9)

board=[i for i in range(64)]

setpi(board)

# a.append(chess.set(i))
for i in range(0,64):
    print(f"{board[i].getval():>4}", end=" ")
    if (i+1)%8==0:
        print("\n")
print("\n"*4)
move = chess.moves(board,1)
for i in move :
    print(i.getpla())
    print(i.getmove())
    print('\n'*2)

# nparr=np.array(a)

