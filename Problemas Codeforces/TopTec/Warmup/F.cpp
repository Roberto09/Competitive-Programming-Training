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
#define INF 10E10

ll Time[1000010];
ii entrances[200010];
int main(){
	sync;
	ll e, q, w; cin >> e >> q >> w;
	FOR(i, 0, e){
		cin >> entrances[i].second;
		entrances[i].first = i;
		cin >> entrances[e+i].second;
		entrances[e+i].first = i;
		entrances[e+i].second++;
	}

	sort(entrances, entrances+2*e, [](const ii &p1, const ii &p2){
		return p1.second < p2.second;
	});

	//FOR(i, 0, e*2) //cout << entrances[i].first << " " << entrances[i].second << etr;
	unordered_set<ll> curr;
	ll start = 0;
	FOR(i, 0, w){
		FOR(j, start, 2*e){
			start = j;
			if(entrances[j].second != i) break;
			if(curr.count(entrances[j].first)) curr.erase(entrances[j].first);
			else curr.insert(entrances[j].first);
		}
		Time[i] = curr.size();
	}
	//cout << start << etr;
	ll actualQ;
	//cout << "res" << etr;
	FOR(i, 0, q){
		cin >> actualQ;
		cout << Time[actualQ] << etr;
	}
	return 0;
}
