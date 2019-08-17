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
#define INF 1E15

int main(){
	ll t;
	cin >> t;
	ll n, x, y, d;
	FOR(i, 0, t){
		cin >> n >> x >> y >> d;
		if(abs(y - x) % d == 0){
			cout << abs(y - x) / d << etr;
			continue;
		}
		else{
			ll minRes = INF;
			if((y-1) % d == 0)
				minRes = ceil((double)(x-1) / d) + (y-1) / d;
			if((n - y) % d == 0){
				ll rs = ceil((double)(n - x) / d) + (n-y) / d;
				minRes = min(minRes, rs);
			}
			if(minRes != INF) {
				cout << minRes << etr;
				continue;
			}
		}
		cout << -1 << etr;
	}
	return 0;
}