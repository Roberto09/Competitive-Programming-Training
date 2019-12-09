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
#define INF 1E18
ll row, col;

char m[1005][1005];
ll best[1005][1005];
bool recStack[1005][1005];

ll mv[][2] = {{0, 1},{1, 0},{0, -1},{-1, 0}};

ll doAlg(char c, ll i, ll j){
	if(i < 0 || i >= row || j < 0 || j >= col || m[i][j] != c) return 0;
	if(recStack[i][j]) return INF;
	if(best[i][j] != -1) return best[i][j];
	recStack[i][j] = true;
	ll tent = 0;
	FOR(k, 0, 4){
		if(c == 'D'){
			tent = max(doAlg('I', i+mv[k][0], j+mv[k][1]), tent);
		}
		else if (c == 'I'){
			tent = max(doAlg('M', i+mv[k][0], j+mv[k][1]), tent);
		}
		else if(c == 'M'){
			tent = max(doAlg('A', i+mv[k][0], j+mv[k][1]), tent);
		}
		else{
			tent = max(doAlg('D', i+mv[k][0], j+mv[k][1]), tent);
		}
	}
	recStack[i][j] = false;
	if(tent == INF) return best[i][j] = INF;
	return best[i][j] = (c == 'A' ? 1 + tent : tent);
}

int main(){
 	cin >> row >> col;
 	FOR(i, 0, row){
 		FOR(j, 0, col) cin >> m[i][j];
 	}
 	mem(best, -1ll);

 	ll bst = 0;
 	FOR(i, 0, row){
 		FOR(j, 0, col){
 			if(best[i][j] == -1){
 				ll tent = 0;
 				if(m[i][j] == 'D'){
 					tent = doAlg('D', i, j);
 				}
 				if(tent == INF){
 					cout << "Poor Inna!" << etr;
 					return 0;
 				}
 				bst = max(tent, bst);
 			}
 		}
 	}
 	if(bst == 0){
 		cout << "Poor Dima!";
 	}
 	else cout << bst << etr;
	return 0;
}