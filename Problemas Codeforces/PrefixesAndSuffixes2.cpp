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
#define INF 1E15
string s;
ll n;

ll arr[100050];
ll res[100050];

ll kmp(string &a){
	ll preSuArr[a.length()]; preSuArr[0] = 0;
	ll prev = 0;
	FOR(i, 1, a.length()){
		while(a[i] != a[prev] && prev > 0) prev = preSuArr[prev-1];

		if(a[i] == a[prev]){
			prev ++;
			preSuArr[i] = prev;
		}
		else preSuArr[i] = 0;
	}
	ROF(i, n-1, 0){
		if(preSuArr[i] > 0){
			arr[preSuArr[i] -1] += arr[i] + 1;
		}
	}

	prev = n-1;
	ll cnt = 1;
	while(preSuArr[prev] > 0){
		res[preSuArr[prev]-1] = arr[preSuArr[prev]-1] + 1;
		prev = preSuArr[prev]-1;
		cnt ++;
	}
	
	res[n-1] = 1;
	return cnt;
}

int main(){
	cin >> s;
	n = s.length();
	ll cnt = kmp(s);

	cout << cnt << etr;
	FOR(i, 0, n)
		if(res[i] > 0) cout << i+1 << " " << res[i] << etr;
	return 0;
}