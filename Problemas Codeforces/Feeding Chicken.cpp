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

ll n, m, k;

char mtrx[150][150];

char currs = '0';

void upd(){
    if(k==0) return;
    if(currs == '9') currs = 'a'-1;
    else if(currs == 'z') currs = 'A'-1;
    currs ++;
    k--;
}

void solve(){
    currs = '0';
    cin >> n >> m >> k;
    ll r = 0;
    FOR(i,0 , n){
        FOR(j, 0, m){
            cin >> mtrx[i][j];
            if(mtrx[i][j] == 'R') r++;
        }
    }

    ll mnr = r/k;
    ll ben = r%k;
    
    bool cm = false;
    ll curr;
    curr = mnr + (ben ? 1 : 0);
    if(ben) ben--;
    k--;

    FOR(i, 0, n){
        FOR(j, 0, m){
            ll sj = j;
            if(cm) sj = m-1-j;
            if(mtrx[i][sj] == 'R'){
                mtrx[i][sj] = currs;
                curr--;
                if(curr == 0){
                    curr = mnr + (ben ? 1 : 0);
                    if(ben) ben--;
                    upd();
                }
            }
            else mtrx[i][sj] = currs;
        }
        cm = !cm;
    }

    FOR(i, 0, n){
        FOR(j, 0, m) cout << mtrx[i][j];
        cout << etr;
    }
}
 
int main(){
    sync;
    ll t;
    cin >> t;
    FOR(i, 0, t)
        solve();
    return 0;
}