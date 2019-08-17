#include <iostream>
#include <vector>

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


ll floorExtraFactor[55];
ii cars[2510];

ll flrs, length, t, carNo;

void clear(){
	FOR(i, 0, flrs)
		floorExtraFactor[i] = 0;
	carNo = 0;
}

ll getRes(){
	ll total = 00;
	FOR(i, 1, carNo+1){
		ll &factor = floorExtraFactor[cars[i].second];
		factor %= length;
		if(factor < 0) factor += length;

		ll o1 = (cars[i].first + factor) % length;
		if(o1 < 0) cout << "xd" << etr;
		ll o2 = length - ((cars[i].first + factor) % length);
		if(o2 < 0) cout << "xd" << etr;

		if(o1 < o2){
			total += o1 * 5;
			factor -= o1;
		}
		else{
			total += o2 * 5;
			factor += o2;
		}
		total += 20 * cars[i].second;
	}
	return total;
}

int main(){
	sync;
	cin >> t;

	ll car;

	FOR(i, 0, t){
		cin >> flrs >> length;
		clear();
		FOR(i, 0, flrs){
			FOR(j, 0, length){
				cin >> car;
				if(car == -1) continue;
				cars[car].first = j;
				cars[car].second = i;
				carNo ++;
			}
		}
		cout << getRes() << etr;
	}
	return 0;
}