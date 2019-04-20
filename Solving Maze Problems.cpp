#include <iostream>
#include <queue>

using namespace std;

char maze[10][10];
char answer[10][10];
int Distance[10][10];
int directions[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
int start_x, start_y;

struct Point {
	int x;
	int y;
};

void DrawAnswerMaze(int x, int y) // ��2��BFS�A�z�L�Z���ӱo�����T���|�A�̫�Ψӧ��answer
{
	Point start, curr, next;
	start.x = x;
	start.y = y;
	queue<Point> Q;
	Q.push(start);
	answer[start.x][start.y] = '+';

	while (!Q.empty()) {
		curr = Q.front();
		Q.pop();

		for (int i = 0; i < 4; i++) {
			next.x = curr.x + directions[i][0];
			next.y = curr.y + directions[i][1];

			if (next.x < 0 || next.x >= 10 || next.y < 0 || next.y >= 10)
				continue;

			if (Distance[next.x][next.y] == Distance[curr.x][curr.y] - 1) {
				if (Distance[curr.x][curr.y] == 1) // �o��n�S�O�p�ߡA�]���w�]��Distance���O0�A�ҥH�i��|���p�ߧ�D�_�I����m�令+
					return;
				answer[next.x][next.y] = '+';
				Q.push(next);
				break;
			}
		}
	}
}

int BFS(int x, int y) // ��1��BFS�Ψӧ�X�f�A�ðO���Z��
{
	Point start, curr, next;
	start.x = x;
	start.y = y;
	queue<Point> Q;
	Q.push(start);
	maze[start.x][start.y] = '#';
	Distance[start.x][start.y] = 0;

	while (!Q.empty()) {
		curr = Q.front();
		Q.pop();

		for (int i = 0; i < 4; i++) {
			next.x = curr.x + directions[i][0];
			next.y = curr.y + directions[i][1];

			if (next.x < 0 || next.x >= 10 || next.y < 0 || next.y >= 10)
				continue;

			if (maze[next.x][next.y] != '#') {
				Distance[next.x][next.y] = Distance[curr.x][curr.y] + 1;

				if (maze[next.x][next.y] == 'G') {
					DrawAnswerMaze(next.x, next.y);
					return Distance[next.x][next.y];
				}
				else {
					Q.push(next);
					maze[next.x][next.y] = '#';
				}
			}
		}
	}
	return -1;
}

int main()
{
	for (int i = 0; i < 10; i++) {
		cin >> maze[i];
		for (int j = 0; j < 10; j++) {
			answer[i][j] = maze[i][j];
			if (maze[i][j] == 'S') {
				answer[i][j] = '+';
				start_x = i;
				start_y = j;
			}
		}
	}

	int minutes = BFS(start_x, start_y);

	if (minutes == -1)
		cout << "No solution\n";
	else {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				cout << answer[i][j];
			}
			cout << "\n";
		}
	}
	return 0;
}