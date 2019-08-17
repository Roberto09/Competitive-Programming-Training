#include <iostream>
#include <vector>
#include <map>
#include <stdio.h>
#include <string.h>
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
#define INF 1E16
#define INV 1E17

ll dp[1005][17][17];
vii nmbrs;

ll getBest(ll lev, ll b, ll w){
	if(lev == nmbrs.size()){
		if(b == 15 && w == 15) return 0;
		return -INF;
	}

	if(dp[lev][b][w] != INV) return dp[lev][b][w];
	ll bl = -INF, wi = -INF, ni= -INF;
	//blacke
	if(b < 15){
		bl = getBest(lev+1, b+1, w);
		if(bl != -INF) bl += nmbrs[lev].first;
	}
	//white
	if(w < 15){
		wi = getBest(lev+1, b, w+1);
		if(wi != -INF) wi += nmbrs[lev].second;
	}
	//ninguno
	ni = getBest(lev+1, b, w);

	return dp[lev][b][w] = max(bl, max(wi, ni));
}

int main(){
	ll a, b;
	while(cin >> a >> b){
		if(a == 0) break;
		nmbrs.pb(mp(a, b));
	}
	FOR(i, 0, nmbrs.size()+1){
		FOR(j, 0, 17){
			FOR(k, 0, 17) dp[i][j][k] = INV;
		}
	}

	cout << getBest(0, 0, 0) << etr;

	return 0;
}