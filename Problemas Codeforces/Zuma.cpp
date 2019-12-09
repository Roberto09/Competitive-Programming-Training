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
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); //////cout.tie(NULL)
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

ll dp[505][505];
bool dpb[505][505];
ll arr[505];
ll n;

ll getRes(ll l, ll r){
	if(l > r) return  0;
	if(dpb[l][r]) return dp[l][r];
	ll toFnd = arr[l];
	ll bst = INF;
	FOR(i, l+1, r+1)
		if(arr[i] == toFnd) bst = min(bst, (i == l+1 ? 1 :  getRes(l+1, i-1)) + getRes(i+1, r));
	bst = min(bst, getRes(l+1, r) + 1);
	dpb[l][r] = true;
	return dp[l][r] = bst;
}

int main(){
	sync;
	cin >> n;
	FOR(i, 0, n) cin >> arr[i];
	cout << getRes(0, n-1);

	return 0;
}
