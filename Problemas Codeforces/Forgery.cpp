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
#define INF 1E9;
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cerr << name << " : " << arg1 << '\n';
}

string arr[1005];

void canDoFill(ll row, ll col){
	FOR(i, 0, 3){
		arr[row][col+i] = 'x';
	}
	//segunda fila
	arr[row+1][col] = 'x';
	arr[row+1][col+2] = 'x';
	//tercera fila
	FOR(i, 0, 3){
		arr[row+2][col+i] = 'x';
	}
}

bool canGetSegment(ll row, ll col, ll h, ll w){
	if(col + 3 > w || row + 3 > h) return false;
	//primera fila
	FOR(i, 0, 3){
		if(arr[row][col+i] == '.') return false;
	}
	//segunda fila
	if(arr[row+1][col] == '.') return false;
	//if(arr[row+1][col+1] != '.') return false;
	if(arr[row+1][col+2] == '.') return false;
	//tercera fila
	FOR(i, 0, 3){
		if(arr[row+2][col+i] == '.') return false;
	}

	canDoFill(row, col);
	return true;
}

int main(){
	ll h, w;
	cin >> h >> w;
	FOR(i, 0, h) cin >> arr[i];
	FOR(r, 0, h){
		FOR(c, 0, w){
			canGetSegment(r, c, h, w);
		}
	}

	FOR(r, 0, h){
		FOR(c, 0, w){
			if(arr[r][c] != '.' && arr[r][c] != 'x'){
				cout << "NO" << etr;
				return 0;
			}
		}
	}

	cout << "YES" << etr;
	return 0;
}