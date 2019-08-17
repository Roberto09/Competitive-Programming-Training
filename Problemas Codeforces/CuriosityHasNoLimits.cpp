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

int main(){
	sync;
	ll n;
	cin >> n;
	ll a[n];
	ll b[n];
	vector<vector<bool>> res (n, vector<bool>(4, false));

	FOR(i, 0, n-1){
		cin >> a[i];
	}

	FOR(i, 0, n-1){
		cin >> b[i];
	}


	if(a[0] == 0){
		res[0][0] = true;
		res[0][1] = false;
		res[0][2] = false;
		res[0][3] = false;
	}
	else if(a[0] == 1){
		res[0][0] = true;
		res[0][1] = true;
		res[0][2] = false;
		res[0][3] = false;
	}
	else if(a[0] == 2){
		res[0][0] = true;
		res[0][1] = false;
		res[0][2] = true;
		res[0][3] = false;
	}
	else{
		res[0][0] = true;
		res[0][1] = true;
		res[0][2] = true;
		res[0][3] = true;
	}

	FOR(i, 0, n-1){
		if(a[i] == 0){
			res[i+1][0] = true;
			res[i+1][1] = false;
			res[i+1][2] = false;
			res[i+1][3] = false;
		}
		else if(a[i] == 1){
			res[i+1][0] = true;
			res[i+1][1] = true;
			res[i+1][2] = false;
			res[i+1][3] = false;
		}
		else if(a[i] == 2){
			res[i+1][0] = true;
			res[i+1][1] = false;
			res[i+1][2] = true;
			res[i+1][3] = false;
		}
		else{
			res[i+1][0] = true;
			res[i+1][1] = true;
			res[i+1][2] = true;
			res[i+1][3] = true;
		}
		res[i][0] = res[i][0] && res[i+1][0];
		res[i][1] = res[i][1] && res[i+1][1];
		res[i][2] = res[i][2] && res[i+1][2];
		res[i][3] = res[i][3] && res[i+1][3];
	}

	FOR(i, 0, n-1){
		if(b[i] == 0){
			res[i+1][0] = res[i+1][0] && true;
			res[i+1][1] = res[i+1][1] && true;
			res[i+1][2] = res[i+1][2] && true;
			res[i+1][3] = res[i+1][3] && true;

			res[i][0] = res[i][0] && true;
			res[i][1] = res[i][1] && true;
			res[i][2] = res[i][2] && true;
			res[i][3] = res[i][3] && true;
		}
		else if(b[i] == 1){
			res[i+1][0] = res[i+1][0] && false;
			res[i+1][1] = res[i+1][1] && true;
			res[i+1][2] = res[i+1][2] && false;
			res[i+1][3] = res[i+1][3] && true;

			res[i][0] = res[i][0] && false;
			res[i][1] = res[i][1] && true;
			res[i][2] = res[i][2] && false;
			res[i][3] = res[i][3] && true;
		}
		else if(b[i] == 2){
			res[i+1][0] = res[i+1][0] && false;
			res[i+1][1] = res[i+1][1] && false;
			res[i+1][2] = res[i+1][2] && true;
			res[i+1][3] = res[i+1][3] && true;

			res[i][0] = res[i][0] && false;
			res[i][1] = res[i][1] && false;
			res[i][2] = res[i][2] && true;
			res[i][3] = res[i][3] && true;
		}
		else{
			res[i+1][0] = res[i+1][0] && false;
			res[i+1][1] = res[i+1][1] && false;
			res[i+1][2] = res[i+1][2] && false;
			res[i+1][3] = res[i+1][3] && true;

			res[i][0] = res[i][0] && false;
			res[i][1] = res[i][1] && false;
			res[i][2] = res[i][2] && false;
			res[i][3] = res[i][3] && true;
		}
	}


	bool can = false;
	bool mayHappen = false;
	ll fRes[n];
	FOR(i, 0, n){
		if(i < 0){
			cout << "NO" << etr;
			return 0;
		}
		can = false;
		mayHappen = false;
		FOR(j, 0, 4){
			if(res[i][j]){
				mayHappen = true;
				if(i == 0 || ((j | fRes[i-1]) == a[i-1] && (j & fRes[i-1]) == b[i-1])){
					fRes[i] = j;
					res[i][j] = false;
					can = true;
					break;
				}
			}
		}
		if(!can){
			if(mayHappen){
				i-=2;
			}
			else{		
				cout << "NO" << etr;
				return 0;
			}
		}
	}

	cout << "YES" << etr;
	FOR(i, 0, n){
		cout << fRes[i] << " ";
	}
	cout << etr;

	return 0;
}