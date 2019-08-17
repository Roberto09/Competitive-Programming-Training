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
#define INF 1E17

ll dp[4005];
unordered_set<ll> options;

ll getBest(ll x){
	if(dp[x] != -1) return dp[x];
	ll mx = 0;
	if(options.count(x)) mx = 1;
	FOR(i, 1, x){
		ll q1, q2;
		q1 = getBest(x-i);
		q2 = getBest(i);
		if(q1 > 0 && q2 > 0)
			mx = max(mx, q1 + q2);
	}
	return dp[x] = mx;
}

int main(){
	sync;
	ll n, a, b, c;
	cin >> n >> a >> b >> c;
	FOR(i, 0, n+1) dp[i] = -1;
	options.insert(a);
	options.insert(b);
	options.insert(c);
	cout << getBest(n) << etr;
	return 0;
}