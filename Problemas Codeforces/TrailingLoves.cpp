#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;
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
#define INF 2E18

unordered_map<ll, ll> primes;

void getPrimes(ll n){
    while (n%2 == 0){
    	if(!primes.count(2)) primes[2] = 0;
        primes[2] ++;
        n = n/2;
    }
    for (ll i = 3; i <= sqrt(n); i = i+2){
        while (n%i == 0){
	    	if(!primes.count(i)) primes[i] = 0;
	        primes[i] ++;
            n = n/i; 
        }
    }

    if (n > 2){	
    	if(!primes.count(n)) primes[n] = 0;
        primes[n] ++;
    }
}

int main(){
	sync;
	ll n, b;
	cin >> n >> b;
	getPrimes(b);
	ll arr[primes.size()];
	ll original[primes.size()];
	ll nmbs[primes.size()];
	ll i = 0;
	for(auto it = primes.begin(); it != primes.end(); it++){
		arr[i] = 0;
		nmbs[i] = it->first; original[i] = it->first;
		i ++;
	}

	bool act = true;
	while(act){
		act = false;
		FOR(k, 0, primes.size()){
			ll nmbr = nmbs[k];
			arr[k] += (n / nmbr);
			if(n/nmbr >= original[k]){
				act = true;
				nmbs[k] *= original[k];
			}
			else nmbs[k] = n + 1;
		}
	}

	ll mnRes = INF;
	FOR(k, 0, primes.size()){
		arr[k] /= primes[original[k]];
		mnRes = min(arr[k], mnRes);
	}

	cout << mnRes << etr;
	return 0;
}