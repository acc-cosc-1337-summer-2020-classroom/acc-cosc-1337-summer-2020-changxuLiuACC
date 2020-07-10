#include "tic_tac_toe.h"

int main() 
{
	TicTacToe tic_tac_toe;		//instance of TicTacToe for game
	std::string player;		//string used to store input for first player
	char play_again;	//char used to hold input on whether to play another round 

	do
	{	
		std::cout<<"\nEnter X or O: ";		//input on first player
		std::cin>>player;
		while(!(player == "X" || player == "O"))	//first player input validation
		{
			std::cout<<"Invalid Input. Please enter X or O: ";
			std::cin>>player;
		}

		tic_tac_toe.start_game(player);		//starts game

		do
		{
			int position;
			std::cout<<"Enter position fron 1 to 9: ";		//input from player on where to mark
			std::cin>>position;
			while(position < 1 || position > 9)		//input validation for where to mark
			{
				std::cout<<"Invalid Input. Please enter a position from 1 to 9: ";
				std::cin>>position;
			}
			tic_tac_toe.mark_board(position);	//member function of TicTacToe to mark the board
			tic_tac_toe.display_board();		//member function of TicTacToe to display the board
		} while (tic_tac_toe.game_over() == false);		//checks if the game ends (by tie or win) on whether to end loop
		
		if(tic_tac_toe.get_winner() != "C")	//displays the winner or tied in else ("C")
		{
			std::cout<<"Game Over. Winner is: "<<tic_tac_toe.get_winner();	
		}
		else
		{
			std::cout<<"Game Over. Tied! (Winner is: "<<tic_tac_toe.get_winner()<<")";
		}

		std::cout<<"\nPlay Again? Enter 'Y' or 'y' to start another round (or any other character to exit): ";	//asks user if they'd like to play again
		std::cin>>play_again;
	} while (toupper(play_again) == 'Y');

	return 0;
}
