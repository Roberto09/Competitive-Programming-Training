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

int main(){
	int n,m;
	cin >> n >> m;
	int cont = 1;
	while(true){
		if(n==0 || m==0) break;
		char mat[m][n], dir;
		int posI,posJ;
		FOR(i,0,m){
			FOR(j,0,n){
				cin >> mat[i][j];
				if(mat[i][j]=='*'){
					posI = i, posJ = j;
					if(i==0) dir='D';
					else if(i==m-1) dir = 'U';
					else if(j==0) dir = 'R';
					else if(j==n-1) dir = 'L';
				}
			}
		}
		while(mat[posI][posJ]!='x'){
			switch(dir){
				case 'L':
					posJ--;
					break;
				case 'R':
					posJ++;
					break;
				case 'U':
					posI--;
					break;
				case 'D':
					posI++;
					break;
			}
			if(mat[posI][posJ] == '/'){
				switch(dir){
					case 'L':
						dir = 'D';
						break;
					case 'R':
						dir = 'U';
						break;
					case 'U':
						dir = 'R';
						break;
					case 'D':
						dir = 'L';
						break;
				}
			}
			else if(mat[posI][posJ] == '\\'){
				switch(dir){
					case 'L':
						dir = 'U';
						break;
					case 'R':
						dir = 'D';
						break;
					case 'U':
						dir = 'L';
						break;
					case 'D':
						dir = 'R';
						break;
				}
			}
		}
		mat[posI][posJ] = '&';
		cout << "HOUSE " << cont << etr;
		FOR(i,0,m){
			FOR(j,0,n){
				cout << mat[i][j];
			}
			cout << etr;
		}
		cin >> n >> m;
		cont++;
	}
	return 0;
}