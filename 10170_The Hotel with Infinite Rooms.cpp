#include <iostream>

using namespace std;

long long S, D;

int main()
{
	while (cin >> S >> D) {

		D -= S;
		while (D > 0) {
			S++;
			D = D - S;
		}
		cout << S << "\n";
	}
	return 0;
}