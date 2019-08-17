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
ll l, p;
string s;

int main(){
	cin >> l >> p;
	cin >> s;
	p--;
	ll mid = (l-1) / 2;

	//acomodamos p en el left
	if(p > mid)
		p = (2*mid - p) + (l-1)%2;

	ll res = 0, minLeft = p, minRight = p;
	FOR(i, p+1, mid+1){
		if(s[i] != s[l-1-i])
			minRight = i;
	}

	ROF(i, p-1, 0){
		if(s[i] != s[l-1-i])
			minLeft = i;
	}


	res += min(minRight - p, p - minLeft) * 2 + max(minRight - p, p - minLeft);

	FOR(i, minLeft, minRight+1){
		if(s[i] != s[l-1-i]){
			ll a = s[i] - 'a', b = s[l-1-i] - 'a';
			res += min(abs(b-a), -abs(b-a) + 26);
		}
	}
	cout << res << etr;
	return 0;
}
