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
ll nmbr;
ll dp[1005][1005];
string s1, s2;

ll getBestDp(ll s1i, ll s2i){
	if(s1i >= s1.length() || s2i >= s2.length()) return 0;
	if(dp[s1i][s2i] != -1) return dp[s1i][s2i];
	
	ll together, advances1, advances2;
	together = getBestDp(s1i+1, s2i + 1);
	advances1 =  getBestDp(s1i+1, s2i);
	advances2 =  getBestDp(s1i, s2i+1);
	if(s1[s1i] == s2[s2i]) together ++;
	ll res = max(together, max(advances1, advances2));
	return dp[s1i][s2i] = res;
}

int main(){
	cin >> nmbr;
	cin.ignore();
	FOR(i, 0, nmbr){
		getline(cin, s1);
		getline(cin, s2);
		mem(dp, -1);
		cout << "Case " << i+1 << ": " << getBestDp(0, 0) << etr;
	}
	return 0;
}