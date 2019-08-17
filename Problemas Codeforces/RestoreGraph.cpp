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

/*

3 2
0 1 1

*/

ll v, k;
int main(){
	cin >> v >> k;
	unordered_map<ll, vi> edgeCnt;
	ll x;
	ll highest = 0;
	FOR(i, 1, v+1){
		cin >> x;
		edgeCnt[x].pb(i);
		highest = max(x, highest);
	}
	if(!edgeCnt.count(0) || edgeCnt[0].size() != 1){
		cout << -1 << etr;
		return 0;
	}

	vii res;
	bool can = true;
	ll kk = k+1;
	FOR(i, 1, highest+1){			
		if(!edgeCnt.count(i)){
			can = false; break;
		}
		vi &prev = edgeCnt[i-1];
		vi &act = edgeCnt[i];
		ll currP = 0, currK = 1;
		FOR(j, 0, act.size()){
			if(currK == kk){
				currP ++;
				currK = 1;
			}
			if(currP >= prev.size()){
				can = false; break;
			}
			ll actV = act[j];
			res.pb(mp(actV, prev[currP]));
			currK++;
		}
		if(!can) break;
		kk = k;
	}
	if(can){
		cout << res.size() << etr;
		FOR(i, 0, res.size()) cout << res[i].first << " " << res[i].second << etr;
	}
	else cout << -1 << etr;

	return 0;
}