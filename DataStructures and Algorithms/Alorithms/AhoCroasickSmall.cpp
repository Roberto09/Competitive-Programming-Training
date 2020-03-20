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
#define INF 1E15

#define SZ 100500
#define AP 58

ll n;

ll trie[SZ][AP];
ll suffl[SZ];
vi strEIds[SZ]; // this can be a vector as well
ll sz[SZ];

vector<string> strs;
vi ids;

ll solve(string &s){
	ll tsz = 1;
	// add strings
	vi pts(strs.size());
	for(ll lb = 0, i = 0; i < strs.size(); lb++){
		while(i < strs.size() && strs[ids[i]].length() <= lb) i++;
		FOR(j, i, strs.size()){
			ll &nv = trie[pts[j]][strs[ids[j]][lb] - 'A'];
			if(!nv) nv = tsz++;
			pts[j] = nv;
			if(strs[ids[j]].size()-1 == lb) strEIds[nv].pb(ids[j]); // setting up string ids
		}
	}

	// adding suffix links
	FOR(i, 1, tsz){
		FOR(j, 0, AP){
			if(trie[i][j]) suffl[trie[i][j]] = trie[suffl[i]][j];
			else trie[i][j] = trie[suffl[i]][j];
		}
	}

	// adding ending stuff
	for(auto e : pts) sz[e]++;
	FOR(i, 1, tsz) sz[i] += sz[suffl[i]];
	
	// calculating result
	vi ress(strs.size(), 0);
	ll res = 0;
	ll state = 0;
	for(auto c : s){
		state = trie[state][c-'A'];
		// identifying ids of strings that already appeared
		ll substate = state;
		while(sz[substate]){
			for(auto e : strEIds[substate]) ress[e] ++;
			substate = suffl[substate];
		}
		res += sz[state];
	}
	//FOR(i, 0, strs.size()) cout << (ress[i] > 0 ? 'y' : 'n') << etr;
	FOR(i, 0, tsz) mem(trie[i], ll(0)), strEIds[i].clear(), suffl[i] = sz[i] = 0;
	strs.clear(); ids.clear();
	return res;
}

int main(){
	// read strings
	cin >> n;
	FOR(i, 0, n)
		ids.pb(i), strs.pb(""), cin >> strs[i];

	// sort string ids
	sort(ids.begin(), ids.end(), [&](ll &i1, ll &i2){
		return strs[i1].length() < strs[i2].length();
	});

	string s;
	cin >> s;
	cout << solve(s) << etr;
	return 0;
}
