#include <cstdio>
#include <cstring>

int T;
int buttons[10];
int result;
int dp[1000001];

int NM(int num) {
	char buf[8];
	sprintf(buf, "%d", num);
	int length = 0;
	while (buf[length] != '\0')
		length++;
	//for all char
	//if a char is in buttons
	//pass
	for (int i = 0; i < length; i++) {
		int idx = buf[i] - '0';
		if (!buttons[idx])
			return 0;
	}
	return length;
}

int M(int result) {
	// if computed before
	if (dp[result])
		return dp[result];
	// can be produced without multiplication
	else if (int nm = NM(result)) {
		dp[result] = nm;
		return dp[result];
	}
	// else
	int lastq = result;
	int min = 100;
	bool changed = false;
	for (int i = 2; i < lastq; i++) {
		if (!(result % i)) {
			int q = result / i;
			if (M(i) && M(q) && min > M(i) + M(q) + 1){
				min = M(i) + M(q) + 1;
				changed = true;
			}
			lastq = q;
		}
	}
	if (changed){
		dp[result] = min;
		return dp[result];
	}
	return 0;
}

int main(void) {
	/*
	FILE *fp = fopen("c:/users/bjg01/desktop/test.txt", "r");
	fscanf(fp, "%d", &T);
	for (int t = 1; t <= T; t++) {
		//init variables
		for (int i = 0; i < 10; i++)
			fscanf(fp, "%d", &buttons[i]);
		fscanf(fp, "%d", &result);
		memset(dp, 0, sizeof(int) * 1000001);
		//solve
		M(result);
		if(dp[result])
			printf("#%d %d\n", t, dp[result]+1);
		else
			printf("#%d -1\n", t);
	}
	*/
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		//init variables
		for (int i = 0; i < 10; i++)
			scanf("%d", &buttons[i]);
		scanf("%d", &result);
		memset(dp, 0, sizeof(int) * 1000001);
		//solve
		M(result);
		if (dp[result])
			printf("#%d %d\n", t, dp[result] + 1);
		else
			printf("#%d -1\n", t);
	}
}