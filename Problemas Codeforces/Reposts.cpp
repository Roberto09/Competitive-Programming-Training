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
#define INF 1E9

struct node{
	vector<string> sons;
	ll maxDist;
};

unordered_map<string, node> nodes;

ll getBest(string s){
	if(!nodes.count(s))
		return 0;
	node &actual = nodes[s];
	if(actual.maxDist != -1) return actual.maxDist + 1;

	ll maxDist = -1;
	FOR(i, 0, actual.sons.size()){
		maxDist = max(maxDist, getBest(actual.sons[i]));
	}
	actual.maxDist = maxDist;
	return actual.maxDist + 1;
}

int main(){
	sync;
	ll n;
	cin >> n;
	string s1, s2, nll;
	FOR(i, 0, n){
		cin >> s1 >> nll >> s2;
		transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
		transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
		if(!nodes.count(s2))
			nodes[s2] = node();
		nodes[s2].sons.pb(s1);
		nodes[s2].maxDist = -1;
	}
	cout << getBest("polycarp") + 1 << etr;
	return 0;
}