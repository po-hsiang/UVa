#include <iostream>
#include <vector>

using namespace std;

int N;

int main()
{
	while (cin >> N && N != 0) {

		if (N == 13) {
			cout << "1\n";
			continue;
		}

		vector<int> nums;
		for (int m = 2; ; m++) {
			nums.clear();

			for (int i = 1; i <= N; i++)
				nums.push_back(i);

			unsigned int temp = m; // �]���n��vector.size()������A�ҥH��unsigned
			nums.erase(nums.begin()); // �C�����q��1�Ӷ}�l�R

			while (nums.size() != 1) {

				// ��temp�W�Lvetor��size�A�N�n�@��������
				while (temp > nums.size())
					temp = temp - nums.size();

				nums.erase(nums.begin() + temp - 1);
				temp = temp + m - 1;
			}
			if (nums.front() == 13) {
				cout << m << '\n';
				break;
			}
		}
	}
	return 0;
}