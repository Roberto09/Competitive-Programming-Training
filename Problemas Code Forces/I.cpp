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
#define INF 1E15

ll n, m, q;

struct qry{
	ll a, b, k;
	ll i;
	qry(ll a, ll b, ll k, ll i){
		this->a = a;
		this->b = b;
		this->k = k;
		this->i = i;
	}
};


unordered_map<ll, ll> graph[500];
ii temp[500];
vector<qry> cold, hot;
ll flyd[500][500];
ll qRes[1000000];

void getResults(vector<qry> &qrs){
	FOR(i, 0, 405){
		FOR(j, 0, 405){
			if(i == j) flyd[i][j] = 0;
			else if(graph[i].count(j))
					flyd[i][j] = graph[i][j];
			else flyd[i][j] = INF;	
		}
	}
	ll lqIdx = 0;
	ll k = 1;
	FOR(i, 0, n){
		FOR(j, 0, n){
			FOR(w, 0, n){
				ll tent = flyd[j][temp[i].second] + flyd[temp[i].second][w];
				flyd[j][w] = min(flyd[j][w], tent);
			}
		}
		if(i != n-1 && temp[i].first == temp[i+1].first) continue;
		//process results
		while(lqIdx < qrs.size()){
			if(qrs[lqIdx].k <= k){
				qRes[qrs[lqIdx].i] = flyd[qrs[lqIdx].a][qrs[lqIdx].b];
				lqIdx ++;
			}
			else break;
		}
		k++;
	}

	while(lqIdx < qrs.size()){
		qRes[qrs[lqIdx].i] = flyd[qrs[lqIdx].a][qrs[lqIdx].b];
		lqIdx ++;
	}
}

int main(){
	sync;
	cin >> n >> m;
	FOR(i, 0, n){
		ll x;
		cin >> x;
		temp[i] = mp(x, i);
	}
	ll a, b, c, d;
	FOR(i ,0, m){
		cin >> a >> b >> c;
		a --; b--;
		graph[a][b] = c;
		graph[b][a] = c;
	}
	cin >> q;
	FOR(i, 0, q){
		cin >> a >> b >> c >> d;
		a--; b--;
		if(d == 1)
			hot.pb(qry(a, b, c, i));
		else
			cold.pb(qry(a, b, c, i));
	}


	FOR(i, 0, q) qRes[i] = INF;
	//sort temperatures in ascending order
	sort(temp, temp+n, [](auto &p1, auto &p2){
		return p1.first < p2.first;
	});
	//sort queries in ascending k
	sort(all(cold), [](qry &q1, qry &q2){
		return q1.k < q2.k;
	});
	getResults(cold);

	//sort temperatures in ascending order
	reverse(temp, temp+n);
	//sort queries in ascending k
	sort(all(hot), [](qry &q1, qry &q2){
		return q1.k < q2.k;
	});
	getResults(hot);


	FOR(i, 0, q){
		if(qRes[i] == INF) cout << -1 << etr;
		else cout << qRes[i] << etr;
	}

	return 0;
}