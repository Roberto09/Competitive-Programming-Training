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
#define INF 1E18

ll n;
vii arr;
unordered_map<ll, unordered_set<ll>> app;
map<ii, ll, greater<ii>> prs;
bool used[1005];

int main(){
	sync;
	cin >> n;
	ll a, b;
	FOR(i, 0, n-1){
		cin >> a >> b;
		prs[mp(min(a, b), max(a, b))] ++;
		app[a].insert(b);
		app[b].insert(a);
		used[a] = used[b] = true;
	}

	priority_queue<ll> unused;
	FOR(i, 1, n+1) if(!used[i]) unused.push(i);

	for(auto it = app.begin(); it != app.end(); it++){
		if(it->second.size() <= 1) continue;
		for(auto it2 = it->second.begin(); it2 != it->second.end(); it2 ++){
			if(*it2 >= it->first) {cout << "NO" << etr; return 0;}
		}
	}

	vii res;
	//we might can
	for(auto it = prs.begin(); it != prs.end(); it++){
		ii pr = it->first;
		ll val = it->second;
		ll cr = pr.first;
		FOR(i, 0, val-1){
			if(unused.empty()) {cout << "NO" << etr; return 0;}
			ll op = unused.top(); unused.pop();
			if(op > pr.first) {cout << "NO" << etr; return 0;}
			res.pb(mp(cr, op));
			cr = op;
		}
		res.pb(mp(cr, pr.second));
	}

	while(!unused.empty()){
		res.pb(mp(unused.top(), n));
		unused.pop();
	}

	cout << "YES" << etr;

	for(ii pr : res) cout << pr.first << " " << pr.second << etr;

	return 0;
}