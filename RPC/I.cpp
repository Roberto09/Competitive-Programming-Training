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
#define INF 1E10

vector<ll> primes;
vector<ll> cycle;

ll MakeCycle(ll prime){
	set<ll> enter{1};
	ll pot2 = 2;
	ll cont = 1;
	while(!enter.count(pot2)){
		enter.insert(pot2);
		++cont;
		pot2 = (pot2 * 2) % prime;
	}

	return cont;
}

void generate(){
	primes.pb(3);
	cycle.pb(2);
	bool flag;
	ll i = 5;
	while(primes.size() <= 999){
		flag = true;
		for(int j = 0; j < primes.size(); j++ ){
			if(i % primes[j] == 0){
				flag = false;
				break;
			}
		}
		if(flag){
			primes.pb(i);
			cycle.pb(MakeCycle(i));
		}
		i += 2;
	}


}


int main(){
    //sync;
    generate();
    ll a, b, aux;
    bool flag;
    while(cin >> a >> b){
    	aux = a + b;
    	flag = true;
    	FOR(i,0,cycle.size()){
    		cout << "entre con :" << cycle[i] << " " << primes[i] << etr;
    		if(aux % (cycle[i]) == 0 && aux / cycle[i] > 1){
    			flag = false;
    			break;
    		}
    	}
    	if(flag){
    		cout << "2^"<<aux<<"-1 is prime" << endl;
    	}else{
    		cout << "2^"<<aux<<"-1 not prime" << endl;
    	}
    }
    return 0;

}

