#include <iostream>
#include <set> // set<int>

using namespace std;

int input;
int testCase;

int SumSquareDigits(int temp)
{
	int result = 0;
	do {
		result += (temp % 10)*(temp % 10);
		temp /= 10;
	} while (temp >= 10);

	result += (temp % 10)*(temp % 10); // 個位數要記得算上去
	return result;
}

int main()
{
	cin >> testCase;

	for (int i = 0; i < testCase; i++) {

		cin >> input;
		set<int> test;

		int	tempInput = input;

		if (tempInput == 1)
			cout << "Case #" << i + 1 << ": " << input << " is a Happy number.\n";
		else {


			while (true) {
				
				tempInput = SumSquareDigits(tempInput);
				if (tempInput == 1) {
					cout << "Case #" << i + 1 << ": " << input << " is a Happy number.\n";
					break;
				}
				else if (test.find(tempInput) != test.end()) { // 若檢查到重複出現的，就不會變成1了，不一定要檢查到確定變成自己，這樣可以加快不會TLE
					cout << "Case #" << i + 1 << ": " << input << " is an Unhappy number.\n";
					break;
				}
				test.insert(tempInput);
			}
		}
	}
	return 0;
}