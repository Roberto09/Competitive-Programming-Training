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
#define INF 10E10

ll n;
struct Node{
	bool flag;
	ll parent;
	vi sons;
	ll isViable;
};

vector<Node> tree;
priority_queue<ll, vi, greater<ll>> rem;

bool calculate(ll node){
	Node &curr = tree[node];
	bool is = true;

	FOR(i, 0, curr.sons.size()){
		is = is & calculate(curr.sons[i]);
	}
	if(curr.flag && is) rem.push(node);
	return curr.flag;
}

int main(){
	cin >> n;
	ll a, b;
	tree.resize(n);
	ll prnt;
	FOR(i, 0, n){
		cin >> a >> b;
		if(a == -1) prnt = i;
		a --;
		tree[i].parent = a;
		if(b == 1) tree[i].flag = true;
		else tree[i].flag = false;
		if(a == -2) continue;
		tree[a].sons.pb(i);
	}
	calculate(prnt);

	if(rem.empty()) cout << -1 << etr;
	else{
		while(!rem.empty()){
			cout << rem.top() + 1 << " ";
			rem.pop();
		}
		cout << etr;
	}
	return 0;
}