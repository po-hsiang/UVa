#include <iostream>
#include <cstring> // memset

using namespace std;

int visit[10001];
int prime[10001];

int main()
{
	// �ؽ�ƪ�
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
				break; // ��������

			sum += prime[i]; // ��Ƴs�[
			
			while (sum > input) {
				sum -= prime[l++]; // �W�L���ܡA�N�q�̤p����ƶ}�l��		
			}
			if (sum == input)
				ans++;
		}
		cout << ans << "\n";
	}
	return 0;
}