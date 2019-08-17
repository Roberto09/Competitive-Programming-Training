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

ll dp[10010];
char arr[10010];

int main(){
	string s;
	cin >> s;
	for(int i = 0;  i < s.size() * 2; i++){
		arr[i] = '#';
		arr[i+1] = s[i];
	}
	dp[0] = dp[1] = 0;
	ll common = 0;
	FOR(i, 2, s.size()*2){
		//dp[i] = dp[i-1];6
		FOR(j, 1, min(i, s.size() * 2 - (i-1)){
			if(arr[i+j] == arr[i-j]){
				if(arr[i+j] != '#'){
					dp[i+j] ++;
					common ++;
				}
			}
			else break;
		}
	}
}