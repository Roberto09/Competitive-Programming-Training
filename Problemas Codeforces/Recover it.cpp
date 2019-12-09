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
#define INF 1E18

/*
3
3 5 2 3 2 4
*/

ll n;

unordered_map<ll, ll> fp;


const ll maxP = 3000000;
bool p[maxP];
void criba(){
	memset(p, true, sizeof(p));
	// PloglogP
    FOR(i,2,maxP) if(p[i]) for(ll j=i*i; j<maxP; j+=i) p[j]=false;
    ll cnt = 1;
    FOR(i,2,maxP){
    	if(p[i]){
    		fp[cnt] = i;
    		cnt ++;
    	}
    }
}

vi res;

int main(){
	sync;
	criba();
	cin >> n;
	map<ll, ll> primes;
	map<ll, ll, greater<ll>> np;
	FOR(i, 0, 2*n){
		ll x;
		cin >> x;
		if(p[x]) primes[x] ++;
		else np[x] ++;
	}
	for(auto it = np.begin(); it != np.end(); it ++){
		if(it->second == 0) continue;
		ll x = it->first;
		FOR(i, 0, it->second) res.pb(x);
		ll fnd;
		FOR(i, 2, sqrt(x)+1){
			if(x % i == 0){
				fnd = i; break;
			}
		}

		fnd = x / fnd;
		if(np.count(fnd)) np[fnd] -= it->second;
		else primes[fnd] -= it->second;
	}

	for(auto it = primes.begin(); it != primes.end(); it++){
		if(it->second == 0) continue;
		FOR(i, 0, it->second) res.pb(it->first);
		ll tofnd = fp[it->first];
		primes[tofnd] -= it->second;
	}

	for(ll x : res) cout << x << " ";
	return 0;
}