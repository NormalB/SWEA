#include <cstdio>
#include <list>

int board[100][100];
int N;
int answer;

void check() {
	for (int j = 0; j < N; j++) {
		bool val = false;
		for (int i = 0; i < N; i++) {
			if (val){
				if (board[i][j] == 2) {
					answer++;
					val = 0;
				}
			}
			else {
				if (board[i][j] == 1) 
					val = 1;
			}			
		}
	}
}

int main(void) {
	/*
	FILE *fp = fopen("c:/users/bjg01/desktop/test.txt", "r");
	for(int t=1; t<=10; t++){
	//init variable
	answer = 0;
	fscanf(fp, "%d", &N);
	for (int i = 0; i < N; i++)
	for (int j = 0; j < N; j++)
	fscanf(fp, "%d", &board[i][j]);
	check();
	printf("#%d %d\n", t, answer);
	}
	*/
	for (int t = 1; t <= 10; t++) {
		//init variable
		answer = 0;
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				scanf("%d", &board[i][j]);
		check();
		printf("#%d %d\n", t, answer);
	}
}