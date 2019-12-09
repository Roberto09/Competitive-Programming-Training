#include <bits/stdc++.h>
using namespace std;

typedef int ll;
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

/*
3
1 2 -1
*/

map<ll, ll> curr;
ll getBest(ll nde, ll prev){
	if(curr[nde] == 0) return -INF;
	curr[nde] --;
	ll res = 0;
	if(curr[nde + prev]){
		res = getBest(nde + prev, nde);
	}
	curr[nde] ++;
	return res + 1;
}

ll n;
ll arr[1050];
int main(){
	sync;
	cin >> n;
	FOR(i, 0, n){
		cin >> arr[i];
		curr[arr[i]] ++;
	}
	ll mx = 0;
	if(curr[0]>1) mx = curr[0], curr[0]=1;
	FOR(i, 0, n){
		FOR(j, 0, n){
			if(i == j && curr[arr[i]] < 2) continue;
			curr[arr[i]] --;
			ll o = 1 + getBest(arr[j], arr[i]);
			mx = max(mx, o);
			curr[arr[i]] ++;
		}
	}

	cout << mx << etr;
}