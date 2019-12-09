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
 
ll n, k , d;
ll arr[500050];
ll ps[500050];
 
int main(){
	sync;
	cin >> n >> k >> d;
	FOR(i, 0, n) cin >> arr[i];
	sort(arr, arr+n);
	map<ll, ll> app;
	app[INF] = n;
	ROF(i, n-1, 0){
		ll nm = arr[i];
		ll tfnd = nm + d;
		auto op = app.upper_bound(tfnd);
		if(op->second - i >= k){
			if(ps[i + k] - ps[op->second+1] || op->second == n) ps[i] = 1;
		}
		ps[i] += ps[i+1];
		app[nm] = i;
	}
 
	if(ps[0] > ps[1]) cout << "YES" << etr;
	else cout << "NO" << etr;
 
	return 0;
}