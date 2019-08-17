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

//R23C55
void NtoA(string &s){
	string row = "";
	string column = "";
	ll col;
	string newCol = "";
	ll i = 1;
	for(; s[i] != 'C'; i++){
		row += s[i];
	}

	i++;
	for(; i < s.size(); i++){
		column += s[i];
	}
	col = stoll(column);

	while(col != 0){
		col --;
		newCol += (char)('A' + col % 26);
		col /= 26;
	}

	reverse(newCol.begin(), newCol.end());

	cout << newCol << row << etr;
}

//BC23
void AtoN(string &s){
	string column = "";
	string row = "";
	FOR(i, 0, s.size()){
		if(s[i] >= 'A' && s[i] <= 'Z') column += s[i];
		else row +=s[i];
	}

	ll columnCalc = 0;
	ll exponent = 1;

	ROF(i, column.size() - 1, 0){
		columnCalc += exponent * (column[i] - 'A' + 1);
		exponent *= 26;
	}

	cout << 'R' << row << 'C' << columnCalc << etr;
}

void check(string &act){
	if(act[0] == 'R' && act[1] >= '0' && act[1] <= '9'){
		FOR(i, 0, act.length()){
			if(act[i] == 'C'){
				NtoA(act);
				return;
			}
		}
	}
	AtoN(act);
}

int main(){
	sync;
	ll n; 
	cin >> n;
	string act;
	FOR(i, 0, n){
		cin >> act;
		check(act);
	}
	return 0;
}