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
#define INF 1E10

int main(){
	sync;
	ll n;
	cin >> n;
	n++;
	ll arr[n];
	bool canBe = false;
	ll lastPos = 0;
	ll prev = 0;
	FOR(i, 0, n){
		cin >> arr[i];
		if(arr[i] >= 2 && prev >= 2){
			lastPos = i;
			canBe = true;
		}
		prev = arr[i];
	}
	if(!canBe){
		cout << "perfect" << etr;
		return 0;
	}

	cout << "ambiguous" << etr;


	cout << 0;
	
	ll sum = 1;
	FOR(i, 1, n){
		FOR(j , 0, arr[i])
			cout << " " << sum;
		sum += arr[i];
	}
	cout << etr;

	sum = 1;
	cout << 0;
	FOR(i, 1, n){
		if(i == lastPos){
			cout << " " << sum - 1;
			FOR(j, 1, arr[i]){
				cout << " " << sum;
			}
			sum += arr[i];
		}
		else{
			FOR(j , 0, arr[i]){
				cout << " " << sum;
			}
			sum += arr[i];
		}
	}
	cout << etr;
	return 0;
}