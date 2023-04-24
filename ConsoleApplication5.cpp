#include <string>
#include <iostream>
using namespace std;
#define length 3
int n = 2;
char MATRIX[length][length];
char turn = 'x';
int scores[2];
string names[2];
void turn_over()
{
	if (turn == 'x')
		turn = 'o';
	else if (turn == 'o')
		turn = 'x';
}
void print()
{
	cout << endl;
	cout << endl;
	cout << "||";
	for (int j = 0; j < length; j++)
	{
		cout << "---|";
	}
	cout << "|";
	cout << endl;	for (int i = 0; i < length; i++)
	{
		cout << "||";
		for (int j = 0; j < length; j++)
		{
			cout << " " << MATRIX[i][j] << " |";
		}
		cout << "|";
		cout << endl;
		cout << "||";
		for (int j = 0; j < length; j++)
		{
			cout << "---|";
		}
		cout << "|";
		cout << endl;
	}
	cout << "||";
	cout << "Have fun!";
	cout << endl;
	cout << "0 ==>Menu!";
	cout << endl;
	cout << "It's " << turn << "'s turn!";
}

int CountInRow(char c, char row[])
{
	int count = 0;
	int temp = 0;
	for (int i = 0; i < length; i++)
	{
		if (row[i] == c)
		{
			temp++;
			if (temp > count)
				count = temp;
		}
		else temp = 0;
	}
	return count;
}
bool IsWin(char c)
{
	for (int i = 0; i < length; i++)
	{
		char temp[length];
		for (int j = 0; j < length; j++)
		{
			temp[j] = MATRIX[i][j];
		}
		int t = CountInRow(c, temp);
		if (t >= n)
			return true;
	}


	for (int i = 0; i < length; i++)
	{
		char temp[length];
		for (int j = 0; j < length; j++)
		{
			temp[j] = MATRIX[j][i];
		}
		int t = CountInRow(c, temp);
		if (t >= n)
			return true;
	}
	{
		char temp[length];
		for (int j = 0; j < length; j++)
		{
			temp[j] = MATRIX[j][j];
		}
		int t = CountInRow(c, temp);
		if (t >= n)
			return true;
	}

	{
		char temp[length];
		for (int j = 0; j < length; j++)
		{
			temp[j] = MATRIX[length - 1 - j][j];
		}
		int t = CountInRow(c, temp);
		if (t >= n)
			return true;
	}
	return false;
}

bool IsItOk(int r, int c)
{
	if (MATRIX[r][c] != ' ')
		return false;
	if (r < 0)
		return false;
	if (c < 0)
		return false;
	if (r >= length)
		return false;
	if (c >= length)
		return false;
	return true;
}
void run()
{
	while (true)
	{
		print();
		int r, c;
		cin >> r;
		if (r == 0)
			return;
		cin >> c;
		while (!IsItOk(r - 1, c - 1))
		{
			cout << "\nWrong cell! ";
			cin >> r;
			cin >> c;
		}
		MATRIX[r - 1][c - 1] = turn;
		if (IsWin(turn))
		{
			cout << endl << "Player " << turn << " wins";
			if (turn == 'x')				scores[0]++;
			if (turn == 'o')				scores[1]++;
			return;
		};
		turn_over();
	}
}
void init()
{
	for (int i = 0; i < length; i++)
		for (int j = 0; j < length; j++)
			MATRIX[i][j] = ' ';
}
int main()
{

	scores[0] = 0;
	scores[1] = 0;
	cout << "\nplayer1 name: "; cin >> names[0];
	cout << "\nplayer2 name: "; cin >> names[1];
	cout << "\nn:"; cin >> n;
	while (true)
	{
		cout << endl << "1)new game\n2)scores\n3)exit";
		int m;
		cin >> m;
		switch (m)
		{
		case 1:init(); run(); break;
		case 2:cout << endl << names[0] << "(x): " << scores[0] << endl << names[1] << "(o): " << scores[1]; break;
		case 3:return 0; break;
		default:
			break;
		}
	}
}