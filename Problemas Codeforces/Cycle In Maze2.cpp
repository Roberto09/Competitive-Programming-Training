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
#define INF 1E10

ll p[4][2] = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};

char mtrx[1005][1005];

ll n, m, k, a, b;

char getC1(ll r, ll c){
	if(r == -1 && c == 0) return 'U';
	if(r == 0 && c == 1) return 'R';
	if(r == 0 && c == -1) return 'L';
	return 'D';
}


string getRes(ll ck){
	string res = "";
	ll cr = a, cc = b;
	FOR(j, 0, ck){
		FOR(i, 0, 4){
			ll r = cr + p[i][0], c = cc + p[i][1];
			if(r >= n || r < 0 || c >= m || c < 0 || mtrx[r][c] == '*') continue;
			res += getC1(r - cr, c - cc);
			cr = r; cc = c;
			break;
		}
	}

	return res + getResGo(res, cr, cc);
}

string getResGo(string go, ll r, ll c){
	priority_queue<char, vector<char>, greater<char>> pq;
	FOR(i, 0, go.length()) pq.push(go[i]);
	
}

bool validate(){
	if(k % 2 != 0) return false;
	FOR(i, 0, 4){
		ll r = a + p[i][0], c = b + p[i][1];
		if(r >= n || r < 0 || c >= m || c < 0) continue;
		if(mtrx[r][c] == '.') return true;
	}
	return false;
}

int main(){
	sync;
	cin >> n >> m >> k;

	FOR(i, 0, n){
		FOR(j, 0,  m){
			cin >> mtrx[i][j];
			if(mtrx[i][j] == 'X'){
				a = i; b = j;
			}
		}
	}
	if(!validate()){
		cout << "IMPOSSIBLE" << etr;
		return 0;
	}

	return 0;
}