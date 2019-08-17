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
#define INF 1E18 + 5
#define flg cout << "flag" << etr

int main(){
	sync;
	ll n; 
	cin >> n;
	ll arr[n];
	FOR(i, 0, n){
		cin >> arr[i];
	}
	ll s, f;
	cin >> s >> f;
	ll dif = f - s;

	ll sum = 0;
	FOR(i, 0, dif){
		sum += arr[i];
	}
	ll maxPos = 0;
	ll max = sum;
	ll res = s;

	FOR(i, 1, n){
		sum -= arr[i - 1];
		sum += arr[(i+(dif-1))%(n)];
		if(sum > max){
			max = sum;
			maxPos = i;
			res = (((s + n - (i)) % (n)) == 0 ? n : ((s + n - (i)) % (n)));
		}
		else if(sum == max){
			if((((s + n - (i)) % (n)) == 0 ? n : ((s + n - (i)) % (n))) < res){
				max = sum;
				maxPos = i;
				res = (((s + n - (i)) % (n)) == 0 ? n : ((s + n - (i)) % (n)));
			}
		}
	}
	cout << res << etr;
	return 0;
}