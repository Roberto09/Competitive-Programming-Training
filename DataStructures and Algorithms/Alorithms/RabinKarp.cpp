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
#define INF 1E9

ll hashFunc(string &s, ll startPos, ll len, ll prevHash, ll lastExp, ll alphaSize){
	//Formula
	return (alphaSize * (prevHash - s[startPos-1] * lastExp)+ s[startPos + len - 1]) % MOD;
}

ll RabinKarp(string &str, string &pattern, ll alphaSize){
	if(pattern.length() > str.length()) return -1;
	
	//generate lastExponent
	ll lastExp = 1;
	FOR(i, 1, pattern.length())	lastExp = (lastExp * alphaSize) % MOD;

	ll patternHash = 0, stringHash = 0;
	//generate patternHash and str first hash
	FOR(i, 0, pattern.length()){
		patternHash = (patternHash * alphaSize + pattern[i]) % MOD;
		stringHash = (stringHash * alphaSize + str[i]) % MOD;
	}

	//start trying hash funtions
	for(int i = 0; i <= str.length() - pattern.length(); i++){
		if(stringHash == patternHash){
			bool possible = true;
			FOR(j, 0, pattern.length()){
				if(pattern[j] != str[i + j]){
					possible = false;
					break;
				}
			}
			return i;
		}
		if (i < str.length() - pattern.length()){
			stringHash = hashFunc(str, i+1, pattern.length(), stringHash, lastExp, alphaSize);
			if(stringHash < 0) stringHash += MOD;
		}
	}
	return -1;
}

int main(){
	sync;
	string str = "missisipik";
	string pattern = "k";
	cout << RabinKarp(str, pattern, 256) << etr;
	return 0;
}