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
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); ////cout.tie(NULL)
#define PI 3.1415926535897932384626433832795
#define mem(x, val) memset((x), (val), sizeof(x))
#define sz(x) (ll)(x).size()
#define endl '\n'
#define clockon ll t = 1; while (t--) { clock_t z = clock();
#define clockoff debug("Elapsed Time: %.3f\n", (double)(clock() - z) / CLOCKS_PER_SEC); }
#define EPS 1e-6
#define MOD 1000000007
#define etr "\n"
#define INF 1E18
#define mx 100

ll n;
ii arr[mx];


struct DisjointSet{
    DisjointSet(ll n);
    ll find(ll node);
    bool merge(ll node1, ll node2);
    void print();

    ll size;
    ll nodes[mx];
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

void solve(){
    cin >> n;
    FOR(i, 0, n){
        ll a, b;
        cin >> a >> b;
        arr[i] = mp(a, b);
    }

    DisjointSet ds(n);

    sort(arr, arr+n, [](const auto &a, const auto &b){
        return a.first < b.first;
    });

    map<ll, ll> prev;
    ll e = 0;
    FOR(i, 0, n){
        ii o = arr[i];
        auto it = prev.lower_bound(o.first);
        for(; it != prev.end(); it ++){
            if(it->first < o.second){
                ll a = i, b = it->second;
                e++;
                if(!ds.merge(a, b)){
                    cout << "NO" << etr;
                    return;
                }
            }
            else break;
        }
        prev[o.second] = i;
    }

    if(e == n-1)
        cout << "YES" << etr;
    else cout << "NO" << etr;
}

int main(){
    //sync;
    ll t = 1;
    //cin >> t;
    FOR(i, 0, t) solve();
    return 0;
}