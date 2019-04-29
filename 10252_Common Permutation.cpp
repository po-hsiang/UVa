#include <iostream>
#include <algorithm>
#include <cstring> // strlen

using namespace std;

char a[1001], b[1001];

int main()
{
	while (cin.getline(a, sizeof(a)) && cin.getline(b, sizeof(b))) {

		int la = strlen(a);
		int lb = strlen(b);

		// 要照字母順序排列，所以先進行sort
		sort(a, a + la);
		sort(b, b + lb);


		for (int i = 0, j = 0; i < la && j < lb; ) {
			if (a[i] == b[j]) {
				cout << a[i]; // 遇到一樣的就直接印出來
				i++;
				j++;
			}
			else if (a[i] > b[j])
				j++;
			else if (a[i] < b[j])
				i++;
		}
		cout << "\n";
	}
	return 0;
}