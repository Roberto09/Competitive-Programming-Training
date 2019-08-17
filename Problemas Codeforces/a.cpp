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

ll n, q;

/*
	8
	8 7 3 1 7 0 9 4
	3
	1 8
	2 5
	7 7
*/

ll arr[100050];

unordered_map<ll, unordered_map<ll, ii>> dp;

ii solve(ll l, ll r){
	if(l == r) return mp(0, arr[r]);
	if(dp.count(l) && dp[l].count(r)) return dp[l][r];
	ii left = solve(l, l + (r-l) / 2), right = solve(l + (r-l) / 2 + 1, r);
	ll res = left.first + right.first;
	if(left.second + right.second >= 10) res ++;
	return dp[l][r] = mp(res, (left.second + right.second) % 10);
}

int main(){
	sync;
	cin >> n;
	FOR(i, 0, n) cin >> arr[i];
	cin >> q;
	ll l, r;
	FOR(i, 0, q){
		cin >> l >> r;
		cout << solve(l - 1, r - 1).first << etr;
	}

	return 0;
}