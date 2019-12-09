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

//		[tour][bags][wins]
unordered_map<ll, double> dp[205][205];

double trs[205];
ll bgs[205];

ll n, l, s;

double dpRec(ll tr, ll bg, ll w){
	if(tr == n){
		if(w >= l && bg >= 0) return 1;
		return 0;
	}
	ll altbg = min((ll)200, bg);
	if(dp[tr][w].count(altbg)) return dp[tr][w][altbg];
	// 2 cases
	double wnRes = 0.0, lRes = 0.0;
	// win	
	wnRes = trs[tr] * dpRec(tr + 1, bg + bgs[tr], w + 1);
	// loose
	lRes = (1.0 - trs[tr]) * dpRec(tr + 1, bg, w);
	return dp[tr][w][altbg] = wnRes + lRes;
}

int main(){
	sync;
	cin >> n >> l >> s;
	FOR(i, 0, n){
		double x;
		cin >> x;
		trs[i] = x / 100;
	}
	FOR(i, 0, n) cin >> bgs[i];
	cout <<  std::setprecision (15) << dpRec(0, s, 0);
	return 0;
}


