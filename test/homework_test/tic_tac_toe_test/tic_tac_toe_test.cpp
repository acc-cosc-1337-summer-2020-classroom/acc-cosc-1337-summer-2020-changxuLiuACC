#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test first player set to X")
{
	TicTacToe tic_tac_toe;
	tic_tac_toe.start_game("X");
	REQUIRE(tic_tac_toe.get_player() == "X");
}

TEST_CASE("Test first player set to O")
{
	TicTacToe tic_tac_toe;
	tic_tac_toe.start_game("O");
	REQUIRE(tic_tac_toe.get_player() == "O");
}

TEST_CASE("Test game over if 9 slots are selected")
{
	TicTacToe tic_tac_toe1;
	tic_tac_toe1.start_game("X");

	tic_tac_toe1.mark_board(1);
	REQUIRE(tic_tac_toe1.game_over() == false);
	tic_tac_toe1.mark_board(2);
	REQUIRE(tic_tac_toe1.game_over() == false);
	tic_tac_toe1.mark_board(3);
	REQUIRE(tic_tac_toe1.game_over() == false);
	tic_tac_toe1.mark_board(4);
	REQUIRE(tic_tac_toe1.game_over() == false);
	tic_tac_toe1.mark_board(5);
	REQUIRE(tic_tac_toe1.game_over() == false);
	tic_tac_toe1.mark_board(7);
	REQUIRE(tic_tac_toe1.game_over() == false);
	tic_tac_toe1.mark_board(6);
	REQUIRE(tic_tac_toe1.game_over() == false);
	tic_tac_toe1.mark_board(9);
	REQUIRE(tic_tac_toe1.game_over() == false);
	tic_tac_toe1.mark_board(8);
	REQUIRE(tic_tac_toe1.game_over() == true);	//should result in a tie

	REQUIRE(tic_tac_toe1.get_winner() == "C");
}

TEST_CASE("Test win by first column")
{
	TicTacToe tic_tac_toe;
	tic_tac_toe.start_game("X");

	//Positions: 1-4-7
	tic_tac_toe.mark_board(1);	//X
	tic_tac_toe.mark_board(8);
	tic_tac_toe.mark_board(4);	//X
	tic_tac_toe.mark_board(9);
	tic_tac_toe.mark_board(7);	//X

	REQUIRE(tic_tac_toe.game_over() == true);
}

TEST_CASE("Test win by second column")
{
	TicTacToe tic_tac_toe;
	tic_tac_toe.start_game("X");

	//Positions: 2-5-8
	tic_tac_toe.mark_board(2);	//X
	tic_tac_toe.mark_board(1);
	tic_tac_toe.mark_board(5);	//X
	tic_tac_toe.mark_board(3);
	tic_tac_toe.mark_board(8);	//X

	REQUIRE(tic_tac_toe.game_over() == true);
}

TEST_CASE("Test win by third column")
{
	TicTacToe tic_tac_toe;
	tic_tac_toe.start_game("X");

	//Positions: 3-6-9
	tic_tac_toe.mark_board(3);	//X
	tic_tac_toe.mark_board(1);
	tic_tac_toe.mark_board(6);	//X
	tic_tac_toe.mark_board(2);
	tic_tac_toe.mark_board(9);	//X

	REQUIRE(tic_tac_toe.game_over() == true);
}

TEST_CASE("Test win by first row")
{
	TicTacToe tic_tac_toe;
	tic_tac_toe.start_game("X");

	//Positions: 1-2-3
	tic_tac_toe.mark_board(1);	//X
	tic_tac_toe.mark_board(4);
	tic_tac_toe.mark_board(2);	//X
	tic_tac_toe.mark_board(7);
	tic_tac_toe.mark_board(3);	//X	

	REQUIRE(tic_tac_toe.game_over() == true);
}

TEST_CASE("Test win by second row")
{
	TicTacToe tic_tac_toe;
	tic_tac_toe.start_game("X");

	//Positions: 4-5-6
	tic_tac_toe.mark_board(4);	//X
	tic_tac_toe.mark_board(1);
	tic_tac_toe.mark_board(5);	//X
	tic_tac_toe.mark_board(7);
	tic_tac_toe.mark_board(6);	//X

	REQUIRE(tic_tac_toe.game_over() == true);
}

TEST_CASE("Test win by third row")
{
	TicTacToe tic_tac_toe;
	tic_tac_toe.start_game("X");
	
	//Positions: 7-8-9
	tic_tac_toe.mark_board(7);	//X
	tic_tac_toe.mark_board(1);
	tic_tac_toe.mark_board(8);	//X
	tic_tac_toe.mark_board(4);
	tic_tac_toe.mark_board(9);	//X

	REQUIRE(tic_tac_toe.game_over() == true);
}

TEST_CASE("Test win diagonally from top left")
{
	TicTacToe tic_tac_toe;
	tic_tac_toe.start_game("X");

	//Positions: 1-5-9
	tic_tac_toe.mark_board(1);	//X
	tic_tac_toe.mark_board(3);
	tic_tac_toe.mark_board(5);	//X
	tic_tac_toe.mark_board(7);
	tic_tac_toe.mark_board(9);	//X

	REQUIRE(tic_tac_toe.game_over() == true);
}

TEST_CASE("Test win diagonally from bottom left")
{
	TicTacToe tic_tac_toe;
	tic_tac_toe.start_game("X");

	//Positions: 7-5-3
	tic_tac_toe.mark_board(7);	//X
	tic_tac_toe.mark_board(1);
	tic_tac_toe.mark_board(5);	//X
	tic_tac_toe.mark_board(9);
	tic_tac_toe.mark_board(3);	//X

	REQUIRE(tic_tac_toe.game_over() == true);
}
