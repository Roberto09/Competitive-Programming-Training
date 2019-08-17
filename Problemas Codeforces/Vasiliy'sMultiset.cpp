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
#define bits 30

struct node{
	node *left;
	node *right;
	int count;
	node(){
		left = NULL;
		right = NULL;
		count = 0;
	}
};

int cnt = -1;
node mem[6000000];
node* newNode(){
	cnt ++;
	return &mem[cnt];
}
node *head = newNode();

void initTree(){
	node *actual = head;
	FOR(i, 0, bits){
		actual->left = newNode();
		actual->left->count = 1;
		actual = actual->left;
	}
}

void addNumber(int number){
	int mask = 1 << (bits-1);
	node *actual = head;
	FOR(i, 0, bits){
		if(number&mask){
			if(actual->right == NULL) actual->right = newNode();
			actual = actual->right;
		}
		else{
			if(actual->left == NULL) actual->left = newNode();
			actual = actual->left;
		}
		actual->count ++;
		mask >>= 1;
	}
}

void removeNumber(int number){
	int mask = 1 << (bits-1);
	node *actual = head;
	FOR(i, 0, bits){
		if(number&mask){
			if(actual->right->count == 1){
				actual->right = NULL;
				return;
			}
			actual = actual->right;
		}
		else{
			if(actual->left->count == 1){
				actual->left = NULL;
				return;
			}
			actual = actual->left;
		}
		actual->count --;
		mask >>= 1;
	}
}

int getBestResult(int number){
	int result = 0;
	int mask = 1 << (bits-1);
	node *actual = head;
	node *desiredNode;
	FOR(i, 0, bits){
		//mi bit es 1
		if(number&mask){
			//busco un 0
			desiredNode = actual->left;
			//checo si se puede
			if(desiredNode == NULL){
				//no se puede
				actual = actual->right;
				result <<= 1;
			}
			else{
				//si se puede
				actual = desiredNode;
				result <<= 1;
				result |= 1;
			}
		}
		//mi bit es 0
		else{
			//busco un 1
			desiredNode = actual->right;
			//checo si se puede
			if(desiredNode == NULL){
				//no se puede
				actual = actual->left;
				result <<= 1;
			}
			else{
				//si se puede
				actual = desiredNode;
				result <<= 1;
				result |= 1;
			}
		}
		mask >>= 1;
	}
	return result;
}

int main(){
	ll q;
	cin >> q;
	initTree();
	int x;
	char c;
	FOR(i, 0, q){
		cin >> c;
		cin >> x;
		if(c == '+'){
			addNumber(x);
		}
		else if(c == '-'){
			removeNumber(x);
		}
		else{
			cout << getBestResult(x) << etr;
		}
	}
	return 0;
}

