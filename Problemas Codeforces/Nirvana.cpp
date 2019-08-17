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

string s;

ll dp[15][2];

ll getBest(bool fluct, ll idx){
	if(idx == s.length()) return 1;
	ll nmbr = s[idx] - '0';
	if(fluct){
		if(dp[idx][0] != -1) return dp[idx][0];
		return dp[idx][0] = 9 * getBest(fluct, idx + 1);
	}
	else{
		if(dp[idx][1] != -1) return dp[idx][1];
		return dp[idx][1] = max(nmbr * getBest(false, idx + 1), max(nmbr - 1, (ll) 1) * getBest(true, idx + 1));
	}
}


int main(){
	cin >> s;
	mem(dp, -1);
	cout << getBest(false, 0) << etr;
	return 0;
}