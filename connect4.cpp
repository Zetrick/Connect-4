//  Connect 4
//  Created by Zachary Hetrick on 8/27/15.
//  Copyright (c) 2015 Zetrick. All rights reserved.
//

#include <iostream>

const char xMarker = 'X';
const char oMarker = 'O';
const char blankTile = '_';

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

bool checkForWin(gameBoard * theBoard)
{
    //Start checking horizontally for a win
    for(int i = 0; i < theBoard->height; ++i)
    {
        for(int j = 0; j < theBoard->width - 3; ++j)
        {
            if (theBoard->gameBoard[i][j].hasX && theBoard->gameBoard[i][j+1].hasX
                && theBoard->gameBoard[i][j+2].hasX && theBoard->gameBoard[i][j+3].hasX)
                return true;
            if (theBoard->gameBoard[i][j].hasO && theBoard->gameBoard[i][j+1].hasO
                && theBoard->gameBoard[i][j+2].hasO && theBoard->gameBoard[i][j+3].hasO)
                return true;
        }
    }
    
    //Check vertically
    for(int i = 0; i < theBoard->height - 3; ++i)
    {
        for(int j = 0; j < theBoard->width; ++j)
        {
            if (theBoard->gameBoard[i][j].hasX && theBoard->gameBoard[i+1][j].hasX
                && theBoard->gameBoard[i+2][j].hasX && theBoard->gameBoard[i+3][j].hasX)
                return true;
            if (theBoard->gameBoard[i][j].hasO && theBoard->gameBoard[i+1][j].hasO
                && theBoard->gameBoard[i+2][j].hasO && theBoard->gameBoard[i+3][j].hasO)
                return true;
            
        }
    }
    
    //Check diagonal SE
    for(int i = 0; i < theBoard->height - 3; ++i)
    {
        for(int j = 0; j < theBoard->width - 3; ++j)
        {
            if (theBoard->gameBoard[i][j].hasX && theBoard->gameBoard[i+1][j+1].hasX
                && theBoard->gameBoard[i+2][j+2].hasX && theBoard->gameBoard[i+3][j+3].hasX)
                return true;
            if (theBoard->gameBoard[i][j].hasO && theBoard->gameBoard[i+1][j+1].hasO
                && theBoard->gameBoard[i+2][j+2].hasO && theBoard->gameBoard[i+3][j+3].hasO)
                return true;
        }
    }
    
    //Check diagonal SW
    for(int i = 0; i < theBoard->height - 3; ++i)
    {
        for(int j = 0; j < theBoard->width - 3; ++j)
        {
            if (theBoard->gameBoard[i][j+3].hasX && theBoard->gameBoard[i+1][j+2].hasX
                && theBoard->gameBoard[i+2][j+1].hasX && theBoard->gameBoard[i+3][j].hasX)
                return true;
            if (theBoard->gameBoard[i][j+3].hasO && theBoard->gameBoard[i+1][j+2].hasO
                && theBoard->gameBoard[i+2][j+1].hasO && theBoard->gameBoard[i+3][j].hasO)
                return true;
        }
    }
    return false;
}

//Creates the game board and returns it
gameBoard * makeGameBoard(gameBoard * theBoard)
{
    theBoard->gameBoard = new slot * [theBoard->height];
    for(int i = 0; i < theBoard->height; ++i)
        theBoard->gameBoard[i] = new slot [theBoard->width];
    
    return theBoard;
}

void printBoard(gameBoard * theBoard)
{
    std::cout << "\n\n\n\n\n\n\n\n";
    for(int i = 0; i < theBoard->height; ++i)
    {
        std::cout << "\t\t\t\t\t\t|";
        for(int j = 0; j < theBoard->width; ++j)
        {
            if(theBoard->gameBoard[i][j].hasX) std::cout << xMarker << "|";
            else if(theBoard->gameBoard[i][j].hasO) std::cout << oMarker << "|";
            else std::cout << blankTile << "|";
        }
        std::cout << std::endl;
    }
    std::cout << "\t\t\t\t\t\t ";
    for(int i = 0; i < theBoard->width; ++i)
        std::cout << i+1 << " ";
    std::cout << std::endl << std::endl;
    
}

bool updateBoard(gameBoard * theBoard, int columnSelection, Turn playerTurn)
{
    if(columnSelection < 1 || columnSelection > theBoard->width) return false;
    
    --columnSelection; // for cleanliness in the loops (avoiding the constant -1)
    
    //Start with lowest tile in the selected column and check up for occupied spaces
    for(int i = theBoard->height-1; i >= 0; --i)
    {
        //If the space is not taken, then take it!
        if(!theBoard->gameBoard[i][columnSelection].hasX && !theBoard->gameBoard[i][columnSelection].hasO)
        {
            if(playerTurn == PLAYER_1) { theBoard->gameBoard[i][columnSelection].hasX = true; return true; }
            if(playerTurn == PLAYER_2) { theBoard->gameBoard[i][columnSelection].hasO = true; return true; }
        }
    }
    //If this returns, that means there was no valid move to be found. Ask the player to enter another column
    return false;
}

void takeTurn(gameBoard * theBoard, Turn & playerTurn)
{
    //switch whos turn it is
    if(playerTurn == PLAYER_1)
        playerTurn = PLAYER_2;
    else playerTurn = PLAYER_1;
    
    int columnSelection = 0;
    bool validMove = false;;
    while(!validMove)
    {
        printBoard(theBoard);
        if(playerTurn == PLAYER_1)
            std::cout << "(" << xMarker << ") Player 1\nEnter Column: ";
        else std::cout << "(" << oMarker << ") Player 2\nEnter Column: ";
        
        std::cin >> columnSelection;
        validMove = updateBoard(theBoard, columnSelection, playerTurn);
    }
}

int main()
{
    gameBoard * theBoard;
    Turn whosTurn = BEGINNING;
    
    std::cout << "Standard height is 6. Standard width is 7.\n";
    while(theBoard->height < 4)
    {
        std::cout << "Please select a height(minimum: 4) for the Connect Four board: ";
        std::cin >> theBoard->height;
    }
    while(theBoard->width < 4)
    {
        std::cout << "Please select a width(minimum: 4) for the Connect Four board: ";
        std::cin >> theBoard->width;
    }
    
    //Make a new game board with specified width and height
    theBoard = makeGameBoard(theBoard);
    
    while( !checkForWin(theBoard) )
    {
        takeTurn(theBoard, whosTurn);
    }
    
    printBoard(theBoard);
    
    if(whosTurn == PLAYER_1)
        std::cout << "\n\nPlayer 1 wins!";
    else std::cout << "\n\nPlayer 2 wins!";
    
    for(int i = 0; i < theBoard->height; ++i)
        delete [] theBoard->gameBoard[i];
    delete theBoard->gameBoard;
}
