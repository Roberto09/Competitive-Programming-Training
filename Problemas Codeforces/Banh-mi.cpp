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
#define INF 1E9

ll makeCalculation(ll EXP[], ll dp[], ll l, ll r){
	l--; r--;
	ll ones = dp[r] - ( l == 0 ? 0 : dp[l-1]);
	ll ceros = (r - l + 1) - ones;
	if(ones == 0) return 0;
	//formula
	return (EXP[ones] - 1 + ((EXP[ones] - 1) * (EXP[ceros] - 1)) % MOD) % MOD;
}


int main(){
	sync;
	ll n, q;
	cin >> n >> q;
	ll arr[n+1];
	ll dp[n];
	string s;
	cin >> s;

	arr[0] = 1;

	FOR(i, 1, n+1){
		arr[i] = (arr[i-1] * 2) % MOD;
	}

	dp[0] = s[0] == '1' ? 1 : 0;
	FOR(i, 1, n){
		if(s[i] == '1'){
			dp[i] = dp[i-1] + 1;
		}
		else{
			dp[i] = dp[i-1];
		}
	}

	ll l, r;
	FOR(i, 0, q){
		cin >> l >> r;
		cout << makeCalculation(arr, dp, l, r) << etr;
	}


	return 0;
}