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

ll c, u, d, t, n;
ll arr[1000000];


void strt(bool turn){
    ll xc = c, xu = u;
    ll curr = 0;
    while(1){
        if(xc == 0 && xu == 0) break;
        if(turn && xc){
            xc --;
            arr[curr] = 0;
        }
        else if(!turn && xu){
            xu --;
            arr[curr] = 1;
        }
        curr ++;
        turn = !turn;
    }
}

void end(bool turn){
    ll xd = d, xt = t;
    ll curr = n-1;
    while(curr >= 0){
        if(xd == 0 && xt == 0) break;
        if(turn && xd){
            xd --;
            arr[curr] = 2;
        }
        else if(!turn && xt){
            xt --;
            arr[curr] = 3;
        }
        curr --;
        turn = !turn;
    }
}


bool verify(){
    ll p = arr[0];
    FOR(i, 1, n){
        if(abs(arr[i]-p) != 1) return false;
        p = arr[i];
    }
    return true;
}

void solve(){
    cin >> c >> u >> d >> t;
    n = c + u + d + t;

    if(n == 1){
        cout << "YES" << etr;
        if(c) cout << 0 << etr;
        else if(u) cout << 1 << etr;
        else if(d) cout << 2 << etr;
        else cout << 3 << etr;
        return;
    }

    FOR(b, 0, 4){
        FOR(i, 0, n) arr[i] = -10;

        strt(b&1);
        end(b&2);

        if(verify()){
            cout << "YES" << etr;
            FOR(i, 0, n){
                cout << arr[i] << " ";
            }
            return;
        }
    }

    cout <<"NO" << etr;
}



int main(){
    sync;
    ll t = 1;
    FOR(i, 0, t) solve();
    return 0;
}