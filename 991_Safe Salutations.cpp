#include <iostream>

using namespace std;

int main()
{
	int Salutatuoins[11] = { 1,1,2,5 };
	int input;

	// 決定好一組後，左邊的組合乘上右邊的組合
	for (int i = 4; i <= 10; i++) {	
		for (int j = 0; j < i; j++) {
			Salutatuoins[i] += Salutatuoins[j] * Salutatuoins[i - 1 - j];
		}
	}
	
	int t = 0;

	while (cin >> input) {

		// 這題的空行要求非常奇怪!
		if (t > 0)
			cout << "\n";
		cout << Salutatuoins[input] << "\n";
		t++;
		
	}
	return 0;
}