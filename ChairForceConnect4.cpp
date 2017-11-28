#include <iostream>
#include <cstdlib> 
#include <ctime>

using namespace std;

//global variables
int rows = 6;
int columns = 7;
char space = '_';

int Tie(char board[][7])								//Checks for tie. If tie occurs game ends.
{
    int tie = 0;
    
    for(int y = 1; y <= columns; ++y) //itterates through the top row and increments tie whenever there is an 'R' or 'B'
    {                                 //if tie = 7 that means there is a piece in every entry in the top row and thus the board is full
            if(board[1][y] != space)
            {
            	++tie;
            }
    }
    return tie;
}

void DisplayBoard(char board[][7])
{
    for(int i = 1; i <= rows; i++)
	{
		cout << "|";
		
		for(int j = 1; j <= columns; j++)
		{
			if(board[i][j] != 'R' && board[i][j] != 'B')
			{
				    board[i][j] = space; 
			}
			cout << "|" << board[i][j] << "|";		//each itteration adds two "||" to create borders around each playable space
	    }
        cout << "|" << endl;		//outlines outside of board
	}
	cout << "| 1  2  3  4  5  6  7 |";		//Numbers each column of the board
	cout << endl;
	
}

int CheckConnectFour(char board[][7], char winningPiece) // checks the entire board starting from the top right corner for a winning combination
{
	//char winningPiece = 1; //tells you which player won

	int win = 0; //using this to determine if the player won

	for(int x = 8; x >= 1; --x)
	{
		for(int y = 9; y >= 1; --y)
		{
			if(board[x][y] == winningPiece && board[x-1][y-1] == winningPiece && board[x-2][y-2] == winningPiece && board[x-3][y-3] == winningPiece) //checks diagnally down to the left
			{
				win = 1;
			}
			if(board[x][y] == winningPiece && board[x][y-1] == winningPiece && board[x][y-2] == winningPiece && board[x][y-3] == winningPiece) //checks vertically down
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
		}
	}
	return win;
}

int main()
{
    
    //all of the variables we will need.
    srand(time(NULL));
    char board[6][7];
    bool win = false;
    string player1, player2;
    char player1piece, player2piece;
    int turn = (rand() % 2) + 1;
    int playerChoice;
    int playAgain = 0;
    int didThePlayerWin = 0;
    int isThereATie = 0;
    
    
    cout << "Let's Play Connect 4!" << endl; //get the players' info
	cout << "Player 1, please enter your name: ";
	getline(cin, player1); //set the name of the player
	player1piece = 'R'; //set the color piece of the player
	
	cout << "Player 2, please enter your name: ";
	getline(cin, player2); //same as above
    player2piece = 'B';
    
    DisplayBoard(board); //display the board for the first time
    
    cout << endl;
    
   
    
    do
    {
        while(turn == 1) //while loop for player 1
        {
            int currentRow = 6; //starting from the bottom
            
            cout << "It is " << player1 << "'s turn. \nPlease select where you want to put your piece: "; //get the player's choice
            do
            {
                cin  >> playerChoice;

		        while(board[1][playerChoice] == 'R' || board[1][playerChoice] == 'B') //if the top row and player's column has an R or B then that row has to be full
		        {
			        cout << "\nThat column is full, please enter a different column: ";
			        cin  >> playerChoice; //try again
		        }
            }
            while(playerChoice < 1 || playerChoice > 7); //will keep asking them until they put a number 1-7
            do
            {
                if (board[currentRow][playerChoice] != 'R' && board[currentRow][playerChoice] != 'B') //if there is no R or B then its empty and a piece can go there
		        {
			        board[currentRow][playerChoice] = player1piece; //that space equals that player's piece
			        turn = 2; //end the turn
		        }
		        else
	    	    {
		          --currentRow; //if not, then check the row above it
		        }
            }
            while (turn != 2); // end turn
        }
        DisplayBoard(board); //display updated board
        didThePlayerWin = CheckConnectFour(board, player1piece); //Checks if Player 1 has connect 4 using the CheckConnectBoard Function. 
        isThereATie = Tie(board); //checks if the board is full, meaning there is a tie
		if(didThePlayerWin == 1)
		{
			cout << player1 << " wins!" << endl; //tell which player won
		  	win = true;//ends the game
		  	break; 
		  	
		}
		if(isThereATie == 7)
		{
			cout << "There was a tie. Game Over" << endl; //tell the player the game is over
			win = true;//ends the game
			break;
		}
		
        
        while(turn == 2) //while loop for player 2
        {
            int currentRow = 6; //start from the bottom
            
            cout << "It is " << player2 << "'s turn. \nPlease select where you want to put your piece: "; //get the player's choice
            do
            {
                cin  >> playerChoice;

		        while(board[1][playerChoice] == 'R' || board[1][playerChoice] == 'B')  //if the top row and player's column has an R or B then that row has to be full
		        {
			        cout << "\nThat column is full, please enter a different column: ";
			        cin  >> playerChoice;
		        }
            }
            while (playerChoice < 1 || playerChoice > 7);//will keep asking them until they put a number 1-7
            do
            {
                if (board[currentRow][playerChoice] != 'R' && board[currentRow][playerChoice] != 'B') //if there is no R or B then its empty and a piece can go there
		        {
			        board[currentRow][playerChoice] = player2piece; //that space equals that player's piece
			        turn = 1; //end the turn
		        }
		        else
	    	    {
		          --currentRow; //check above
		        }
            }
            while (turn != 1); //end turn
            
        
            DisplayBoard(board); //display updated board
        	didThePlayerWin = CheckConnectFour(board, player2piece);	//Checks if Player 2 has connect 4 using the CheckConnectBoard Function.
        	isThereATie = Tie(board); //check if the board is full, meaning there is a tie
			if(didThePlayerWin == 1)
			{
		  		cout << player2 <<" wins!" << endl; //say which player won
		  		win = true;//ends the game
		    }
		    if(isThereATie == 7)
			{
				cout << "There was a tie. Game Over" << endl; //say there is a tie
				win = true;//ends the game
				break;
			}
			
		}
    }
    while(win != true);//as long as win isnt true the loop will repeat
    
    return 0; //end program
}

