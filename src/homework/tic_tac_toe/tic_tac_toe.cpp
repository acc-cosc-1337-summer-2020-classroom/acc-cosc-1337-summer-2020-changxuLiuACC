//cpp
#include "tic_tac_toe.h"

bool TicTacToe::game_over()     //determines if the game is over by a win or tie (board filled up)
{
    if(check_column_win() || check_row_win() || check_diagonal_win())
    {
        set_winner();  
        return true;
    }
    else if (check_board_full())    //for a tie
    {
        winner = "C";
        return true;
    }    
    return false;   //returns false if neither of the game ending conditions above are met
}

void TicTacToe::mark_board(int position)
{
    pegs[position - 1] = player;
    set_next_player();
}

void TicTacToe::start_game(std::string first_player)
{
    player = first_player;
    clear_board();
}

void TicTacToe::display_board() const
{
    for(std::size_t i = 0; i < pegs.size(); i += 3)
    {
        std::cout<<pegs[i]<<"|"<<pegs[i+1]<<"|"<<pegs[i+2]<<"\n";
    }
}

void TicTacToe::set_next_player()
{
    if(player == "X")
    {
        player = "O";
    }
    else
    {
        player = "X";
    }
}

bool TicTacToe::check_board_full() const
{
    for(auto peg: pegs)
    {
        if(peg == " ")
        {
            return false;
        }
    }
    return true;
}

void TicTacToe::clear_board()
{
    for(std::size_t i = 0; i < pegs.size(); ++i)
    {
        pegs[i] = " ";
    }
}

bool TicTacToe::check_column_win()
{
    for(int i = 0; i < 3; ++i)  //iterates through each column
    {
        if(pegs[i] != " " && pegs[i] == pegs[i+3] && pegs[i+3] == pegs[i+6])    //checks if each column is non-blank and the same, indicating a win
        {
            return true;   
        }
    }
    return false;   //if none of the win conditions are met above, then the function will make it to this return statement of false (no column win)
}

bool TicTacToe::check_row_win()
{
    for(int i = 0; i < 7; i += 3)   //iterates through each row
    {
        if(pegs[i] != " " && pegs[i] == pegs[i+1] && pegs[i+1] == pegs[i+2])    //checks if each row is non-blank and the same, indicating a win
        {
            return true;
        }
    }
    return false;   //if none of the win conditions are met above, then the function will make it to this return statement of false (no row win)
}

bool TicTacToe::check_diagonal_win()
{
    if((pegs[0] != " " && pegs[0] == pegs[4] && pegs[4] == pegs[8]) || (pegs[2] != " " && pegs[2] == pegs[4] && pegs[4] == pegs[6]))    //checks if the diagonals are non-blank and the same, indicating a win
    {
        return true;
    }
    return false;   //don't need else because if the above if was met, it would have already exited the function
}

void TicTacToe::set_winner()
{
    if(player == "X")
    {
        winner = "O";   //after mark_board(), it will have already switched players, so need to assign opposite of current player as the winner if win detected
    }
    else
    {
        winner = "X";
    }
    
}
