
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
	ll n, x, y;
	string s;
	cin >> n >> x >> y >> s;
	ll conv0s = 0;
	bool enRacha = false;
	FOR(i, 0, n){
		if(s[i] == '0'){
			if(!enRacha){
				conv0s ++;
				enRacha = true;
			}
		}
		else{
			enRacha = false;
		}
	}
	if(conv0s == 0){
		cout << 0 << etr;
	}
	else{
		if(x < y){
			cout << (conv0s-1) * x + y << etr;
		}
		else{
			cout << conv0s * y << etr;
		}
	}
	return 0;
}