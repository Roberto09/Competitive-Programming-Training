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
//#define PI 3.1415926535897932384626433832795
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

ll gcd(ll a,ll b) {
    if(b) return gcd(b, a%b);
    return a;
}

ll mcm(ll a, ll b) {
    return a/gcd(a, b)*b;
}

int main(){
	ll n, k, a, b;
	cin >> n >> k >> a >> b;

	ll start = a;
	vi optionsFirstStop;
	for(ll i = 0; i < n*k; i+= k){
		ll o1, o2;
		o1 = i - b;
		o2 = i + b;
		if(o1 < 0) o1 += n*k;
		if(o2 > n*k) o2 -= n * k;

		optionsFirstStop.pb(o1);
		optionsFirstStop.pb(o2);
	}

	ll mn = INF;
	ll mx = -INF;

	FOR(i, 0, optionsFirstStop.size()){
		ll opt = optionsFirstStop[i];
		//cout << opt << etr;
		ll dist = abs(start - opt);
		if(opt <= start)
			dist = (n*k - start) + opt;

		ll x, y;
		x = (n*k) / dist;
		y =  (n*k) % dist;
		ll pos = mcm(n*k, dist) / (dist);
		mn = min(pos, mn);
		mx = max(pos, mx);
	}
	cout << mn << " " << mx << etr;
	return 0;
}