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

ll getLongestPalindromicSubstring(string s){
	//array stuff
	ll len = s.length()*2 + 3;
	char newString[len];
	ll palindromes[len] = {0};
	fill(newString, newString + len, '#');
	newString[0] = '$'; newString[len-1] = '@';

	for(int i = 2, j = 0; j < s.length(); i+= 2, j++) newString[i] = s[j];

	FOR(i, 0, len){
		cout << newString[i];
	}
	cout << etr;

	//algorithm itself "hola" -> "$ # H # O # L # A # @"
	ll mirror = 0, center = 0, right = 0;
	for(ll i = 2; i < len-1 && newString[right+1] != '@'; i++){

		ll j = 1;
		if(i <= right){
			mirror = 2*center - i;
			if(i + palindromes[mirror] == right){
				j += palindromes[mirror];
				palindromes[i] = palindromes[mirror];
			}
			else{
				palindromes[i] = min(right-i, palindromes[mirror]);
				continue;
			}
		}

		while(newString[i-j] == newString[i+j]){
			j++;
			palindromes[i]++;
		}
		right = i + palindromes[i];
		center = i;
	}

	ll maxVal = 0;
	FOR(i, 0, len){
		maxVal = max(maxVal, palindromes[i]);
		cout << palindromes[i];
	}
	cout << etr;
	return maxVal;
}

int main(){
	string s = "abaxabaxabb";
	cin >> s;
	//cin >> s;
	cout <<getLongestPalindromicSubstring(s) << etr;

	return 0;
}