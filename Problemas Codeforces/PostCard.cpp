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
	/*
	hw?ap*yn?eww*ye*ar
	12
	*/
	string s;
	cin >> s;
	ll k;
	cin >> k;

	ll str = 0, cdy = 0;
	FOR(i, 0, s.length()){
		if(s[i] == '*'){
			str ++;
		}
		else if(s[i] == '?'){
			cdy ++;
		}
	}

	ll strOriginalLength = s.length() - (str + cdy);
	string res = "";
	if(strOriginalLength == k){
		FOR(i, 0, s.length()){
			if(s[i] == '*'){
				continue;
			}
			else if(s[i] == '?'){
				continue;
			}
			res += s[i];
		}
	}
	//reducir string original
	else if(strOriginalLength > k){
		ll posReduc = str + cdy;
		if(strOriginalLength - posReduc <= k){
			FOR(i, 0, s.length() - 1){
				if(s[i] == '*' || s[i] == '?'){
					continue;
				}

				if(strOriginalLength > k){
					if(s[i+1] == '*' || s[i+1] == '?'){
						strOriginalLength --;
						continue;
					}
					else{
						res += s[i];
					}
				}
				else{
					res+=s[i];
				}

			}
			if(!(s[s.length() - 1] == '*' || s[s.length() - 1] == '?')){
				res += s[s.length()-1];
			}
		}
		else{
			res = "Impossible";
		}
	}

	//aumentar strOriginal
	else{
		if(str > 0){
			ll faltan = k - strOriginalLength;
			bool doneUpdating = false;
			FOR(i, 0, s.length()){
				if(s[i] == '?'){
					continue;
				}
				if(s[i] == '*'){
					if(doneUpdating)
						continue;
					else{
						FOR(j, 0, faltan){
							res += s[i-1];
						}
						doneUpdating = true;
						continue;
					}
				}
				else res += s[i];
			}
		}
		else{
			res = "Impossible";
		}		
	}

	cout << res << etr;
	return 0;
}