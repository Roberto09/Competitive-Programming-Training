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

struct btl{

};

int main(){
	sync;
	ll n;
	cin >> n;
	string Vitamins;

	ll minA = INF, minB = INF, minC = INF, minAB = INF, minAC = INF, minBC = INF, minABC = INF;
	
	ll price;
	string vits;
	FOR(i, 0, n){
		cin >> price >> vits;
		if(vits.length() == 3){
			minABC = min(price, minABC);
		}
		else if(vits.length() == 2){
			bool fA = false, fB = false, fC = false;
			if(vits.find('A') != -1) fA = true;
			if(vits.find('B') != -1) fB = true;
			if(vits.find('C') != -1) fC = true;
			if(fA && fB){
				minA = min(price, minA);
				minB = min(price, minB);
				minAB = min(price, minAB);
			}
			else if(fA && fC){
				minA = min(price, minA);
				minC = min(price, minC);
				minAC = min(price, minAC);
			}
			else{
				minB = min(price, minB);
				minC = min(price, minC);
				minBC = min(price, minBC);
			}
		}
		else{
			bool fA = false, fB = false, fC = false;
			if(vits.find('A') != -1) fA = true;
			if(vits.find('B') != -1) fB = true;
			if(vits.find('C') != -1) fC = true;
			if(fA){
				minA = min(price, minA);
			}
			else if(fB){
				minB = min(price, minB);
			}
			else{
				minC = min(price, minC);
			}
		}
	}

	ll mincomb = minABC;
	mincomb = min(minA + minB + minC, mincomb);


	mincomb = min(minA + minBC, mincomb);
	mincomb = min(minC + minAB, mincomb);
	mincomb = min(minB + minAC, mincomb);

	mincomb = min(minAB + minAC + minBC, mincomb);
	mincomb = min(minAB + minBC, mincomb);
	mincomb = min(minAC + minBC, mincomb);
	mincomb = min(minAB + minAC, mincomb);

	if(mincomb >= INF) cout << -1 << etr;
	else
		cout << mincomb << etr;
	return 0;
}