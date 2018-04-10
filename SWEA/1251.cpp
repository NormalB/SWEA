//############################################################################################################################
//#############################################  Heap version  ###############################################################
//############################################################################################################################

/*
#include <cstdio>
#include <cstring>
#include <math.h>
#include <vector>

typedef long long ll;

class Edge {
public:
	int start;
	int end;
	ll cost;
	Edge(int s, int e, ll Cost) {
		start = s;
		end = e;
		cost = Cost;
	}
};

class minHeap {
public:
	int length;
	Edge *arr[1000000];
	void initialize() {
		for (int i = 1; i <= length; i++) {
			delete arr[i];
		}
		length = 0;
	}
	void push(Edge *ep) {
		arr[++length] = ep;
		int i = length;
		while (i > 1 && arr[i / 2]->cost > arr[i]->cost) {
			Edge *temp = arr[i];
			arr[i] = arr[i/2];
			arr[i/2] = temp;
			i /= 2;
		}
	}
	Edge* pop() {
		Edge *to_return = arr[1];
		arr[1] = arr[length--];
		int i = 1;
		while (2 * i <= length) {
			// has two children
			if (2 * i < length)
				if (arr[2 * i]->cost < arr[2 * i + 1]->cost) {
					if(arr[i]->cost > arr[2*i]->cost){
						Edge *temp = arr[i];
						arr[i] = arr[2*i];
						arr[2*i] = temp;
						i = 2*i;
					}
					else if (arr[i]->cost > arr[2 * i + 1]->cost) {
						Edge *temp = arr[i];
						arr[i] = arr[2 * i + 1];
						arr[2 * i + 1] = temp;
						i = 2 * i + 1;
					}
					else break;
				}
				else {
					if (arr[i]->cost > arr[2 * i + 1]->cost) {
						Edge *temp = arr[i];
						arr[i] = arr[2 * i + 1];
						arr[2 * i + 1] = temp;
						i = 2 * i + 1;
					}
					else if (arr[i]->cost > arr[2 * i]->cost) {
						Edge *temp = arr[i];
						arr[i] = arr[2 * i];
						arr[2 * i] = temp;
						i = 2 * i;
					}
					else break;
				}
			// only has one child
			else {
				if (arr[i]->cost > arr[2 * i]->cost) {
					Edge *temp = arr[i];
					arr[i] = arr[2 * i];
					arr[2 * i] = temp;
					i = 2 * i;
				}
				else break;
			}
		}
		return to_return;
	}
};

int N;
int T;
double E;
ll distance = 0;
bool visited[1000];
std::vector<std::vector<Edge*>> adj;
minHeap mh;

 ll getCost(ll x1, ll y1, ll x2, ll y2) {
	 return (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2);
}

 bool check_term() {
	 bool stop = true;
	 for (int i = 0; i < N; i++)
		 if (!visited[i]){
			 stop = false;
			 break;
		 }
	 return stop;
 }

int main(void) {

	FILE *fp = fopen("c:/users/bjg01/desktop/test.txt", "r");
	fscanf(fp, "%d", &T);
	for (int t = 1; t <= T; t++) {
		//init variables
		memset(visited, 0, sizeof(visited));
		distance = 0;
		adj.clear();
		mh.initialize();
		int x_arr[1000];
		int y_arr[1000];
		fscanf(fp, "%d", &N);
		for (int i = 0; i < N; i++)
			fscanf(fp, "%d", &x_arr[i]);
		for (int i = 0; i < N; i++)
			fscanf(fp, "%d", &y_arr[i]);
		fscanf(fp, "%lf", &E);
		//initialize adj
		for (int i = 0; i < N; i++) {
			std::vector<Edge*> nv;
			adj.push_back(nv);
		}
		for (int i = 0; i < N; i++) {
			for (int j = i+1; j < N; j++) {
				Edge *ne = new Edge(i, j, getCost(x_arr[i], y_arr[i], x_arr[j], y_arr[j]));
				Edge *ne2 = new Edge(i, j, getCost(x_arr[i], y_arr[i], x_arr[j], y_arr[j]));
				adj[i].push_back(ne);
				adj[j].push_back(ne2);
			}
		}
		mh.push(new Edge(0, 0, 0));
		while (!check_term()) {
			Edge * ep = mh.pop();
			//find newly visited node;
			int new_node = 0;
			if (visited[ep->start] && visited[ep->end]) {
				delete ep;
				continue;
			}
			else if (visited[ep->start]) new_node = ep->end;
			else  new_node = ep->start;
			//mark visited
			visited[new_node] = true;
			//update cost
			distance += ep->cost;			
			//put new edges in the heap
			for (int i = 0; i < adj[new_node].size(); i++) {
				mh.push(adj[new_node][i]);
			}
			delete ep;
		}
		printf("#%d %.0lf\n", t, distance*E);
	}
	
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		//init variables
		memset(visited, 0, sizeof(visited));
		distance = 0;
		adj.clear();
		mh.initialize();
		int x_arr[1000];
		int y_arr[1000];
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
			scanf("%d", &x_arr[i]);
		for (int i = 0; i < N; i++)
			scanf("%d", &y_arr[i]);
		scanf("%lf", &E);
		//initialize adj
		for (int i = 0; i < N; i++) {
			std::vector<Edge*> nv;
			adj.push_back(nv);
		}
		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				Edge *ne = new Edge(i, j, getCost(x_arr[i], y_arr[i], x_arr[j], y_arr[j]));
				Edge *ne2 = new Edge(i, j, getCost(x_arr[i], y_arr[i], x_arr[j], y_arr[j]));
				adj[i].push_back(ne);
				adj[j].push_back(ne2);
			}
		}
		mh.push(new Edge(0, 0, 0));
		while (!check_term()) {
			Edge * ep = mh.pop();
			//find newly visited node;
			int new_node = 0;
			if (visited[ep->start] && visited[ep->end]) {
				delete ep;
				continue;
			}
			else if (visited[ep->start]) new_node = ep->end;
			else  new_node = ep->start;
			//mark visited
			visited[new_node] = true;
			//update cost
			distance += ep->cost;
			//put new edges in the heap
			for (int i = 0; i < adj[new_node].size(); i++) {
				mh.push(adj[new_node][i]);
			}
			delete ep;
		}
		printf("#%d %.0lf\n", t, distance*E);
	}
	
}
*/

