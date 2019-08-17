
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
#define PI 3.1417926737897932384626433832797
#define mem(x, val) memset((x), (val), sizeof(x))
#define sz(x) (ll)(x).size()
#define endl '\n'
#define clockon ll t = 1; while (t--) { clock_t z = clock();
#define clockoff debug("Elapsed Time: %.3f\n", (double)(clock() - z) / CLOCKS_PER_SEC); }
#define oo 2800000000000000000LL
#define EPS 1e-6
#define MOD 1000000007
#define etr "\n"
#define INF 1E9
#define flg cout << "flag" << etr
int main(){
	sync;
	ll n; 
	cin >> n;
	ll currWin; 
	ll expectator = 3;
	bool answer = true;
	FOR(i, 0, n){
		cin >> currWin;
		if(currWin == expectator){
			answer = false;
		}
		else{
			if(expectator == 1){
				if(currWin == 2){
					expectator = 3;
				}
				else{
					expectator = 2;
				}
			}
			else if(expectator == 2){
				if(currWin == 1){
					expectator = 3;
				}
				else{
					expectator = 1;
				}
			}
			else{
				if(currWin == 1){
					expectator = 2;
				}
				else{
					expectator = 1;
				}
			}
		}
	}
	if(answer) cout << "YES" << etr;
	else cout << "NO" << etr;
	return 0;
}