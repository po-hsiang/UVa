#include <iostream>

using namespace std;

struct Point {
	int x;
	int y;
};

Point Maja[100000];

int main()
{
	Maja[1].x = 0;
	Maja[1].y = 0;

	for (int i = 2, index = 1; i <= 100000; index++) {

		for (int j = 0; j < index && i <= 100000; j++) {
			// ���U
			Maja[i].x = Maja[i - 1].x;
			Maja[i].y = Maja[i - 1].y + 1;
			i++;
		}
		for (int j = 0; j < index - 1 && i <= 100000; j++) {
			// �����U�A�n�S�O�`�N�o��֤@��
			Maja[i].x = Maja[i - 1].x - 1;
			Maja[i].y = Maja[i - 1].y + 1;
			i++;
		}
		for (int j = 0; j < index && i <= 100000; j++) {
			// �����W
			Maja[i].x = Maja[i - 1].x - 1;
			Maja[i].y = Maja[i - 1].y;
			i++;
		}
		for (int j = 0; j < index && i <= 100000; j++) {
			// ���W
			Maja[i].x = Maja[i - 1].x;
			Maja[i].y = Maja[i - 1].y - 1;
			i++;
		}
		for (int j = 0; j < index && i <= 100000; j++) {
			// ���k�W
			Maja[i].x = Maja[i - 1].x + 1;
			Maja[i].y = Maja[i - 1].y - 1;
			i++;
		}
		for (int j = 0; j < index && i <= 100000; j++) {
			// ���k�U
			Maja[i].x = Maja[i - 1].x + 1;
			Maja[i].y = Maja[i - 1].y;
			i++;
		}
	}

	int input;
	while (cin >> input) {
		cout << Maja[input].x << " " << Maja[input].y << "\n";
	}

	return 0;
}