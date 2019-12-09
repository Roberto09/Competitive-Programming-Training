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
#define INF 1E18

ll n, k;
ll res = 0;
ll arr[200050];

int main(){
	sync;
	cin >> n >> k;
	FOR(i, 0, n) cin >> arr[i];
	sort(arr, arr+n);


	ll l = 0, r = n/2-1;
	ll o = -1;
	while(l <= r){
		ll m = l + (r-l) / 2;
		ll j = 0;
		bool x = false;
		ROF(i, m, 0){
			if(arr[n - 1 -j] - arr[i] < k){
				r = m-1;
				x = true;
				break;
			}
			j ++;
		}
		if(x) continue;
		l = m + 1;
		o = m;
	}

	cout << o + 1 << etr;
	return 0;
}