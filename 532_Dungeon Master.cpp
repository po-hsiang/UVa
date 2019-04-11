#include <iostream>
#include <queue>

using namespace std;

char dungeon[32][32][32];
int Distance[32][32][32];
int direction[6][3] = { {-1,0,0}, {1,0,0}, {0,-1,0}, {0,1,0}, {0,0,-1}, {0,0,1} };
int start_i, start_j, start_k;
int L, R, C;

struct Point {
	int x;
	int y;
	int z;
};

int BFS(int i, int j, int k)
{
	Point start, curr, next;
	start.x = i;
	start.y = j;
	start.z = k;
	queue<Point> qq;
	qq.push(start);
	Distance[start.x][start.y][start.z] = 0;
	dungeon[start.x][start.y][start.z] = '#';

	while (!qq.empty()) {
		curr = qq.front();
		qq.pop();
		
		for (int a = 0; a < 6; a++) {
			next.x = curr.x + direction[a][0];
			next.y = curr.y + direction[a][1];
			next.z = curr.z + direction[a][2];

			if (next.x < 0 || next.x >= L || next.y < 0 || next.y >= R || next.z < 0 || next.z >= C)
				continue; // 若超過迷宮的地圖範圍，則直接跳過這次

			if (dungeon[next.x][next.y][next.z] != '#') {
				Distance[next.x][next.y][next.z] = Distance[curr.x][curr.y][curr.z] + 1; // '.'或'E'都代表可以走，距離+1

				if (dungeon[next.x][next.y][next.z] == 'E') { // 找到出口
					return Distance[next.x][next.y][next.z];
				}
				else { // 不是出口，則將next放入queue，繼續找下一個點
					qq.push(next);
					dungeon[next.x][next.y][next.z] = '#';
				}
			}
		}
	}
	return -1;
}

int main()
{
	while (cin >> L >> R >> C) {

		if (!L && !R && !C)
			break;

		for (int i = 0; i < L; i++) {
			for (int j = 0; j < R; j++) {
				cin >> dungeon[i][j]; // 輸入迷宮地圖資訊

				for (int k = 0; k < C; k++) {
					if (dungeon[i][j][k] == 'S') { // 若找到迷宮的起點
						start_i = i;
						start_j = j;
						start_k = k;
					}
				}
			}
		}

		int minutes = BFS(start_i, start_j, start_k);

		if (minutes != -1)
			cout << "Escaped in " << minutes << " minute(s).\n";
		else
			cout << "Trapped!\n";
	}
	return 0;
}	