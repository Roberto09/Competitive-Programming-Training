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
#define INF 1E18
 
ll n, m, s;
 
ll res = 0;
 
vi graph[5010];
bool ireach[5010];
bool visited[5010];
unordered_map<ll, ll> cnt;
 
void mark(ll nde){
	if(ireach[nde]) return;
	ireach[nde]=true;
	for(ll neig : graph[nde])
		mark(neig);
}
 
void dfs(ll prnt, ll nde){
	if(ireach[nde] || visited[nde]) return;
	visited[nde] = true;
	cnt[prnt] ++;
	for(ll neig : graph[nde])
		dfs(prnt, neig);
}
 
int main(){
	cin >> n >> m >> s;
	s --;
	ll a, b;
	FOR(i, 0, m){
		cin >> a >> b;
		a--; b--;
		graph[a].pb(b);
	}
 
	mark(s);
	FOR(i, 0, n){
		dfs(i, i);
		mem(visited, false);
	}
 	vii sortedx;
		for(auto it = cnt.begin(); it != cnt.end(); it++)
			sortedx.pb(mp(it->second, it->first));
	sort(sortedx.begin(), sortedx.end(), greater<ii>());

	for(ii x : sortedx){
		if(!ireach[x.second]){
			mark(x.second);
			res ++;
		}
	}

	cout << res << etr;
 
	return 0;
}