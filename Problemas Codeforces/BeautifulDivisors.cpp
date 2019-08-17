
#include <bits/stdc++.h>
using namespace std;

typedef int ll;
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

void checkN(ll i, ll &biggest){
	ll cons0s = 0;
	ll cons1s = 0;
	ll dn = i;
	bool withCeros = true;
	bool mayBe = true;
	while(dn != 0){
		if(withCeros){
			if(dn & 1){
				withCeros = false;
				cons1s ++;
			}
			else{
				cons0s ++;
			}
		}
		else{
			if(dn&1){
				cons1s ++;
			}
			else{
				mayBe = false;
				break;
			}
		}
		dn >>= 1;
	}
	if(mayBe){
		if(cons1s - 1 == cons0s && i > biggest){
			biggest = i;
		}
	}

}
int main(){
	sync;
	ll n; 
	cin >> n;
	ll biggest = 1;
	FOR(i, 1, sqrt(n) + 1){
		if(n%i == 0){
			checkN(i, biggest);
			checkN(n/i, biggest);
		}
	}
	cout << biggest << etr;
}
