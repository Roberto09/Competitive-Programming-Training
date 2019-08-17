#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef pair<ii, ll> iii;
typedef vector<ii> vii;
typedef vector<vi> gr;
typedef vector<vii> wgr;
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

struct node{
	vi e;
	vi w;
	vi ids;
};

ll n, m, k;

node g[300010];
node g2[300010];
bool remaining[300010];

struct pqn{
	ll cost, nde, prnt, id;
	pqn(){}
	pqn(ll c, ll nd, ll pr, ll idds){
		cost = c; nde = nd; prnt = pr; id = idds;
	}
};

ll cnt = 0;

void removeG2(ll curr, ll &toRemove, ll id){
	FOR(i, 0, g2[curr].e.size()){
		removeG2(g2[curr].e[i], toRemove, g2[curr].ids[i]);
	}
	if(toRemove > 0){
		remaining[id] = false;
		cnt --;
		toRemove --;
	}
}

class Compare
{
public:
    bool operator() (pqn &p1, pqn &p2)
    {
        return p1.cost > p2.cost;
    }
};

void shortesPaths(){
	priority_queue<pqn, vector<pqn>, Compare> pq;
	pq.push(pqn(0, 0, -2, -2));
	ll prnt[n]; mem(prnt, -1);
	pqn cur;
	while(!pq.empty()){
		cur = pq.top(); pq.pop();
		if(prnt[cur.nde] != -1) continue;
		prnt[cur.nde] = cur.id;
		
		if(cur.prnt >= 0){
			g2[cur.prnt].e.pb(cur.nde);
			g2[cur.prnt].ids.pb(cur.id);
		}

		FOR(i, 0, g[cur.nde].e.size()){
			pq.push(pqn(cur.cost + g[cur.nde].w[i], g[cur.nde].e[i], cur.nde, g[cur.nde].ids[i]));
		}
	}

	FOR(i, 0, n){
		if(prnt[i] < 0) continue;
		remaining[prnt[i]] = true;
		cnt ++;
	}

	ll dif = cnt - k;
	if(cnt > k){
		removeG2(0, dif, 0);
	}

	cout << cnt << etr;
	FOR(i,0,m){
		if(remaining[i]) cout << i+1 << " ";
	}
}

int main(){
	mem(remaining, false);
	sync;
	cin >> n >> m >> k;
	ll x, y, w;
	FOR(i, 0, m){
		cin >> x >> y >> w;
		x --; y--;
		g[x].e.pb(y);
		g[x].w.pb(w);
		g[x].ids.pb(i);
		g[y].e.pb(x);
		g[y].w.pb(w);
		g[y].ids.pb(i);
	}
	shortesPaths();

	return 0;
}