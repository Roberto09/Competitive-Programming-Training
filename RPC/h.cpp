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

int twos[10005],fives[10005];

void multiplyBy(string &num, int n){
	//reverse(num.begin(),num.end());
	int sobran = 0;
	for(int i=0; i < num.length(); i++){
		int curr_num = num[i]-'0', mult = curr_num * n + sobran;
		num[i] = mult%10+'0';
		sobran = mult/10;
	}
	if(sobran)num+=sobran + '0';
	//reverse(num.begin(),num.end());
}

int main(){
    sync;
    string two="1", five = "1";
    for(int i=1; i < 10004; i++){
    	multiplyBy(two,2);
    	multiplyBy(five,5);
    	// cout << two << " " << five << endl;
    	twos[i] = two.length();
    	fives[i] = five.length();
    }
    int t;
    cin >> t;
    int a,b,ans = 0;
    for (int test = 0; test < t; ++test)
    {
    	ans = 0;
    	cin >> a >> b;
    	ans+= min(a,b);
    	if(a<b){
    		ans += fives[b-a];
    	}
    	else if(b<a){
    		ans += twos[a-b];
    	}
    	else ans++;
    	cout << ans << endl;
    }
    return 0;

}

