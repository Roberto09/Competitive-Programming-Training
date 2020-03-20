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

const ll MAX = 100000;

ll arr[MAX];
ll t[MAX*4];
ll lzy[MAX*4];

void push(ll nde, bool u){ // update lazy
    t[nde] += lzy[nde];
    if(u){
        lzy[nde] = 0; return;
    }
    lzy[2*nde+1] += lzy[nde];
    lzy[2*nde+2] += lzy[nde];
    lzy[nde] = 0;
}

ll build(ll l, ll r, ll nde){
    if(l == r) return t[nde] = arr[r];
    ll m = l + (r-l)/2;
    return t[nde] = min(build(l, m, 2*nde+1), build(m+1, r, 2*nde+2));
}

ll query(ll l, ll r, ll ql, ll qr, ll nde){
    if(l > r) return INF;
    push(nde, l==r);
    if(ql > r || qr < l) return INF; // no ovelap
    if(ql <= l && qr >= r) // total overlap
        return t[nde];
    ll m = l + (r-l)/2;
    return min(query(l, m, ql, qr, 2*nde+1), query(m+1, r, ql, qr, 2*nde+2)); // partial ovelap
}

void rupdate(ll l, ll r, ll ql, ll qr, ll vl, ll nde){ // range update (adition)
    if(l > r) return;
    push(nde, l==r);
    if(ql > r || qr < l) return; // no ovelap
    if(ql <= l && qr >= r){ // total overlap
        lzy[nde] += vl; push(nde, l == r);
        return;
    }
    ll m = l + (r-l)/2;
    rupdate(l, m, ql, qr, vl, 2*nde+1); rupdate(m+1, r, ql, qr, vl, 2*nde+2);
    t[nde] = min(t[2*nde+1], t[2*nde+2]); // partial ovelap
}

int main(){
    ll n;
    cin >> n;
    FOR(i, 0, n) cin >> arr[i];

    build(0, n-1, 0);

    rupdate(0, n-1, 1, n-1, 40, 0);
    //test
    while(true){
        ll a, b;
        cin >> a >> b;
        cout << query(0, n-1, a, b, 0) << etr;
    }

    return 0;
}

