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

string ans;
ll arr[26];
ll fact[17];

void factoriales(){
	fact[0] = 1;
	FOR(i,1,17){
		fact[i] = fact[i-1] * i;
	}
}

void count(string &pal){
	FOR(i,0,26){
		arr[i] = 0;
	}
	FOR(i,0,pal.size()){
		++arr[pal[i]-'A'];
	}
}

ll calculate(){
	ll counts = 0;
	ll rept = 1;
	FOR(i,0,26){
		counts += arr[i];
		if(arr[i] > 1) rept *= fact[arr[i]];
	}
	return fact[counts] / rept;
}

void solve(ll n){
	if(n == 0) return;
	ll left = 1;
	ll right;
	ll flag = true;
	FOR(i,0,26){
		if(arr[i] == 0) continue;
		if(!flag) left = right + 1;
		flag = false;
		--arr[i];
		right = left + calculate() - 1;
		++arr[i];
		//cout << left << " " << right << endl;
		if(left <= n && n <= right){
			//cout << "ENTRE" << endl;
			--arr[i];
			ans.pb('A'+i);
			solve(n-left+1);
			return;
		}
	}
}

int main(){
	sync;
	factoriales();

	string a;
	ll n;
	cin >> a >> n;
	while(a != "#" && n != 0){
		ans = "";
		count(a);
		solve(n);
		if(ans.size() < a.size()){
			FOR(i,0,26){
				while(arr[i] > 0){
					ans.pb('A' + i);
					--arr[i];
				}
			}
		}
		cout << ans << endl;
		cin >> a >> n;
	}


	return 0;
}