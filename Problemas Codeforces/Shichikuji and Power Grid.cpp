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

struct DisjointSet{
    DisjointSet(ll n);
    ll find(ll node);
    bool merge(ll node1, ll node2);
    void print();

    ll size;
    ll nodes[2050];
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

ll n;

ii coord[2050];
ll cs[2050], ks[2050], mnn[2050];
bool ud[2050];
ii adj[2050][2050];
ll ttl = 0;

unordered_set<ll> pwr;
vii edgs;

ll getmn(ll a){
    return mnn[a];
}

void update(ll a, ll b, DisjointSet &ds){
    ii sub[n];
    ll btp = ds.find(b);
    ll mn;

    if(cs[getmn(a)] < cs[getmn(btp)]) mn = getmn(a), pwr.erase(getmn(btp));
    else mn = getmn(btp), pwr.erase(getmn(a));

    ttl -= max(cs[getmn(a)], cs[getmn(btp)]);
    
    FOR(i, 0, n) sub[i] = min(adj[a][i], adj[btp][i]);
    ds.merge(a, b);
    ll ntp = ds.find(a);
    FOR(i, 0, n) adj[ntp][i] = sub[i];
    mnn[ntp] = mn;
}

void solve(){
    DisjointSet ds(n);
    FOR(i, 0, n){
        ll tp = ds.find(i);
        if(ud[tp]) continue;
        while(true){
            tp = ds.find(i);
            ll mn = INF, nde, src;
            FOR(j, 0, n){
                ll opt = ds.find(j);
                if(opt == tp) continue;
                ll dst = adj[tp][j].first;
                if(dst < mn){
                    mn = dst; nde = j; src = adj[tp][j].second;
                }
            }
            if(mn < cs[getmn(tp)]){
                edgs.pb(mp(src+1, nde+1));
                ttl += mn;
                update(tp, nde, ds);
            } else{
                break;
            }
        }
        ud[tp] = true;
    }
    cout << ttl << etr;
    cout << pwr.size() << etr;
    for(ll i : pwr) cout << i+1 << " ";
    cout << etr;
    cout << edgs.size() << etr;
    for(ii e : edgs) cout << e.first << " " << e.second << etr;
}

int main(){
    cin >> n;
    FOR(i, 0, n) cin >> coord[i].first >> coord[i].second;

    FOR(i, 0, n){
        cin >> cs[i];
        ttl += cs[i];
        mnn[i] = i;
        pwr.insert(i);
    }
    FOR(i, 0, n) cin >> ks[i];

    FOR(i, 0, n){
        FOR(j, 0, n)
            adj[i][j].first = (abs(coord[i].first - coord[j].first) + abs(coord[i].second - coord[j].second))* (ks[i] + ks[j]), adj[i][j].second = i;
    }

    solve();

    return 0;
}