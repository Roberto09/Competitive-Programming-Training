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

ll t, n;

ll matr[12][12];
ll dp[12][12];

ll getDp(){
	FOR(i, 0, n){
		dp[n-1][i] = matr[n-1][i];
	}
	ROF(i, n-2, 0){
		FOR(j, 0, i+1){
			dp[i][j] = max(dp[i+1][j], dp[i+1][j+1]) + matr[i][j];
		}
	}
	return dp[0][0];
}

int main(){
	cin >> t;
	FOR(i, 0, t){
		cin >> n;
		FOR(j, 0, n){
			FOR(k, 0, j+1){
				cin >> matr[j][k];
			}
		}
		cout << getDp() << etr;
	}
	return 0;
}