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

//returns count
int constructTree(ll arr[], ll segment[], ll low, ll high, ll pos){
	if(low == high){
		segment[pos] = arr[low];
		return 1;
	}
	ll mid = low + (high-low)/2;
	int count = constructTree(arr, segment, low, mid, 2*pos+1);
	constructTree(arr, segment, mid+1, high, 2*pos+2);
	if(count % 2 == 1) segment[pos] = segment[2*pos+1] | segment[2*pos+2];
	else segment[pos] = segment[2*pos+1] ^ segment[2*pos+2];
	return count + 1;
}

void changeNumberAtNPosition(ll segment[], ll arr[], ll arrHigh, ll N, ll X){
	arr[N] = X;
	//get to number and change it
	ll low = 0, high = arrHigh, mid, pos = 0;
	while(low != high){
		mid = low + (high - low)/2;
		//left
		if(N <= mid){
			high = mid; pos = 2*pos + 1;
		}
		//right
		else{
			low = mid + 1; pos = 2*pos + 2;
		}
	}
	segment[pos] = X;

	int count = 1;
	// go backwards
	ll prev = pos, left, right;
	while(prev > 0){
		prev = (prev-1) / 2;
		left = segment[2*prev+1];
		right = segment[2*prev+2];
		//si el menor es igual aun que cambiemos el numero paramos
		if(count % 2 == 1) segment[prev] = left | right;
		else segment[prev] = left ^ right;
		count ++;
	}
}

int main(){
	ll n, m;
	cin >> n >> m;
	n = 1 << n;

	ll arr[n];
	ll segment[(2*n)-1];

	FOR(i, 0, n){
		cin >> arr[i];
	}

	constructTree(arr, segment, 0, n-1, 0);

	ll pos, change;
	FOR(i, 0, m){
		cin >> pos >> change;
		pos--;
		changeNumberAtNPosition(segment, arr, n-1, pos, change);
		cout << segment[0] << "\n";
	}
	return 0;
}