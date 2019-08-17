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
#define INF 1E9
int main(){
	sync;
	ll n, k;
	cin >> n >> k;
	ii arr[n];
	ll arrOrder[n];
	FOR(i, 0, n){
		cin >> arr[i].first;
		arrOrder[i] = arr[i].first;
	}
	FOR(i, 0, n){
		cin >> arr[i].second;
	}
	sort(arr, arr + n);

	unordered_map <ll, ll> results;
	priority_queue<ll, vector<ll>, greater<ll>> pq;
	
	ll sumTotal = 0;
	if(k > 0){
		results[arr[0].first] = arr[0].second;
		sumTotal = arr[0].second;
		pq.push(arr[0].second);
	}
	FOR(i, 1, k){
		results[arr[i].first] = arr[i].second + results[arr[i-1].first];
		pq.push(arr[i].second);
		sumTotal += arr[i].second;
	}

	FOR(i, k, n){
		results[arr[i].first] = sumTotal + arr[i].second;
		if(!pq.empty() && arr[i].second > pq.top()){
			sumTotal -= pq.top();
			sumTotal += arr[i].second;
			pq.pop();
			pq.push(arr[i].second);
		}
	}

	FOR(i, 0, n){
		cout << results[arrOrder[i]] << " ";
	}
	cout << etr;


	return 0;
}