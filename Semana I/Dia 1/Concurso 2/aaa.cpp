#include <bits/stdc++.h>
#include <fstream>
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

bool isMay(char c){
	return (c>='A' && c <= 'Z');
}

bool isLow(char c){
	return (c>='a' && c <= 'z');
}

bool isSep(char c){
	return (c==' ' || c == ',' || c== '.');
}

int main(){
	ifstream fin("abbreviation.in", std::ifstream::in);
	ofstream fout("abbreviation.out", std::ofstream::out);
	string str;
	while(getline(cin,str)){
		string copy = "", currSeq="", currAbb="";
		bool fWord = false, copying = true, oneLetter = false;
		int i=0;
		int fChar,lChar;
		for(i;i<str.length();i++){
			oneLetter = false;
			if(isMay(str[i]) && (i==0 || isSep(str[i-1]))){
				int fCharWord = i;
				char currMay = str[i++];
				currSeq += currMay;
				while(i < str.length() && isLow(str[i])) currSeq += str[i++];
				if(i - fCharWord == 1) oneLetter = true;
				if(copying){
					if(!oneLetter && i < str.length()-1 && str[i] == ' ' && isMay(str[i+1])){
						currSeq += str[i];
						fChar = fCharWord;
						currAbb += currMay;
						copying = false;
						fWord = true;
					}
					else{
						copy += currSeq;
						if(i!=str.length()) copy += str[i];
						currSeq = "";
						currAbb = "";
						copying = true;
					}
				}
				else if(fWord){
					fWord = false;
					if(!oneLetter && i < str.length()-1 && str[i] == ' ' && isMay(str[i+1])){
						lChar = i - fChar;
						currAbb += currMay;
						currSeq += str[i];
					}
					else if(!oneLetter && (i==str.length() || isSep(str[i]))){
						currAbb += currMay;
						copy += currAbb + " (" + currSeq + ')';
						currAbb = "";
						currSeq = "";
						if(i!=str.length()) copy += str[i];
						copying = true;
					}
					else{
						copy += currSeq;
						if(i!=str.length()) copy += str[i];
						copying = true;
						currSeq = "";
						currAbb = "";
					}
				}
				else{
					if(!oneLetter && i < str.length()-1 && str[i] == ' ' && isMay(str[i+1])){
						lChar = i - fChar;
						currAbb += currMay;
						currSeq += str[i];
					}
					else{
					
						if(!oneLetter && (i==str.length() || isSep(str[i]))){
							currAbb += currMay;
							copy += currAbb + " (" + currSeq + ')';
							currAbb = "";
							currSeq = "";
							if(i!=str.length()) copy += str[i];
							copying = true;
						}
						else{
							currSeq += str[i];
							copy += currAbb + " (" + currSeq.substr(0,lChar) + ')' + currSeq.substr(lChar);
							currAbb = "";
							currSeq = "";
							copying = true;
						}
					}
				}
			}
			else copy += str[i];
		}
		cout << copy << etr;
	}
	return 0;
}