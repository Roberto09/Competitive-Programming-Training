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

string s;

bool isPalindrome(int start, int end){
	while(start < end){
		if(s[start] != s[end]) return false;
		start ++; end--;
	}
	return true;
}

int main(){
	cin >> s;

	bool isSplited = s.length() % 2 != 0;
	bool canSolve = false;
	ll start = ceil(s.length()/2.0), end = s.length() -1;
	while(start < end){
		if(!isPalindrome(start, end)){
			canSolve = true;
			break;
		}
		if((end - start + 1) % 2 != 0) isSplited = true;
		start = ceil((end + start + 1) / 2);
	}

	if(canSolve){
		if(isSplited) cout << 2 << etr;
		else cout << 1 << etr;
	}
	else cout << "Impossible" << etr;

	return 0;
}