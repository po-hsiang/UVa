#include <iostream>
#include <stdio.h> // getchar
#include <string> // getline
//#include <utility> // swap

using namespace std;

struct Dice {

	int top, bottom, north, south, east, west;

	Dice()
	{
		top = 1;
		north = 2;
		west = 3;
		east = 4;
		south = 5;
		bottom = 6;
	}

	void Rotate(string command)
	{
		if (command == "north") {
			swap(top, north);
			swap(south, bottom);
			swap(top, bottom);
		}
		else if (command == "south") {
			swap(top, south);
			swap(north, bottom);
			swap(top, bottom);
		}
		else if (command == "east") {
			swap(top, east);
			swap(west, bottom);
			swap(top, bottom);
		}
		else if (command == "west") {
			swap(top, west);
			swap(east, bottom);
			swap(top, bottom);
		}
	}
};

int main()
{
	int num;
	string input;
	
	while (cin >> num) {
		getchar();
		if (num == 0)
			break;
		Dice dice;
		for (int i = 0; i < num; i++) {
			getline(cin, input);
			dice.Rotate(input);
		}
		cout << dice.top << "\n";
	}
	return 0;
}