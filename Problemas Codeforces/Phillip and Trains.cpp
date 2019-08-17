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
#define INF 10E10

/*
2
16 4
...AAAAA........
s.BBB......CCCCC
........DDDDD...
16 4
...AAAAA........
s.BBB....CCCCC..
.......DDDDD....
*/

ll t;

char matr[3][105];

ll n, tr;
ll rs, cs;

int dp[3][105];

bool checkStand(ll r, ll c, ll mult){
	ll dist = mult*2;
	if(c + dist >= n) return true;
	return matr[r][c+dist] == '.' | matr[r][c+dist] == 's';
}

bool dpAlg(ll r, ll c, ll stp){
	if(stp >= n - cs) return true;
	
	if(dp[r][c] != -1) return dp[r][c];

	if(!checkStand(r, c, stp) || !checkStand(r, c+1, stp)) return dp[r][c] = 0;

	//3 opciones
	bool dAr, dAb, dQ;
	//der arriba
	if(r == 0) dAr = false;
	else dAr = dpAlg(r-1, c+1, stp+1) & checkStand(r-1, c+1, stp);

	//der abajo
	if(r == 2) dAb = false;
	else dAb = dpAlg(r+1, c+1, stp+1) & checkStand (r+1, c+1, stp);

	//der quedarte
	dQ = dpAlg(r, c+1, stp+1);

	if(dAr || dAb || dQ) return dp[r][c] = 1;
	else return dp[r][c] = 0;
}

bool doAlg(){
	mem(dp, -1);
	return dpAlg(rs, cs, 0);
}

int main(){
	sync;
	cin >> t;
	FOR(i, 0, t){
		cin >> n >> tr;
		FOR(r, 0, 3){
			FOR(c, 0, n){
				cin >> matr[r][c];
				if(matr[r][c] == 's'){
					rs = r; cs = c;
				}
			}
		}
		if(doAlg()) cout << "YES" << etr;
		else cout << "NO" << etr;
	}
	return 0;
}
