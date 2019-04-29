#include <iostream>
#include <cstring> // memset

using namespace std;

int main()
{
	int T, N, P = 0;
	int h[101];
	int hartals[3651];

	cin >> T; // input cases

	while (T--) {

		cin >> N; // days
		cin >> P; // parties

		for (int i = 1; i <= P; i++) {
			cin >> h[i];
		}

		memset(hartals, 0, sizeof(hartals));
		int answer = 0;

		for (int i = 1; i <= P; i++) {
			for (int j = h[i]; j <= N; j += h[i]) {
				hartals[j] = 1; // 1代表那一天罷工

				if (j % 7 == 6 || j % 7 == 0) // 星期五和星期六不算
					hartals[j] = 0;
			}
		}

		for (int i = 1; i <= N; i++) {
			if (hartals[i] == 1)
				answer++;
		}
		cout << answer << "\n";
	}
	return 0;
}

// 另一種解法，是用for跑每一天，再去跑每一個party是否罷工
/*
#include<iostream>
using namespace std;
int main()
{
	int num;
	cin >> num;

	while (num--) {
		int N, P;
		int finalAnswer = 0;
		cin >> N;
		cin >> P;
		int h[100];

		for (int i = 0; i < P; i++)
			cin >> h[i];

		for (int days = 1; days <= N; days++) {
			if (days % 7 == 6 || days % 7 == 0)
				continue;
			for (int i = 0; i < P; i++) {
				if (days % h[i] == 0) {
					finalAnswer++;
					break;
				}
			}
		}
		cout << finalAnswer << "\n";
	}
	return 0;
}
*/