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
#define INF 1E15


int main(){
	// sync;
	double n,res;
	int t,toAdd;
	vector<int> ans;
	cin >> t;
	FOR(i,0,t){
		cin >> n;
		ans.clear();
		FOR(j,0,8){
			toAdd = floor(n);
			ans.pb(toAdd);
			n -= toAdd;
			n = 1/n;
		}
		int num=1,den=ans[7],aux;
		ROF(j,6,0){
			num += ans[j] * den;
			aux = num;
			num = den;
			den = aux;
		}
		FOR(j,0,8) cout << ans[j] << " ";
		cout << endl << den << "/" << num << endl;
	}

	return 0;
}