#include <stdio.h>
#include <iostream>
#include <cstdlib>

using namespace std;

bool reshuffleAndCheckGameOver(char board[3][3], int position, int turn);
void printBoard(char board[3][3]);
int main() 
{
	char board[3][3] = {{'1','2','3'}, {'4','5','6'}, {'7','8','9'}};
	int maxTurns = 9;
	int i = 1;
	int position;	
	while (i <= maxTurns) {
		cout << "Enter move:";
		cin >> position;
		if (reshuffleAndCheckGameOver(board, position, i)) 
		{
			cout << "Game over!" << endl;
			return -1;
		}
		i += 1;
	}
	cout << "Game over!" << endl;
	return 0;
}

bool reshuffleAndCheckGameOver(char board[3][3], int position, int turn)
{
	int winning_positions[8][3] = {{1,2,3},{4,5,6},{7,8,9},{1,4,7}, {2,5,8}, {3,6,9}, {1,5,9}, {3,5,7}};
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
	if (turn % 2 != 0) // odd turn - 1, 3, 5, 7, 9 
	{
		board[row][col] = 'X';
	} else { // even turn - 2, 4, 6, 8
		board[row][col] = 'O';
	}
	printBoard(board);

	
	// check if valid
	if (
	    // horizontal wins
	    (board[0][0] == board[0][1] & board[0][0] == board[0][2]) ||
	    (board[1][0] == board[1][1] & board[1][0] == board[1][2]) ||
   	    (board[2][0] == board[2][1] & board[2][0] == board[2][2]) ||
	    // vertical wins
	    (board[0][0] == board[1][0] & board[0][0] == board[2][0]) ||
	    (board[0][1] == board[1][1] & board[0][1] == board[2][1]) ||
	    (board[0][2] == board[1][2] & board[0][2] == board[2][2]) ||
	    // diagonal wins
	    (board[1][1] == board[0][0] & board[1][1] == board[2][2]) ||
	    (board[1][1] == board[0][2] & board[1][1] == board[2][0]))
	{
		return true;
	}
	return false;
}

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
