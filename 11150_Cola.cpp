#include <iostream>

using namespace std;

int main()
{
	int input, enjoyed, temp;

	while (cin >> input) {
		if (input == 0 || input > 200)
			break;

		// borrow 2
		enjoyed = input;
		temp = input;
		temp += 2;
		while (temp >= 3) {
			enjoyed += temp / 3;
			temp = temp / 3 + temp % 3;
		}
		if (temp % 3 == 2) { // 確認可以還2瓶
			cout << enjoyed << "\n";
			continue;
		}

		// borrow 1
		enjoyed = input;
		temp = input;
		temp += 1;
		while (temp >= 3) {
			enjoyed += temp / 3;
			temp = temp / 3 + temp % 3;
		}
		if (temp % 3 == 1) { // 確認可以還1瓶
			cout << enjoyed << "\n";
			continue;
		}

		// borrow 0
		enjoyed = input;
		temp = input;
		while (temp >= 3) { 
			enjoyed += temp / 3;
			temp = temp / 3 + temp % 3;
		}
		cout << enjoyed << "\n";
	}
	return 0;
}