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
#define INF 1E10


struct node{
	vector<ll> neig;
	ll cost;
};

ll dfs(ll nde, vector<node> &nodes, vector<bool> &visited){
	visited[nde] = true;
	ll minCost = nodes[nde].cost;
	FOR(i, 0, nodes[nde].neig.size()){
		if(!visited[nodes[nde].neig[i]])
	
			minCost = min(dfs(nodes[nde].neig[i], nodes, visited), minCost);
	}
	return minCost;
}

int main(){
	sync;
	ll n, m;
	cin >> n >> m;
	vector<node> nodes(n+1);
	ll f, w;
	FOR(i, 1, n+1){
		cin >> nodes[i].cost;
	}
	FOR(i, 0, m){
		cin >> f >> w;
		nodes[f].neig.pb(w);
		nodes[w].neig.pb(f);
	}
	vector<bool> visited(n+1, false);
	ll sum = 0;
	FOR(i, 1, n+1){
		if (!visited[i]) sum += dfs(i, nodes, visited);
	}
	cout << sum << etr;
	return 0;
}