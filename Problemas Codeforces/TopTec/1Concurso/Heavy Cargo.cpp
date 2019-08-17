#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

typedef long long ll;

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
	bool visited;
	ll max;
	vector<string> neig;
	vector<ll> weight;
	node(){}
};

class Compare
{
public:
    bool operator() (const pair<string, ll> &a, const pair<string, ll> &b)
    {
        return a.second < b.second;
    }
};

ll alg(string start, string end, map<string, node> &graph){
	priority_queue<pair<string, ll>, vector<pair<string, ll>>, Compare> order;
	order.push(mp(start, INF));
	
	string actual;
	ll weight;
	while(!order.empty()){
		actual = order.top().first;
		weight = order.top().second;
		order.pop();
		if(actual == end){
			return weight;
		}
		if(graph[actual].visited) continue;
		graph[actual].visited = true;

		ll best;
		string next;
		FOR(i, 0, graph[actual].neig.size()){
			next = graph[actual].neig[i];
			best = min(weight, graph[actual].weight[i]);
			//check if we can relax
			if(best > graph[next].max){
				order.push(mp(next, best));
				graph[next].max = best;
			}
		}
	}
	return 0;
}

int main(){
	ll n, r;
	ll idx = 1;
	while(true){
		cin >> n >> r;
		if(n == 0 && r == 0) break;
		map<string, node> graph;
		string a,b;
		ll x;
		FOR(i, 0, r){
			cin >> a >> b >> x;
			if(!graph.count(a)) graph[a] = node();
			graph[a].neig.pb(b);
			graph[a].weight.pb(x);
			graph[a].visited = false;
			graph[a].max = -1;

			if(!graph.count(b)) graph[b] = node();
			graph[b].neig.pb(a);
			graph[b].weight.pb(x);
			graph[b].visited = false;
			graph[b].max = -1;
		}
		cin >> a >> b;
		cout << "Scenario #" << idx << etr;
		cout << alg(a, b, graph) << " tons" << etr << etr;
		idx ++;
	}
	return 0;
}
