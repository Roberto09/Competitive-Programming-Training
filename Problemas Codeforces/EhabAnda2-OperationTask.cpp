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
#define INF 1E9
int main(){
	sync;
	ll n;
	cin >> n;
	ll arr[n];
	FOR(i, 0, n){
		cin >> arr[i];
	}

	vii result;

	ll accumulatedSum = 0;
	ROF(i, n-1, 0){
		ll expValue = i+1;
		if((arr[i] + accumulatedSum) % (n+1) != expValue){
			ll val = arr[i] + accumulatedSum;
			val %= n+1;
			ll res = expValue - val;
			if(res < 0) res += (n+1);

			result.pb(mp(expValue, res));
			accumulatedSum += (res);
		}
		arr[i] = ((arr[i] + accumulatedSum) % (n+1)); 
	}

	cout << (result.size() == 0 ? 0 : result.size() + 1) << etr;
	FOR(i, 0, result.size()){
		cout << 1 << " " << result[i].first << " " << result[i].second << etr;
	}
	if(result.size() > 0){
		cout << 2 << " " << n << " " << n+1 << etr;
	}
	return 0;
}