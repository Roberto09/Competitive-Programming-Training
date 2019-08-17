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
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); //cout.tie(NULL)
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
#define INF 1E9 + 1;

struct node{
	ll parent = 0;
	ll distance = 0;
	vi sons;
};

void bfs(vector<node> &graph, vector<bool> &visited, vi &order){
 	ll dist = 0, sons = 1;
	queue<ll> fila;
	fila.push(1);
	visited[1] = true;
	ll factor = 0;
	while(!fila.empty()){
		graph[fila.front()].distance = dist;
		if(dist > 2)
			order.pb(fila.front());
		sons --;
		FOR(i, 0, graph[fila.front()].sons.size()){
			if(!visited[graph[fila.front()].sons[i]]){
				visited[fila.front()] = true;
				fila.push(graph[fila.front()].sons[i]);
				graph[graph[fila.front()].sons[i]].parent = fila.front();
			}
		}

		if(sons == 0){
			dist ++;
			sons = fila.size()-1;
		}
		fila.pop();
	}
}

int main(){
	sync;
	ll v;
	cin >> v;
	vector<node> graph(v+1);
	vector<bool> visited(v+1, false);
	vi order;
	ll from, where;

	FOR(i, 0, v-1){
		cin >> from >> where;
		graph[from].sons.pb(where);
		graph[where].sons.pb(from);
	}

	bfs(graph, visited, order);

	ll ctr = 0;
	if(!order.empty()){
		ROF(ver, (order.size() - 1), 0){
			if(graph[order[ver]].distance > 2){
				node &f = graph[graph[order[ver]].parent];
				f.distance = 1;
				FOR(sp, 0, f.sons.size()){
					graph[f.sons[sp]].distance = 2;
				}
				ctr ++;
			}
		}
	}

	cout << ctr << etr;
	return 0;
}