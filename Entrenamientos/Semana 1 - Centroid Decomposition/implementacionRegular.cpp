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
#define INF 1E10

ll n, m, x;

struct node{
	vi neig;
	ll wght;
};

vector<node> tree;
vector<bool> visited;

ll precalcWghts(ll nde, ll prnt){
	tree[nde].wght = 1;
	FOR(i, 0, tree[nde].neig.size()){
		ll curr = tree[nde].neig[i];
		if(curr == prnt || visited[curr]) continue;
		tree[nde].wght += precalcWghts(curr, nde);
	}
	return tree[nde].wght;
}

//  finds centroid of a single tree, O(n)
ll findSingleCentroid(ll nde, ll prnt, ll ttlw){
	FOR(i, 0, tree[nde].neig.size()){
		ll curr = tree[nde].neig[i];
		if(visited[curr] || curr == prnt) continue;
		if(tree[curr].wght > ttlw / 2){
			return findSingleCentroid(curr, nde, ttlw);
		}
	}
	return nde;
}

// finds all the centroids of a tree, O(n log(n)) at worst case
ll findAllCentroids(ll nde){
	precalcWghts(nde, -1);
	ll currCentroid = findSingleCentroid(nde, -1, tree[nde].wght);
	visited[currCentroid] = true;

	FOR(i, 0, tree[currCentroid].neig.size()){
		ll curr = tree[currCentroid].neig[i];
		if(visited[curr]) continue;
		findAllCentroids(curr);
	}
	return currCentroid;
}

int main(){
	sync;
	cin >> n;
	tree.resize(n);
	visited.resize(n, false);

	FOR(i, 0, n-1){
		ll a, b;
		cin >> a >> b;
		tree[a].neig.pb(b);
		tree[b].neig.pb(a);
	}
	
	ll superCentroid = findAllCentroids(0);
	cout << superCentroid << etr;
	return 0;
}