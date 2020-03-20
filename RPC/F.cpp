#include <bits/stdc++.h>
using namespace std;
 
typedef unsigned long long ll;
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
    //sync;
    int arr2[50010];
    int arr3[50010];
    int arr4[50010];
    int arr7[50010];
    int arr13[50010];

    arr2[0] = arr3[0] = arr4[0] = arr7[0] = arr13[0] = 0;
    arr2[1] = arr3[1] = arr4[1] = arr7[1] = arr13[1] = 1;
    FOR(i,2,50001){
    	arr2[i] = (2 * arr2[i-1] + arr2[i-2]) % 2;
    	arr3[i] = (2 * arr3[i-1] + arr3[i-2]) % 3;
    	arr4[i] = (2 * arr4[i-1] + arr4[i-2]) % 4;
    	arr7[i] = (2 * arr7[i-1] + arr7[i-2]) % 7;
    	arr13[i] = (2 * arr13[i-1] + arr13[i-2]) % 13;
    }

    int n;
    bool flag, div4;
    while(cin >> n){
    	flag = false;
    	if(arr2[n] == 0){
    		cout << "Pell's number " << n << " is divisible by 2" << etr;
    		flag = true;
    	}
    	if(arr3[n] == 0){
    		cout << "Pell's number " << n << " is divisible by 3" << etr;
    		flag = true;
    	}
    	if(arr4[n] == 0){
    		cout << "Pell's number " << n << " is divisible by 4" << etr;
    		flag = true;
    	}
    	if(arr7[n] == 0){
    		cout << "Pell's number " << n << " is divisible by 7" << etr;
    		flag = true;
    	}
    	if(arr13[n] == 0){
    		cout << "Pell's number " << n << " is divisible by 13" << etr;
    		flag = true;
    	}
    	if(!flag){
    		cout << -1 << endl;
    	}
    }

    return 0;

}

