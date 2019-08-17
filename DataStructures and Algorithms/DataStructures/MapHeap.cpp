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
#define INF 1E9 + 1;

/*map heap*/
struct Priority{
	vector<ii> heap;
	unordered_map<ll, ll> heapMap;
	bool order; //true -> max    false -> min

	void swap(ll pos1, ll pos2);
	bool compare(ll pos1, ll pos2);
	void popUp(ll pos);
	void popDown(ll pos);

	Priority(bool o);
	void push(ii p);
	void pop();
	ii top();
	bool empty();
	bool contains(ll numb);
	void changeValue(ll num, ll value);
	ll getValueOfNode(ll num);
};

Priority::Priority(bool o){
	heap.pb(mp(0, 0));
	order = o;
}

void Priority::swap(ll pos1, ll pos2){
	ii pair1 = heap[pos1], pair2 = heap[pos2];
	heapMap[pair1.first] = pos2;
	heapMap[pair2.first] = pos1;

	ii aux = heap[pos1];
	heap[pos1] = heap[pos2];
	heap[pos2] = aux;
}

bool Priority::compare(ll pos1, ll pos2){
	if(heap[pos1].second > heap[pos2].second)
		return order;
	return !order;
}

void Priority::popUp(ll pos){
	ll currPos = pos;
	ll posBefore;
	while(currPos > 1){
		posBefore = currPos/2;
		if(compare(currPos, posBefore)){
			swap(currPos, posBefore);
			currPos = posBefore;
		}
		else break;
	}
}

void Priority::popDown(ll pos){
	ll currPos = pos;
	ll right = pos*2, left = pos*2+1, posToChange;

	while(left < heap.size()){
		posToChange = (right >= heap.size() || compare(left, right)) ? left : right;
		if(compare(posToChange, currPos)){
			swap(currPos, posToChange);
			currPos = posToChange;
		}
		else break;
		left = currPos*2;
		right = currPos*2+1;
	}
}

void Priority::push(ii p){
	heapMap[p.first] = heap.size();
	heap.pb(p);
	popUp(heap.size() - 1);
}

void Priority::pop(){
	if(heap.size() == 1) return;
	swap(1, heap.size()-1);
	heapMap.erase(heap[heap.size() - 1].first);
	heap.pop_back();
	popDown(1);
}

ii Priority::top(){return heap[1];}

bool Priority::empty(){return heap.size() == 1;}

bool Priority::contains(ll num){return heapMap.count(num);}

void Priority::changeValue(ll num, ll value){
	ll pos = heapMap[num];
	ll prevValue = heap[pos].second;
	heap[pos].second = value;
	if(!(value > prevValue ^ order))
		popUp(pos);
	else
		popDown(pos);
}

ll Priority::getValueOfNode(ll num){
	ll pos = heapMap[num];
	return heap[pos].second;
}


int main(){
	Priority pq(false);
	pq.push(mp(1001, 4));
	pq.push(mp(1002, 30));
	pq.push(mp(1003, 30));
	pq.push(mp(1004, 30));
	pq.changeValue(1003, 2);
	pq.changeValue(1001, 1);
	pq.pop();
	FOR(i, 1, pq.heap.size()){
		cout << "(" <<  pq.heap[i].first << " " << pq.heap[i].second << ")  ";
	}
	cout << etr;

	return 0;
}

