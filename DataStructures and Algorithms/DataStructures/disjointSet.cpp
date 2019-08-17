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
	void print();

	ll size;
	ll nodes[10000];
};

DisjointSet::DisjointSet(ll n){
	size = n;
	fill(nodes, nodes+n, -1);
}


ll DisjointSet::find(ll node){
	if(nodes[node] < 0) return node;
	nodes[node] = find(nodes[node]);
	return nodes[node];
}

bool DisjointSet::merge(ll node1, ll node2){
	ll p1 = find(node1);
	ll p2 = find(node2);

	if(p1 == p2) return false;

	ll r1 = nodes[p1];
	ll r2 = nodes[p2];

	//r1 tiene mejor rango
	if(r1 <= r2){
		nodes[p1] += nodes[p2];
		nodes[p2] = p1;
	}
	else{
		nodes[p2] += nodes[p1];
		nodes[p1] = p2;
	}

	return true;
}

void DisjointSet::print(){
	FOR(i, 0, size){
		cout << i << ": " << nodes[i] << "   ";
	}
	cout << etr;
}

int main(){
	DisjointSet ds(10);

	ll op;
	while(true){
		cout << "operacion:  1- unir   2 -- encontrar" << etr;
		cin >> op;
		if(op == 1){
			ll n1, n2;
			cin >> n1 >> n2;
			ds.merge(n1, n2);
		}
		else{
			ll n1;
			cin >> n1;
			cout << ds.find(n1);;
		}
		cout << etr;
		ds.print();
	}

	ds.print();
	return 0;
}