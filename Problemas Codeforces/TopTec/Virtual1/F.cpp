#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <sstream>
#include <math.h>
#include <set>

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

ll n = 1;
void getPFactors(vi &f){
	if(n%2 == 0) {
		f.pb(2);
	}
	while(n % 2 == 0) 
		n/= 2;
	for (int i = 3; i <= sqrt(n); i+=2) {	
	    if(n%i == 0){
	    	f.pb(i);
	    }
	    while (n%i == 0) n = n/i;
	} 
	if(n > 2) f.pb(n);
}


int main(){
	while(n != 0){
		cin >> n;
		if(n == 0) break;
		vi pF;
		ll dN = n;

		getPFactors(pF);

		ll total = 0;
		FOR(i, 0, pF.size()){
			cout << pF[i] << etr;
			total += (dN/pF[i]);
		}

		FOR(i, 0, pF.size()){
			FOR(j, i+1, pF.size()){
				total -= dN / (pF[i] * pF[j]);
			}
		}

		cout << dN-total << etr;
	}
}