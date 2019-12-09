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
#define INF 1E15

ll n;
double arr[4050];
vector<double> v;

double get(ll mid){
	double sum2 = 0;
	FOR(i, 0, mid)
		sum2 += floor(v[i]);
	FOR(i, mid, v.size())
		sum2 += ceil(v[i]);
	return sum2;
}

int main(){
	sync;
	cin >> n;
	double sum = 0;
	FOR(i, 0, n*2){
		cin >> arr[i];
		if((double)floor(arr[i]) != (double)arr[i]){
			sum += arr[i];
			v.pb(arr[i]);
		}
	}

	sort(v.begin(), v.end(), [&](double &d1, double &d2){
		return d1-floor(d1) < d2-floor(d2);
	});

	double res = INF;
	ll a = v.size() / 2 - (2*n - v.size())/2; a = max(a, 0);
	ll b = v.size() / 2 + (v.size()%2) + (2*n - v.size())/2; b = min(b, ll(v.size()));
	FOR(i, a, b + 1)
		res = min(res, abs(sum - get(i)));


	cout << fixed << setprecision(3) << res << etr;

	return 0;
}