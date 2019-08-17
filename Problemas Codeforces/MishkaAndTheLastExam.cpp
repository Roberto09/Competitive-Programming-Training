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
	ll n, a, preva;
	cin >> n;

	ll arr[n];
	cin >> a;
	arr[0] = 0;
	arr[n-1] = a;
	preva = a;
	FOR(i, 1, n/2){
		cin >> a;
		if(a <= preva){
			arr[i] = arr[i-1];
			arr[n-i-1] = a - arr[i];
		}
		else{
			arr[n-i-1] = arr[n-i];
			arr[i] = a - arr[n-i];
		}
		preva = a;
	}
	FOR(i, 0, n){
		cout << arr[i] << " ";
	}
	cout << etr;
	return 0;
}