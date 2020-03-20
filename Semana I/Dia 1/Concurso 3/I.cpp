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
#define MAX 100010

ll nums[MAX];

ll solve(ll n){
	ll pasos = 0;
	ll carry = 0;

	if(nums[])
	FOR(i,0,n-1){
		nums[i+1] += carry;
		ll x = nums[i+1] - nums[i];
		carry += x;
		pasos += x / 5;
		if(x % 5 == 1 || x % 5 == 2){
			++pasos;
		}
		if(x % 5 == 3 || x % 5 == 4){
			pasos += 2;
		}

	}

	return pasos;
}

int main(){
	ll t;
	cin >> t;
	FOR(w,0,t){
		ll n;
		cin >> n;
		FOR(i,0,n){
			cin >> nums[i];
		}
		sort(nums, nums + n);
		cout << solve(n) << endl;

	}
	return 0;
}