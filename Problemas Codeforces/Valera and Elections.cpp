#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef pair<ii, ll> iii;
typedef vector<vi> vvi;
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
#define INF 1E9 + 7

ll n;

struct node{
	vi neig;
	vector<bool> isBad;
};

bool findBest(vector<node> &graph, vi &result, ll nde, bool isBad, ll parent){
	node &curr = graph[nde];

	bool sonsPushed = false;
	ll check;
	FOR(i, 0, curr.neig.size()){
		check = curr.neig[i];
		if(check == parent) continue;
		if(findBest(graph, result, check, curr.isBad[i], nde)) sonsPushed = true;
	}
	if(isBad){
		if(!sonsPushed)
			result.pb(nde);
		return true;
	}
	return sonsPushed;
}

int main(){
	sync;
	cin >> n;
	vector<node> graph(n+1);
	ll a, b, x; 
	FOR(i, 0, n-1){
		cin >> a >> b >> x;
		graph[a].neig.pb(b);
		graph[b].neig.pb(a);
		graph[a].isBad.pb(x == 1 ? false : true);
		graph[b].isBad.pb(x == 1 ? false : true);
	}

	vector<ll> result;
	findBest(graph, result, 1, false, -1);
	cout << result.size() << etr;
	FOR(i, 0, result.size()){
		cout << result[i] << " ";
	}
	return 0;
}