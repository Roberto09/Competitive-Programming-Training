#include <iostream>
#include <math.h>
#include <cstring>

//https://codeforces.com/blog/entry/18051
using namespace std;
int MAX = 10000000;
const int N = 1e5;  // limit for array size
int n;  // array size
int t[2 * N];

void build() {  // build the tree
	for (int i = n - 1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];
}

void modify(int p, int value) {  // set value at position p
	for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
}

void modifyAddValueToInterval(int l, int r, int value) { //modify on interval [l, r)
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if (l&1) t[l++] += value;
		if (r&1) t[--r] += value;
	}
}

int query(int l, int r) {  // sum on interval [l, r)
	int res = 0;
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if (l&1) res += t[l++];
		if (r&1) res += t[--r];
	}
	return res;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", t + n + i);
	build();
	cout << endl;
	for(int i = 0; i <= 2*n; i++) cout << t[i] << endl;
	modifyAddValueToInterval(0, 3, 5);
	//			push();
	cout << endl << endl;
	for(int i = 0; i <= 2*n; i++) cout << t[i] << endl;
	//printf("%d\n", query(3, 11));
	return 0;
}