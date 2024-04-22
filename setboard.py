import build.brain as chess

def eva(i,j):
    return i*8+j

def setPieces(bor):
    for i in range(0,8):
        if i==0 :
            v=5
            for j in (0,2,1):
                bor[eva(i,j)]=chess.set(v)
                bor[eva(i,7-j)]=chess.set(v)
                v-=1
        elif i==7 :
            v=5
            for j in (0,2,1):
                bor[eva(i,j)]=chess.set(-v)
                bor[eva(i,7-j)]=chess.set(-v)
                v-=1
        elif i==1 :
            for j in range(0,8):
                bor[eva(i,j)]=chess.set(1)
        elif i==6 :
            for j in range(0,8):
                bor[eva(i,j)]=chess.set(-1)
        else :
            for j in range(0,8):
                bor[eva(i,j)]=chess.set()
    bor[3]=chess.set(9)
    bor[4]=chess.set(20)
    bor[59]=chess.set(-9)
    bor[60]=chess.set(-20)



def setest(bor):
    for i in range(0,8):
        for j in range(0,8):
            bor[eva(i,j)]=chess.set()
    # bor[eva(i,j)]=chess.set()
    bor[eva(1,1)]=chess.set(3)
    bor[eva(2,3)]=chess.set(-1)
