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
#define INF 1E15

ll n, m;
unordered_map<ll, ll> dp;

ll getRes(ll l, ll r){
	if(r-l + 1 < 0) return 0;
	if(r-l + 1 == m) return 2;
	if(r-l + 1 < m) return 1;
	if(dp.count(r-l)) return dp[r-l];

	ll mid = l+(r-l)/2;
	ll subRes = (getRes(l, mid) * getRes(mid + 1, r)) % MOD;
	FOR(i, 1, m)
		subRes = (subRes + (getRes(l, mid-i) * getRes(mid+(m-i)+1, r)) % MOD) % MOD;	
	
	return dp[r-l] = subRes;
}

int main(){
	sync;
	cin >> n >> m;
	cout << getRes(0, n-1);
	return 0;
}