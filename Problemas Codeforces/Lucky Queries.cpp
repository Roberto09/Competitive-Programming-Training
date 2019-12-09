#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

#define FOR(i, a, b) for(ll i=ll(a); i<ll(b); i++)
#define ROF(i, a, b) for(ll i=ll(a); i>=ll(b); i--)
#define pb push_back
#define mp make_pair
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); //cout.tie(NULL)
#define mem(x, val) memset((x), (val), sizeof(x))
#define MOD 1000000007
#define etr "\n"
#define INF 10E10
const ll MAX = 1000050;

struct Node{
    ll inc, x4s, x7s, dec;
    Node(ll i, ll x, ll y, ll dec) : inc(i), x4s(x), x7s(y), dec(dec){}
    Node(){}
};

ll arr[MAX];
Node t[MAX*4];
bool lzy[MAX*4];
ll n, m;

Node merge(ll nde){
    Node &l = t[2*nde+1], &r = t[2*nde+2];
    return Node(max(l.x4s + r.inc, l.inc + r.x7s), l.x4s + r.x4s, l.x7s + r.x7s, max(l.x7s + r.dec, l.dec + r.x4s));
}
void inv(ll nde){
    t[nde] = Node(t[nde].dec, t[nde].x7s, t[nde].x4s, t[nde].inc);
}

void push(ll nde, bool u){ // update lazy
    if(!lzy[nde]) return;
    inv(nde);
    if(u){
        lzy[nde] = false; return;
    }
    lzy[2*nde+1] ^= lzy[nde];
    lzy[2*nde+2] ^= lzy[nde];
    lzy[nde] = false;
}

void build(ll l, ll r, ll nde){
    if(l == r){
        t[nde] = Node(1, (arr[r] ? 0 : 1), (arr[r] ? 1 : 0), 1);
        return;
    }
    ll m = l + (r-l)/2;
    build(l, m, 2*nde+1), build(m+1, r, 2*nde+2);
    t[nde] = merge(nde);
}

void rupdate(ll l, ll r, ll ql, ll qr, ll nde){ // range update (adition)
    if(l > r) return;
    push(nde, l==r);
    if(ql > r || qr < l) return; // no ovelap
    if(ql <= l && qr >= r){ // total overlap
        lzy[nde] ^= true; push(nde, l == r);
        return;
    }
    ll m = l + (r-l)/2;
    rupdate(l, m, ql, qr, 2*nde+1); rupdate(m+1, r, ql, qr, 2*nde+2);
    t[nde] = merge(nde); // partial ovelap
}

ll query(){
    push(0, 0 == n-1);
    return t[0].inc;
}
void update(ll ql, ll qr){
    rupdate(0, n-1, ql, qr, 0);
}

int main(){
	sync;
    cin >> n >> m;
    string s;
    cin >> s;
    FOR(i, 0, n){
        if(s[i] =='4') arr[i] = 0;
        else arr[i] = 1;
    }

    build(0, n-1, 0);

    FOR(i, 0, m){
        cin >> s;
        if(s[0] == 'c'){
            cout << query() << etr;
        }
        else{
            ll a, b;
            cin >> a >> b;
            a--; b--;
            update(a, b);
        }
    	
    }

    return 0;
}

