#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

typedef long long ll;

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

string getResult(string n1, string n2){
	string res = "";
	
	string aux;
	if(n1.length() < n2.length()){
		aux = n1;
		n1 = n2;
		n2 = aux;
	}

	bool carry = 0;
	ll actSum;
	FOR(i, 0, n1.length()){
		ll numSum =  n1[n1.length() - i - 1] - '0' + (i >= n2.length() ? 0 : n2[n2.length() - i - 1] - '0');
		actSum = carry + numSum;
		if(actSum == 0){
			carry = 0;
			res += '0';
			continue;
		}
		else if(actSum == 1){
			carry = 0;
			res += '1';
		}
		else if(actSum == 2){
			carry = 1;
			res += '0';
		}
		else{
			carry = 1;
			res += '1';
		}
	}
	if(carry) res+='1';

	reverse(res.begin(), res.end());
	ll x;
	FOR(i, 0, res.length()){
		x = i;
		if(res[i] == '1') break;
	}

	return res.substr(x);
}

int main(){
	ll t;
	string s1, s2;
	cin >> t;
	FOR(i, 0, t){
		cin >> s1 >> s2;
		cout << i + 1 << " " << getResult(s1, s2) << etr;
	}
	return 0;
}