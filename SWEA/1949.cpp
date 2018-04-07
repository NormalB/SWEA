#include <cstdio>
#include <queue>

int T, N, K;
int board[8][8];
int answer;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
std::queue<std::pair<int, int>> q;

void bfs(int i, int j, int len, bool constructable, int came_from) {
	//keep from searching previous location
	int forbidden = 4;
	if(came_from != -1)
		forbidden = (came_from + 2) % 4;
	bool continuable = false;
	//look around
	for (int p = 0; p < 4; p++) {
		if (p == forbidden) continue;
		if (i + dx[p] >= 0 && i + dx[p] < N && j + dy[p] >= 0 && j + dy[p] < N) {
			//if downhill
			if (board[i][j] > board[i + dx[p]][j + dy[p]]){
				continuable = true;
				bfs(i + dx[p], j + dy[p], len + 1, constructable, p);
			}
			//else if constructable
			else if (constructable && board[i + dx[p]][j + dy[p]] - board[i][j] < K) {
				//do the construction
				int temp = board[i + dx[p]][j + dy[p]];
				continuable = true;
				board[i + dx[p]][j + dy[p]] = board[i][j] - 1;
				bfs(i + dx[p], j + dy[p], len + 1, false, p);
				//undo the change
				board[i + dx[p]][j + dy[p]] = temp;
			}
		}
	}
	// at deadend, update the answer
	if (!continuable && answer < len)
		answer = len;
}

void solve(void) {
	//get highest places' loc
	while(!q.empty()){
		int start_i = q.front().first;
		int start_j = q.front().second;
		q.pop();
		bfs(start_i, start_j, 1, true, -1);
	}
}

int main(void) {
	/*
	FILE *fp = fopen("c:/users/bjg01/desktop/test.txt", "r");
	fscanf(fp, "%d", &T);
	for (int t = 1; t <= T; t++) {
		//init variables
		answer = 0;
		//find highest places
		fscanf(fp, "%d%d", &N, &K);
		int highest = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++){
				fscanf(fp, "%d", &board[i][j]);
				if (highest < board[i][j])
					highest = board[i][j];
			}
		//insert highest places
		for(int i=0; i<N; i++)
			for (int j = 0; j < N; j++) {
				if (board[i][j] == highest)
					q.push(std::make_pair(i, j));
			}
		//solve
		solve();
		printf("#%d %d\n", t, answer);
	}
	*/
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		//init variables
		answer = 0;
		//find highest places
		scanf("%d%d", &N, &K);
		int highest = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++) {
				scanf("%d", &board[i][j]);
				if (highest < board[i][j])
					highest = board[i][j];
			}
		//insert highest places
		for (int i = 0; i<N; i++)
			for (int j = 0; j < N; j++) {
				if (board[i][j] == highest)
					q.push(std::make_pair(i, j));
			}
		//solve
		solve();
		printf("#%d %d\n", t, answer);
	}
}