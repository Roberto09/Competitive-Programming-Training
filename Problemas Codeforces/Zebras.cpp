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

struct comb{
	ll abre = -1, cierra = -1;
	bool usado = false;
};

int main(){
	sync;
	ll cn = 0, on = 0; 
	string str;
	cin >> str;
	ll n = str.length();
	bool arr[n];
	FOR(i, 0, n){
		char x = str[i];
		if(x == '1'){
			on ++;
			arr[i] = true;
		}
		else{
			cn ++;
			arr[i] = false;
		}
	}

	if(arr[0] || arr[n-1]){
		cout << -1 << etr;
		return 0;
	}

	queue<ll> ceros;
	comb cbs[n];
	FOR(i, 0, n){
		cbs[i].abre = -1;
		cbs[i].cierra = -1;
		cbs[i].usado = false;
	}
	bool canBeDone = true;
	ROF(i, n-1, 0){
		// 1
		if(arr[i]){
			if(ceros.empty()){
				canBeDone = false;
				break;
			}
			ll cero = ceros.front();
			cbs[cero].cierra = i;
			cbs[cero].usado = true;
			ceros.pop();
		}
		// 0
		else{
			ceros.push(i);
		}
	}
	if(!canBeDone){
		cout << -1 << etr;
		return 0;
	}

	stack<ll> ceros2;

	FOR(i, 0, n){
		if(arr[i]){
			if(ceros2.empty()){
				canBeDone = false;
				break;
			}
			ll cero = ceros2.top();
			cbs[cero].abre = i;
			cbs[cero].usado = true;
			ceros2.pop();
		}
		// 0
		else{
			if(!cbs[i].usado)ceros2.push(i);
		}
	}

	if(!canBeDone){
		cout << -1 << etr;
		return 0;
	}

	ll usedCeros = 0;
	FOR(i, 0, n){
		comb &cb = cbs[i];
		if(cb.usado){
			usedCeros ++;
			if(cb.abre != -1){
				cbs[cb.abre].abre = i;
			}
			else{
				cbs[cb.cierra].cierra = i;
			}
		}
	}
	ll number = (cn - usedCeros) + on;
	cout << number << etr;

	FOR(i, 0, n){
		if(arr[i]){
			cout << 3 << " " << cbs[i].abre+1 << " " << i+1 << " " << cbs[i].cierra+1 << etr;
		}
		else{
			if(cbs[i].usado) continue;
			cout << 1 << " " << i+1 << etr;
		}
	}

	return 0;
}