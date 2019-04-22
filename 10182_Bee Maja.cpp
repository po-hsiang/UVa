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
			// 往下
			Maja[i].x = Maja[i - 1].x;
			Maja[i].y = Maja[i - 1].y + 1;
			i++;
		}
		for (int j = 0; j < index - 1 && i <= 100000; j++) {
			// 往左下，要特別注意這邊少一次
			Maja[i].x = Maja[i - 1].x - 1;
			Maja[i].y = Maja[i - 1].y + 1;
			i++;
		}
		for (int j = 0; j < index && i <= 100000; j++) {
			// 往左上
			Maja[i].x = Maja[i - 1].x - 1;
			Maja[i].y = Maja[i - 1].y;
			i++;
		}
		for (int j = 0; j < index && i <= 100000; j++) {
			// 往上
			Maja[i].x = Maja[i - 1].x;
			Maja[i].y = Maja[i - 1].y - 1;
			i++;
		}
		for (int j = 0; j < index && i <= 100000; j++) {
			// 往右上
			Maja[i].x = Maja[i - 1].x + 1;
			Maja[i].y = Maja[i - 1].y - 1;
			i++;
		}
		for (int j = 0; j < index && i <= 100000; j++) {
			// 往右下
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