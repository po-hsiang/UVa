#include <stdio.h>

long long count[30005] = { 1 };
int possible[11] = { 5,10,20,50,100,200,500,1000,2000,5000,10000 };
int dollar, cent;

int main()
{
	// �q�̤p���w���}�l���W��X�Ҧ��Ʀr���զX�i���
	for (int i = 0; i < 11; i++) {
		for (int j = possible[i]; j < 30001; j++) {
			count[j] += count[j - possible[i]];
		}
	}

	while (scanf("%d.%d", &dollar, &cent) != EOF) {

		if (!dollar && !cent)
			break;

		printf("%3d.%02d%17lld\n", dollar, cent, count[100 * dollar + cent]);
	}

	return 0;
}