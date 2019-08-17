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

struct DisjointSet{
	DisjointSet(ll n);
	ll find(ll node);
	bool merge(ll node1, ll node2);
	void initSet(ll node, ll value);
	void changePopulation(ll node, ll value);

	ll size;
	vector<ll> nodes;
	vector<ll> population;
	vector<ll> originalPop;
	ll maxPopulation;
	set<pair<long long, long long>, greater< pair<long long, long long> > >biggest;
};

DisjointSet::DisjointSet(ll n){
	size = n+1;
	originalPop.resize(n+1, 0);
	population.resize(n+1, 0);
	nodes.resize(n+1, -1);
	maxPopulation = 0;
}

void DisjointSet::initSet(ll node, ll value){
	population[node] = value;
	originalPop[node] = value;
	biggest.insert(mp(value, node));
	maxPopulation = biggest.begin()->first;
}

ll DisjointSet::find(ll node){
	ll parent = node;
	if(nodes[parent] < 0) return node;
	while(nodes[parent] > 0){
		parent = nodes[parent];
	}
	if(parent != nodes[node])
		nodes[node] = parent;
	return parent;
}

bool DisjointSet::merge(ll node1, ll node2){
	ll p1 = find(node1);
	ll p2 = find(node2);

	//no se realiza el merge ya que ambos estan ya en el mismo set
	if(p1 == p2) return false;

	ll r1 = nodes[p1];
	ll r2 = nodes[p2];

	//r1 tiene mejor rango
	if(r1 <= r2){
		nodes[p1] += nodes[p2];
		nodes[p2] = p1;
		biggest.erase(mp(population[p1], p1));
		biggest.erase(mp(population[p2], p2));
		biggest.insert(mp(population[p1] + population[p2], p1));
		population[p1] += population[p2];
	}
	else{
		nodes[p2] += nodes[p1];
		nodes[p1] = p2;
		biggest.erase(mp(population[p1], p1));
		biggest.erase(mp(population[p2], p2));
		biggest.insert(mp(population[p1] + population[p2], p2));
		population[p2] += population[p1];
	}
	maxPopulation = biggest.begin()->first;
	return true;
}

void DisjointSet::changePopulation(ll node, ll value){
	ll dif = value - originalPop[node];
	originalPop[node] = value;
	ll parent = find(node);

	biggest.erase(mp(population[parent], parent));
	biggest.insert(mp(population[parent] + dif, parent));

	population[parent] += dif;
	maxPopulation = biggest.begin()->first;
}

int main(){
	sync;
	ll cities, rds, qries;
	cin >> cities >> rds >> qries;

	ii roads[rds+1];
	pair<bool, ll> queries[qries+1];
	stack<ll> populations[cities+1];
	ll results[qries+1];
	bool deactivated[cities+1] = {false};

	//reading cities populations
	ll pop;
	FOR(i, 1, cities + 1){
		cin >> pop;
		populations[i].push(pop);
	}

	//reading roads
	FOR(i, 1, rds+1)
		cin >> roads[i].first >> roads[i].second;

	//reading queries
	char c;
	FOR(i, 1, qries+1){
		cin >> c;
		if(c == 'P'){
			queries[i].first = true;
			cin >> queries[i].second;
			cin >> pop;
			populations[queries[i].second].push(pop);
		}
		else{
			queries[i].first = false;
			cin >> queries[i].second;
			deactivated[queries[i].second] = true;
		}
	}

	DisjointSet ds(cities);

	//armar disjoint set
	FOR(i, 1, cities + 1){
		ds.initSet(i, populations[i].top());
	}

	FOR(i, 1, rds + 1){
		if(!deactivated[i]){
			ds.merge(roads[i].first, roads[i].second);
		}
	}

	//arreglar queries de reversa
	ROF(i, qries, 1){
		results[i] = ds.maxPopulation;
		if(queries[i].first){
			populations[queries[i].second].pop();
			ds.changePopulation(queries[i].second, populations[queries[i].second].top());
		}
		else{
			//create road back
			ds.merge(roads[queries[i].second].first, roads[queries[i].second].second);
		}
	}

	//print result
	FOR(i, 1, qries+1)
		cout << results[i] << etr;

	return 0;
}