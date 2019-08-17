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

/*map heap*/
struct Priority{
	vector<ii> heap;
	unordered_map<ll, ll> heapMap;
	bool order; //true -> max    false -> min

	void swap(ll pos1, ll pos2);
	bool compare(ll pos1, ll pos2);
	void popUp(ll pos);
	void popDown(ll pos);

	Priority(bool o);
	void push(ii p);
	void pop();
	ii top();
	bool empty();
	bool contains(ll numb);
	void changeValue(ll num, ll value);
	ll getValueOfNode(ll num);
};

Priority::Priority(bool o){
	heap.pb(mp(0, 0));
	order = o;
}

void Priority::swap(ll pos1, ll pos2){
	ii pair1 = heap[pos1], pair2 = heap[pos2];
	heapMap[pair1.first] = pos2;
	heapMap[pair2.first] = pos1;

	ii aux = heap[pos1];
	heap[pos1] = heap[pos2];
	heap[pos2] = aux;
}

bool Priority::compare(ll pos1, ll pos2){
	if(heap[pos1].second > heap[pos2].second)
		return order;
	return !order;
}

void Priority::popUp(ll pos){
	ll currPos = pos;
	ll posBefore;
	while(currPos > 1){
		posBefore = currPos/2;
		if(compare(currPos, posBefore)){
			swap(currPos, posBefore);
			currPos = posBefore;
		}
		else break;
	}
}

void Priority::popDown(ll pos){
	ll currPos = pos;
	ll right = pos*2, left = pos*2+1, posToChange;

	while(left < heap.size()){
		posToChange = (right >= heap.size() || compare(left, right)) ? left : right;
		if(compare(posToChange, currPos)){
			swap(currPos, posToChange);
			currPos = posToChange;
		}
		else break;
		left = currPos*2;
		right = currPos*2+1;
	}
}

void Priority::push(ii p){
	heapMap[p.first] = heap.size();
	heap.pb(p);
	popUp(heap.size() - 1);
}

void Priority::pop(){
	if(heap.size() == 1) return;
	swap(1, heap.size()-1);
	heapMap.erase(heap[heap.size() - 1].first);
	heap.pop_back();
	popDown(1);
}

ii Priority::top(){return heap[1];}

bool Priority::empty(){return heap.size() == 1;}

bool Priority::contains(ll num){return heapMap.count(num);}

void Priority::changeValue(ll num, ll value){
	ll pos = heapMap[num];
	ll prevValue = heap[pos].second;
	heap[pos].second = value;
	if(!(value > prevValue ^ order))
		popUp(pos);
	else
		popDown(pos);
}

ll Priority::getValueOfNode(ll num){
	ll pos = heapMap[num];
	return heap[pos].second;
}

/*
El algorimo de Dijstra sirve para encontrar la distancia mas corta desde un vertice V0 hasta cualquier
otro vertice del grafo V. Su complejidad puede variar, en algunas implementaciones es de O(VE) pero en
esta es de O((E+V)log(V))
*/

struct node{
	vector<ll> neig;
	vector<ll> weight;
};


void dijkstra(ll origins[], ll minDist[], Priority &pq, vector<node> &graph, ll source){
	//preparacion¿
	pq.push(mp(source, 0));
	FOR(i, 1, source) pq.push(mp(i, INF));
	FOR(i, source+1, graph.size()) pq.push(mp(i, INF));
	origins[source] = source;

	//se empieza una BFS
	ll curr;
	ii currNode;
	while(!pq.empty()){
		currNode = pq.top();
		pq.pop();
		curr = currNode.first;
		cout << "curr: " << curr << etr;
		minDist[curr] = currNode.second;
		FOR(i, 0, graph[curr].neig.size()){
			ll neig = graph[curr].neig[i];
			if(pq.contains(neig)){
				ll posVal = minDist[curr] + graph[curr].weight[i];
				if(posVal < pq.getValueOfNode(neig)){
					pq.changeValue(neig, posVal);
					origins[neig] = curr;
				}
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
	//se prepare disjktra
	ll origins[nodes+1]; //first comes from second
	ll minDist[nodes+1];
	Priority pq(false);

	dijkstra(origins, minDist, pq, graph, 1);

	cout << "Origins" << etr;
	FOR(i, 1, nodes+1){
		cout << i << " originates from: " << origins[i] << etr;
	}

	cout << "MinDist" << etr;
	FOR(i, 1, nodes+1){
		cout << i << " --- " << minDist[i] << etr;
	}

	return 0;
}
/*
6 7
1 2 5
2 3 2
3 4 3
4 6 2
6 5 3
5 1 2
1 4 9
*/