//############################################################################################################################
//#############################################  Quicksort version  ###############################################################
//############################################################################################################################


#include <cstdio>
#include <cstring>
#include <math.h>

typedef long long ll;

class Node {
public:
	int n;
	ll cost;
	Node(int N, ll Cost) {
		n = N;
		cost = Cost;
	}
};

int N;
int T;
double E;
Node *nh[1000];
ll distance = 0;

void quickSort(int first, int last, Node **arr) {
	if (first < last) {
		int pivot = first;
		int i = first;
		int j = last;
		while (i < j) {
			while (arr[pivot]->cost >= arr[i]->cost && i < last) {
				i++;
			}
			while (arr[pivot]->cost < arr[j]->cost) {
				j--;
			}
			if (i < j) {
				Node *temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
		Node *temp = arr[j];
		arr[j] = arr[pivot];
		arr[pivot] = temp;
		quickSort(first, j - 1, arr);
		quickSort(j + 1, last, arr);
	}
}

ll getCost(ll x1, ll y1, ll x2, ll y2) {
	return (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2);
}

int main(void) {
	
	FILE *fp = fopen("c:/users/bjg01/desktop/test.txt", "r");
	fscanf(fp, "%d", &T);
	for (int t = 1; t <= T; t++) {
	//init variables
	memset(nh, 0, sizeof(nh));
	distance = 0;
	int x_arr[1000];
	int y_arr[1000];
	fscanf(fp, "%d", &N);
	for (int i = 0; i < N; i++)
	fscanf(fp, "%d", &x_arr[i]);
	for (int i = 0; i < N; i++)
	fscanf(fp, "%d", &y_arr[i]);
	fscanf(fp, "%lf", &E);
	//initialize PQ
	for (int i = 1; i < N; i++) {
	nh[i - 1] = new Node(i, getCost(x_arr[0], y_arr[0], x_arr[i], y_arr[i]));
	}
	for (int c = 0; c < N-1; c++) {
	quickSort(c, N - 2, nh);
	Node * np = nh[c];
	distance += np->cost;
	//update cost
	for (int i = c + 1; i < N - 1; i++) {
	ll cost = nh[i]->cost;
	ll new_cost = getCost(x_arr[np->n], y_arr[np->n], x_arr[nh[i]->n], y_arr[nh[i]->n]);
	if (cost > new_cost)
	nh[i]->cost = new_cost;
	}
	delete np;
	}
	printf("#%d %.0lf\n", t, distance*E);
	}
	/*
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		//init variables
		memset(nh, 0, sizeof(nh));
		distance = 0;
		int x_arr[1000];
		int y_arr[1000];
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
			scanf("%d", &x_arr[i]);
		for (int i = 0; i < N; i++)
			scanf("%d", &y_arr[i]);
		scanf("%lf", &E);
		//initialize PQ
		for (int i = 1; i < N; i++) {
			nh[i - 1] = new Node(i, getCost(x_arr[0], y_arr[0], x_arr[i], y_arr[i]));
		}
		for (int c = 0; c < N - 1; c++) {
			quickSort(c, N - 2, nh);
			Node * np = nh[c];
			distance += np->cost;
			//update cost
			for (int i = c + 1; i < N - 1; i++) {
				ll cost = nh[i]->cost;
				ll new_cost = getCost(x_arr[np->n], y_arr[np->n], x_arr[nh[i]->n], y_arr[nh[i]->n]);
				if (cost > new_cost)
					nh[i]->cost = new_cost;
			}
			delete np;
		}
		printf("#%d %.0lf\n", t, distance*E);
	}
	*/
}
