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
vector<vi> centroids;
vector<char> res;
vector<bool> visited;
 
//  finds centroid of a single tree, O(n)
ll findSingleCentroid(ll nde){
	FOR(i, 0, tree[nde].neig.size()){
		ll curr = tree[nde].neig[i];
		if(visited[curr]) continue;
		if(tree[curr].wght > tree[nde].wght / 2){
			ll newWght = tree[nde].wght;
			tree[nde].wght = newWght - tree[curr].wght;
			tree[curr].wght = newWght;
			return findSingleCentroid(curr);
		}
	}
	return nde;
}
 
// finds all the centroids of a tree, O(n log(n)) at worst case
ll findAllCentroids(ll nde){
	ll currCentroid = findSingleCentroid(nde);
	visited[currCentroid] = true;
	FOR(i, 0, tree[currCentroid].neig.size()){
		ll curr = tree[currCentroid].neig[i];
		if(visited[curr]) continue;
		centroids[currCentroid].pb(findAllCentroids(curr));
	}
	return currCentroid;
}
 
// precalculates weights, O(n)
ll precalcWghts(ll nde, ll prnt){
	ll sum = 0;
	FOR(i, 0, tree[nde].neig.size()){
		ll curr = tree[nde].neig[i];
		if(curr == prnt) continue;
		sum += precalcWghts(curr, nde);
	}
	return tree[nde].wght = sum + 1;
}
 
void BFS(ll nde, ll prnt, char lttr){
	res[nde] = lttr;
	FOR(i, 0, centroids[nde].size()){
		ll curr = centroids[nde][i];
		if(curr == prnt) continue;
		BFS(curr, nde, lttr+1);
	}
}
 
int main(){
	sync;
	cin >> n;
 
	tree.resize(n);
	centroids.resize(n);
	visited.resize(n, false);
	res.resize(n);
 
	FOR(i, 0, n-1){
		ll a, b;
		cin >> a >> b;
		a --; b --;
		tree[a].neig.pb(b);
		tree[b].neig.pb(a);
	}
	precalcWghts(0, -1);
	ll superCentroid = findAllCentroids(0);
 
	BFS(superCentroid, -1, 'A');
	FOR(i,0, n) cout << res[i] << etr;
	return 0;
}