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
#define INF 10E10

ll r, c;

ll mtrx[60][60];
bool vm[60][60];
ii prm[60][60];

bool sts[3];

string res[] = {"NO SOLUTION", "UNREACHABLE CELL", "MULTIPLE PATHS"};
ll mv[][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
ll check[] = {1<<2, 1<<1, 1, 1<<3};
ll check2[] = {1, 1<<3, 1<<2, 1<<1};

void bfs(vii &ops){
	sts[0] = false;
	ll vstd = 0;
	mem(vm, false);
	//mem(prm, mp(-1, -1));
	queue<ii> q;
	q.push(ops[0]);
	vm[ops[0].first][ops[0].second] = true;
	while(!q.empty()){
		ii act = q.front(); q.pop();
		if(act.first == ops[1].first && act.second == ops[1].second) sts[0] = true;
		//cout << "-> " << act.first << " " << act.second << etr;
		vstd ++;
		FOR(i, 0, 4){
			ll nr = act.first, nc = act.second;
			nr += mv[i][0], nc += mv[i][1];
			if(nr >= 0 && nr < r && nc >= 0 && nc < c){
				if(mtrx[act.first][act.second] & check[i] && mtrx[nr][nc] & check2[i]){ // si te puedes mover
					if(vm[nr][nc]){
						if(nr == prm[act.first][act.second].first && nc == prm[act.first][act.second].second){

						}
						else sts[2] = false;
					}
					else{
						q.push(mp(nr, nc));
						vm[nr][nc] = true;
						prm[nr][nc] = mp(act.first, act.second);
					}
				}
			}
		}
	}
	//cout << "vstd: " << vstd << etr;
	if(vstd != (r*c)) sts[1] = false;
}

void solve(){
	string s;
	vii op;
	FOR(i, 0, r){
		cin >> s;
		FOR(j, 0, c){
			if(s[j] >= '0' && s[j] <= '9') mtrx[i][j] = s[j] - '0';
			else mtrx[i][j] = 10 + s[j] - 'A';
			mtrx[i][j] = ~mtrx[i][j];

			if(i == 0 && mtrx[i][j] & (1<<3)){
				op.pb(mp(i, j));
			}
			else if(j == 0 && mtrx[i][j] & (1)){
				op.pb(mp(i, j));
			}
			else if(i == r-1 && mtrx[i][j] & (1<<1)){
				op.pb(mp(i, j));
			}
			else if(j == c-1 && mtrx[i][j] & (1<<2)){
				op.pb(mp(i, j));
			}
		}
	}
	mem(sts, true);

	//cout << "yes" << op[0].first << " " << op[0].second << " ----- " << op[1].first << " " << op[1].second << etr;
	//cout << op.size() << etr;

	bfs(op);
	FOR(i, 0, 3){
		if(!sts[i]){
			cout << res[i] << etr;
			return;
		}
	}
	cout << "MAZE OK" << etr;
}

int main(){
	//cin >> r >> c;
	while(true){
		cin >> r >> c;
		if(r == 0 && c == 0) break;
		solve();
	}

	return 0;
}