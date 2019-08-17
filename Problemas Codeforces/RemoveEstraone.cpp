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
#define INF 1E5+5

ll n, arr[100005];
ll maxArr[100005];

ll verify(){
	ll count = 0;
	ll prevMax = -1;
	FOR(i, 0, n){
		if(arr[i] > prevMax){
			count ++;
		}
		maxArr[i] = max(prevMax, arr[i]);
		prevMax = maxArr[i];
	}

	if(count == n) return arr[0];

	ll res = INF;
	FOR(i, 0, n){
		if(maxArr[i] != arr[i]){
			res = min(res, arr[i]);
		}
	}

	ll prev = -1;
	ll currPrev = -1;
	ll currCount = count -1;
	ll maxCount = count;
	FOR(i, 0, n){
		if(maxArr[i] == prev){
			if(arr[i] > currPrev) currCount ++;
			currPrev = max(currPrev, arr[i]);
		}
		else{
			if(currCount ==  maxCount){
				res = min(res, prev);
			}
			else if(currCount > maxCount){
				res = prev;
				maxCount = currCount;
			}
			currCount = count -1;
			currPrev = prev;
			prev = maxArr[i];
		}
	}

	if(currCount ==  maxCount){
		res = min(res, prev);
	}
	else if(currCount > maxCount){
		res = prev;
		maxCount = currCount;
	}
	return res;
}

int main(){
	sync;
	cin >> n;
	FOR(i, 0, n){
		cin >> arr[i];
	}
	cout << verify() << etr;
	return 0;
}