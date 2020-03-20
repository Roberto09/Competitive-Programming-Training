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

ll n;

vi t[200050];
ll szs[200050];
ll wghts[200050];

ll res = -INF;

ll calcRes(ll nd, ll prnt){
	ll a = -INF, b = -INF;
	FOR(i, 0, t[nd].size()){
		if(t[nd][i] == prnt) continue;
		ll o = calcRes(t[nd][i], nd);
		if(o > a){
			b = a;
			a = o;
		}
		else if(o > b) b = o;
	}
	if(t[nd].size() > 1){
		if(a != -INF && b != -INF)
			res = max(res, a + b);
	}
	return max(wghts[nd], max(a, b));
}

ll calc(ll nd, ll prnt){
	wghts[nd] = szs[nd];
	FOR(i, 0, t[nd].size()){
		if(t[nd][i] == prnt) continue;
		wghts[nd] += calc(t[nd][i], nd);
	}
	return wghts[nd];
}

int main(){
	sync;
	cin >> n;
	FOR(i, 0, n){
		cin >> szs[i];
	}

	ll a, b;
	FOR(i, 0, n-1){
		cin >> a >> b;
		a --; b--;
		t[a].pb(b);
		t[b].pb(a);
	}

	calc(0, -1);
	calcRes(0, -1);
	if(res == -INF) cout << "Impossible" << etr;
	else cout << res << etr;
	return 0;
}
