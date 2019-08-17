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
#define INF 10E10

vector<vii> graph;
ll n, m, k;
vi sizes;

ll fastPow(ll a, ll b){
    ll ret = 1;
    while(b > 0){
        if(b&1) ret = (ret*a) % MOD;
        a = (a*a) % MOD;
        b >>= 1;
    }
    return ret;
}

void fillSizes(ll curr, ll prev, ll prnt){
	sizes[prnt] ++;
	FOR(i, 0, graph[curr].size()){
		if(graph[curr][i].second == prev) continue;
		if(graph[curr][i].first == 0) fillSizes(graph[curr][i].second, curr, prnt);
		else fillSizes(graph[curr][i].second, curr, graph[curr][i].second);
	}
}

ll getSubstractions(){
	ll subs = 0;
	sizes = vi(n);
	FOR(i, 0, n) sizes[i] = 0;

	fillSizes(0, -1, 0);

	FOR(i, 0, n){
		subs = (subs + fastPow(sizes[i], k)) % MOD;
	}
	return subs;
}


ll calculate(){
	ll res = fastPow(n, k);
	//precalculate res and then substract
	return res - getSubstractions();
}

int main(){
	cin >> n >> k;

	ll a, b, c;
	FOR(i, 0, n-1){
		cin >> a >> b >> c;
		a --; b --;
		graph[a].pb(mp(c, b));
		graph[b].pb(mp(c, a));
	}

	cout << calculate() << etr;

	return 0;
}