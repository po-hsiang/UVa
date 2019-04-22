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
		// ���Ƨǫ�A�D����ơA���װ��ƭӾF�~�Ω_�ƭӾF�~�A���D�����|���v�T
		sort(s, s + r); 
		int best = s[r / 2];
		for (int i = 0; i < r; i++) {
			answer += abs(best - s[i]);
		}
		cout << answer << "\n";
	}
	return 0;
}