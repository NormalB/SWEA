#include <cstdio>
#include <map>

int T;
int init_num;
int times_change;
int length;
int global_max;
std::map<int, bool*> m;

void swap(char* arr, int i, int j) {
	char temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

int convert_to_int(char *arr) {
	int result = 0;
	for (int i = length - 1, j = 1; i >= 0; i--, j *= 10) {
		int char_val = arr[i] - '0';
		result += char_val*j;
	}
	return result;
}

void dfs(char* buf, int times_to_search, int number) {
	//if changed 10 times
	if (times_to_search == 0) {
		if (number > global_max)
			global_max = number;
		return;
	}
	//termination condition for backtracking
	else if(m.count(number) && m[number][times_to_search]){
		return;
	}
	else{
		//mark visited state
		if (!m.count(number)) {
			bool visited[11];
			visited[times_to_search] = true;
			m.insert(std::pair<int, bool*>(number, visited));
		}
		else {
			m[number][times_to_search] = true;
		}
		//keep searching
		for (int i = 0; i < length; i++) {
			for (int j = i + 1; j < length; j++) {
				swap(buf, i, j);
				int new_number = convert_to_int(buf);
				dfs(buf, times_to_search-1, new_number);
				swap(buf, i, j);
			}
		}
	}
}

int main(void) {
	/*
	FILE *fp = fopen("c:/users/bjg01/desktop/test.txt", "r");
	fscanf(fp, "%d", &T);
	for (int t = 1; t <= T; t++) {
		fscanf(fp, "%d%d", &init_num, &times_change);
		//init variables
		length = 0;
		global_max = 0;
		m.clear();
		char buf[7];
		sprintf(buf, "%d", init_num);
		while (buf[length] != '\0') {
			length++;
		}
		dfs(buf, times_change, init_num);
		printf("#%d %d\n", t, global_max);
	}
	*/
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%d%d", &init_num, &times_change);
		//init variables
		length = 0;
		global_max = 0;
		m.clear();
		char buf[7];
		sprintf(buf, "%d", init_num);
		while (buf[length] != '\0') {
			length++;
		}
		dfs(buf, times_change, init_num);
		printf("#%d %d\n", t, global_max);
	}
}