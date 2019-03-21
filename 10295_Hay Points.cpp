#include <iostream>
#include <string>
#include <map>

using namespace std;

int m, n;
map<string, int> hay_points;
string word, test;
int dollar;
int main()
{
	cin >> m >> n;
	

	for (int i = 0; i < m; i++) {
		cin >> word >> dollar;
		hay_points[word] = dollar;
	}

	for (int i = 0; i < n; i++) {
		int answer = 0;
		while (cin >> test && test != ".") {
			if (hay_points[test] > 0)
				answer += hay_points[test];
		}
		cout << answer << "\n";
	}

	return 0;
}