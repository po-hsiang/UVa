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

	result += (temp % 10)*(temp % 10); // �Ӧ�ƭn�O�o��W�h
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
				else if (test.find(tempInput) != test.end()) { // �Y�ˬd�쭫�ƥX�{���A�N���|�ܦ�1�F�A���@�w�n�ˬd��T�w�ܦ��ۤv�A�o�˥i�H�[�֤��|TLE
					cout << "Case #" << i + 1 << ": " << input << " is an Unhappy number.\n";
					break;
				}
				test.insert(tempInput);
			}
		}
	}
	return 0;
}