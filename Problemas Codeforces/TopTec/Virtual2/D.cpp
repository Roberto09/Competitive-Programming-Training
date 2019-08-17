#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <sstream>
#include <math.h>
#include <string>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;

#define FOR(i, a, b) for(ll i=ll(a); i<ll(b); i++)
#define ROF(i, a, b) for(ll i=ll(a); i>=ll(b); i--)
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define ifile(a) freopen((a), "r", stdin)
#define ofile(a) freopen((a), "w", stdout)
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); ////cout.tie(NULL)
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

pair<ll, char> arr[55];

int main(){
	sync;
	ll t, n;
	cin >> t;
	FOR(i, 0, t){
		cin >> n;
		ll val;
		char card;
		FOR(j, 0, n){
			cin >> val >> card;
			arr[j].first = val;
			arr[j].second = card;
		}
		bool res = true;
		ll antVal = -1;
		char antC = '.';
		FOR(j, 0, n){
			if(arr[j].first == antVal || arr[j].second == antC){
				res = false;
				break;
			}
			else{
				antVal = arr[j].first;
				antC = arr[j].second;
			}
		}
		if(res) cout << "B" << etr;
		else cout << "M" << etr;
	}
}