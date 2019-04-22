#include <iostream>

#define BIT(i) (1LL << i)
#define OR(x, i) (x | BIT(i))
#define AND(x, i) (x & BIT(i))

using namespace std;

long long N, L, U, M, i;

int main()
{
	while (cin >> N >> L >> U) {
		M = 0; // 每次的answer都要初始化
		for (i = 31; i >= 0; i--) { // 從高位bit往低位bit開始測試
			if (AND(N, i)) { // 如果現在檢查的這個bit是1的話
				if (OR(M, i) <= L) // 自行舉個例子比較
					M |= BIT(i);
			}
			else { // 如果現在檢查的這個bit是0的話
				if (OR(M, i) <= U) // 那M的這個bit應該為1比較好，只要M不會超過U的話
					M |= BIT(i);			
			}
		}
		cout << M << "\n";
	}
	return 0;
}