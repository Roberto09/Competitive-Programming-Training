#include <bits/stdc++.h>
using namespace std;

typedef int ll;
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
	vector<int> neig;
	int best[26];
	node(){best[26];}
};

ll n, m;
string s;

bool visited[300005];
bool recStack[300005];
node graph[300005];

bool checkCycle(int nde){
	node &curr = graph[nde];
	recStack[nde] = true;
	visited[nde] = true;
	int next;
	FOR(i, 0, curr.neig.size()){
		next = curr.neig[i];
		if(recStack[next] || next == nde) return true;
		else if(visited[next]) continue;
		else if(checkCycle(next)) return true;
	}

	recStack[nde] = false;
	return false;
}

void checkMax(int nde){
	node &actual = graph[nde];
	ll next;
	visited[nde] = true;
	FOR(i, 0, actual.neig.size()){
		next = actual.neig[i];
		if(!visited[next]){
			checkMax(next);
		}
		FOR(i, 0, 26){
			actual.best[i] = max(actual.best[i], graph[next].best[i]);
		}
	}
	actual.best[s[nde] - 'a'] ++;
}

int checMaxStart(int nde){
	checkMax(nde);
	int mx = 0;
	FOR(i, 0, 26){
		mx = max(mx, graph[nde].best[i]);
	}
	return mx;
}

int main(){
	sync;
	cin >> n >> m >> s;
	ll a, b;
	FOR(i, 0, m){
		cin >> a >> b;
		a --, b--;
		graph[a].neig.pb(b);
	}

	FOR(i, 0, n) mem(graph[i].best, 0);

	//check for cycle
	FOR(i, 0, n){
		if(!visited[i] && checkCycle(i)){
			cout << -1 << etr;
			return 0;
		}
	}
	FOR(i, 0, n) visited[i] = false;

	//check for max
	int mx = 0;
	FOR(i, 0, n){
		if(!visited[i]){
			mx = max(mx, checMaxStart(i));
		}
	}

	cout << mx << etr;

	return 0;
}
