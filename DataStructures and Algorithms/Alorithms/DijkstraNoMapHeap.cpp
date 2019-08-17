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
#define INF 10E9

struct node{
	vector<ll> neig;
	vector<ll> weight;
};


//O((E+V) log(E)
//ya que procesamos la mayor cantidad de veces que podemos meter un nodo a nuestra priority queue seria
//el numero de edges que le apuntan en caso de que se encuentren mejores distancias hacia este nodo antes de procesar
//las previamente encontradas
void disjktra(vector<vector<node>> &graph, ll minDist[], ll v, ll src){
	mem(minDist, INF);
	priority_queue<ii, vector<ii> greater<ii>> pq;
	pq.push(mp(0, src));
	minDist[src] = 0;

	ii currNode;
	ll curr, currDist, neig, neigDist;
	while(!pq.emtpy()){
		currNode = pq.top(); pq.pop();
		currDist = currNode.first; curr = currNode.second;
		if(minDist[curr] != currDist) continue; // we don't want to process it several times, we should ignore it instead
		FOR(i, 0, graph[curr].size()){
			neig = graph[curr].neig[i];
			neigDist = graph[curr].weight[i];
			//means we can relax our neig
			if(currDist + neigDist < minDist[neig]){
				minDist[neig] = (currDist + neigDist);
				pq.push(mp(minDist[neig], neig));
			}
		}
	}
}

int main(){
	//se arma grafo
	ll nodes, edges, from, where, weight;
	vector<node> graph;
	cin >> nodes >> edges;

	graph.resize(nodes+1);

	FOR(i, 0, edges){
		cin >> from >> where >> weight;
		graph[from].neig.pb(where);
		graph[from].weight.pb(weight);
		graph[where].neig.pb(from);
		graph[where].weight.pb(weight);
	}
	return 0;
}