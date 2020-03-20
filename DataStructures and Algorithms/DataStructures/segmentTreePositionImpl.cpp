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
 
const ll MAX = 300050; // limit for array size
ll n, N;
ll t[4 * MAX], arr[MAX];
ll mnRes[MAX];
 
ll build(ll l, ll r, ll nd){
    if(l > r) return INF;
    if(l == r) return t[nd] = arr[r];
    ll m = l + (r-l)/2;
    return t[nd] = min(build(l, m, 2*nd+1), build(m+1, r, 2*nd+2));
}
 
// [a, b]
ll qry(ll ql, ll qr, ll sl, ll sr, ll nd, ll tfnd){
    if(ql>sr||qr<sl) return INF; // no ovelap
    if(sl == sr) return (t[nd] < tfnd ?  sr : INF);
 
    ll m = sl + (sr-sl)/2;
    if(ql<=sl && qr>=sr){   // total ovelap
        if(t[2*nd+1] < tfnd) return qry(ql, qr, sl, m, 2*nd+1, tfnd);
        else if(t[2*nd+2] < tfnd) return qry(ql, qr, m+1, sr, 2*nd+2, tfnd);
        else return INF;
    }
    return min(qry(ql, qr, sl, m, 2*nd+1, tfnd), qry(ql, qr, m+1, sr, 2*nd+2, tfnd)); // partial ovelap
}
 
int main(){
    cin >> n;
    N = 3*n;
    FOR(i, 0, n){
        cin >> arr[i];  arr[i+2*n] = arr[i+n] = arr[i];
    }
    build(0, N-1, 0);
 
    ll mnReach = N;
    ROF(i, N-1, 0){
        ll nmbr = arr[i];
        ll tfnd = ceil((double)nmbr/2.0);
        ll opt = qry(i+1, N-1, 0, N-1, 0, tfnd);
        mnReach = mnRes[i] = min(mnReach, opt);
    }
 
    FOR(i, 0, n){
        ll dif = mnRes[i] - i; 
        if(dif < 2*n) cout << mnRes[i] - i << " ";
        else cout << -1 << " ";
    }
    return 0;
}