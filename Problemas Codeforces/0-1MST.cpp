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
#define oo 2000000000000000000LL
#define EPS 1e-6
#define MOD 1000000007
#define etr "\n"
#define INF 10E10
ll n, e;

unordered_map<ll, unordered_set<ll>> adj;
unordered_set<ll> nds;
bool vstd[100050];

void dfs(ll nd){
    vstd[nd] = true;
    vi canVisit;
    for(ll ng : nds){
        if(!adj[nd].count(ng)) canVisit.pb(ng);
    }
    for(ll ng : canVisit) nds.erase(ng);
    for(ll ng : canVisit) dfs(ng);
}

int main(){
    cin >> n;
    FOR(i, 0, n)
        nds.insert(i+1);
    
    cin >> e;
    FOR(i, 0, e){
        ll a, b;
        cin >> a >> b;
        adj[a].insert(b);
        adj[b].insert(a);
    }

    ll cnt = 0;
    vstd[1] = true;
    dfs(1);
    FOR(i, 1, n+1){
        if(vstd[i]) continue;
        nds.erase(i);
        cnt ++;
        dfs(i);
    }
    cout << cnt << etr;
    return 0;
}