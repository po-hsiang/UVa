#include <iostream>
#include <cstring>
#define digitMax 2600 // array的寬度上限，用來表是大數的位元數

using namespace std;

int bigNum[1001][digitMax];
int answer[1001];

int main()
{
	memset(bigNum, 0, sizeof(bigNum));
	memset(answer, 0, sizeof(answer));

	bigNum[0][0] = 1;
	answer[0] = 1; // 0階乘等於1

	for (int i = 1; i <= 1000; i++) {
		for (int j = 0; j < digitMax; j++) {
			bigNum[i][j] = bigNum[i - 1][j] * i;
		}
		for (int j = 0; j < digitMax; j++) {
			if (bigNum[i][j] >= 10) {
				bigNum[i][j + 1] += bigNum[i][j] / 10;
				bigNum[i][j] %= 10;
			}
			answer[i] += bigNum[i][j];
		}
	}
	int input;
	while (cin >> input)
		cout << answer[input] << "\n";
	return 0;
}