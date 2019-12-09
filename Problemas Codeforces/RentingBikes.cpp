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

ll n, m, a;
ll arr[100050];
ll arr2[100050];

ii tryOpt(ll nmbr){
	ll oa = a;
	ll spnt = 0;
	FOR(i, 0, nmbr){
		if(arr[i] >= arr2[m - nmbr + i]){
			spnt += arr2[m - nmbr + i];
		}
		else{
			spnt += arr[i];
			oa -= arr2[m - nmbr + i] - arr[i];
			if(oa < 0) return mp(-INF, 0);
		}
	}
	return mp(nmbr, max(spnt - oa, 0ll));
}

int main(){
	sync;
	cin >> n >> m >> a;
	FOR(i, 0, n) cin >> arr[i];
	FOR(i,0,m) cin >> arr2[i];
	sort(arr, arr+n, greater<ll>()); sort(arr2, arr2+m, greater<ll>());

	ll l = 0, r = min(m, n);
 	ii ans = mp(0, 0);
	while(l <= r){
		ll md = l + (r-l) / 2;
		ii tr = tryOpt(md);
		if(tr.first == -INF) r = md -1;
		else{
			l = md + 1; ans = tr;
		}
	}
	cout << ans.first << " " << ans.second << etr;
	return 0;
}
