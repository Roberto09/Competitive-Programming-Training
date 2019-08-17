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
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define PI 3.1415926535897932384626433832795
#define mem(x, val) memset((x), (val), sizeof(x))
#define sz(x) (ll)(x).size()
#define endl '\n'
#define clockon int t = 1; while (t--) { clock_t z = clock();
#define clockoff debug("Elapsed Time: %.3f\n", (double)(clock() - z) / CLOCKS_PER_SEC); }
#define oo 2000000000000000000LL
#define EPS 1e-6

#define MOD 1000000007

int main(){
	sync;

	int n , k;
	string s;
	cin >> n >> k >> s;


	string newString = "";
	for(int i = 0; i < n; i++){
		newString += s[i];
		int j, it;
		for(j = i+1, it = 0; j < n; j++, it = (it+1) % (i+1)){
			if(newString[it] != s[j])
				break;
		}
		if(j == n)
			break;
	}

	string result = "";
	FOR(i, 1, k) result +=  newString;


	result+= s;



	cout << result << "\n";

	return 0;
}