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

unordered_set<ll> vPoints;
ll n, m, k, s, t;

struct Node{
	ll steps;
	ll nmbr;
	Node(){}
	Node(ll st, ll nm){
		steps = st;
		nmbr = nm;
	}
};

bool bfs(ll maxLen, vector<vi> &graph){
	queue<Node> q;
	bool visited[n];
	bool superVisited[n];
	ll bests[n];
	mem(bests, n+1);
	mem(visited, false);
	mem(superVisited, false);
	visited[s] = true;
	q.push(Node(0, s));
	Node curr;
	ll next;
	while(!q.empty()){
		curr = q.front(); q.pop();
		superVisited[curr.nmbr] = true;
		if(curr.nmbr == t) return true;
		ll stps = (vPoints.count(curr.nmbr) ? 0 : bests[curr.nmbr]);
		if(stps < maxLen){
			FOR(i, 0, graph[curr.nmbr].size()){
 				next = graph[curr.nmbr][i];
 				if(!visited[next]){
 					visited[next] = true;
 					q.push(Node(stps+1, next));
 					bests[next] = stps+1;
 				}
 				else if(stps+1 < bests[next]){
 					if(superVisited[next]) q.push(Node(stps+1, next));
 					bests[next] = stps+1;
 				}
 			}
		}
	}
	return false;
}

int main(){
	sync;
	cin >> n >> m >> k;
	vector<vi> graph(n);
	ll x;
	FOR(i, 0, k){
		cin >> x;
		vPoints.insert(x-1);
	}
	ll a, b;
	FOR(i, 0, m){
		cin >> a >> b;
		a--; b--;
		graph[a].pb(b);
		graph[b].pb(a);
	}
	cin >> s >> t;
	s --;
	t--;
	ll l = 0, r = n-1, m = 0;
	ll best = -1;
	while(l <= r){
		m = l + (r-l)/2;
		if(bfs(m, graph)){
			best = m;
			r = m - 1;
		}
		else l = m + 1;
	}
	cout << best << etr;
	return 0;
}