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
#define INF 1E15
#define MAXN 200005

ll n;
ll arr[MAXN];
ll res[MAXN];


ll SG[4*MAXN];
ll Lazy[4*MAXN];

void pull(ll nd) {
	SG[nd] = min(SG[2 * nd + 1], SG[2 * nd + 2]);
}

void apply(ll nd, ll ndal) {
	SG[nd] += ndal;
	Lazy[nd] += ndal;
}

void push(ll nd) {
	if (Lazy[nd] != 0) {
		apply(2 * nd + 1, Lazy[nd]);
		apply(2 * nd + 2, Lazy[nd]);
		Lazy[nd] = 0;
	}
}

void build(ll nd, ll l, ll r) {
	if (l + 1 == r) {
		SG[nd] = arr[l];
	} else {
		ll m = (r + l) >> 1;
		build(2 * nd + 1, l, m);
		build(2 * nd + 2, m, r);
		pull(nd);
	}
}

void add(ll nd, ll l, ll r, ll ql, ll qr, ll ndal) {
	if (r <= ql || qr <= l) {
		return;
	} else if (ql <= l && r <= qr) {
		apply(nd, ndal);
	} else {
		push(nd);
		ll m = (r + l) >> 1;
		add(2 * nd + 1, l, m, ql, qr, ndal);
		add(2 * nd + 2, m, r, ql, qr, ndal);
		pull(nd);
	}
}

ll qry(ll nd, ll l, ll r) {
	if (l + 1 == r) {
		return l;
	} else {
		push(nd);
		ll m = (r + l) >> 1;
		ll res = -1;
		if (SG[2 * nd + 2] == 0) {
			res = qry(2 * nd + 2, m, r);
		} else {
			res = qry(2 * nd + 1, l, m);
		}
		pull(nd);
		return res;
	}
}

void init(int n_) {
	n = n_;
	build(0, 0, n);
}

void add(int l, int r, ll ndal) {
	add(0, 0, n, l, r, ndal);
}

void add(int pos, ll ndal) {
	add(0, 0, n, pos, pos + 1, ndal);
}

int main(){
	cin >> n;
	FOR(i, 0, n) cin >> arr[i];

	init(n);

	FOR(i, 1, n+1){
		ll pos = qry(0, 0, n);
		res[pos]=i;
		add(pos, INF);
		add(pos+1, n, -i);
	}
	FOR(i, 0, n) cout << res[i] << " ";
	return 0;
}