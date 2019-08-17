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

ll dpRight[2010];
ll dpLeft[2010];
ll arr[2010];

ll t, n;
void clear(){
	FOR(i, 0, n) dpRight[i] = dpLeft[i] = 1;
}

ll getResult(){
	ROF(i, n-1, 0){
		ll act = arr[i];
		ll mx = 0;
		FOR(j, i+1, n){
			if(arr[j] > act) mx = max(mx, dpRight[j]);
		}
		dpRight[i] = mx + 1;
	}

	ROF(i, n-1, 0){
		ll act = arr[i];
		ll mx = 0;
		FOR(j, i+1, n){
			if(arr[j] < act) mx = max(mx, dpLeft[j]);
		}
		dpLeft[i] = mx + 1;
	}

	ll mx = 0;
	FOR(i, 0, n){
		ll bestSum = dpRight[i] + dpLeft[i] - 1;
		mx = max(mx, bestSum);
	}
	return mx;
}

int main(){
	sync;
	ll t;
	cin >> t;
	FOR(i, 0, t){
		cin >> n;
		clear();
		FOR(j, 0, n) cin >> arr[j];
		cout << getResult() << etr;
	}

	return 0;
}