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

			unsigned int temp = m; // 因為要跟vector.size()做比較，所以用unsigned
			nums.erase(nums.begin()); // 每次都從第1個開始刪

			while (nums.size() != 1) {

				// 當temp超過vetor的size，就要一直扣掉它
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