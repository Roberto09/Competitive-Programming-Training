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
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); //////cout.tie(NULL)
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
#define INF 1E18


ll SG[MAX];
ll Lazy[MAX];
ll arr[200020];

void build(ll indx, ll start, ll end){
	if(start == end){
		SG[indx] = arr[start-1];
	}else{
		ll mid = (start + end) / 2;
		build(indx * 2, start, mid);
		build(indx * 2 + 1, mid + 1, end);
		SG[indx] = min(SG[indx * 2], SG[indx * 2 + 1]);
	}
}

void Update(ll node, ll start, ll end, const ll& left, const ll& right, const ll& val){
	if(start > end) return;

	//Update the lazy propagation
	if(Lazy[node] != 0){
		SG[node] += Lazy[node];
		if(start != end){
			Lazy[node * 2] += Lazy[node];
			Lazy[node * 2 + 1] += Lazy[node];
		}
		Lazy[node] = 0;
	}

	//No contenida
	if(end < left || right < start){
		return;
	}

	//Completamente contenida
	if(left <= start && end <= right){
		SG[node] += val;
		if(start != end){
			Lazy[node * 2] += val;
			Lazy[node * 2 + 1] += val;
		}
		return;
	}

	//Parcialmente contenia
	ll mid = (start + end) / 2;
	Update(node * 2, start, mid, left, right, val);
	Update(node * 2 + 1, mid + 1, end, left, right, val);

	SG[node] = min(SG[node* 2], SG[node * 2 + 1]);
}

ll query(ll node, ll start, ll end, const ll& left, const ll& right){
	if(start > end) return INF;

	if(Lazy[node] != 0){
		SG[node] += Lazy[node];
		if(start != end){
			Lazy[node * 2] += Lazy[node];
			Lazy[node * 2 + 1] += Lazy[node];
		}
		Lazy[node] = 0;
	}

	//No contenida
	if(end < left || right < start) return INF;
	//Completamente contenida
	if(left <= start && end <= right) return SG[node];
	//Parcialmente contenida
	ll mid = (start + end) / 2;
	return min(query(node * 2, start, mid, left, right), query(node * 2 + 1, mid + 1, end, left, right));
}