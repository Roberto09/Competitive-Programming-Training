

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

/*
6 8
BBBBBBBB
BBBBBBBB
BBBBBBBB
WWWWWWWW
WWWWWWWW
WWWWWWWW

*/

ll matr[110][110];
char arr[110][110];

ll n, m;

ll res = 0;

void mark(ll r, ll c, ll dif){
	FOR(i, 0, r+1){
		FOR(j, 0, c+1) matr[i][j] += dif;
	}
	res ++;
}

ll getDif(ll r, ll c){
	ll toGet;
	if(arr[r][c] == 'B') toGet = -1;
	else toGet = 1;
	return toGet - matr[r][c];
}

int main(){
	sync;
	cin >> n >> m;
	FOR(i, 0, n){
		FOR(j, 0, m){
			cin >> arr[i][j];
		}
	}

	ll r = n-1, c = m-1;
	while(r >= 0 && c >= 0){

		//check mid
		ll difM = getDif(r, c);
		if(difM != 0) mark(r, c, difM);

		//iterate x axis
		ROF(i, c-1, 0){
			difM = getDif(r, i);
			if(difM != 0) mark(r, i, difM);
		}

		//iterate y axis
		ROF(i, r-1, 0){
			difM = getDif(i, c);
			if(difM != 0) mark(i, c, difM);
		}
		r--;
		c--;
	}

	cout << res << etr;
	return 0;
}