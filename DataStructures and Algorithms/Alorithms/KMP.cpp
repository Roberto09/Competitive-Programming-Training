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
#define INF 1E9 + 1;

/*
KMP funciona en 2 partes,

Primero se genera un array de tamaño N que sera nuestro PREFIX array.
Ene este array guardamos para la letra Sn hacia la izquierda cual es es prefijo mas grande que se puede formar.
En otras palabras, guardamos el tamaño del prefijo mas grande que tambien es sufijo en Si;

a c a c a b a c a c a b a c a  c  a c
0 0 1 2 3 0 1 2 3 4 5 6 7 8 9 10 11 4

La segunda parte es utilzar el arreglo obtenido para resolver algun problema de strings o arrays tal como encontrar si algun
string aparece en otro. Para esto usamos nuestor arreglo de prefijos calculado con KMP.
*/


void generateArray(string &s, int prefixArr[]){
	prefixArr[0] = 0;
	ll c = 0;
	FOR(i, 1, s.size()){
		//seguimo sn
		if(s[c] == s[i]){
			prefixArr[i] = c+1;
			c++;
		}
		else{
			while(c != 0){
				c--;
				c = prefixArr[c];
				if(s[c] == s[i]) break;
			}
			if(s[c] == s[i]){
				prefixArr[i]  = c+1;
				c++;
			}
			else
				prefixArr[i] = 0;
		}
	}
}
bool patternFinding(string &pattern, string &s){
	int arrP[pattern.length()];
	generateArray(pattern, arrP);

	ll pi = 0;
	FOR(si, 0, s.length()){
		if(pattern[pi] == s[si]) pi++;
		else{
			while(pi != 0){
				pi--;
				pi = arrP[pi];
				if(pattern[pi] == s[si]) break;
			}
			if(pattern[pi] == s[si]) pi++;
		}
		if(pi == pattern.length()) return true;
	}
	return false;
}

int main(){
	//prueba de prefix array
	/*
	string s = "acacabacacabacacac";
	int arrP[s.length()];

	generateArray(s, arrP);
	
	FOR(i, 0, s.length()){
		cout << arrP[i] << " ";
	}
	cout << etr;
	*/

	//Prueba de pattern finding
	string pattern = "cocoaco";
	string s = "cocoacacoclacocaacacoca";
	if(patternFinding(pattern, s))
		cout << "The pattern is in the string" << etr;
	return 0;
}