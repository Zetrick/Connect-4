#include <connect4.h>
#include <iostream>

int main()
{
	
    gameBoard * theBoard;
    Turn whosTurn = BEGINNING;
    
    std::cout << "Standard height is 6. Standard width is 7.\n";

	// Here I am getting a seg fault because theBoard is a pointer to gameBoard but the memory wasn't
	// allocated... It might have worked for you because an unitialized pointer can point to anything
	// including something from a previous execution or something..
	theBoard = new gameBoard;
	// And then I added a line to delete it at the end (all though since the program ends it doesnt really matter)
	
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
	delete theBoard;
}
