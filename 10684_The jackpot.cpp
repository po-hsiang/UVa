#include <iostream>
#include <algorithm>

using namespace std;

int N;
int inputNum[10001];

int main()
{
	while (cin >> N) {
		
		if (N == 0 || N > 10000)
			break;

		for (int i = 1; i <= N; i++) {
			cin >> inputNum[i];
		}

		int dp[10001] = { 0 };
		int answer = 0;
		
		for (int i = 1; i <= N; i++) {
			dp[i] = max(inputNum[i], dp[i - 1] + inputNum[i]); // 前一個最好的狀態加上目前這個跟現在這個的比較
			answer = max(answer, dp[i]);
		}

		if (answer > 0)
			cout << "The maximum winning streak is " << answer << ".\n";
		else
			cout << "Losing streak.\n";
	}
	return 0;
}