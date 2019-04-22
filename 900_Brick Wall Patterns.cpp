#include <iostream>

using namespace std;

// 一定要用long long，用int會超出表示範圍
long long answer[51];
long long input;

void Fabb() // 從題目舉例子會發現是費式數列
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