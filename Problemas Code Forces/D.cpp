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
#define INF 1E9
#define MAX_N 2

ll n, k;

vi g[100050];
ll gp[100050];

priority_queue<ll> res;

ll calculate(ll n, ll p){
	ll res = 0;
	for(ll ng : g[n]){
		if(ng == p) continue;
		res = max(calculate(ng, n), res);
	}
	return gp[n] = res + 1;
}

void calc(ll n, ll p, bool isUsed){
	ii b, sb;
	b = sb = mp(0, 0);
	for(ll ng : g[n]){
		if(ng == p) continue;
		ll o = gp[ng];
		if(o > b.second){
			sb = b;
			b = mp(ng, o);
		}
		else if (o > sb.second){
			sb = mp(ng, o);
		}
	}
	if(isUsed){
		res.push(sb.second);
	}
	else{
		res.push(b.second + 1);
	}

	for(ll ng : g[n]){
		if(ng == p) continue;
		if(isUsed && (ng == b.first || ng == sb.first)) calc(ng, n, true);
		else if(!isUsed && ng == b.first) calc(ng, n, true);
		else calc(ng, n, false);
	}
}


int main(){
	ll a;
	cin >> n >> k;
	FOR(i, 1 , n){
		cin >> a;
		a--;
		g[i].pb(a);
		g[a].pb(i);
	}

	calculate(0, -1);
	calc(0, -1, false);

	ll fres = 0;
	FOR(i ,0, k){
		fres += res.top(); res.pop();
	}
	cout << fres << etr;

	return 0;
}