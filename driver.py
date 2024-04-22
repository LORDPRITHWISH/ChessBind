import build.brain as chess
from setboard import setPieces,setest
from modify import movepiece,getpos,show,getcord
import numpy as np
from typing import Union
from fastapi import FastAPI


board=[i for i in range(64)]

setPieces(board)

board = np.array(board)



posmov = chess.moves(board,1)

movarr = {getpos(i.getpla()): i.getmove() for i in posmov}

borarr={}
for i in range(0,64):
        borarr[i] = board[i].getval()

show(board)

aimov=chess.play(1,board)
movepiece(board,aimov)

show(board)









app = FastAPI()

@app.get("/")
def read_root():
    return {"Hello": "World"}

@app.get("/move")
def read_move():
    return movarr

@app.get("/board")
def read_board():
    return borarr

@app.get("/play")
def sendmove():
    return (getpos(aimov[0]),getpos(aimov[1]))