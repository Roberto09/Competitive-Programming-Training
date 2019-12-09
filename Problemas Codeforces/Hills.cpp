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

ll n, arr[5005];
//    ksl  curr
ll dp[2510][5010][2];

bool check(ll x){
	return (x == n ? true : arr[x] < arr[x+1]);
}

ll prev(ll x){
	if(x == 0) return -INF;
	return arr[x-1];
}

ll next(ll x){
	if(x >= n-1) return -INF;
	return arr[x+1];
}

ll calcDp(ll curr, ll ksl, bool befr, ll modPrev){
	if(curr >= n || ksl == 0){
		if(ksl <= 0) return 0;
		return INF;
	}
	if(dp[ksl][curr][(befr ? 1 : 0)] != -1) return dp[ksl][curr][(befr ? 1 : 0)];

	// usar este
	ll dif = 0;
	if(befr) dif = max(0ll, modPrev - arr[curr] + 1) + max(0ll, next(curr) - arr[curr] + 1);
	else dif = max(0ll, prev(curr) - arr[curr] + 1) + max(0ll, next(curr) - arr[curr] + 1);
	ll o1 = dif + calcDp(curr + 2, ksl -1, true, next(curr) - max(0ll, next(curr) - arr[curr]+ 1));

	// no usar este
	ll o2 = calcDp(curr+1, ksl, false, arr[curr]);

	ll res = min(o1, o2);
	if(res >= INF) res = INF;

	return dp[ksl][curr][(befr ? 1 : 0)] = min(o1, o2);
	// no usar este
}

int main(){
	sync;
	cin >> n;
	FOR(i, 0, n) cin >> arr[i];

	mem(dp, ll(-1));
	FOR(i, 1, n/2 + n%2 + 1){
		cout << calcDp(0, i, false, 0) << etr;
	}

	return 0;
}