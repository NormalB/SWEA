#include <cstdio>
#include <cstring>

typedef long long ll;

int T;
int N;
int P;
bool visited[100][100];
ll map[100][100];

ll bfs(int n, int iter) {
	if (n < iter) return 0;
	else if (visited[n][iter]) return map[n][iter];
	visited[n][iter] = true;
	ll max = 0;
	for (int i = 1; i < n; i++) {
		ll c = i*bfs(n - i, iter - 1);
		if (max < c)
			max = c;
	}
	map[n][iter] = max;
	return max;
}

int main(void) {
	/*
	FILE *fp = fopen("c:/users/bjg01/desktop/test.txt", "r");
	fscanf(fp, "%d", &T);
	for (int t = 1; t <= T; t++) {
		fscanf(fp, "%d%d", &N, &P);
		//init variables
		memset(visited, 0, sizeof(visited));
		memset(map, 0, sizeof(map));
		//init visited & map
		for (int i = 1; i < N; i++) {
			visited[i][1] = true;
			map[i][1] = i;
			visited[i][i] = true;
			map[i][i] = 1;
		}
		printf("#%d %lld\n", t, bfs(N, P));
	}
	*/
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%d%d", &N, &P);
		//init variables
		memset(visited, 0, sizeof(visited));
		memset(map, 0, sizeof(map));
		//init visited & map
		for (int i = 1; i < N; i++) {
			visited[i][1] = true;
			map[i][1] = i;
			visited[i][i] = true;
			map[i][i] = 1;
		}
		printf("#%d %lld\n", t, bfs(N, P));
	}
}