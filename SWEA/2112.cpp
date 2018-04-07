#include <cstdio>
#include <cstring>

int board[13][20];
int copy_board[13][20];
int zeros[20];
int ones[20];
bool visited[26];
int T, D, W, K;
int global_min;
bool stop;

void check(int m) {
	//if K is 1, all pass
	if (K == 1){
		global_min = m;
		stop = true;
		return;
	}
	//make copy_board
	memcpy(*copy_board, *board, 13*20*sizeof(int));
	//make change to the board
	for (int p = 0; p < D; p++) {
		if (visited[p])
			memcpy(*(copy_board+p), zeros, 20*sizeof(int));
	}
	for (int p = 13; p < D + 13; p++) {
		if (visited[p])
			memcpy(*(copy_board + (p-13)), ones, 20*sizeof(int));
	}
	//check pass or fail
	bool pass = true;
	for (int j = 0; j < W; j++) {
		int max_streak = 0;
		int streak = 1;
		for (int i = 1; i < D; i++) {
			if (copy_board[i][j] == copy_board[i - 1][j]) {
				streak++;
				if (max_streak < streak) max_streak = streak;
			}
			else {
				streak = 1;
			}
		}
		if (max_streak < K) {
			pass = false;
			break;
		}
	}
	if (pass) {
		global_min = m;
		stop = true;
	}
}

void comb(int n, int m, int selected, int now) {
	if (selected == m) {
		check(m);
		return;
	}
	for (int i = now+1; i < n && !stop; i++) {
		visited[i] = true;
		comb(n, m, selected + 1, i);
		visited[i] = false;
	}
}

int main(void) {
	/*
	//init ones
	for (int i = 0; i < 20; i++)
	ones[i] = 1;
	scanf("%d", &T);
	for (int test = 1; test <= T; test++) {
		scanf("%d%d%d", &D, &W, &K);
		for (int i = 0; i < D; i++) {
			for (int j = 0; j < W; j++) {
				scanf("%d", &board[i][j]);
			}
		}
		stop = false;
		for (int i = 0; i <= 26 && !stop; i++) {
			comb(26, i, 0, -1);
		}
		printf("#%d %d\n", test, global_min);
	}
	*/
	//init ones
	for (int i = 0; i < 20; i++)
		ones[i] = 1;
	FILE *fp = fopen("c:/users/bjg01/desktop/test.txt", "r");
	fscanf(fp, "%d", &T);
	for (int test = 1; test <= T; test++) {
		fscanf(fp, "%d%d%d", &D, &W, &K);
		for (int i = 0; i < D; i++) {
			for (int j = 0; j < W; j++) {
				fscanf(fp, "%d", &board[i][j]);
			}
		}
		stop = false;
		for (int i = 0; i <= 26 && !stop; i++) {
			comb(26, i, 0, -1);
		}
		printf("#%d %d\n", test, global_min);
	}
	fclose(fp);
}