#include <iostream>

using namespace std;

int main()
{
	int Salutatuoins[11] = { 1,1,2,5 };
	int input;

	// �M�w�n�@�ի�A���䪺�զX���W�k�䪺�զX
	for (int i = 4; i <= 10; i++) {	
		for (int j = 0; j < i; j++) {
			Salutatuoins[i] += Salutatuoins[j] * Salutatuoins[i - 1 - j];
		}
	}
	
	int t = 0;

	while (cin >> input) {

		// �o�D���Ŧ�n�D�D�`�_��!
		if (t > 0)
			cout << "\n";
		cout << Salutatuoins[input] << "\n";
		t++;
		
	}
	return 0;
}