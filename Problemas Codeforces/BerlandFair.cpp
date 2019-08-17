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
#define INF 10E9;

struct Node{
	ll val;
	Node *next;
};

Node arr[200010];

Node* newNode(ll &n){
	n++;
	return  &(arr[n]);
}

int main(){
	sync;
	ll  n, money;
	cin >> n >> money;
	ll totalSum = 0;
	ll res = 0;
	ll size = n;
	ll cnt = -1;


	Node *dh = newNode(cnt);
	Node *start = newNode(cnt);
	dh->next = start;
	cin >> start->val;
	totalSum += start->val;

	Node *prev = start;
	FOR(i, 1, n){
		prev->next = newNode(cnt);
		cin >> prev->next->val;
		totalSum += prev->next->val;
		prev = prev->next;
	}
	prev->next = NULL;
	while(n > 0){
		res += (money / totalSum) * n;
		money = money % totalSum;
		Node *curr = dh;
		ll subTotalMoney = money;
		totalSum = 0;
		n = 0;
		while(curr->next != NULL){
			if(subTotalMoney == 0){
				curr->next = NULL;
				break;
			}
			else if(curr->next->val > subTotalMoney){
				curr->next = curr->next->next;
			}
			else{
				n++;
				subTotalMoney -= curr->next->val;
				totalSum +=  curr->next->val;
				curr = curr->next;
			}
		}	
	}

	cout << res << etr;
	return 0;
}