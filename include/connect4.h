#ifndef CONNECT4_H
#define CONNECT4_H

//  Connect 4
//  Created by Zachary Hetrick on 8/27/15.
//  Copyright (c) 2015 Zetrick. All rights reserved.
//
#include <iostream>

enum Turn
{
    PLAYER_1,
    PLAYER_2,
    BEGINNING,
};

struct slot
{
    bool hasX = false;
    bool hasO = false;
};

struct gameBoard
{
    slot ** gameBoard = NULL;
    int height = 0;
    int width = 0;
};

bool checkForWin(gameBoard * theBoard);
gameBoard * makeGameBoard(gameBoard * theBoard);
void printBoard(gameBoard * theBoard);
bool updateBoard(gameBoard * theBoard, int columnSelection, Turn playerTurn);
void takeTurn(gameBoard * theBoard, Turn & playerTurn);

#endif
