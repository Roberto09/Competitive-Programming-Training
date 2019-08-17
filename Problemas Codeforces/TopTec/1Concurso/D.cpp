#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

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


ll matr[110][110];
ll t;
ll sumR[110], sumC[110];


void getBest(){
	FOR(i, 0, t) sumR[i] = sumC[i] = 0;
	FOR(r, 0, t){
		FOR(c, 0, t){
			sumR[r] += matr[r][c];
			sumC[r] += matr[c][r];
		}
	}

	bool good = true;
	vector<ll> changeR, changeC;
	FOR(i, 0, t){
		if(sumR[i] % 2){
			good = false;
			changeR.pb(i);
		}
		if(sumC[i] % 2){
			good = false;
			changeC.pb(i);
		}
	}

	if(good){
		cout << "OK" << etr;
		return;
	}
	else if(changeR.size() == 1 && changeC.size() == 1){
		cout << "Change bit (" << changeR[0]+1 << "," << changeC[0]+1 << ")" << etr;
	}
	else{
		cout << "Corrupt" << etr;
	}
}

int main(){
	while(true){
		cin >> t;
		if(t == 0) break;
		FOR(i, 0, t){
			FOR(j, 0, t)
				cin >> matr[i][j];
		}
		getBest();
	}
	return 0;
}