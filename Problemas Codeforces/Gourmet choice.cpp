#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef pair<ii, ll> iii;
typedef vector<ii> vii;
typedef vector<pair<ii, ll>> viii;

#define FOR(i, a, b) for(ll i=ll(a); i<ll(b); i++)
#define ROF(i, a, b) for(ll i=ll(a); i>=ll(b); i--)
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define ifile(a) freopen((a), "r", stdin)
#define ofile(a) freopen((a), "w", stdout)
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); ////cout.tie(NULL)
#define PI 3.1415926535897932384626433832795
#define mem(x, val) memset((x), (val), sizeof(x))
#define sz(x) (ll)(x).size()
#define endl '\n'
#define clockon ll t = 1; while (t--) { clock_t z = clock();
#define clockoff debug("Elapsed Time: %.3f\n", (double)(clock() - z) / CLOCKS_PER_SEC); }
#define oo 2000000000000000000LL
#define EPS 1e-6
#define MOD 1000000007
#define etr "\n"
#define INF 10E10


struct DisjointSet{
	DisjointSet(ll n){
		size = n;
		fill(nodes, nodes+n, -1);
	}

	ll find(ll node){
		if(nodes[node] < 0) return node;
		nodes[node] = find(nodes[node]);
		return nodes[node];
	}
	
	bool merge(ll node1, ll node2){
		ll p1 = find(node1);
		ll p2 = find(node2);

		if(p1 == p2) return false;

		ll r1 = nodes[p1];
		ll r2 = nodes[p2];

		//r1 tiene mejor rango
		if(r1 <= r2){
			nodes[p1] += nodes[p2];
			nodes[p2] = p1;
		}
		else{
			nodes[p2] += nodes[p1];
			nodes[p1] = p2;
		}

		return true;
	}
	ll size;
	ll nodes[2050];
};

struct Node{
	unordered_set<ll> neig;
	ll value;
	Node(){
		value = -1;
	}
};

ll n, m;

string matr[1005];
Node graph[2010];
DisjointSet ds(2010);

void merge(ll i, ll j){
	Node &iN = graph[i];
	Node &jN = graph[j];
	for(auto it = jN.neig.begin(); it != jN.neig.end(); it++)
		iN.neig.insert(*it);
}

bool recStack[2010];
bool visited[2010];

bool checkCycle(ll curr){
	visited[curr] = true;
	recStack[curr] = true;
	Node &act = graph[curr];

	ll next;
	for(auto it = act.neig.begin(); it != act.neig.end(); it++){
		next = ds.find(*it);
		if(visited[next]){
			if(recStack[next]) return false;
			else continue;
		}
		else if(!checkCycle(next)) return false;
	}

	recStack[curr] = false;
	return true;
}

bool buildGraphAndCheckValidity(){
	FOR(i, 0, n){
		FOR(j, 0, m){
			if(matr[i][j] == '='){
				ds.merge(i, n+j);
			}
			else if(matr[i][j] == '>'){
				graph[n+j].neig.insert(i);
			}
			else{
				graph[i].neig.insert(n+j);
			}
		}
	}

	//we merge all to the parent in the ds
	FOR(i, 0, n+m){
		if(ds.find(i) == i) continue;
		merge(ds.find(i), i);
	}
	//determine if there's a cycle
	FOR(i, 0, n+m){
		if(!visited[ds.find(i)] && !checkCycle(ds.find(i))) return false;
	}
	FOR(i, 0, n+m) visited[i] = false;
	return true;
}

stack<ll> order;
void topologicalSortRec(ll curr){
	visited[curr] = true;
	Node &act = graph[curr];

	ll next;
	for(auto it = act.neig.begin(); it != act.neig.end(); it++){
		next = ds.find(*it);
		if(visited[next]) continue;
		topologicalSortRec(next);
	}
	order.push(curr);
}

void expand(ll curr){
	Node &act = graph[curr];
	if(act.value == -1) act.value = 1;
	ll nextVal = act.value + 1;

	ll next;
	for(auto it = act.neig.begin(); it != act.neig.end(); it ++){
		next = ds.find(*it);
		if(nextVal > graph[next].value) graph[next].value = nextVal;
	}
}

void topologicalSort(){
	FOR(i, 0, n+m){
		if(!visited[ds.find(i)]) topologicalSortRec(ds.find(i));
	}
	FOR(i, 0, n+m) visited[i] = false;

	while(!order.empty()){
		ll curr = order.top(); order.pop();
		expand(curr);
	}
}

string s;
int main(){
	sync;
	cin >> n >> m;
	FOR(i, 0, n){
		cin >> matr[i];
	}

	//cout << "xd1" << etr;
	if(!buildGraphAndCheckValidity()){
		cout << "No" << etr;
		return 0;
	}
	cout << "Yes" << etr;

	
	topologicalSort();

	FOR(i, 0, n){
		cout << graph[ds.find(i)].value << " ";
	}
	cout << etr;
	FOR(i, 0, m){
		cout << graph[ds.find(n+i)].value << " ";
	}
	
	cout << etr;
	return 0;
}