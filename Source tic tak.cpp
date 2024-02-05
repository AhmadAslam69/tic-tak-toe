#include <iostream>
#include <iomanip>
using namespace std;






void grid(char arr[3][3])
{
	cout << "Game GRID: " << endl << endl;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << arr[i][j];

			if (j < 2)
			{
				cout << " | ";

			}
			

		}
		cout << endl;

		if (i < 2)
		{
			cout << "----------";
		}
		cout << endl;

	}


}



bool chkwin(char arr[3][3], char player)
{

	for (int i = 0; i < 3; i++)
	{

		if (arr[i][0] == player && arr[i][1] == player && arr[i][2] == player || arr[0][i] == player && arr[1][i] == player && arr[2][i] == player)
		{
			return true;

		}

	}

	if (arr[0][0] == player && arr[1][1] == player && arr[2][2] == player || arr[0][2] == player && arr[1][1] == player && arr[2][0] == player)
	{
		return true;

	}


	return false;

}


bool chkdraw(char arr[3][3])

{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (arr[i][j] == ' ')

				return false;

		}

	}

	return true;


}

char swi(char player)
{

	return (player == 'X') ? 'O' : 'X';


}



int main()
{
	char arr[3][3];
	char player = 'X';

	bool won = false;
	bool draw = false;

	char playagain;

	system("color 17");

	cout << setfill('*') << setw(120);
	cout << " " << endl;
	
	cout << setfill(' ') << setw(75);
	cout << "**** WELCOME TO TIC TAK TOE GAME ****" << endl ; 

	cout << setfill('*') << setw(120);
	cout << " " << endl <<endl;

	do
	{
		// loop to intialize grid 
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				arr[i][j] = ' ';


			}


		}

		grid(arr);

		do
		{
			int row, col;

			cout << "Player " << player << " Enter your positions " << endl <<endl;

			cout << "Enter row # :";
			cin >> row;


			cout << "Enter col # :";
			cin >> col;

			cout << endl;

			if (row >= 0 && row < 3 && col >= 0 && col < 3 && arr[row][col]==' ')
			{
				arr[row][col] = player;

				grid(arr);

		   
				won = chkwin(arr, player);

				if (won)
				{ 
					cout << "Player " << player << " has won the game CONGRATULATIONS " << endl;
					break;


				}

				draw = chkdraw(arr);

				if (draw)
				{
					cout << "The game has been drawn " << endl;
					break;


				}

				player = swi(player);

			}
			else
			{
				cout << "invalid move " << endl;


			}
			cout << endl;

		} while (!won && !draw);

		cout << "if you want to play again press (y or Y) : ";
		cin >> playagain;



	} while (playagain == 'y' || playagain == 'Y');


	return 0;


}


