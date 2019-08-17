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
#define INF 1E9;
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cerr << name << " : " << arg1 << '\n';
}

ll result = 0;

struct node{
	//read
	ll gasCharge = 0;
	vi neig;
	vi cost;
};

ll dfs(vector<node> &graph, ll father, ll current){
	ll firstMax = 0;
	ll secondMax = 0;

	node &cNode = graph[current];
	FOR(i, 0, cNode.neig.size()){
		if(cNode.neig[i] == father) continue;
		ll bestSon = dfs(graph, current, cNode.neig[i]);
		bestSon -= cNode.cost[i];
		if(bestSon > firstMax){
			secondMax = firstMax;
			firstMax = bestSon;
		}
		else if(bestSon > secondMax) secondMax = bestSon;
	}
	result = max(result, firstMax + secondMax + cNode.gasCharge);
	return firstMax + cNode.gasCharge;
}



int main(){
	sync;
	ll n;
	cin >> n;

	vector<node> graph(n+1);
	vi bestCosts(n+1, 0);
	
	FOR(i, 1, n+1){
		cin >> graph[i].gasCharge;
	}

	ll from, where, cst;
	FOR(i, 1, n){
		cin >> from >> where >> cst;
		graph[from].neig.pb(where);
		graph[from].cost.pb(cst);
		graph[where].neig.pb(from);
		graph[where].cost.pb(cst);
	}

	dfs (graph, -1, 1);

	cout << result << etr;

	return 0;
}