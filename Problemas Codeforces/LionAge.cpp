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
#define mem(x, val) memset((x), (val), sizeexdof(x))
#define sz(x) (ll)(x).sizeexd()
#define endl '\n'
#define clockon ll t = 1; while (t--) { clock_t z = clock();
#define clockoff debug("Elapsed Time: %.3f\n", (double)(clock() - z) / CLOCKS_PER_SEC); }
#define oo 2000000000000000000LL
#define EPS 1e-6
#define MOD 1000000007
#define etr "\n"
#define INF 1E10

string s;
ll k; // puedes cambiar hasta k letras
ll sizeexd;

ll values[26][26];

ll dp[26][102][102];

ll bestResult(ll currLevel, ll currK, char prevLetter){
	if(currLevel == sizeexd) return 0;

	if(dp[prevLetter - 'a'][currLevel][currK] != -INF) return dp[prevLetter - 'a'][currLevel][currK];

	// conservamos la letra actual sin hacer cambios
	ll mx = values[prevLetter - 'a'][s[currLevel] - 'a'] + bestResult(currLevel + 1, currK, s[currLevel]);
	//calcular la mejor opcion a partir de aqui
	if(currK < k){
		FOR(i, 0, 26){
			// hacemos un cambio considerando cambiar la letra actual pos todas las posibles letras
			mx = max(mx, values[prevLetter - 'a'][i]+ bestResult(currLevel + 1, currK + 1, (char)('a' + i)));
		}
	}
	return dp[prevLetter - 'a'][currLevel][currK] = mx;
}


ll startAlg(ll currLevel, ll currK, char prevLetter){
	if(currLevel == sizeexd) return 0;
	// conservamos la letra actual sin hacer cambios
	ll mx = bestResult(currLevel + 1, currK, s[currLevel]);
	//calcular la mejor opcion a partir de aqui
	if(currK < k){
		FOR(i, 0, 26){
			// hacemos un cambio considerando cambiar la letra actual pos todas las posibles letras
			mx = max(mx, bestResult(currLevel + 1, currK + 1, (char)('a' + i)));
		}
	}
	return mx;
}

int main(){
	cin >> s >> k;
	sizeexd = s.length();

	FOR(i, 0, 26){
		FOR(j, 0, sizeexd+1){
			FOR(ki, 0, k+1){
				dp[i][j][ki] = -INF;
			}
		}
	}

	memset(values, 0, sizeof values);
	ll x;
	char a, b;
	ll n;
	cin >> n;
	FOR(i, 0, n){
		cin >> a >> b >> x;
		values[a - 'a'][b - 'a'] = x;
	}

	cout << startAlg(0, 0, '*') << etr;
	return 0;
}