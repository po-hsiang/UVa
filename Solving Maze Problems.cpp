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

void DrawAnswerMaze(int x, int y) // 第2次BFS，透過距離來得知正確路徑，最後用來更改answer
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
				if (Distance[curr.x][curr.y] == 1) // 這邊要特別小心，因為預設的Distance都是0，所以可能會不小心把非起點的位置改成+
					return;
				answer[next.x][next.y] = '+';
				Q.push(next);
				break;
			}
		}
	}
}

int BFS(int x, int y) // 第1次BFS用來找出口，並記錄距離
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