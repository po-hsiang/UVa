#include <iostream>

#define BIT(i) (1LL << i)
#define OR(x, i) (x | BIT(i))
#define AND(x, i) (x & BIT(i))

using namespace std;

long long N, L, U, M, i;

int main()
{
	while (cin >> N >> L >> U) {
		M = 0; // �C����answer���n��l��
		for (i = 31; i >= 0; i--) { // �q����bit���C��bit�}�l����
			if (AND(N, i)) { // �p�G�{�b�ˬd���o��bit�O1����
				if (OR(M, i) <= L) // �ۦ��|�ӨҤl���
					M |= BIT(i);
			}
			else { // �p�G�{�b�ˬd���o��bit�O0����
				if (OR(M, i) <= U) // ��M���o��bit���Ӭ�1����n�A�u�nM���|�W�LU����
					M |= BIT(i);			
			}
		}
		cout << M << "\n";
	}
	return 0;
}