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

bool checkStrings(string &b, string &s){
	FOR(i, 0, s.length()){
		if(b[b.length() - 1 - i] != s[s.length() - 1 - i]) return false;
	}
	return true;
}

int main(){
	unordered_map<string,unordered_set<string>> friends;
	unordered_map<string, unordered_set<string>> removals;
	ll n;
	cin >> n;
	ll x;
	string y, w;
	FOR(i, 0, n){
		cin >> y >> x;
		if(!friends.count(y)){
			friends[y] = unordered_set<string>();
			removals[y] = unordered_set<string>();
		}
		FOR(j, 0, x){
			cin >> w;
			friends[y].insert(w);
		}
	}
	//preprocesar
	for(auto it = friends.begin(); it != friends.end(); it++){
		unordered_set<string> &f = it->second;
		for(auto it2 = f.begin(); it2 != f.end(); it2 ++){
			string s1 = *it2;

			auto it3 = it2;
			it3 ++;
			for(; it3 != f.end(); it3 ++){
				string s2 = *it3;
				if(s1.length() < s2.length()){
					if(checkStrings(s2, s1)) removals[it->first].insert(s1);
				}
				else{
					if(checkStrings(s1, s2)) removals[it->first].insert(s2);
				}
			}	
		}
	}

	for(auto it = removals.begin(); it != removals.end(); it ++){
		unordered_set<string> &f = it->second;
		for(auto it2 = f.begin(); it2 != f.end(); it2 ++){
			friends[it->first].erase(*it2);
		}
	}
	

	cout << friends.size() << etr;
	for(auto it = friends.begin(); it != friends.end(); it++){
		unordered_set<string> &f = it->second;
		cout << it->first << " " << f.size();
		for(auto it2 = f.begin(); it2 != f.end(); it2 ++){
			cout << " " << *(it2);
		}
		cout << etr;
	}
	return 0;
}