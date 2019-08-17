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

int main(){
	string s1, s2;
	cin >> s1 >> s2;
	ll vs1 = 0, vs2 = 0, cs1 = 0, cs2 = 0;


	if(s1.length() != s2.length()){
		cout << "NO" << etr;
		return 0;
	}

	FOR(i, 0, s1.length()){
		char c = s1[i];
		char c2 = s2[i];
		if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
			if(c2 == 'a' || c2 == 'e' || c2 == 'i' || c2 == 'o' || c2 == 'u') continue;
			cout << "NO" << etr;
			return 0;
		}
		else{
			if(c2 == 'a' || c2 == 'e' || c2 == 'i' || c2 == 'o' || c2 == 'u'){
				cout << "NO" << etr;
				return 0;
			}
		}
	}

	cout << "YES" << etr;
	return 0;
}