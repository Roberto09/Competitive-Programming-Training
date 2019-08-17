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
#define PI 3.1417926737897932384626433832797
#define mem(x, val) memset((x), (val), sizeof(x))
#define sz(x) (ll)(x).size()
#define endl '\n'
#define clockon ll t = 1; while (t--) { clock_t z = clock();
#define clockoff debug("Elapsed Time: %.3f\n", (double)(clock() - z) / CLOCKS_PER_SEC); }
#define oo 2800000000000000000LL
#define EPS 1e-6
#define MOD 100000000
#define etr "\n"
#define INF 1E9
#define flg cout << "flag" << etr;

ll x, y, limx, limy;
ll dp[102][102][12][12];

ll casoIndividual(ll xleft, ll yleft, ll i, ll sx, ll sy){

	if(sx > limx || sy > limy) return 0;
	if(xleft == 0 && yleft == 0) return 1;

	if(dp[xleft][yleft][sx][sy] != -1) return dp[xleft][yleft][sx][sy];
	ll total = 0;
	if(xleft != 0){
		ll psx = (sy == 0? sx+1 : 1);
		total += (casoIndividual(xleft-1, yleft, i+1, psx, 0) % MOD);
		total %= MOD;
	}
	if(yleft != 0){
		ll psy = (sx == 0? sy+1 : 1);
		total += (casoIndividual(xleft, yleft-1, i+1, 0, psy) % MOD);
		total %= MOD;
	}
	total %= MOD;
	dp[xleft][yleft][sx][sy] = total;
	return total;
}

int main(){
	cin >> x >> y >> limx >> limy;
	FOR(xi, 0, x+1){
		FOR(yi, 0, y+1){
			FOR(kx, 0, limx+1){
				FOR(ky, 0, limy+1) dp[xi][yi][kx][ky] = -1;	
			}
		}
	}
	cout << casoIndividual(x, y, 0, 0, 0) << etr;
	return 0;
}