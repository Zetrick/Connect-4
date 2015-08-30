//
//  Connect 4
//
//
//  Created by Zachary Hetrick on 8/27/2015
//  Copyright (c) 2015 Zetrick. All rights reserved.
//

#include <iostream>

void wait()
{
    std::cin.sync();
    std::cin.get();
}

const char xMarker = 'X';
const char oMarker = 'O';
const char blankTile = '_';

enum Turn
{
    PLAYER_1 = 0,
    PLAYER_2 = 1,
    BEGINNING = 2,
};

struct slot
{
    bool hasX = false;
    bool hasO = false;
};

bool checkForWin(slot ** board, int height, int width)
{
    //Start checking horizontally for a win
    for(int i = 0; i < height; ++i)
    {
        for(int j = 0; j < width - 3; ++j)
        {
            if (board[i][j].hasX && board[i][j+1].hasX && board[i][j+2].hasX && board[i][j+3].hasX)
                return true;
            if (board[i][j].hasO && board[i][j+1].hasO && board[i][j+2].hasO && board[i][j+3].hasO)
                return true;
        }
    }
    
    //Check vertically
    for(int i = 0; i < height - 3; ++i)
    {
        for(int j = 0; j < width; ++j)
        {
            if (board[i][j].hasX && board[i+1][j].hasX && board[i+2][j].hasX && board[i+3][j].hasX)
                return true;
            if (board[i][j].hasO && board[i+1][j].hasO && board[i+2][j].hasO && board[i+3][j].hasO)
                return true;
            
        }
    }
    
    //Check diagonal SE
    for(int i = 0; i < height - 3; ++i)
    {
        for(int j = 0; j < width - 3; ++j)
        {
            if (board[i][j].hasX && board[i+1][j+1].hasX && board[i+2][j+2].hasX && board[i+3][j+3].hasX)
                return true;
            if (board[i][j].hasO && board[i+1][j+1].hasO && board[i+2][j+2].hasO && board[i+3][j+3].hasO)
                return true;
        }
    }
    
    //Check diagonal SW
    for(int i = 0; i < height - 3; ++i)
    {
        for(int j = 0; j < width - 3; ++j)
        {
            if (board[i][j+3].hasX && board[i+1][j+2].hasX && board[i+2][j+1].hasX && board[i+3][j].hasX)
                return true;
            if (board[i][j+3].hasO && board[i+1][j+2].hasO && board[i+2][j+1].hasO && board[i+3][j].hasO)
                return true;
        }
    }
    return false;
}

//Creates the game board and returns it
slot ** makeGameBoard(int height, int width)
{
    slot ** board = new slot * [height];
    for(int i = 0; i < height; ++i)
        board[i] = new slot [width];
    
    return board;
}

void printBoard(slot ** board, int height, int width)
{
    std::cout << "\n\n\n\n\n\n\n\n";
    for(int i = 0; i < height; ++i)
    {
        std::cout << "\t\t\t\t\t\t|";
        for(int j = 0; j < width; ++j)
        {
            if(board[i][j].hasX) std::cout << xMarker << "|";
            else if(board[i][j].hasO) std::cout << oMarker << "|";
            else std::cout << blankTile << "|";
        }
        std::cout << std::endl;
    }
    std::cout << "\t\t\t\t\t\t ";
    for(int i = 0; i < width; ++i)
        std::cout << i+1 << " ";
    std::cout << std::endl << std::endl;
    
}

bool updateBoard(slot** board, int height, int width, int columnSelection, Turn playerTurn)
{
    if(columnSelection < 1 || columnSelection > width) return false;
    
    --columnSelection; // for cleanliness in the loops (avoiding the constant -1)
    bool placedToken = false;
    
    //Start with lowest tile in the selected column and check up for occupied spaces
    for(int i = height-1; i >= 0; --i)
    {
        //If the space is not taken, then take it!
        if(!board[i][columnSelection].hasX && !board[i][columnSelection].hasO && !placedToken)
        {
            if(playerTurn == PLAYER_1) board[i][columnSelection].hasX = true;
            if(playerTurn == PLAYER_2) board[i][columnSelection].hasO = true;
            placedToken = true;
        }
    }
    //If this returns, that means there was no valid move to be found. Ask the player to enter another column
    return placedToken;
}

void takeTurn(slot ** board, int height, int width, Turn & playerTurn)
{
    //switch whos turn it is
    if(playerTurn == PLAYER_1)
        playerTurn = PLAYER_2;
    else playerTurn = PLAYER_1;
    
    int columnSelection = 0;
    bool validMove = false;;
    while(!validMove)
    {
        printBoard(board, height, width);
        if(playerTurn == PLAYER_1)
            std::cout << "(" << xMarker << ") Player 1\nEnter Column: ";
        else std::cout << "(" << oMarker << ") Player 2\nEnter Column: ";
        
        std::cin >> columnSelection;
        validMove = updateBoard(board, height, width, columnSelection, playerTurn);
    }
}

int main(int argc, const char * argv[])
{
    int height = 0;
    int width = 0;
    Turn whosTurn = BEGINNING;
    
    std::cout << "Standard height is 6. Standard width is 7.\n";
    while(height < 4)
    {
        std::cout << "Please select a height(minimum: 4) for the Connect Four board: ";
        std::cin >> height;
    }
    while(width < 4)
    {
        std::cout << "Please select a width(minimum: 4) for the Connect Four board: ";
        std::cin >> width;
    }
    
    //Make a new game board with specified width and height
    slot ** gameBoard = makeGameBoard(height, width);
    
    while( !checkForWin(gameBoard, height, width) )
    {
        takeTurn(gameBoard, height, width, whosTurn);
    }
    
    printBoard(gameBoard, height, width);
    
    if(whosTurn == PLAYER_1)
        std::cout << "\n\n(" << xMarker << ") Player 1 wins!";
    else std::cout << "\n\n(" << oMarker << ") Player 2 wins!";
    
    for(int i = 0; i < height; ++i)
        delete [] gameBoard[i];
    delete gameBoard;
}
