#include <cstdio>
#include <cstring>

int T;
int N;
int M;
int K;
int num_org[1000];
int dir_org[1000];
int n_org[1000];
int m_org[1000];
int map[100][100];
bool alive[1000];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int get_next_dir(int i) {
	switch (i) {
	case 0:
		return 1;
	case 1:
		return 0;
	case 2:
		return 3;
	case 3:
		return 2;
	}
}

int main(void) {
	/*
	FILE *fp = fopen("c:/users/bjg01/desktop/test.txt", "r");
	fscanf(fp, "%d", &T);
	for (int t = 1; t <= T; t++) {
		fscanf(fp, "%d%d%d", &N, &M, &K);
		//init variables
		for (int i = 0; i < K; i++)
			alive[i] = true;
		for (int i = 0; i < K; i++)
			for (int j = 0; j < K; j++)
				map[i][j] = 1001;
		for (int i = 0; i < K; i++) {
			int n;
			int m;
			int no;
			int doo;
			fscanf(fp, "%d%d%d%d", &n, &m, &no, &doo);
			map[n][m] = i;
			n_org[i] = n;
			m_org[i] = m;
			num_org[i] = no;
			dir_org[i] = doo-1;
		}
		for (int m = 0; m < M; m++) {
			for (int k = 0; k < K; k++) {
				//check alive
				if (!alive[k]) continue;
				//move org
				int on = n_org[k];
				int om = m_org[k];
				//unmark the map
				map[n_org[k]][m_org[k]] = 1001;
				//not in the danzer zone
				if (on + dy[dir_org[k]] > 0 && on + dy[dir_org[k]] < N-1 && om + dx[dir_org[k]] > 0 && om + dx[dir_org[k]] < N-1) {
					n_org[k] += dy[dir_org[k]];
					m_org[k] += dx[dir_org[k]];
				}
				// org gets to the danger zone
				else {
					//if num_org is 1
					if (num_org[k] == 1) {
						alive[k] = false;
						continue;
					}
					//else
					else{
						n_org[k] += dy[dir_org[k]];
						m_org[k] += dx[dir_org[k]];
						//change num and dir
						num_org[k] /= 2;
						dir_org[k] = get_next_dir(dir_org[k]);
					}
				}
			}
			//set map
			for (int k = 0; k < K; k++) {
				if (!alive[k]) continue;
				int on = n_org[k];
				int om = m_org[k];
				if(map[on][om] == 1001)
					map[on][om] = k;
				else {
					//collision
					//find most num value & idx
					int most_num_idx = k;
					int most_num = num_org[k];
					for (int kk = 0; kk < K; kk++) {
						if (!alive[kk]) continue;
						else if (on == n_org[kk] && om == m_org[kk]) {
							if (most_num < num_org[kk]) {
								most_num = num_org[kk];
								most_num_idx = kk;
							}
						}
					}
					//merge orgs
					for (int kk = 0; kk < K; kk++) {
						if (!alive[kk]) continue;
						else if (kk == most_num_idx) continue;
						else if (on == n_org[kk] && om == m_org[kk]) {
							//kill org
							alive[kk] = false;
							//merge num
							num_org[most_num_idx] += num_org[kk];
						}
					}
					map[on][om] = most_num_idx;
				}
			}
		}
		int sum = 0;
		for (int k = 0; k < K; k++)
			if (alive[k])
				sum += num_org[k];
		printf("#%d %d\n", t, sum);
		*/
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%d%d%d", &N, &M, &K);
		//init variables
		for (int i = 0; i < K; i++)
			alive[i] = true;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				map[i][j] = 1001;
		for (int i = 0; i < K; i++) {
			int n;
			int m;
			int no;
			int doo;
			scanf("%d%d%d%d", &n, &m, &no, &doo);
			map[n][m] = i;
			n_org[i] = n;
			m_org[i] = m;
			num_org[i] = no;
			dir_org[i] = doo - 1;
		}
		for (int m = 0; m < M; m++) {
			for (int k = 0; k < K; k++) {
				//check alive
				if (!alive[k]) continue;
				//move org
				int on = n_org[k];
				int om = m_org[k];
				//unmark the map
				map[n_org[k]][m_org[k]] = 1001;
				//not in the danzer zone
				if (on + dy[dir_org[k]] > 0 && on + dy[dir_org[k]] < N - 1 && om + dx[dir_org[k]] > 0 && om + dx[dir_org[k]] < N - 1) {
					n_org[k] += dy[dir_org[k]];
					m_org[k] += dx[dir_org[k]];
				}
				// org gets to the danger zone
				else {
					//if num_org is 1
					if (num_org[k] == 1) {
						alive[k] = false;
						continue;
					}
					//else
					else {
						n_org[k] += dy[dir_org[k]];
						m_org[k] += dx[dir_org[k]];
						//change num and dir
						num_org[k] /= 2;
						dir_org[k] = get_next_dir(dir_org[k]);
					}
				}
			}
			//set map
			for (int k = 0; k < K; k++) {
				if (!alive[k]) continue;
				int on = n_org[k];
				int om = m_org[k];
				if (map[on][om] == 1001)
					map[on][om] = k;
				else {
					//collision
					//find most num value & idx
					int most_num_idx = k;
					int most_num = num_org[k];
					for (int kk = 0; kk < K; kk++) {
						if (!alive[kk]) continue;
						else if (on == n_org[kk] && om == m_org[kk]) {
							if (most_num < num_org[kk]) {
								most_num = num_org[kk];
								most_num_idx = kk;
							}
						}
					}
					//merge orgs
					for (int kk = 0; kk < K; kk++) {
						if (!alive[kk]) continue;
						else if (kk == most_num_idx) continue;
						else if (on == n_org[kk] && om == m_org[kk]) {
							//kill org
							alive[kk] = false;
							//merge num
							num_org[most_num_idx] += num_org[kk];
						}
					}
					map[on][om] = most_num_idx;
				}
			}
		}
		int sum = 0;
		for (int k = 0; k < K; k++)
			if (alive[k])
				sum += num_org[k];
		printf("#%d %d\n", t, sum);
	}
}