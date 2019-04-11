#include <iostream>
#include <string> // getline
#include <stdio.h> // getchar

using namespace std;

int testCase;
char oper[13];
string input;

int main()
{
	cin >> testCase;
	getchar();

	while (testCase--) {

		getline(cin, input);
		// 整理input
		int opCount = 0;
		int num[13] = { 0 };
		for (int i = 0; i < input.length(); i++) {
			if (input[i] == '+' || input[i] == '*')
				oper[++opCount] = input[i];
			else
				num[opCount] = (10 * num[opCount]) + (input[i] - '0');
		}

		long long max = 1, min = 0, temp;

		// max：先算加法，再算乘法
		temp = num[0];
		for (int i = 1; i <= opCount; i++) {
			if (oper[i] == '+')
				temp += num[i];
			else {
				max *= temp;
				temp = num[i];
			}
		}
		if (temp)
			max *= temp;

		// min：先算乘法，再算加法
		temp = num[0];
		for (int i = 1; i <= opCount; i++) {
			if (oper[i] == '*')
				temp *= num[i];
			else {
				min += temp;
				temp = num[i];
			}
		}
		if (temp)
			min += temp;

		cout << "The maximum and minimum are " << max << " and " << min << ".\n";
	}
	return 0;
}