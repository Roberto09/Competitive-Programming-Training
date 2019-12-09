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

ll getNmbr(ll sm){
	ll tent = (-1 + sqrt(8*sm + 1)) / 2;
	tent ++;
	if((tent * (tent-1))/2 == sm) return tent;
	return -1;
}

ll x, y, z, w;

int main(){
	sync;
	ll ceros, ones;
	cin >> x >> y >> z >> w;

	if(x == 0 && y == 0 && z == 0 && w != 0){
		ones = getNmbr(w);
		if(ones == -1){
			cout << "Impossible" << etr;
			return 0;
		}
		FOR(i, 0, ones) cout <<'1';
		cout << etr;
		return 0;
	}
	if(w == 0 && y == 0 && z == 0){
		ones = getNmbr(x);
		if(ones == -1){
			cout << "Impossible" << etr;
			return 0;
		}
		FOR(i, 0, ones) cout <<'0';
		cout << etr;
		return 0;
	}

	ceros = getNmbr(x);
	ones = getNmbr(w);
	if(ceros == -1 || ones == -1 || ceros * ones != (y + z)){
		cout << "Impossible" << etr;
		return 0;
	}
	string s = "";
	FOR(i, 0, z / ceros) s+='1';
	FOR(i, 0, ceros - z%ceros) s+='0';
	if(z % ceros != 0) s+= '1';
	FOR(i, 0, z%ceros) s+='0';
	FOR(i, 0, ones - ceil((double)z / ceros)) s+='1';
	cout << s << etr;

	return 0;
}