
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
#define PI 3.1417926737897932384626433832797
#define mem(x, val) memset((x), (val), sizeof(x))
#define sz(x) (ll)(x).size()
#define endl '\n'
#define clockon ll t = 1; while (t--) { clock_t z = clock();
#define clockoff debug("Elapsed Time: %.3f\n", (double)(clock() - z) / CLOCKS_PER_SEC); }
#define oo 2800000000000000000LL
#define EPS 1e-6
#define MOD 1000000007
#define etr "\n"
#define INF 1E9
#define flg cout << "flag" << etr
int main(){
	sync;
	vector<pair<ll, char>> arr(4);
	arr[0].second = 'A';
	arr[1].second = 'B';
	arr[2].second = 'C';
	arr[3].second = 'D';
	ll sum = 0;
	FOR(i, 0, 4){
		cin >> arr[i].first;
		sum += arr[i].first;
	}
	sort(arr.begin(), arr.end());


	vector<vector<char>> res; // al menos 1 tiene
	//llenamos hileras
	FOR(i, 0, 11)
		res.pb(vector<char>(49, arr[1].second));

	FOR(i, 0, 11)
		res.pb(vector<char>(49, arr[2].second));

	FOR(i, 0, 11)
		res.pb(vector<char>(49, arr[3].second));

	FOR(i, 0, 11)
		res.pb(vector<char>(49, arr[0].second));

	ll rowStart = 1;
	FOR(i, 0, 4){
		for(ll r = 0; r < 11; r+= 2){
			for(ll c = 1; c < 48; c+=2){
				if(arr[i].first > 1){
					res[r + rowStart][c] = arr[i].second;
					arr[i].first --;
				}
			}
		}
		rowStart += 11;
	}
	cout << 44 << " " << 49 << etr;
	FOR(r, 0, 44){
		FOR(c, 0, 49){
			cout << res[r][c];
		}
		cout << etr;
	}
	return 0;
}