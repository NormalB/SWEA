#include <cstdio>

int N;
int dx[4] = {1, -1, -1, 1};
int dy[4] = {1, 1, -1, -1};
int start_i; int start_j;
int global_max;
int board[20][20];
FILE *fp;

void bfs(int i, int j, bool *cafes, int score, int last_dir, int dir_change) {
	int forbidden = 4;
	if(last_dir != 4)
		forbidden = (last_dir + 2) % 4;
	for (int p = 0; p < 4; p++) {
		if (p == forbidden) continue;
		if (i + dx[p] >= 0 && i + dx[p] < N && j + dy[p] >= 0 && j + dy[p] < N) {
			int next_cafe = board[i + dx[p]][j + dy[p]];
			// termination condition
			if (start_i == i + dx[p] && start_j == j + dy[p]) {
				if (global_max < score) global_max = score;
				return;
			} 
			// if the cafe is not visited
			else if (!cafes[next_cafe]) {
				// when new direction is same as before
				if (last_dir == p) {
					cafes[next_cafe] = true;
					bfs(i + dx[p], j + dy[p], cafes, score + 1, p, dir_change);
					cafes[next_cafe] = false;
				} 
				// taking new route
				// if dir changed less than 3 times, continue the search
				else if(dir_change < 4) {
					cafes[next_cafe] = true;
					bfs(i + dx[p], j + dy[p], cafes, score + 1, p, dir_change+1);
					cafes[next_cafe] = false;
				}
			}
		}
	}
}

void solve(void) {
	fscanf(fp, "%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			fscanf(fp, "%d", &board[i][j]);
		}
	}
	bool cafes[101];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			start_i = i;
			start_j = j;
			cafes[board[i][j]] = true;
			bfs(i, j, cafes, 1, 4, 0);
			cafes[board[i][j]] = false;
		}
	}
	/*
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &board[i][j]);
		}
	}
	bool cafes[101];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			start_i = i;
			start_j = j;
			cafes[board[i][j]] = true;
			bfs(i, j, cafes, 1, 4, 0);
			cafes[board[i][j]] = false;
		}
	}
	*/
}

int main(void) {
	int T;
	fp = fopen("c:/users/bjg01/desktop/test.txt", "r");
	fscanf(fp, "%d", &T);
	for (int t = 0; t < T; t++) {
		global_max = -1;
		solve();
		printf("#%d %d\n", t + 1, global_max);
	}
	/*
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		global_max = -1;
		solve();
		printf("#%d %d\n", t + 1, global_max);
	}
	*/
}