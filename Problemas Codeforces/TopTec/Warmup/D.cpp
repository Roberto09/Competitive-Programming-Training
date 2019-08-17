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

ll arr[100010];
ll dp[100010];
ll t, n;

void doAlg(){
	cin >> n;
	FOR(i, 0, n){
		cin >> arr[i];
		dp[i] = 0;
	}
	FOR(i, n, n+5) dp[i] = 0;

	ll sum = 0;	
	if(n <= 3){
		FOR(i, 0, n) sum+= arr[i];
		cout << sum << etr;
		return;
	}

	dp[n-1] = arr[n-1];
	dp[n-2] = dp[n-1] + arr[n-2];
	dp[n-3] = dp[n-2] + arr[n-3];
	ll o1, o2, o3;
	ROF(i, n-4, 0){
		//opcion 1
		o1 = arr[i] + dp[i+2];
		//opcion 2
		o2 = arr[i] + arr[i+1] + dp[i+4];
		//opcion 3
		o3 = arr[i] + arr[i+1] + arr[i+2] + dp[i+6];
		dp[i] = max(o1, max(o2, o3));
	}
	cout << dp[0] << etr;
}

int main(){
	sync;
	cin >> t;
	FOR(i, 0, t){
		doAlg();
	}
	return 0;
}