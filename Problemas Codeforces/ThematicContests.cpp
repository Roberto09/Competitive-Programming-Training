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
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define PI 3.1415926535897932384626433832795
#define mem(x, val) memset((x), (val), sizeof(x))
#define sz(x) (ll)(x).size()
#define endl '\n'
#define clockon int t = 1; while (t--) { clock_t z = clock();
#define clockoff debug("Elapsed Time: %.3f\n", (double)(clock() - z) / CLOCKS_PER_SEC); }
#define oo 2000000000000000000LL
#define EPS 1e-6

#define MOD 1000000007

using namespace std;

ll calculate(ll v[], int n){
	ll possible = v[0];
	ll max = 0;
	for(ll i = 1; i<= possible; i++){
		ll divisor = i;
		ll curr = i;
		for(ll j = 1; j < n; j++){
			if(divisor % 2 != 0) break;
			divisor/=2;
			if(v[j] >= divisor) curr += divisor;
			else break;
		}
		if(curr > max) max = curr;
	}
	return max;
}

ll arr[200005];
map<ll, ll> problems;
ll countProblems[200005];

int main(){
	sync;
	ll n, prob;
	cin >> n;
	for(ll i = 0; i < n; i++){
		cin >> arr[i];
		problems[arr[i]] = 0;
	}


	int x = 0;
	for(auto it = problems.begin(); it != problems.end(); it++, x++){
		problems[it->first] = x;
	}

	for(ll i = 0; i < n; i++){
		arr[i] = problems[arr[i]];
		countProblems[arr[i]] ++;
	}

	sort(countProblems, countProblems + problems.size(), greater<ll>());

	cout << calculate(countProblems, problems.size()) << "\n";
	return 0;
}