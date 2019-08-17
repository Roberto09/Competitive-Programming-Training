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
	ll smallestNegative = -INF, sNPos = 0;
	vector<ll> ceros;
	vector<ll> pos;
	ll neg = 0;
	ll number;
	FOR(i, 1, n+1){
		cin >> number;
		if(number == 0){
			ceros.pb(i);
		}
		else if(number < 0){
			neg ++;
			pos.pb(i);
			if(number >= smallestNegative){
				smallestNegative = number;
				sNPos = i;
			}
		}
		else{
			pos.pb(i);
		}
	}

	if(neg % 2 != 0){
		FOR(i, 0, pos.size()){
			if(pos[i] == sNPos){
				pos[i] = pos[pos.size() - 1];
				pos.pop_back();
				break;
			}
		}
		if(ceros.size()> 0){
			FOR(i, 0, ceros.size() - 1){
				cout << 1 << " " << ceros[i] << " " << ceros[i+1] << etr;
			}
			cout << 1 << " " << ceros[ceros.size() - 1] << " " << sNPos << etr;
		}
		if(pos.size() > 0) cout << 2 << " " << sNPos << etr;
	}
	else{
		if(ceros.size()> 0){
			FOR(i, 0, ceros.size() - 1){
				cout << 1 << " " << ceros[i] << " " << ceros[i+1] << etr;
			}
			if(pos.size() > 0) cout << 2 << " " << ceros[ceros.size() - 1] << etr;
		}
	}

	if(pos.size() <= 1) return 0;
	FOR(i, 0, pos.size() - 1){
		cout << 1 << " " << pos[i] << " " << pos[i+1] << etr;
	}


	return 0;
}