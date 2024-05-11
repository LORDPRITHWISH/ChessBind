import build.brain as chess

def eva(i,j):
    return i*8+j

def setPieces(bor):
    for i in range(0,8):
        if i==0 :
            v=5
            for j in (0,2,1):
                bor[eva(i,j)]=chess.set(v,eva(i,j))
                bor[eva(i,7-j)]=chess.set(v,eva(i,7-j))
                v-=1
        elif i==7 :
            v=5
            for j in (0,2,1):
                bor[eva(i,j)]=chess.set(-v,eva(i,j))
                bor[eva(i,7-j)]=chess.set(-v,eva(i,7-j))
                v-=1
        elif i==1 :
            for j in range(0,8):
                bor[eva(i,j)]=chess.set(1,eva(i,j))
        elif i==6 :
            for j in range(0,8):
                bor[eva(i,j)]=chess.set(-1,eva(i,j))
        else :
            for j in range(0,8):
                bor[eva(i,j)]=chess.set(0,eva(i,j))
    bor[3]=chess.set(9,3)
    bor[4]=chess.set(20,4)
    bor[59]=chess.set(-9,59)
    bor[60]=chess.set(-20,60)



def setest(bor):
    for i in range(0,8):
        for j in range(0,8):
            bor[eva(i,j)]=chess.set(0,eva(i,j))
    # bor[eva(i,j)]=chess.set()
    bor[eva(2,5)]=chess.set(5,eva(2,5))
    bor[eva(5,2)]=chess.set(-1,eva(2,5))
    # bor[eva(4,1)]=chess.set(1)
    # bor[eva(3,3)]=chess.set(-1)
