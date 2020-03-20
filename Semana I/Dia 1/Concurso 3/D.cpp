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
#define MAX 4100

ll cost[MAX][MAX];
ll aux[MAX][MAX];
ll n, k;
ll dp[MAX][MAX];

void clear(){
}


void fastscan(int &number) 
{ 
    //variable to indicate sign of input number 
    bool negative = false; 
    register int c; 
  
    number = 0; 
  
    // extract current character from buffer 
    c = getchar(); 
    if (c=='-') 
    { 
        // number is negative 
        negative = true; 
  
        // extract the next character from the buffer 
        c = getchar(); 
    } 
  
    // Keep on extracting characters if they are integers 
    // i.e ASCII Value lies from '0'(48) to '9' (57) 
    for (; (c>47 && c<58); c=getchar()) 
        number = number *10 + c - 48; 
  
    // if scanned input has a negative sign, negate the 
    // value of the input number 
    if (negative) 
        number *= -1; 
}


void readFast(){
	char aux2;
	int b;
	FOR(i,0,n){
		FOR(j,0,n){
			fastscan(b);
			aux[i][j] = (ll)b;
		}
	}
}

void CreateCostMatrix(){
	for(int i = n-2; i >= 0; i--){
		for(int j = i + 1; j < n; j++){
			cost[i][j] = cost[i][j-1] + cost[i+1][j] - cost[i+1][j-1] + aux[i][j];
		}
	}
}

void print(){
	FOR(i,0,n){
		FOR(j,0,n){
			cout << cost[i][j] << " ";
		}
		cout << endl;
	}
}

ii comp(ii& a, const ii& b){
	if(a.first == b.first){
		if(a.second < b.second){
			return b;
		}
		return a;
	}
	return min(a,b);
}

void solve(ll k, ll nl, ll nr, ll jl , ll jr){
	//if(nl == n) return;
	if(nl > nr) return;
	ll mid = (nl + nr) / 2;
	ii best = {INF, INF}; 
	
	for(int i = jl; i <= min(jr, mid) ; i++){
		best = comp(best, {dp[i-1][k-1] + cost[i][mid], i});
	}


	dp[mid][k] = best.first;
	ll opt = best.second;  

	solve(k,nl, mid - 1, jl, opt);
	solve(k,mid + 1, nr,opt, jr);
}



int main(){
	clear();
	//sync;
	scanf("%lld %lld ", &n, &k);
	readFast();
	CreateCostMatrix();
	FOR(i,0,n){
		dp[i][0] = cost[0][i];
	}


	FOR(i,1,k){
		solve(i,0,n-1,0,n-1);
	}

	//print();

	printf("%lld\n", dp[n-1][k-1]);

	return 0;
}