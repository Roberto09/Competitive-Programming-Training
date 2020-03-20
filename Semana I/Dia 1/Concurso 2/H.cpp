#include <bits/stdc++.h>
#include <fstream>
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

ifstream fin("hard.in", std::ifstream::in);
ofstream fout("hard.out", std::ofstream::out);

ll strt = -32768;
ll eend = 32767;

unordered_map<ll, ll> cnt;

string to_str(ll x){
	if(x == 0) return "0";
	string res = "";
	bool add = false;
	if(x < 0){
		add = true;
		x = abs(x);
	}
	while(x){
		res += ('0' + x%10);
		x/=10;
	}
	if(add) res+= "-";
	reverse(res.begin(), res.end());
	return res;
}

void parse(){
	vii res;
	if(cnt.size() == 0){
		fout << "false" << etr;
		return;
	}
	for(auto it = cnt.begin(); it != cnt.end(); it++){
		res.pb(*it);
	}
	sort(res.begin(), res.end());

	vector<string> sres;

	ll last = INF;
	res.pb(mp(INF, INF));
	ll a = res[0].first, b = res[0].second;
	FOR(i, 1, res.size()){
		ii pr = res[i];
		if(pr.first <= b+1){
			b = max(pr.second, b);
		}
		else{
			if(a == strt && b == eend){
				fout << "true" << etr;
				return;
			}
			string s = "";
			if(a == strt){
				s += "x <= "; s+= to_str(b); s+= " ||";
			}
			else if(b == eend){
				s += "x >= "; s+= to_str(a); s+= " ||";
			}
			else{
				s += "x >= "; s+= to_str(a); s+= " && x <= "; s+=  to_str(b); s+=  " ||";
			}
			sres.pb(s);
			a = pr.first; b = pr.second;
		}
	}


	sres[sres.size() - 1] = sres[sres.size() - 1].substr(0, sres[sres.size() - 1].size() - 3);
	FOR(i, 0, sres.size()){
		fout << sres[i] << etr;
	}

}


void add(ll a, ll b){
	if(cnt.count(a)){
		cnt[a] = max(b, cnt[a]);
	}
	else cnt[a] = b;
}

int main(){
	string s;
	bool brk = false;
	while(!brk){
		getline(fin, s);
		if(s[s.length()-1] != '|') brk = true;
		ll a, b;
		ll k = s.find(' ', 5);
		if(k == -1) k = s.length() -1;
		a = stoll(s.substr(5, k));

		if(s.length()-k <= 3){
			if(s[2] == '>'){
				add(a, eend);
			}
			else{
				add(strt, a);
			}
			continue;
		}
		else{
			ll k2 = s.find(' ', k+9);
			if(k2 == -1) k2 = s.length() -1;
			b = stoll(s.substr(k+9, k2));
		}
		if(a == b){
			add(a, a);
		}
		else if(a > b) continue;
		add(a, b);
	}


	parse();

	return 0;
}