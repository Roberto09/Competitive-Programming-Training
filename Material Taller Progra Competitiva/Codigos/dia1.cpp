#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <queue>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

#define INF 1000000000
#define FOR(i, a, b) for(int i=int(a); i<int(b); i++)
#define FORC(cont, it) for(decltype((cont).begin()) it = (cont).begin(); it != (cont).end(); it++)
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

const int maxN = 1000000;

int N;
ll t[2*maxN];

void modify(int p, int v) {
    p+=N;
    t[p]=v;
    while(p>>=1) {
        t[p] = t[2*p] + t[2*p+1];
        //t[p] = t[p<<1] + t[p<<1|1]; // Optimizado
    }
}

ll query(int l, int r) { // [l, r)
    l+=N, r+=N;
    ll sum=0;
    for(; l<r; l>>=1, r>>=1) {
        if (l&1) sum+=t[l++];
        if (r&1) sum+=t[--r];
    }
    return sum;
}

ll fastPow(ll a, ll b) {
    ll ret=1;
    while(b>0) {
        if(b&1) ret=ret*a;
        a=a*a;
        b>>=1;
    }
    return ret;
}

ll gcd(ll a,ll b) {
    if(b) return gcd(b, a%b);
    return a;
}

ll mcm(ll a, ll b) {
    return a/gcd(a, b)*b;
}

const int maxP = 35000;
bool p[maxP];
vi divs[maxP];

int main() {
    memset(p, true, sizeof(p));
    // PlogP
    // sum(1, maxP, P/i)
    FOR(i,2,maxP) for(int j=2*i; j<maxP; j+=i) p[j]=false;
    
    // PloglogP
    FOR(i,2,maxP) if(p[i]) for(int j=i*i; j<maxP; j+=i) p[j]=false;
    
    FOR(i,1,maxP) for(int j=i; j<maxP; j+=i) divs[j].pb(i);
    
    FOR(i,0,divs[20].size()) {
        cout<<divs[20][i]<<" ";
    }
    
    vi primes;
    FOR(i,2,maxP) if(p[i]) primes.pb(i);
    cout<<primes.size()<<endl;
    return 0;
}
