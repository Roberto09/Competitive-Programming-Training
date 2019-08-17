#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <sstream>
#include <math.h>
#include <string>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;

#define FOR(i, a, b) for(ll i=ll(a); i<ll(b); i++)
#define ROF(i, a, b) for(ll i=ll(a); i>=ll(b); i--)
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define ifile(a) freopen((a), "r", stdin)
#define ofile(a) freopen((a), "w", stdout)
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); ////cout.tie(NULL)
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

int main(){

	string a, d;
	cin >> a;
	cin.ignore();
	getline(cin, d);
	string res = "";
	FOR(i, 0, d.length()){
		if(d[i] == ' ') res += ' ';
		else if(d[i] >= 'a' && d[i] <= 'z')
			res += a[d[i] - 'a'];
		else
			res += toupper(a[tolower(d[i]) - 'a']);
	}
	cout << res << etr;
	return 0;
}