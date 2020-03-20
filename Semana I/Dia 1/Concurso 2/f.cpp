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

ifstream fin("foreign.in", std::ifstream::in);
ofstream fout("foreign.out", std::ofstream::out);

string s;
ll cs = 0;
ll wss = 0;
long double veacum = 0.0;
long double venext = 0.0;

int main(){
	fin >> s;
	ROF(i, s.length()-1, 0){
		ll kth = s.length()-i;
		char c = s[i];
		venext = veacum;
		if(c == 'C'){
			cs += kth;
			veacum = (long double)(venext + wss)/(long double)kth + venext;
		}
		else{
			wss += kth;
			veacum = (long double)(venext + cs)/(long double)kth + venext;
		}
		//fout << veacum << etr;
	}

	fout << setprecision(15) << fixed << veacum - venext << etr;
	return 0;
}