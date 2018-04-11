#include <cstdio>
#include <cstring>
#include <math.h>

int T;
int N;
int answer;
int balls[10];
int value_sum;
bool visited[10];

int fact(int num) {
	int sum = 1;
	for (int i = 1; i <= num; i++) {
		sum *= i;
	}
	return sum;
}

void bfs(int n, int r, int l) {
	if (r > l) return;
	else if (n == N) {
		answer += 1;
		return;
	}
	else if (l >= value_sum - l) {
		int res = N - n;
		answer += fact(res) * (int)pow(2, res);
		return;
	}
	for (int i = 0; i < N; i++) {
		if (visited[i]) continue;
		//put first ball left
		visited[i] = true;
		bfs(n + 1, r, l + balls[i]);
		//put first ball right
		bfs(n + 1, r + balls[i], l);
		visited[i] = false;
	}
}

int main(void) {
	FILE *fp = fopen("c:/users/bjg01/desktop/test.txt", "r");
	fscanf(fp, "%d", &T);
	for (int t = 1; t <= T; t++) {
		fscanf(fp, "%d", &N);
		//init variables
		answer = 0;
		value_sum = 0;
		for(int i=0; i<N; i++)
			fscanf(fp, "%d", &balls[i]);
		for (int i = 0; i < N; i++)
			value_sum += balls[i];
		bfs(0, 0, 0);
		printf("#%d %d\n", t, answer);
	}
}