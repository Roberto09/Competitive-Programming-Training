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
#define INF 1E18

string s;

ll valid(ll j){
	ll act = 0;
	ll ttl = 0;
	ll usedl = 0;
	ll usedr = 0;
	ll res = 0;
	FOR(i, j, s.length()){
		if(s[i]=='(')
			act ++;
		else if(s[i] == ')'){
			act --;
			if(act < 0){
				if(usedl > 0){
					usedl --;
					act ++;
				}
				else if((ttl-usedl)-usedr > 0){
					usedr ++;
					act ++;
				}
				else return res;
			}
		}
		else{
			ttl ++;
			if(act > 0){
				act --;
				usedl ++;
			}
		}
		if (act == 0 && ((ttl - usedl - usedr)%2 ==0)) res ++;
	}
	return res;
}

int main(){
	sync;
	cin >> s;
	ll cnt = 0;
	FOR(i, 0, s.length()){
		cnt += valid(i);
	}
	cout << cnt << etr;
	return 0;
}