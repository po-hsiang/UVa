#include <iostream>
#include <sstream>	// istringstream
#include <string>	// getline()
#include <stdio.h>	// getchar()
#include <cstring>	// memset

using namespace std;

int testCase;
int dp[20][100];
string input;
int weights[20];


int main()
{
	cin >> testCase;
	getchar();

	while (testCase--) {

		getline(cin, input);
		istringstream str(input); // 將input字串分割處理至weights[]中
		
		memset(weights, 0, sizeof(weights));
		int weightsIndex = 0;
		int sum = 0;
		int temp;
		
		while (str >> temp) {
			weights[weightsIndex++] = temp;
			sum += temp;
		}

		if (sum % 2 == 1) {
			// 總和若為奇數，一定不可能
			cout << "NO\n";
			continue;
		}
		else {
			sum /= 2;
			memset(dp, 0, sizeof(dp));
			dp[0][0] = 1;
			// 在只能拿前i個物品的狀態下，是否能湊齊重量為j的可能性
			for (int j = 0; j <= sum; j++) {
				for (int i = 0; i < weightsIndex; i++) {
					if (j == 0)
						dp[i][j] = 1; // 重量為0的話，皆能湊齊(都不拿)
					else
						dp[i][j] = dp[i - 1][j] || dp[i - 1][j - weights[i]]; // 不拿第i項 || 拿第i項
				}
			}
			if (dp[weightsIndex - 1][sum])
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}
	return 0;
}