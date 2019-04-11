#include <iostream>

using namespace std;

int n, m;
int caseCount = 0;
char mines[102][102];
char answer[102][102];

int main()
{
	while (cin >> n >> m) {

		if (!n && !m)
			break;

		caseCount++;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				answer[i][j] = '0';
			}
		}


		for (int i = 0; i < n; i++) {
			cin >> mines[i];
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {

				if (mines[i][j] == '*') {
					answer[i][j] = '*';

					// ���W++
					if (i - 1 >= 0 && j - 1 >= 0 && mines[i - 1][j - 1] != '*')
						answer[i - 1][j - 1] += 1;

					// �W++
					if (i - 1 >= 0 && mines[i - 1][j] != '*')
						answer[i - 1][j] += 1;

					// �k�W++
					if (i - 1 >= 0 && j + 1 <= m - 1 && mines[i - 1][j + 1] != '*')
						answer[i - 1][j + 1] += 1;

					// ��++
					if (j - 1 >= 0 && mines[i][j - 1] != '*')
						answer[i][j - 1] += 1;

					// �k++
					if (j + 1 <= m && mines[i][j + 1] != '*')
						answer[i][j + 1] += 1;

					// ���U++
					if (i + 1 <= n - 1 && j - 1 >= 0 && mines[i + 1][j - 1] != '*')
						answer[i + 1][j - 1] += 1;

					// �U++
					if (i + 1 <= n - 1 && mines[i + 1][j] != '*')
						answer[i + 1][j] += 1;

					// �k�U++
					if (i + 1 <= n - 1 && j + 1 <= m - 1 && mines[i + 1][j + 1] != '*')
						answer[i + 1][j + 1] += 1;
				}
			}
		}
		if (caseCount > 1)
			cout << "\n";

		cout << "Field #" << caseCount << ":\n";

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << answer[i][j];
			}
			cout << "\n";
		}
	}
	return 0;
}