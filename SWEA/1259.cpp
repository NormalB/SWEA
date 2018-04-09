#include <cstdio>
#include <utility>

int T;
int N;
int answer[40];
std::pair<int, int> parr[20];

bool isconnected(int now) {
	bool connected = true;
	for (int i = 1; i < now; i++) {
		if (parr[i - 1].second != parr[i].first){
			connected = false;
			break;
		}
	}
	return connected;
}

void updateAnswer() {
	for(int i=0, j=0; j<N; j++){
		answer[i++] = parr[j].first;
		answer[i++] = parr[j].second;
	}
}

void permutation(int N, int M, int now, std::pair<int, int> *p) {
	if (!isconnected(now)) {
		return;
	}
	else if (now == M) {
		updateAnswer();
		return;
	}
	for (int i = now; i < N; i++) {
		//swap variables
		std::pair<int, int> temp = p[i];
		p[i] = p[now];
		p[now] = temp;
		permutation(N, M, now + 1, p);
		//swap variables
		temp = p[i];
		p[i] = p[now];
		p[now] = temp;
	}
}

int main(void) {
	/*
	FILE *fp = fopen("c:/users/bjg01/desktop/test.txt", "r");
	fscanf(fp, "%d", &T);
	for (int t = 1; t <= T; t++) {
		fscanf(fp, "%d", &N);
		int x;
		int y;
		for(int i=0; i<N; i++){
			fscanf(fp, "%d%d", &x, &y);
			parr[i] = std::pair<int, int>(x, y);
		}
		permutation(N, N, 0, parr);
		printf("#%d ", t);
		for (int i = 0; i < 2 * N; i++)
			printf("%d ", answer[i]);
		printf("\n");
	}
	*/
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%d", &N);
		int x;
		int y;
		for (int i = 0; i<N; i++) {
			scanf("%d%d", &x, &y);
			parr[i] = std::pair<int, int>(x, y);
		}
		permutation(N, N, 0, parr);
		printf("#%d ", t);
		for (int i = 0; i < 2 * N; i++)
			printf("%d ", answer[i]);
		printf("\n");
	}
}