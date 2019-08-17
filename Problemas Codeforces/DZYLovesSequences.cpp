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


ll n;
ll arr[100005];
vii intervals;

ll checkInterval(ii &prev, ii &actual){
	//separacion de 0
	if (prev.second + 1 == actual.first){
		if(actual.first == actual.second) return actual.second - prev.first + 1;
		else if(prev.second == prev.first){
			if(arr[actual.first+1] - arr[prev.second] >= 2) return actual.second - prev.first + 1;
		}
		else{
			if(arr[actual.first+1] - arr[prev.second] >= 2 || arr[actual.first] - arr[prev.second-1] >= 2){
				return actual.second - prev.first + 1;
			}
		}
	}
	return max(prev.second - prev.first, actual.second - actual.first) + 2;
}

int main(){
	sync;
	cin >> n;
	FOR(i ,0 , n){
		cin >> arr[i];
	}
	if(n == 1){
		cout << 1 << etr;
		return 0;
	}

	arr[n] = 0;
	ii actual{0, 0};
	ll prev = arr[0];

	ll mx = 0;

	FOR(i, 1, n){
		if(arr[i] > prev)
			actual.second ++;
		else{
			intervals.pb(actual);
			actual = {i, i};
		}
		prev = arr[i];
	}
	intervals.pb(actual);

	mx = max(mx, intervals[0].second - intervals[0].first + 1);

	FOR(i, 1, intervals.size()){
		mx = max(mx, checkInterval(intervals[i-1], intervals[i]));
	}
	cout << mx << etr;

	return 0;
}
