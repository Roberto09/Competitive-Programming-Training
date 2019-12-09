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
#define INF 1E18
ll n;

unordered_set<ll> pf;

void pfc(ll n){
    while (n % 2 == 0){  
        pf.insert(2);
        n = n/2;  
    }
    for (int i = 3; i <= sqrt(n); i = i + 2)  {  
        while (n % i == 0)  {  
            pf.insert(i); 
            n = n/i;  
        }  
    }
    if (n > 2)  
        pf.insert(n);

}
vi pos;


ll calc(ll k){
    ll lst = 0;
    ll res = 0;
    while(lst < pos.size()){
        FOR(i, 0, k){
            res += abs(pos[lst+i] - pos[lst+k/2]);
        }
        lst += k;
    }
    return res;
}


int main(){
    sync;
    cin >> n;
    ll ttl = 0;
    FOR(i, 0, n){
        ll a;
        cin >> a;
        if(a) ttl ++, pos.pb(i);
    }
    if(ttl == 1){
        cout << -1 << etr;
        return 0;
    }
    pfc(ttl);

    ll res = INF;
    for(ll i : pf){
        res = min(res, calc(i));
    }

    cout << res << etr;

    return 0;
}