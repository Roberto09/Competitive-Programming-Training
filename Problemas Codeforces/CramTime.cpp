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
	ll a, b;
	cin >> a >> b;
	vector<ll> resA;
	vector<ll> resB;

	ll ab = a+b;
	ll maxRes = (-1 + sqrt(1 + 4 * (2 * ab))) / 2;

	ll countB = 0;
	ll countA = 0;
	ROF(i, maxRes, 1){
		if(countB == b){
			resA.pb(i);
		}
		else{
			if(countB + i <= b){
				countB += i;
				resB.pb(i);
			}
			else{
				resA.pb(i);
			}
		}
	}

	cout << resA.size() << etr;
	if(resA.size() > 0){
		ROF(i, resA.size()-1, 0)
		cout << resA[i] << " ";
		cout << etr;
	}

	cout << resB.size() << etr;
	if(resB.size() > 0){
		ROF(i, resB.size()-1, 0)
		cout << resB[i] << " ";
		cout << etr;
	}
	return 0;
}