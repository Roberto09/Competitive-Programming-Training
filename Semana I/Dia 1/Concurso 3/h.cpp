#include <bits/stdc++.h>
#include <fstream>
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
#define sync ios_base::sync_with_stdio(false); fin.tie(NULL); //fout.tie(NULL)
#define PI 3.1415926535897932384626433832795
#define mem(x, val) memset((x), (val), sizeof(x))
#define sz(x) (ll)(x).size()
#define endl '\n'
#define clockon ll t = 1; while (t--) { clock_t z = clock();
#define clockoff debug("Elapsed Time: %.3f\n", (long double)(clock() - z) / CLOCKS_PER_SEC); }
#define oo 2000000000000000000LL
#define EPS 1e-6
#define MOD 1000000007
#define etr "\n"
#define INF 10E18

ll k = 314159;

string x, y, xinv;
ll pot[500050];

ll xsub[100050], xinvsub[100050], revx[100050];


string fix(string &a, string &b){
	string nw = "";
	FOR(i, 0, b.length() - a.length()){
		nw += '0';
	}
	nw += a;
	return nw;
}

ll res = 0;

int main(){
	cin >> x >> y;
	if(x.length() < y.length())
		x = fix(x, y);
	else if(x.length() > y.length())
		y = fix(y, x);

	for(char c: x){
		if(c == '0') xinv += '1';
		else xinv += '0';
	}
	pot[0] = 1;
	FOR(i, 1, 500050) pot[i] = (2*pot[i-1]) % MOD;

	
	ll prev = 0;
	ll ones = 0;
	FOR(i, 0, x.length()){
		xsub[i] = prev;
		if(x[i] == '1'){
			xsub[i] = (xsub[i] + pot[x.length()-i-1])%MOD;
		}
		if(y[i] == '1') ones ++;
		prev = xsub[i];
	}

	prev = 0;
	FOR(i, 0, xinv.length()){
		xinvsub[i] = prev;
		if(xinv[i] == '1'){
			xinvsub[i] = (xinvsub[i] + pot[xinv.length()-i-1])%MOD;
		}
		prev = xinvsub[i];
	}

	prev = 0;
	ROF(i, x.length()-1, 0){
		revx[i] = prev;
		if(x[i] == '1'){
			revx[i] = (revx[i] + pot[x.length()-i-1])%MOD;
		}
		prev = revx[i];
	}
	//cout << etr;
	//p1
	ROF(i, y.length()-1, 0){
		if(y[i] == '0')
			res = (res + xsub[i]) % MOD;
		else
			res = (res + xinvsub[i]) % MOD;
	}

	//cout << "first res: " << res << etr;

	//p2
	res = (res + (revx[0] * (k- x.length()))%MOD)%MOD;
	if(res < 0) res += MOD;

	ROF(i, x.length()-1, 0) res = (res + revx[i]) % MOD;

	//cout << "second res: " << res << etr;

	//p3
	//cout << "ones: " << ones << etr;
	//

	FOR(i, 0, y.length()){
		if(y[i] == '1'){
			res = (res + ((pot[k+x.length()-i] -1) - (pot[x.length()] -1)))%MOD;
			if(res < 0) res += MOD;
		}
	}

	cout << res << etr;

	return 0;
}