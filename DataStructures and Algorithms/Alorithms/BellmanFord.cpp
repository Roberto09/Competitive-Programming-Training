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
#define INF 10E9

bool bellmanFord(vii &edges, vii &minDist, vector<unordered_map<ll, ll>> &weights, ll v, vii &res){
	//for v-1 times ...
	res[0].first = 0; res[0].second = 0;
	FOR(i, 1, v) res[i].first = INF;

	FOR(i, 0, v-1){
		FOR(j, 0, edges.size()){
			ll from = edges[j].first, where = edges[j].second;
			if(res[from].first + weights[from][where] < res[where].first){
				res[where].first = res[from].first + weights[from][where];
				res[where].second = from;
			}
		}
	}

	//encontramos un ciclo negativo
	FOR(j, 0, edges.size()){
		ll from = edges[j].first, where = edges[j].second;
		if(res[from].first + weights[from][where] < res[where].first){
			return false;
		}
	}

	return true;
}

void printPaths(vii &res, ll n){
	FOR(i, 0, n){
		cout << "El mejor path de 0 a: " << i << " con una distancia recorrida de: " << res[i].first << " es:" << etr;
		stack<ll> currVertices;
		ll curr = i;
		while(curr != 0){
			currVertices.push(curr);
			curr = res[curr].second;
		}
		cout << 0;
		while(!currVertices.empty()){
			cout << " -> " << currVertices.top();
			currVertices.pop();
		}
		cout << etr;
	}
}


int main(){
	ll n, e;
	cin >> n >> e;
	
	vii edges(n);
	vii minDist(n);
	vector<unordered_map<ll, ll>> weights(n);

	ll from, where, w;
	//directed graph
	FOR(i, 0, e){
		cin >> from >> where >> w;
		edges.pb(mp(from, where));
		weights[from][where] = w;
	}

	vii res(n);
	if(bellmanFord(edges, minDist, weights, n, res)){
		printPaths(res, n);
	}
	else{
		cout << "Encontramos un ciclo" << etr;
	}

	return 0;
}

/*
5 7
0 3 8
1 2 -3
3 4 2
2 4 4
0 1 4
4 3 1
0 2 5
*/