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
#define INF 10E10

map<pair<ll,string>, bool> dp;


bool solve(string& aux, ll indx, string& a, string& b){

	if(dp.count(mp(indx, aux)) > 0){
		return dp[mp(indx, aux)];
	}

	if(indx == a.size()){
		return dp[mp(indx, aux)] = aux == b;
	}


	//ES MAYUSCULA YA NO SE PUEDE CAMBIAR
	if(a[indx] <= 'Z'){
		//PREGUNTAR SI SE PUEDE IR CREANDO O NO PARA ESTO PREGUNTAREMOS
		//SI SE PUEDE PONER POR TAMANO
		if(aux.size() >= b.size()){
			dp[mp(indx, aux)] = false;
			return false;
		}

		// NO COINCIDEN LOS CARACTERES
		if(a[indx] != b[aux.size()]){
			dp[mp(indx, aux)] = false;
			return false;
		}

		// SI SE PUEDE PONER PORQUE COINCIDE
		aux.pb(a[indx]);
		bool flag = solve(aux, indx + 1, a, b);
		dp[mp(indx, aux)] = flag;
		aux.pop_back();
		return flag;
	}

	//DECIDAMOS PONER SOLO PODEMOS PONER SI COINCIDEN LAS PALABRAS
	bool flag1 = false;
	if(aux.size() < b.size() && toupper(a[indx]) == b[aux.size()]){
		aux.pb(toupper(a[indx]));
		flag1 = solve(aux, indx + 1, a, b);
		aux.pop_back();
	}
	if(flag1){
		return dp[mp(indx, aux)] = true;
	}
	//DECIDIMOS NO PONER
	bool flag2 = false;
	//SOLO PODEMOS NO PONER EN CASO DE QUE NOS SOBREN MUCHOS CARACTERES
	if(a.size() - indx >= b.size() - aux.size())
		flag2 = solve(aux, indx + 1, a, b);
	
	return dp[mp(indx, aux)] = flag2 || flag1;
}

int main(){
	sync;
	ll q;
	cin >> q;
	string a, b;
	FOR(i,0,q){
		cin >> a >> b;
		dp.clear();
		string aux = "";
		cout << ( solve(aux,0,a,b) ? "YES" : "NO") << endl;;
	}
	return 0;
}