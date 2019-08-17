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
#define INF 10E10

ll getAns(ll l, ll r){
	if(l == r) return l;
	ll b = floor(log2(r));
	ll b2b = pow(2, b);
	//no se puede utilizar b como resultado
	if(l >= b2b){
		//quitamos el primer 1 de ambos y vemos que onda
		return getAns(l - b2b, r - b2b) + b2b;
	}
	
	if(r == pow(2, b+1) - 1) return pow(2, b+1)-1;
	return b2b - 1;
}


int main(){
	ll n;
	cin >> n;
	ll a, b;	

	FOR(i, 0, n){
		cin >> a >> b;
		cout << getAns(a, b) << etr;
	}
	return 0;
}