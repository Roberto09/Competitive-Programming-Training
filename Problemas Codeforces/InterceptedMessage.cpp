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


int main(){
	sync;
	ll x, y;
	cin >> x >> y;

	ll arrx[x];
	ll arry[y];
	FOR(i, 0, x){
		cin >> arrx[i];
	}
	FOR(i,0, y){
		cin >> arry[i];
	}

	ll prevSumx = 0, prevSumy = 0;
	ll ix = 0, iy = 0;
	ll res = 0;
	ll xn, yn;
	while(ix < x){
		xn = arrx[ix];
		yn = arry[iy];
		if(prevSumx == 0 && prevSumy == 0){
			prevSumx += xn;
			prevSumy += yn;
		}
		else if(prevSumy > prevSumx){
			prevSumx += xn;
		}
		else{
			prevSumy += yn;
		}

		if(prevSumy == prevSumx){
			prevSumx = 0;
			prevSumy = 0;
			ix ++;
			iy ++;
			res ++;
		}
		else if(prevSumy > prevSumx){
			ix ++;
		}
		else{
			iy ++;
		}
	}
	cout << res << etr;

	return 0;
}