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
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define PI 3.1415926535897932384626433832795
#define mem(x, val) memset((x), (val), sizeof(x))
#define sz(x) (ll)(x).size()
#define endl '\n'
#define clockon int t = 1; while (t--) { clock_t z = clock();
#define clockoff debug("Elapsed Time: %.3f\n", (double)(clock() - z) / CLOCKS_PER_SEC); }
#define oo 2000000000000000000LL
#define EPS 1e-6

#define MOD 1000000007

struct node{
	ll needRight = 0;
	ll needLeft = 0;
	ll length = 0;
};

void constructTree(string &br, node segment[], int low, int high, int pos){
	if(low == high){
		segment[pos].length = 0;
		if(br[low] == ')') segment[pos].needLeft = 1;
		else segment[pos].needRight = 1;
		return;
	}
	int mid = low + (high-low)/2;
	constructTree(br, segment, low, mid, 2*pos+1);
	constructTree(br, segment, mid+1, high, 2*pos+2);
	node &left = segment[2*pos+1], &right = segment[2*pos+2];
	segment[pos].length = left.length + right.length + 2*min(right.needLeft, left.needRight);
	segment[pos].needLeft = left.needLeft + right.needLeft - min(right.needLeft, left.needRight);
	segment[pos].needRight = left.needRight + right.needRight - min(right.needLeft, left.needRight);
}

node query (node segment[], int qlow, int qhigh, int low, int high, int pos){
	//no overlap
	if(high < qlow || low > qhigh) return node();
	//total overlap 
	else if(low >= qlow && high <= qhigh) return segment[pos];
	//partial ovelap
	else{
		int mid = low + (high-low)/2;
		node left = query(segment, qlow, qhigh, low, mid, 2*pos +1);
		node right = query(segment, qlow, qhigh, mid+1, high, 2*pos +2);
		node resNode;
		resNode.length = left.length + right.length + 2*min(right.needLeft, left.needRight);
		resNode.needLeft = left.needLeft + right.needLeft - min(right.needLeft, left.needRight);
		resNode.needRight = left.needRight + right.needRight - min(right.needLeft, left.needRight);
		return resNode;
	}
}

node segment[4000000];

int main(){
	string s;
	ll n, l, r;
	cin >> s >> n;
	
	constructTree(s, segment, 0, s.length() -1 , 0);

	FOR(i, 0, n){
		cin >> l >> r;
		l--;
		r--;
		cout << query(segment, l, r, 0, s.length()-1, 0).length << "\n";
	}
	return 0;
}