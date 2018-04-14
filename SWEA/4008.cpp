#include <cstdio>
#include <cstring>

int T;
int N;
int global_min;
int global_max;
// num of +, -, *, /
int op_count[4];
int numarr[12];

void bfs(int iter, int val) {
	if (iter == N-1) {
		if (val > global_max)
			global_max = val;
		if (val < global_min)
			global_min = val;
		return;
	}
	//search with +
	if(op_count[0]){
		op_count[0]--;
		bfs(iter + 1, val + numarr[iter + 1]);
		op_count[0]++;
	}
	//search with -
	if (op_count[1]) {
		op_count[1]--;
		bfs(iter + 1, val - numarr[iter + 1]);
		op_count[1]++;
	}
	//search with *
	if (op_count[2]) {
		op_count[2]--;
		bfs(iter + 1, val * numarr[iter + 1]);
		op_count[2]++;
	}
	//search with /
	if (op_count[3]) {
		op_count[3]--;
		bfs(iter + 1, val / numarr[iter + 1]);
		op_count[3]++;
	}
}

int main(void) {
	/*
	FILE *fp = fopen("c:/users/bjg01/desktop/test.txt", "r");
	fscanf(fp, "%d", &T);
	for (int t = 1; t <= T; t++) {
		fscanf(fp, "%d", &N);
		for(int i=0; i<4; i++)
			fscanf(fp, "%d", &op_count[i]);
		for (int i = 0; i<N; i++)
			fscanf(fp, "%d", &numarr[i]);
		//init variables
		global_min = 100000001;
		global_max = -100000001;
		//start w 0 and first element of numarr
		bfs(0, numarr[0]);
		printf("#%d %d\n", t, global_max - global_min);
	}
	*/
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%d", &N);
		for (int i = 0; i<4; i++)
			scanf("%d", &op_count[i]);
		for (int i = 0; i<N; i++)
			scanf("%d", &numarr[i]);
		//init variables
		global_min = 100000001;
		global_max = -100000001;
		//start w 0 and first element of numarr
		bfs(0, numarr[0]);
		printf("#%d %d\n", t, global_max - global_min);
	}
}