#include <iostream>
#include <stdio.h> // getchar
#include <algorithm> // sort
#include <cmath> // abs

using namespace std;

int testCases, r, answer;
int s[500];

int main()
{
	cin >> testCases;
	getchar();

	while (testCases--) {
		cin >> r;
		answer = 0;

		for (int i = 0; i < r; i++) {
			cin >> s[i];
		}
		// 逼―い计ぃ阶案计綟﹡┪计綟﹡肈常ぃ穦Τ紇臫
		sort(s, s + r); 
		int best = s[r / 2];
		for (int i = 0; i < r; i++) {
			answer += abs(best - s[i]);
		}
		cout << answer << "\n";
	}
	return 0;
}