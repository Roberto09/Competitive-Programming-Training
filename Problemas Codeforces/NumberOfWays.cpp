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

ll arr[500005];
ll sumToHere[500005];
vi twoNPos;

ll bsL(ll low){
	ll l = 0, r = twoNPos.size() - 1, m;
	ll best = -1; 
	while(l <= r){
		m = l + (r-l) / 2;
		if(twoNPos[m] < low){
			l = m+1; continue;
		}
		best = m;
		r = m-1;
	}
	if(best == -1) return 0;
	return twoNPos.size() - best;
}

int main(){
	sync;
	ll n;
	cin >> n;
	ll prev = 0;
	FOR(i, 0, n){
		cin >> arr[i];
		sumToHere[i] = prev + arr[i];
		prev = sumToHere[i];
	}

	if(sumToHere[n-1]%3 != 0){
		cout << 0 << etr;
		return 0;
	}
	ll find =sumToHere[n-1]/3;
	
	FOR(i, 0, n-1){
		if(sumToHere[i] == find * 2){
			twoNPos.pb(i);
		}
	}

	//FOR(i, 0, n) cout << sumToHere[i] << etr;
	ll res = 0;
	FOR(i, 0, n-2){
		if(sumToHere[i] == find){
			ll l = i+1;
			ll p = bsL(l);
			res += p;
		}
	}
	cout << res << etr;
	return 0;
}

