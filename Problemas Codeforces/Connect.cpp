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


/*5
1 1
5 5
00001
11111
00111
00110
00110
*/
ll n;

ii direct[] = {{0,1}, {0,-1}, {-1,0}, {1,0}};

bool canReach(ll ar, ll ac, char matr[50][50], ll findr, ll findc, vii &reachStart){
	queue<ii> nexts;
	matr[ar][ac] = 3;
	nexts.push(mp(ar, ac));
	ii curr;
	while(nexts.size()){
		curr = nexts.front(); nexts.pop();
		if(curr.first == findr && curr.second == findc) return true;
		ii nextCurr;
		reachStart.push_back(curr);
		FOR(i, 0, 4){
			nextCurr = mp(curr.first + direct[i].first, curr.second + direct[i].second);
			if(nextCurr.first < n && nextCurr.first >= 0 && nextCurr.second < n && nextCurr.second >= 0 && matr[nextCurr.first][nextCurr.second] != '1' && matr[nextCurr.first][nextCurr.second] != '3'){
				nexts.push(nextCurr);
				matr[nextCurr.first][nextCurr.second] = '3';
			}
		}
	}
	return false;
}

int main(){
	cin >> n;
	ll ar, ac, dr, dc;
	cin >> ar >> ac >> dr >> dc;
	ar --; ac --; dr--; dc --;
	char matr[50][50];
	FOR(i, 0, n){
		FOR(j, 0, n) cin >> matr[i][j];
	}

	vii reachStart, reachEnd;
	if(canReach(ar, ac, matr, dr, dc, reachStart)){
		cout << 0 << etr;
		return 0;
	}

	canReach(dr, dc, matr, ar, ac, reachEnd);
	
	ll best = INF;
	FOR(i, 0, reachStart.size()){
		FOR(j, 0, reachEnd.size()){
			best = min(best, (reachStart[i].first - reachEnd[j].first) * (reachStart[i].first - reachEnd[j].first) + (reachStart[i].second - reachEnd[j].second) * (reachStart[i].second - reachEnd[j].second));
		}
	}

	cout << best << etr;
	return 0;
}