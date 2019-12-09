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

ll n;
double arr[105];

double getRes(ll m){
	double prob = 0.0;
	double calc = 1.0;
	FOR(i,0,m){
		calc *= (1.0 - arr[i]);
	}
	FOR(i, 0, m){
		double cCalc = calc / (1.0 - arr[i]);
		prob += cCalc * arr[i];
	}
	return prob;
}

int main(){
	sync;
	cin >> n;
	FOR(i, 0, n) cin >> arr[i];
	sort(arr, arr+n, greater<double>());
	if(arr[0] == 1.0){
		cout << 1.0 << etr;
		return 0;
	}
	ll l = 0, r = n, m;
	double dm, drm;
	double prb = 0.0;
	while(l <= r){
		m = l + (r-l) / 2;
		dm = getRes(m);
		drm = (m == n ? -1.0 : getRes(m+1));
		if(drm < dm){
			r = m-1;
			prb = dm;
		}
		else l = m+1;
	}
	cout << std::setprecision (15) << prb << etr;
	return 0;
}