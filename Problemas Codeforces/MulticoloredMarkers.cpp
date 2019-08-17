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
#define INF 1E17


int main(){
	ll x, y;
	cin >> x >> y;
	ll area = x + y;
	vii combinations;

	set<ll, greater<ll>> setx, sety;

	FOR(i, 1, sqrt(x)+1){
		if(x%i == 0){
			setx.insert(i); setx.insert(x/i);
		}
	}

	FOR(i, 1, sqrt(y)+1){
		if(y%i == 0){
			sety.insert(i); sety.insert(y/i);
		}
	}

	//encontramos todas las posibles b*h
	//sqrt(n)
	FOR(i, 1, sqrt(area)+1){
		if(area%i == 0)
			combinations.pb(mp(i, area/i));
	}

	//probamos las posibles combinaciones
	ll aplusb = INF;

	ll s1, s2;
	ll a, b;
	FOR(i, 0, combinations.size()){
		s1 = combinations[i].first, s2 = combinations[i].second;
		if(s2 >= x || s2 >= y){
			aplusb = min(aplusb, s1 + s2);
		}
		else{
			auto a = setx.lower_bound(s1);
			auto b = sety.lower_bound(s1);
			if((a !=setx.end() && x/(*a) <= s2) || (b !=sety.end() && y/(*b) <= s2)) aplusb = min(aplusb, s1 + s2);
		}
	}

	cout << 2 * aplusb << etr;
	return 0;
}