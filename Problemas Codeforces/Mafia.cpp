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

bool check(ll mid){
	ll reusesLeft = mid;
	FOR(i, 0, n){
		reusesLeft -= (mid - arr[i]);
	}
	if (reusesLeft <= 0) return true;
	return false;
}

int main(){
	sync;
	cin >> n;
	FOR(i, 0, n) cin  >> arr[i];
	sort(arr, arr+n);
	ll l = arr[n-1], r = ceil((double)(l*n) / (n-1));
	ll mid;
	ll res = 0;
	while(l<=r){
		mid = l + (r-l)/2;
		if(check(mid)){
			res = mid;
			r = mid-1;
		}
		else l = mid+1;
	}
	cout << res << etr;
	return 0;
}