#include <iostream>
#include <vector>
#include <queue>
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
#define INF 10E10

ll k, n, m;

struct node{
	bool isLead;
	bool isVisited;
	vi sons;
	vi vals;
	ll sumRes;
	node(){
		isLead = false;
		isVisited = false;
		sumRes = 0;
	}
};

class comp
{
public:
    bool operator() (const pair<ll, ll> &n1, const pair<ll, ll> &n2)
    {
        if(n1.first == n2.first){
        	return n1.second > n2.second;
        }
        return n1.first < n2.first;
    }
};

node graph[100000];

ll getRes(ll curr){
	node &nde = graph[curr];
	if(nde.isVisited) return nde.sumRes;
	FOR(i, 0, nde.sons.size()){
		nde.sumRes += nde.vals[i] + getRes(nde.sons[i]);
	}
	nde.isVisited = true;
	return nde.sumRes;
}

int main(){
	cin >> k >> n >> m;
	ll x;
	FOR(i, 0, n){
		cin >> x; x--;
		graph[x].isLead = true;
	}

	ll j, e, v;
	FOR(i, 0, m){
		cin >> j >> e >> v;
		j --; e --;
		graph[j].sons.pb(e);
		graph[j].vals.pb(v);
	}

	priority_queue<ii, vii, comp> pq;
	FOR(i, 0, k){
		if(!graph[i].isVisited) getRes(i);
		if(graph[i].isLead) pq.push(mp(graph[i].sumRes, i+1));
	}

	while(!pq.empty()){
		cout << pq.top().second << " " << pq.top().first << etr;
		pq.pop();
	}


	return 0;
}