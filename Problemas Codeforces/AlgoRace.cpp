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
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); //////cout.tie(NULL)
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

ll n, m, r;


ll carOpt[65][65][65];

ll res[1005][65][65];

void classcFlyd(ll mx[65][65]){
	FOR(i, 0, n){
		FOR(j, 0, n){
			FOR(k, 0, n){
				mx[j][k] = min(mx[j][k], mx[j][i] + mx[i][k]);
				res[0][j][k] = res[1][j][k] = min(res[0][j][k], mx[j][k]);
			}
		}
	}
}

void calc(ll im){
	FOR(i, 0, n){
		FOR(j, 0, n){
			FOR(k, 0, n){
				res[im][j][k] = res[im+1][j][k] = min(res[im][j][k], min(res[0][j][i] + res[im-1][i][k], res[im-1][j][i] + res[0][i][k]));
			}
		}
	}
}

void setup(){
	FOR(i, 0, 1005){
		FOR(j, 0, 65){
			FOR(w, 0, 65) res[i][j][w] = INF;
		}
	}
}

int main(){
	sync;
	setup();
	cin >> n >> m >> r;
	FOR(i, 0, m){
		FOR(j, 0, n){
			FOR(w, 0, n){
				cin >> carOpt[i][j][w];
			}
		}
	}

	FOR(i, 0, m) classcFlyd(carOpt[i]); 
	FOR(i, 1, 70) calc(i);

	ll a, b, c;
	FOR(i,0, r){
		cin >> a >> b >> c;
		a--; b--;
		cout << res[min(c, (ll)65)][a][b] << etr;
	}

	return 0;
}