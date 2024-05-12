# import .build.brain as chess
from .build import brain as chess    
# from setboard import setPieces,setest
from .setboard import setPieces,setest
# from . import setboard as sb
# from modify import movepiece,show,getpos,getcord
from .modify import movepiece,show,getpos,getcord
# from modify import movepiece,show,getpos,getcord
import numpy as np
# from fastapi import FastAPI
# import uvicorn
import time


board=[i for i in range(64)]

setPieces(board)
# setest(board)

board = np.array(board)


def allmoves():
    posmov = chess.moves(board,1)

    return {i.getpla(): i.getmove() for i in posmov}
# keys = list(movarr.keys())
# for i in keys:
#     print(i, movarr[i])

# borarr={}
# for i in range(0,64):
#         borarr[i] = board[i].getval()

def play(side:int):
    stm=time.time()
    aimov=chess.play(side,board)
    movepiece(board,aimov)
    print(aimov)
    show(board)
    print(time.time()-stm)
    # return -side

# show(board)
# stm=time.time()
# aimov=chess.play(1,board)
# movepiece(board,aimov)


# for i in range(0,20):
#     play(1)
#     play(-1)

show(board)
play(1)




# cmake .. && make && python3 ../driver.py






# app = FastAPI()

# @app.get("/")std::cout
# def read_root():
#     return {"Hello": "World"}

# @app.get("/move")
# def read_move():
#     return movarr

# @app.get("/board")
# def read_board():
#     return borarr

# @app.get("/play")
# def sendmove():
#     return (getpos(aimov[0]),getpos(aimov[1]))

# @app.post("/chance")
# async def receive_integers(integers: list[int]):
#     print(getcord(integers[0]),getcord(integers[1]))
#     return {"received_integers": integers}


# uvicorn.run(app)