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
#define INF 9223372036854775807;

int main(){
	sync;
	ll n, k;
	cin >> n >> k;
	vii divisors;

	FOR(i, 1, sqrt(n)+1){
		if(n%i == 0){
			divisors.pb(mp(i, n/i));
		}
	}

	ii pos;
	ll posx = INF;
	FOR(i, 0, divisors.size()){
		pos = divisors[i];
		ll posx2 = pos.first * k + pos.second;
		if((posx2 / k) * (posx2 % k) == n){
			posx = min(posx, posx2);
		}
		posx2 = pos.second * k + pos.first;
		if((posx2 / k) * (posx2 % k) == n){
			posx = min(posx, posx2);
		}
	}
	cout << posx << etr;
	return 0;
}