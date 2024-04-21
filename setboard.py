import build.brain as chess

def setPieces(bor):
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