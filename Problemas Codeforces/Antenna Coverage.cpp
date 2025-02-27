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

ii arr[100];
ll n, m;

ll dp[100050];

/*
3 595
43 2
300 4
554 10

*/


bool add(ll l, ll r, ll addr){
    if(r >= m && l < 0) return false;
    l = max(0ll, l);
    r = min(m-1, r);
    dp[r] = min(dp[r], addr + (l == 0 ? 0 : dp[l-1]));
    return true;
}

int main(){
    cin >> n >> m;
    FOR(i, 0, n) cin >> arr[i].first >> arr[i].second;
    FOR(i, 0, m) dp[i] = INF;
    sort(arr, arr+n);


    FOR(i, 0, n){
        ii pr = arr[i];
        ll p, s; p = pr.first-1, s = pr.second;

        ll l = p-s, r = p+s;

        ll cnt = 0;

        add(max(0ll, l), min(r, m-1), 0);
        while(add(l, r, cnt)){

            l--; r++; cnt ++;
        }


        ll mn = INF;
        ROF(i, m-1, 0){
            mn = min(mn, dp[i]);
            dp[i] = mn;
        }
    }
    cout << dp[m-1] << etr;

    return 0;
}