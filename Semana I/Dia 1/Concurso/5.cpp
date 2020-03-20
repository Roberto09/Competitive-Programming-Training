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

int I,J;
char matr[25][25];

void clear(){
	FOR(i,0,25){
		FOR(j,0,25) matr[i][j] = ' ';
	}
}

void buildPerim(int i,int j,int H, int W){
	matr[i][j] = matr[i][j+W-1] = matr[i+H-1][j] = matr[i+H-1][j+W-1] = '+';
	FOR(pos,i+1,i+H-1){
		matr[pos][j] = matr[pos][j+W-1] = '|';
	}
	FOR(pos,j+1,j+W-1){
		matr[i][pos] = matr[i+H-1][pos] = '-';
	}
}

void buildSmRect(int posI, int posJ, char num1, char num2){
	buildPerim(posI,posJ,5,5);
	int res = (num1-'0') * (num2-'0');
	matr[posI+1][posJ+1] = (char) (res/10 + '0');
	matr[posI+3][posJ+3] = (char) (res%10 + '0');
	matr[posI+1][posJ+3] = matr[posI+2][posJ+2] = matr[posI+3][posJ+1] = '/';
}

void writeAns(int i,int j,string n,string m){
	int ans = stoi(n) * stoi(m);
	char dir = 'L';
	while(ans!=0){
		if(ans >= 10) matr[i][j] = '/';
		if(dir=='L'){
			matr[i][j+2] = ans%10 + '0';
			if(j==1){
				dir = 'U';
				i-=4;
			}
			else j-= 4;
		}
		else{
			matr[i+2][j] = ans%10 + '0';
			i-= 4;
		}
		ans /= 10;
	}
}

int main(){
	string n,m;
	cin >> n >> m;
	while(true){
		clear();
		if(n[0]=='0') break;
		I = 8+ (m.length()-1) * 3 + m.length(), J = 8+ (n.length()-1) * 3 + n.length();
		buildPerim(0,0,I,J);
		FOR(i,0,n.length()){
			matr[1][(i+1)*4] = (char)(n[i]);
		}

		FOR(i,0,m.length()){
			matr[(i+1)*4][J-2] = (char)(m[i]);
		}
		int ans, ansI,ansJ;
		FOR(x,0,n.length()){
			FOR(y,0,m.length()){
				buildSmRect(4*y+2,4*x+2,n[x],m[y]);
				if(x == n.length()-1 && y == m.length()-1){
					ansI = 4*(y+1)+3, ansJ = 4*x + 1;
				}
			}
		}
		writeAns(ansI,ansJ,n,m);
		FOR(i,0,I){
			FOR(j,0,J) cout << matr[i][j];
			cout << etr;
		}
		cin >> n >> m;
	}
	return 0;
}