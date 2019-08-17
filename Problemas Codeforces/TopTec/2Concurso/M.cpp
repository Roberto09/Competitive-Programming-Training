#include <iostream>
#include <string>
#include <vector>
#include <map>

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
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); //////cout.tie(NULL)
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

struct arrInfo {
	ll size;
	map<ll, ll> declaredPositions;
	arrInfo(){}
	arrInfo(ll s) {
		size = s;
	}
};

ll myStoy(string &s, ll start, ll end){
	ll res = 0;
	FOR(i,start,end+1){
		res*=10;
		res += s[i] - '0';
	}
	return res;
}

map <string, arrInfo> arrays;

void initialize(string &s) {
	string name = "";
	ll newStart;
	FOR(i, 0, s.length()){
		if(s[i] != '[') name += s[i];
		else{
			newStart = i+1;
			break;
		}
	}
	arrays[name] = arrInfo(myStoy(s, newStart, s.length()-2));
}


bool assignment(string &name, ll position, ll value) {
	if (position >= arrays[name].size) return false;
	
	arrays[name].declaredPositions[position] = value;
	return true;
}

ll getInerQuery(string &str, ll intialPos, ll endPos) {
	//es numero caso base
	if(str[intialPos] <= '9' && str[intialPos] >= '0'){
		return myStoy(str, intialPos, endPos);
	}

	string name = "";
	ll newStart;
	FOR(i, intialPos, endPos+1){
		if(str[i] != '[') name += str[i];
		else{
			newStart = i+1;
			break;
		}
	}

	ll idx = getInerQuery(str, newStart, endPos - 1);
	if(idx == -INF) return -INF;
	arrInfo &a = arrays[name];

	if(a.declaredPositions.count(idx)) return a.declaredPositions[idx];
	return -INF;
}

ll solveTest(vector<string> &lines){
	//cout << "xd" << etr;
	FOR(i, 0, lines.size()){
		string &curr = lines[i];
		//2 casos, inicializacion o assignment
		ll equalSign = curr.find("=");
		//cout << "equal sign: " << equalSign << etr;
		if(equalSign != string::npos){
			//sacamos el nombre
			string name = "";
			ll newStart;
			FOR(i, 0, curr.length()){
				if(curr[i] != '[') name += curr[i];
				else{
					newStart = i+1;
					break;
				}
			}
			//sacamos el valor
			ll idx = getInerQuery(curr, newStart, equalSign - 2);
			if(idx == -INF) return i+1;

			ll value = getInerQuery(curr, equalSign + 1, curr.length()-1);
			if(value == -INF) return i+1;
			if(!assignment(name, idx, value)) return i+1;
		}
		else
			initialize(curr);
	}
	return 0;
}

int main(){
	sync;
	string curr;
	ll prevPoint = false;
	vector<string> test;
	while(true){
		cin >> curr;
		if(curr == "." && prevPoint) break;
		else if(curr == ".") {
			cout << solveTest(test) << etr;
			prevPoint = true;
			arrays.clear();
			test.clear();
			continue;
		}
		else prevPoint = false;
		test.pb(curr);
	}
	return 0;
}