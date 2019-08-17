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
#define INF 1E9 + 1;

int main(){
	sync;
	ll t;
	cin >> t;
	string s;

	ll count[26];

	FOR(i, 0, t){
		fill(count, count+26, 0);
		cin >> s;
		bool canBeDone = true;
		FOR(c, 0, s.length()){
			count[s[c] - 'a'] ++;
		}
		if(count[s[0] -'a'] == s.length()){
			canBeDone = false;
		}
		if(!canBeDone){
			cout << -1 << etr;
			continue;
		}
		s = "";
		FOR(c, 0, 26){
			FOR(j, 0, count[c]){
				s+= (char)('a' + c);
			}
		}
		cout << s << etr;
	}
	return 0;
}