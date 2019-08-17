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

int main(){
	sync;
	ll n;
	cin >> n;
	ll x = n + n%2;
	if((x/2) % 2 == 0){
		cout << "Yes" << etr;
		cout << x/2 << " ";
		for(int i = 1; i <= n; i+= 2){
			cout << i << " ";
		}
		cout << etr << n/2 << " ";
		for(int i = 2; i <= n; i+= 2){
			cout << i << " ";
		}
		cout << etr;
	}
	else{
		ll pos = (n * (n+1)) / 2;
		bool posibl= false;
		ll numb = 0;
		FOR(i, 2, n+1){
			if((pos - i) % i == 0){
				numb = i;
				posibl = true;
				break;
			}
		}
		if (!posibl){
			cout << "No" << etr;
			return 0;
		}
		else{
			cout << "Yes" << etr;
			cout << 1 << " " << numb << etr;
			cout << n-1 << " ";
			FOR(i, 1, n+1){
				if(i != numb) cout << i << " ";
			}
			cout << etr;
		}
	}
	return 0;
}