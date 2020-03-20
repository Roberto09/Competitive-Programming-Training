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

ll x, y, t, l, w;

//      x      y
ll mtrx[1050][1050];
bool vs[1050][1050];
ll mv[][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
vii ps;

ll bfs(){
	ll res = 0;
	queue<ii> q;
	for(ii kk : ps){
		q.push(kk);
		vs[kk.first][kk.second] = true;
	}

	ll currt = 0;
	ll levcnt = q.size();
	while(!q.empty()){
		res ++;
		levcnt --;
		ii cr = q.front(); q.pop();
		FOR(i, 0, 4){
			ll cx = cr.first, cy = cr.second;
			cx += mv[i][0], cy += mv[i][1];
			if(cx >= 1 && cx <= x && cy >= 1 && cy <= y){
				if(mtrx[cx][cy] == 0 && !vs[cx][cy]){
					q.push(mp(cx, cy));
					vs[cx][cy] = true;
				}
			}
		}
		if(levcnt == 0){
			currt ++;
			levcnt = q.size();
		}
		if(currt == t) break;
	}
	return res;
}

void add(ll xa, ll ya, ll xb, ll yb){
	ll mx, my;
	mx = xb - xa; my = yb - ya;
	if(mx != 0) mx/= abs(mx);
	if(my != 0) my /= abs(my);

	ll cx = xa, cy =ya; 
	//cout << mx << " " << my << etr;
	while(true){
		mtrx[cx][cy] = 2;
		if(cx == xb && cy == yb) break;
		cx += mx; cy += my;
	}
}

void solve(){
	mem(mtrx, 0ll);
	mem(vs, false);
	ps.clear();
	FOR(i, 0, l){
		ll xi, yi;
		cin >> xi >> yi;
		mtrx[xi][yi] = 1;
		ps.pb(mp(xi, yi));
	}
	FOR(i, 0, w){
		ll xa, ya, xb, yb;
		cin >> xa >> ya >> xb >> yb;
		add(xa, ya, xb, yb);
	}
	cout << bfs() << etr;
}
int main(){
	sync;
	while(true){
		cin >> x;
		if(x == -1) break;
		cin >> y >> t >> l >> w;
		solve();
	}


	return 0;
}