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
#define INF 1E9 + 7


ll findNearestPrime(ll n){
	ROF(i, n, 1){
		bool prime = true;
		FOR(j, 2, sqrt(n)+1){
			if(i%j == 0) {
				prime = false;
				break;
			}
		}
		if(prime) return i;
	}
}

int main(){
	sync;
	ll n;
	cin >> n;

	//encontramos el numero primo mas cercano hacia abajo
	ll nP = findNearestPrime(n);
	//sacamos la diferencia entre este numero y el siguiente (sabemos que la diferencia sera par ya que ambos numeros son impares)
	ll dif = n - nP;
	//ya que la diferencia es menor a 300 podemos encontrar 2 numeros primos que sumados nos den 1 numero par menor a 300, y eso lo podemos hacer bruteforce
	
	//calculamos los primos de 1 a 300
	vi primes;
	FOR(i, 2, 301){
		bool prime = true;
		FOR(j, 2, sqrt(i)+1){
			if(i%j == 0){
				prime = false;
				break;
			}
		}
		if(prime) primes.pb(i);
	}

	//     <needs>
	unordered_set<ll> find;
	find.insert(0);

	ll n1 = 0, n2 = 0;
	FOR(i, 0, primes.size()){
		ll numbr = primes[i];
		find.insert(numbr);
		if(find.count(dif - numbr)){
			n1 = numbr;
			n2 = dif - numbr;
			break;
		}
	}

	cout << 1 + (n1 == 0 ?  0 : 1) + (n2 == 0 ?  0 : 1) << etr; 
	cout << nP << " ";
	if(n1 != 0){
		cout << n1 << " ";
		if(n2 != 0){
			cout << n2 << " ";
		}
	}

	return 0;
}