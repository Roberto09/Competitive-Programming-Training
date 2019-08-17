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
#define INF 1E17

ll n, m, r;
ll s, e, k;

//      car  a   b
ll cars[62][62][62];
ll bestCars[62][62][62];

ll coolPaths[1005][62][62];

class Compare{
public:
    bool operator() (const ii &p1, const ii &p2)
    {
        return p1.first > p2.first;
    }
};

void dijkstra(ll start, ll car){
	priority_queue<ii, vii, Compare> pq;
	bool calc[n];
	FOR(i, 0, n) calc[i] = false;
	pq.push(mp(0, start));
	ll calculated = 0;
	ii curr;
	while(!pq.empty()){
		curr = pq.top(); pq.pop();
		if(calc[curr.second]) continue;
		calc[curr.second] = true;
		calculated++;
		bestCars[car][start][curr.second] = curr.first;
		FOR(i, 0, n){
			if (i == curr.second) continue;
			pq.push(mp(curr.first + cars[car][curr.second][i], i));
		}
	}
}

void bestPath(ll car){
	FOR(i, 0, n){
		dijkstra(i, car);
	}
}

void calculateCoolPath(ll kth){
	FOR(i, 0, n){
		FOR(j, 0, n){
			FOR(w, 0, n){
				if()
				coolPaths[kth][i][j] = min(coolPaths[kth][i][j], coolPaths[kth-1][i][w] + coolPaths[kth-1][w][j]);
			}
		}
	}
}

void clearCoolPaths(){
	FOR(w, 0, 1005){
		FOR(i, 0, n){
			FOR(j, 0, n){
				coolPaths[w][i][j] = INF;
			}
		}
	}
}

int main(){
	sync;
	cin >> n >> m >> r;

	FOR(i, 0, m){
		FOR(j, 0, n){
			FOR(w, 0, n){
				cin >> cars[i][j][w];
			}
		}
	}

	FOR(i, 0, m) bestPath(i);

	clearCoolPaths();

	//calculamos el primer coolpath con 0 k
	FOR(i, 0, n){
		FOR(j, 0, n){
			FOR(w, 0, m){
				coolPaths[0][i][j] = min(coolPaths[0][i][j], bestCars[w][i][j]);
			}
		}
	}

	FOR(i, 1, 1005) calculateCoolPath(i);

	FOR(i, 0, r){
		cin >> s >> e >> k;
		s--;
		e--;
		cout << coolPaths[k][s][e] << etr;
	}
	return 0;
}