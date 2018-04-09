#include <cstdio>
#include <cstring>

int T;
int N;
int map[300][300];
int dx[8] = { 1, 1, 0, -1, -1, -1, 0, 1};
int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
bool visited[300][300];
int answer = 0;

void init_map(int n, int m) {
	int count = 0;
	for (int i = 0; i < 8; i++) {
		if (n + dx[i] >= 0 && n + dx[i] < N && m + dy[i] >= 0 && m + dy[i] < N) {
			if (map[n + dx[i]][m + dy[i]] == 9)
				count++;
		}
	}
	map[n][m] = count;
}

void bfs(int n, int m) {
	//already visited
	if (visited[n][m]) return;
	//set visited
	visited[n][m] = true;
	//if value of the place is not zero, stop searching
	if (map[n][m]) return;
	for (int i = 0; i < 8; i++)
		if (n + dx[i] >= 0 && n + dx[i] < N && m + dy[i] >= 0 && m + dy[i] < N) {
			bfs(n + dx[i], m + dy[i]);
		}
}

int main(void) {
	/*
	FILE *fp = fopen("c:/users/bjg01/desktop/test.txt", "r");
	fscanf(fp, "%d", &T);
	for (int t = 1; t <= T; t++) {
		//init variables
		memset(visited, 0, sizeof(visited));
		memset(map, 0, sizeof(map));
		answer = 0;
		//get input values
		fscanf(fp, "%d", &N);
		for (int i = 0; i < N; i++) {
			char string[301];
			fscanf(fp, "%s", &string);
			for (int j = 0; j < N; j++) {
				char temp = string[j];
				if (temp == '*'){
					map[i][j] = 9;
					visited[i][j] = true;
				}
			}
		}
		//init map
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				if(!visited[i][j])
					init_map(i, j);
		//start search
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				if(!map[i][j] && !visited[i][j]){
					bfs(i, j);
					answer++;
				}
		//count unvisited
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				if (!visited[i][j])
					answer++;
		printf("#%d %d\n", t, answer);
	}
	*/
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		//init variables
		memset(visited, 0, sizeof(visited));
		memset(map, 0, sizeof(map));
		answer = 0;
		//get input values
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			char string[301];
			scanf("%s", &string);
			for (int j = 0; j < N; j++) {
				char temp = string[j];
				if (temp == '*') {
					map[i][j] = 9;
					visited[i][j] = true;
				}
			}
		}
		//init map
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				if (!visited[i][j])
					init_map(i, j);
		//start search
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				if (!map[i][j] && !visited[i][j]) {
					bfs(i, j);
					answer++;
				}
		//count unvisited
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				if (!visited[i][j])
					answer++;
		printf("#%d %d\n", t, answer);
	}
}