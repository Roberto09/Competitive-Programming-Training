#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
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

void findMirrorStrings(string s){
	//setup dp array
	ll len = 2*s.length() + 3;
	ll count[len] = {0};
	char newString[len];
	fill(newString, newString + len, '#');
	newString[0] = '$'; newString[len-1] = '@';

	for(ll j = 2, i = 0; i < s.length(); j+= 2, i++) newString[j] = s[i];

	ll center = 0, right = 0, mirrorLetter = 0;
	for(ll i = 2; i < len-1; i++){
		ll j = 1;
		if(i <= right){
			mirrorLetter = 2*center - i;
			if(i + count[mirrorLetter] == right){
				j += count[mirrorLetter];
				count[i] = count[mirrorLetter];
			}
			else{
				count[i] = min(right-i, count[mirrorLetter]);
				continue;
			}
		}
		while(newString[i+j] == newString[i-j]){
			j++;
			count[i] ++;
		}
		center = i;
		right = i + count[i];
	}

	ll maxVal = 0;
	FOR(i, 0, len) maxVal = max(maxVal, count[i]);

	ll countMaxVal = 0;
	FOR(i, 0, len) if(count[i] == maxVal) countMaxVal++;

	cout << maxVal << " " << countMaxVal << etr;
}

int main(){
	sync;
	ll t;
	cin >> t;
	string s;
	FOR(i, 0, t){
		cin >> s;
		findMirrorStrings(s);
	}
	return 0;
}