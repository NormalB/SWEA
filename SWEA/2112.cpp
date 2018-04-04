#include <cstdio>
#include <queue>

int board[13][20];
int copy_board[13][20];
int T, D, W, K;
int global_min;

class State {
public:
	int round;
	bool visited[26] = {false, };

	State(int r) {
		round = r;
	}

	State* copy() {
		State *ns = new State(round + 1);
		for (int i = 0; i < 26; i++)
			ns->visited[i] = visited[i];
		return ns;
	}
};

std::queue<State*> Q;

void clearQ(std::queue<State*> *someQueue)
{
	std::queue<State*> newQueue;
	std::swap(*someQueue, newQueue);
}

void bfs() {
	State *s = new State(0);
	Q.push(s);
	while (!Q.empty()) {
		State *ts = Q.front();
		/*
			printf("when round %d, visited: ", ts->round);
			for (int i = 0; i < 26; i++)
				printf("%d ", ts->visited[i]);
			printf("\n");
		*/
		Q.pop();
		//make copy board
		for (int i = 0; i < D; i++) {
			for (int j = 0; j < W; j++) {
				copy_board[i][j] = board[i][j];
			}
		}
		//make change to the board
		for (int p = 0; p < D; p++) {
			if (ts->visited[p]) {
				for (int j = 0; j < W; j++) {
					copy_board[p][j] = 0;
				}
			}
		}
		for (int p = 13; p < D + 13; p++) {
			if (ts->visited[p]) {
				for (int j = 0; j < W; j++) {
					copy_board[p-13][j] = 1;
				}
			}
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
		if (pass){
			global_min = ts->round;
			return;
		}
		//change row by row
		for (int i = 0; i < D; i++) {
			if (!ts->visited[i]) {
				State *ns = ts->copy();
				ns->visited[i] = true;
				Q.push(ns);
			}
		}
		for (int i = 13; i < D+13; i++) {
			if (!ts->visited[i]) {
				State *ns = ts->copy();
				ns->visited[i] = true;
				Q.push(ns);
			}
		}
		delete ts;
	}
}

int main(void) {
	/*
	scanf("%d", &T);
	for (int test = 1; test <= T; test++) {
		scanf("%d%d%d", &D, &W, &K);
		for (int i = 0; i < D; i++) {
			for (int j = 0; j < W; j++) {
				scanf("%d", &board[i][j]);
			}
		}
		bfs();
		printf("#%d %d\n", test, global_min);
		clearQ(Q);
	}
	*/
	FILE *fp = fopen("c:/users/bjg01/desktop/test.txt", "r");
	fscanf(fp, "%d", &T);
	for (int test = 1; test <= T; test++) {
		fscanf(fp, "%d%d%d", &D, &W, &K);
		for (int i = 0; i < D; i++) {
			for (int j = 0; j < W; j++) {
				fscanf(fp, "%d", &board[i][j]);
			}
		}
		bfs();
		printf("#%d %d\n", test, global_min);
		clearQ(&Q);
	}
	fclose(fp);
}