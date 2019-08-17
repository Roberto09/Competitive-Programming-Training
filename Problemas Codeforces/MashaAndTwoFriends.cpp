#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;
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
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); ////cout.tie(NULL)
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
#define INF 1E9;
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cerr << name << " : " << arg1 << '\n';
}

struct coord{
	ll x1 = 1, y1 = 1, x2 = 1, y2 = 1;
};

ii getColors(coord &c){
	ll calc = ((c.x2-c.x1)+1) * ((c.y2-c.y1)+1);
	if(calc%2 == 0) return ii(calc/2, calc/2);
	if((c.x1+c.y1)%2 == 0) return ii(calc/2+1, calc/2);
	return ii(calc/2, calc/2+1);
}

coord getIntersection(coord &c1, coord &c2){
	coord res;
	
	if(c1.x2 < c2.x1 || c2.x2 < c1.x1 || c1.y2 < c2.y1 || c2.y2 < c1.y1){
		res.x1 = -1;
		return res;
	}

	res.x1 = c1.x1 > c2.x1 ? c1.x1 : c2.x1;
	res.x2 = c1.x2 < c2.x2 ? c1.x2 : c2.x2;
	res.y1 = c1.y1 > c2.y1 ? c1.y1 : c2.y1;
	res.y2 = c1.y2 < c2.y2 ? c1.y2 : c2.y2;

	return res;
}

int main(){
	sync;
	ll t;
	cin >> t;
	coord tbl, f1, f2, its;
	ii colorsTotal, f1C, f2C, itsC;//white, black
	ll nW, nB;

	FOR(i, 0, t){
		cin >> tbl.y2 >> tbl.x2;
		cin >> f1.x1 >> f1.y1 >> f1.x2 >> f1.y2;
		cin >> f2.x1 >> f2.y1 >> f2.x2 >> f2.y2;

		colorsTotal = getColors(tbl);
		its = getIntersection(f1, f2);


		f1C = getColors(f1);
		f2C = getColors(f2);

		//cout << "square: " << "x1: " << tbl.x1 << "  y1: " << tbl.y1 << "  x2: " << tbl.x2 << "  y2: " << tbl.y2 << etr;
		//cout <<  "square: " << "w: " << colorsTotal.first << "   b: " << colorsTotal.second << etr;

		if(its.x1 != -1){
			//cout << "intersection: " << "x1: " << its.x1 << "  y1: " << its.y1 << "  x2: " << its.x2 << "  y2: " << its.y2 << etr;
			itsC = getColors(its);
			//cout <<  "intersection: " << "w: " << itsC.first << "   b: " << itsC.second << etr;
			f1C.second -= itsC.second;
		}

		colorsTotal.first += f1C.second;
		colorsTotal.second -= f1C.second;

		colorsTotal.second += f2C.first;
		colorsTotal.first -= f2C.first;

		cout << colorsTotal.first << " " << colorsTotal.second << etr;
	}

	return 0;
}