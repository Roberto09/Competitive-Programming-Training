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
#define INF 1E1
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cerr << name << " : " << arg1 << '\n';
}

int main(){
	sync;
	ll n;
	cin >> n;
	ll max = n + n-1;
	ll biggest = 0;
	while(max > 0){
		biggest ++;
		max /= 10;
	}
	biggest --;
	ll number = 0;
	FOR(i, 0, biggest){
		number *= 10;
		number += 9;
	}
	if(number*10 + 9 == n + n-1){
		number = number * 10 + 9;
	}
	if(number == 0){
		cout << (n*(n-1))/2 << etr;
		return 0;
	}
	number ++;

	ll res = 0;
	ll repetitions = n / number;

	FOR(i, 0, repetitions){
		ll subRes = (number) / 2; // la actual repeticion dentro de si misma
		res += subRes;
		res += i * number;
	}

	//quitamos las combinaciones con 0 no validas
	res -= repetitions;

	//ahora, con quienes podemos combinar los ultimos numeros
	//combinaciones individuales de intervalo 10 11 12 13 14
	ll basedNumber = n % number;
	if(basedNumber > 0){
		ll mid = (number / 2) - 1;
		if(basedNumber > mid){
			res += basedNumber - mid;
		}
	}

	if(repetitions == 0 && number == n+1){
		res --;
	}
	//combinacinoes con los numeros anteriores
	if(repetitions > 0){
		ll subRes = (basedNumber + 1) * repetitions;
		if(basedNumber + 1 == number) subRes --;
		res += subRes;
	}

	cout << res << etr;

	return 0;
}