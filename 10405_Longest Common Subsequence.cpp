#include <iostream>
#include <string> // getline

using namespace std;

string str1, str2;
int lcs[1001][1001];

int main()
{
	while (getline(cin, str1) && getline(cin, str2)) {

		// ��l��
		for (int i = 0; i <= str1.length(); i++)
			lcs[i][0] = 0;
		for (int j = 0; j <= str2.length(); j++)
			lcs[0][j] = 0;

		for (int i = 1; i <= str1.length(); i++) {
			for (int j = 1; j <= str2.length(); j++) {

				if (str1[i - 1] == str2[j - 1]) // �Y�@�ˡA�h���ץ[1
					lcs[i][j] = lcs[i - 1][j - 1] + 1;
				else // �Y���@�ˡA�ݥ���ΤW�����Ӹ��j
					lcs[i][j] = lcs[i - 1][j] > lcs[i][j - 1] ? lcs[i - 1][j] : lcs[i][j - 1];
			}
		}
		cout << lcs[str1.length()][str2.length()] << "\n";
	}
	return 0;
}