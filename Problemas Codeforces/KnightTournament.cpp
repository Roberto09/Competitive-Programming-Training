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

ll n, m;

struct point{
	ll orderOfApp;
	bool isStart;
	ll bound;
	ll value;
};

point pts[600010];

int main(){
	sync;
	cin >> n >> m;
	ll a, b, x;
	ll prevX = -1;
	ll prevIX = -1;
	FOR(i, 0, m){
		cin >> a >> b >> x;
		if(x == prevX && ((a >= pts[prevIX].bound && a <= pts[m + prevIX].bound) || (b >= pts[prevIX].bound && b <= pts[m + prevIX].bound) || (a <= pts[prevIX].bound && b >= pts[prevIX].bound)) ){
			//we check for intersection
			pts[i].orderOfApp = INF;
			pts[i].bound = INF;
			
			pts[m + i].orderOfApp = INF;
			pts[m + i].bound = INF;

			pts[prevIX].bound = min(a, pts[prevIX].bound);
			
			pts[m + prevIX].bound = max(b+1, pts[m + prevIX ].bound);
		}
		else{		
			pts[i].orderOfApp = i;
			pts[i].isStart = true;
			pts[i].bound = a;
			pts[i].value = x;
			
			pts[m + i].orderOfApp = i;
			pts[m + i].isStart = false;
			pts[m + i].bound = b+1;
			prevIX = i;
		}
		prevX = x;
	}

	sort(pts, pts+m*2, [](const point &p1, const point &p2){
		return p1.bound < p2.bound;
	});

	//point and winner
	map<ll, ll> app;
	ll lastIdx = 0;
	FOR(i, 1, n+1){
		//meter y sacar los que aparecen
		for(; lastIdx < 2*m; lastIdx++){
			if(pts[lastIdx].bound != i)
				break;
			else{
				if(pts[lastIdx].isStart)
					app[pts[lastIdx].orderOfApp] = pts[lastIdx].value;
				else
					app.erase(pts[lastIdx].orderOfApp);
			}
		}

		//sacamos el resultado del acutal
		auto res = app.begin();
		if(res != app.end()){
			while(res != app.end()){
				if(res->second == i) res++;
				else{
					cout << res->second << " ";
					break;
				}
			}
			if(res == app.end()) cout << 0 << " ";
		}
		else cout << 0 << " ";
	}
	return 0;
}
