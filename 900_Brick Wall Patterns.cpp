#include <iostream>

using namespace std;

// �@�w�n��long long�A��int�|�W�X��ܽd��
long long answer[51];
long long input;

void Fabb() // �q�D���|�Ҥl�|�o�{�O�O���ƦC
{
	answer[1] = 1;
	answer[2] = 2;
	answer[3] = 3;

	for (int i = 4; i <= 50; i++)
		answer[i] = answer[i - 1] + answer[i - 2];
	
}

int main()
{
	Fabb();
	while (cin >> input && input != 0)
		cout << answer[input] << "\n";

	return 0;	
}