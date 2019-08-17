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

string big, good, bad, goodSuf;
bool sufIsSame = false;

ll findApp(string &needdle, string &nest){
	ll cnt = 0;
	for(ll i = 0; i < (ll)((ll)nest.length() - (ll)needdle.length()) + 1; i++){
		if(nest[i] == needdle[0]){
			bool can = true;
			for(ll j = 0; j < needdle.length(); j++){
				if(needdle[j] != nest[i+j]){
					can = false;
					break;
				}
			}
			if(can) cnt ++;
		}
	}
	return cnt;
}

bool canFit(string &needle, string &nest, ll start){
	if(needle.length() > nest.length() - start) return false; 
	FOR(i, 0, needle.length()){
		if(nest[i+start] == '*' || nest[i+start] == needle[i]) continue;
		else return false;
	}
	return true;
}

string getSmallestSufix(string &curr){
	string pFix = "";
	ll cnt = 0;
	FOR(i, 0, curr.length()-1){
		pFix += curr[i];
		bool cool = true;
		FOR(j, 0, i+1){
			if(pFix[j] != curr[curr.length() - i - 1 + j]){
				cool = false;
				break;
			}
		}
		if(cool) cnt = i+1;
	}
	return curr.substr(cnt);
}

ll getDif(string &str){
	return findApp(good, str) - findApp(bad, str);
}

struct dpNode{
	bool calc;
	bool canUseSufRes;
    string bestRes;
  	string sufRes;

	dpNode(){
		calc = false; bestRes = ""; sufRes = ""; canUseSufRes = false;
	}
};

dpNode dpNds[1200];

void calcDp(ll ci){
  if(ci >= big.length() || dpNds[ci].calc) return;
	bool calculatedGood = false;
	ll lr0 = -INF, lr1 = -INF, lr2 = -INF, lr3 = -INF, lr4 = -INF, lr5 = -INF, lr6 = -INF;
  	string r0, r1, r2, r3, r4, r5, r6;
  	//3 opciones
  	//poner
  	if(canFit(good, big, ci)){
  		calculatedGood = true;
  		//poner + continuar
  		calcDp(ci + good.length());
  		if(dpNds[ci + good.length()].canUseSufRes){
	  		r0 = good + dpNds[ci + good.length()].sufRes;
	  		lr0 = getDif(r0);
  		}
    	//poner + sig posisicion imediata
    	r1 = good + dpNds[ci + good.length()].bestRes;
    	lr1 = getDif(r1);
    	//poner + un skip despues de poner
    	calcDp(ci + good.length() + 1);
    	r2 = good + big[ci + good.length()] + dpNds[ci + good.length() + 1].bestRes;
    	lr2 = getDif(r2);
  	}
  	//skip
  	//simplemente hacer skip
  	calcDp(ci+1);
  	r3 = big[ci] + dpNds[ci + 1].bestRes;
  	lr3 = getDif(r3);

  	dpNds[ci].calc = true;
  	//decide best to put
  	if(calculatedGood){
		if(lr0 >= lr1 && lr0 >= lr2 && lr0 >= lr3) dpNds[ci].bestRes = r0;
		else if(lr1 >= lr2 && lr1 >= lr3 && lr1 >= lr0) dpNds[ci].bestRes = r1;
		else if(lr2 >= lr1 && lr2 >= lr3 && lr2 >= lr0) dpNds[ci].bestRes = r2;
		else dpNds[ci].bestRes = r3;
  	}
  	else{
  		dpNds[ci].bestRes = r3;
  	}
  
	//poner sufijo
  	if(!sufIsSame && canFit(goodSuf, big, ci)){
    	//poner + volver a poner sufijo
    	calcDp(ci + goodSuf.length());
    	calcDp(ci + goodSuf.length() + 1);
    	if(dpNds[ci + goodSuf.length()].canUseSufRes){
    		r4 = goodSuf + dpNds[ci + goodSuf.length()].sufRes;
    		lr4 = getDif(r4);
    	}
    	//poner + poner normal
    	r5 = goodSuf + dpNds[ci + goodSuf.length()].bestRes;
    	lr5 = getDif(r5);
    	//poner un skip despues de poner
    	r6 = goodSuf + big[ci + goodSuf.length()] + dpNds[ci + goodSuf.length()+1].bestRes;
    	lr6 = getDif(r6);


    	if(lr4 >= lr5 && lr4 >= lr6) dpNds[ci].sufRes = r4;
		else if(lr5 >= lr4 && lr5 >= lr6) dpNds[ci].sufRes = r5;
		else dpNds[ci].sufRes = r6;
		dpNds[ci].canUseSufRes = true;
  	}
}

ll getDpRes(){
	ll mxmx = -INF;
	calcDp(0);
	return getDif(dpNds[0].bestRes);
}

void clearDp(){
	FOR(i, 0, 1200) dpNds[i] = dpNode();
}

int main(){
	sync;
	clearDp();
	cin >> big >> good >> bad;
	goodSuf = getSmallestSufix(good);
  	sufIsSame = good == goodSuf;
	cout << getDpRes() << etr;

	return 0;
}