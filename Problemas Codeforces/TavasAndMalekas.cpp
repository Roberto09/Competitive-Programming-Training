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
#define sz(x) (ll)(x).length()
#define endl '\n'
#define clockon ll t = 1; while (t--) { clock_t z = clock();
#define clockoff debug("Elapsed Time: %.3f\n", (double)(clock() - z) / CLOCKS_PER_SEC); }
#define oo 2000000000000000000LL
#define EPS 1e-6
#define MOD 1000000007
#define etr "\n"
#define INF 1E9 + 1;


ll fastPow(ll a, ll b){
    ll ret = 1;
    while(b > 0){
        if(b&1) ret = ((ret%MOD)*(a%MOD)) % MOD;
        a = ((a%MOD)*(a%MOD)) % MOD;
        b >>= 1;
    }
    return ret%MOD;
}

void generatePattern(ll pattern[], string &s){
	ll c = 0;
	pattern[0] = 0;

	FOR(i, 1, s.length()){
		if(s[i] == s[c]){
			c++;
			pattern[i] = c;
		}
		else{
			while(c != 0){
				c--;
				c = pattern[c];
				if(s[i] == s[c]) break;
			}
			if(s[i] == s[c]){
				c++;
				pattern[i] = c;
			}
			else pattern[i] = 0;
		}
	}
}


ll pttr[100005];
char original[100005];
string p;
ll sub[100005];

bool checkExistence(ll subLength, ll sSize){
	ll subCurrIdx = 0;
	ll pi = 0;

	FOR(oi, sub[0], sSize){
		if(original[oi] == p[pi]) pi++;
		else{
			while(pi != 0){
				pi --;
				pi = pttr[pi];
				if(original[oi] == p[pi]) break;
			}
			if(original[oi] == p[pi]) pi++;
		}

		if(pi == p.length()){
			ll startIdx = oi - (p.length()-1);
			if(startIdx == sub[subCurrIdx]){
				subCurrIdx++;
				if(subCurrIdx == subLength) return true;
				pi --;
				pi = pttr[pi];
			}
			else if(startIdx < sub[subCurrIdx]){
				pi --;
				pi = pttr[pi];
			}
			else return false;
		}
	}
	return false;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll sSize, subLength;
	cin >> sSize >> subLength;
	cin >> p;
	fill(original, original+100005, '*');
	if(subLength == 0){
		cout << fastPow(26, sSize);
		return 0;
	}

	sSize++;

	FOR(i, 0, subLength){
		cin >> sub[i];
	}
	//fill(s, s+sZise, 'x');
	generatePattern(pttr, p);
	//sacamos el ultimo prefijo que tambein es sufijo

	ll totalChars = 0;
	ll endOfLastOne = -1;
	ll dif = 0;
	FOR(i, 0, subLength){
		if(endOfLastOne >= sub[i]){
			dif = endOfLastOne - sub[i] + 1;
			FOR(j,dif, p.length()){
				original[j+sub[i]] = p[j];
			}
			totalChars += (p.length() - dif);
			endOfLastOne = sub[i] + (p.length() - 1);
		}
		else{
			FOR(j, 0, p.length()){
				original[j+sub[i]] = p[j];
			}
			totalChars += p.length();
			endOfLastOne = sub[i] + (p.length() - 1);
		}
	}

/*
	FOR(i, 0, sSize){
		cout << original[i];
	}
	cout << etr;
*/
	
	if(!checkExistence(subLength, sSize)){
		cout << 0 << etr;
		return 0;
	}

	cout << fastPow(26, (sSize - totalChars - 1)%MOD);
	return 0;
}