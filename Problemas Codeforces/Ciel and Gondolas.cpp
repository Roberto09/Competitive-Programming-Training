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
#define MAX 4100

ll n, k;

ll cs[4050][4050];
ll cost[4050][4050];
ll dp[850][4050];
//+ =

void calcDp(ll ik, ll l, ll r, ll lb, ll rb){
	if(l > r) return;
	ll m = l+(r-l)/2;
	ll mn, ps; mn = ps = INF;
	FOR(j, max(lb, m), rb+1){
		ll o = dp[k-1][j+1] + cost[m][j];
		cout << "ik: " << ik << " j: " << j << " o: " << o << etr;
		if(o < mn)
			mn = o, ps = j;
	}
	dp[ik][m] = mn;
	calcDp(ik, l, m-1, lb, ps); calcDp(ik, m+1, r, ps, rb);
}

void calcCosts(){
	ROF(i, n-1, 0){
		FOR(j, i, n) cost[i][j] = cost[i][j-1] + cost[i+1][j] - cost[i+1][j-1] + cs[i][j];
	}
}

int main(){
	cin >> n >> k;
	FOR(i, 0, n){
		FOR(j, 0, n)
			cin >> cs[i][j];
	}
	calcCosts();
	
	FOR(i,0,n){
		dp[0][i] = cost[i][n-1];
	}

	FOR(i, 1, k){
		calcDp(i, 0, n-1, 0, n-1);
	}

	FOR(i, 0, k){
		FOR(j, 0, n) cout << dp[i][j] << " ";
	cout << etr;
	}

	cout << dp[k-1][0] << etr;

	return 0;
}