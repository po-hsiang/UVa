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
		istringstream str(input); // �Ninput�r����γB�z��weights[]��
		
		memset(weights, 0, sizeof(weights));
		int weightsIndex = 0;
		int sum = 0;
		int temp;
		
		while (str >> temp) {
			weights[weightsIndex++] = temp;
			sum += temp;
		}

		if (sum % 2 == 1) {
			// �`�M�Y���_�ơA�@�w���i��
			cout << "NO\n";
			continue;
		}
		else {
			sum /= 2;
			memset(dp, 0, sizeof(dp));
			dp[0][0] = 1;
			// �b�u�ள�ei�Ӫ��~�����A�U�A�O�_�������q��j���i���
			for (int j = 0; j <= sum; j++) {
				for (int i = 0; i < weightsIndex; i++) {
					if (j == 0)
						dp[i][j] = 1; // ���q��0���ܡA�ү���(������)
					else
						dp[i][j] = dp[i - 1][j] || dp[i - 1][j - weights[i]]; // ������i�� || ����i��
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