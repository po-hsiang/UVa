#include <iostream>
#include <cstring> // memset

using namespace std;

int visit[10001];
int prime[10001];

int main()
{
	// 建質數表
	memset(visit, 0, sizeof(visit));
	int primeIndex = 0;
	for (int i = 2; i < 10001; i++) {
		if (!visit[i]) {
			prime[primeIndex++] = i;
			for (int j = i; j < 10001; j += i) {
				visit[j] = 1;
			}
		}
	}
	
	int input;
	while (cin >> input) {
		if (input == 0)
			break;

		int sum = 0, l = 0, ans = 0;
		for (int i = 0; i < 10001; i++) {
			
			if (prime[i] > input)
				break; // 提早結束

			sum += prime[i]; // 質數連加
			
			while (sum > input) {
				sum -= prime[l++]; // 超過的話，就從最小的質數開始減		
			}
			if (sum == input)
				ans++;
		}
		cout << ans << "\n";
	}
	return 0;
}