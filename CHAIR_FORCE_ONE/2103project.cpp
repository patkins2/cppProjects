#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>

using namespace std;

//this basically just creates a new datatype called "player"
//this allows us to do pretty much whatever we want without worry about
//trying to convert data types and making confusing conditional statements
//so any "player" object will have two things attached to it, a string for the name, and a char for their color
//i.e. Player 1 or Player 2 and R(red) or B(black)
struct player 
{
	string playerName;
	char playerColor;
};

const char space = '_'; //this global variable will be used to fill in the empty spaces on the board

void CheckChoice(char board[][7], player currentPlayer) //places the player's piece and checks to make sure it is a valid choice
{
	int playerDropChoice= 0;
	do
	{
		cout << "It is " << currentPlayer.playerName << "'s turn. ";
		cout << "Please enter what column you want to drop your piece in: ";
		cin  >> playerDropChoice;

		while (board[1][playerDropChoice] == 'R' || board[1][playerDropChoice] == 'B') //checks to make sure that the chosen column is not already full by checking the top of the board. 
		{
			cout << "That column is full, please enter a different column: ";
			cin  >> playerDropChoice;
		}

	}
	while (playerDropChoice < 1 || playerDropChoice > 7); //does the turn again without skipping the current player
	
	
	int row = 6;
	int playerTurn = 0;

	do 
	{
		if (board[row][playerDropChoice] != 'R' && board[row][playerDropChoice] != 'B') //this determines if the space is not full, then it will equal the color of the current player
		{
			board[row][playerDropChoice] = currentPlayer.playerColor; //sets that space to color of the current player
			playerTurn = 1; //we set playerTurn equal to one so that it automatically ends the turn
		}
		else
		{
		    --row; //but if the space was full, then we subtract row by 1, which means it will check the next space, which is one above
		}
	}
	while (playerTurn != 1); //when playerTurn = 1, it signifies the end of that player's turn
}

int CheckConnectFour(char board[][7], player currentPlayer) // checks the entire board starting from the top right corner for a winning combination
{
	char winningPiece = currentPlayer.playerColor; //tells you which player won

	int win = 0; //using this to determine if the player won

	for(int x = 8; x >= 1; --x)
	{
		for(int y = 9; y >= 1; --y)
		{
			if(board[x][y] == winningPiece && board[x-1][y-1] == winningPiece && board[x-2][y-2] == winningPiece && board[x-3][y-3] == winningPiece) //checks diagnally down to the left
			{
				win = 1;
			}
			if(board[x][y] == winningPiece && board[x][y-1] == winningPiece && board[x][y-2] == winningPiece &&board[x][y-3] == winningPiece) //checks vertically down
			{
				win = 1;
			}
			if(board[x][y] == winningPiece && board[x-1][y] == winningPiece && board[x-2][y] == winningPiece && board[x-3][y] == winningPiece) // checks horizontally to the left
			{	
				win = 1;
			}
			if(board[x][y] == winningPiece && board[x-1][y+1] == winningPiece && board[x-2][y+2] == winningPiece && board[x-3][y+3] == winningPiece) //checks diagnally to the left and up
			{
				win = 1;
			}
			if (board[x][y] == winningPiece   && board[x][y+1] == winningPiece && board[x][y+2] == winningPiece && board[x][y+3] == winningPiece) // checks vertically up
			{
				win = 1;
			}
		}
	}
	return win;
}

void DisplayBoard(char board[][7]) //displays the board
{
	int rows = 6, columns = 7, x, y;
	
	for(x = 1; x <= rows; x++)
	{
		cout << "|"; //sets the barriers of the board
		for(y = 1; y <= columns; y++)
		{
			if(board[x][y] != 'R' && board[x][y] != 'B')
			{
				    board[x][y] = space; //this fills the board with whatever we want the blank spaces to be
			}
			cout << "|" << board[x][y] << "|";
	    }
        cout << "|" << endl;// barriers 
	}
	cout << "| 1  2  3  4  5  6  7 |";
	
}

int RestartGame(char board[][7]) //asks the player if they would like to play again
{
	int restart = 0;

	cout << "Would you like to play again? 1 for Yes, 2 for No: "; //ask the user if they want to play again
	cin  >> restart; //get the user input
	
	if(restart == 1) //if they choose to restart
	{
		for(int x = 1; x <= 6; x++)
		{
			for(int y = 1; y <= 7; y++)
			{
				board[x][y] = space; //reloads the board with the space character
			}
		}
		DisplayBoard(board); //display the for the new game
	}
	else if (restart != 1) //if they choose to end
	{
		cout << "Goodbye!" << endl;
	}
    return restart;
}

int CheckIfFull(char board[][7]) //checks to see if the board is full, which would mean there is a tie
{
	int isBoardFull = 0;
	for (int x = 1; x <= 6; ++x) {
		for (int y = 1; y <= 7; ++y)//goes through the whole board
		{
		if (board[x][y] != space) //so if the index we are looking at is not equal to the space character, then obviously
			{					  //it must be a 'R' or 'Y'. So add 1 to isBoardFull. If isBoardFull is equal to 1 by the time
			++isBoardFull;        //this function ends, then that means all of the spots on the board have to be full
			}
		}
	}
return isBoardFull;
}

int main() 
{
    player player1, player2; //this creates the players 
	char board[6][7]; //this creates the board
	int playerWin, isBoardFull, playAgain = 0; //variables we will need for later

	
	cout << "Let's Play Connect 4!" << endl << endl; //get the players' info
	cout << "Player 1, please enter your name: ";
	getline(cin, player1.playerName); //set the name of the player
	player1.playerColor = 'R'; //set the color piece of the player
	
	cout << "Player 2, please enter your name: ";
	getline(cin, player2.playerName); //same as above
	player2.playerColor = 'B';
	
	DisplayBoard(board); //display the board for the first time
	cout << endl;
	do
	{
	    CheckChoice(board, player1); //check to see if that space is full or not, and then decide where to put it
	    DisplayBoard(board); //this should display an updated board
	    playerWin = CheckConnectFour(board, player1); //check is the player has connected 4 pieces
	   
	    cout << endl;
	    if(playerWin == 1) //if they have connected 4 pieces
	    {
	    	cout << endl << player1.playerName << " You Connected Four, You Win!" << endl;//tell them they won
	    	playAgain = RestartGame(board); //ask them if they want to restart the game.
			if (playAgain != 1)
			{
				break; //end the program
			}
			else 
			{
				continue; //restart the loop
			}
	    }
	    
	    CheckChoice(board, player2); //check to see if that space is full or not, and then decide where to put it
	    DisplayBoard(board); //this should display an updated board
	    playerWin = CheckConnectFour(board, player2); //check if the player has connected 4 pieces
	    
	    
	    cout << endl;
	    if(playerWin == 1)
	    {
	    	cout << endl << player2.playerName << " You Connected Four, You Win!" << endl; //let them know they won
	    	playAgain = RestartGame(board); // ask if they want to restart the board
			if (playAgain != 1) 
			{
				break; //end the program
			}
			else 
			{
				continue; //restart the loop
			}
	    }
	    
	    
	    isBoardFull = CheckIfFull(board); //calls a function to see if the board is full
		if (isBoardFull == 1)
		{
			cout << "The board is full, it is a tie!" << "\nRestarting the game." << endl; //display that the board is full
			playAgain = RestartGame(board); //asks if the player wants to restart the game
		}
	    
	}
	while(playAgain != 2); //basically triple checks that the game will end 
	return 0; //end of program
}
