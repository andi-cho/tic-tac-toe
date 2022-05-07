#include <stdio.h>
#include <iostream>
#include <cstdlib>

using namespace std;

void reshuffle(char board[3][3], int position, int turn);
void printBoard(char board[3][3]);

int main() 
{
	// initialize tic tac toe board
	char board[3][3] = {{'1','2','3'}, {'4','5','6'}, {'7','8','9'}};
	int maxTurns = 9;
	int i = 1;
	int position;	
 	
	while (i <= maxTurns) {
		cout << "Enter move:";
		cin >> position;
		reshuffle(board, position, i); 
		i += 1;
	}
	cout << "Game over!" << endl;
	return 0;
}

// find row + col of user inputted position and mark either 'X' or 'O' depending on player
void reshuffle(char board[3][3], int position, int turn)
{
	int row, col;
	if (position == 1 || position == 2 || position == 3)
	{
		row = 0;
	}
	else if (position == 4 || position == 5 || position == 6)
	{
		row = 1;
	}
	if (position == 7 || position == 8 || position == 9)
	{
		row = 2;
	}
	if (position == 1 || position == 4 || position == 7)
	{
		col = 0;
	}
	else if (position == 2 || position == 5 || position == 8)
	{
		col = 1;
	}
	if (position == 3 || position == 6 || position == 9)
	{
		col = 2;
	}
	if (turn % 2 != 0) // odd turn is player 'X'  
	{
		board[row][col] = 'X';
	} else { // even turn is player 'O'
		board[row][col] = 'O';
	}
	printBoard(board);
}

// print board in required format
void printBoard(char board[3][3])
{
	int row, col;
	for (int row = 0; row < 3; row++) 
	{
		for (int col = 0; col < 3; col++)
		{
			cout << board[row][col];
		}
		cout << "" << endl;
	}
	return;
}
