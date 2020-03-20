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
#define INF 1E15

struct vrt{
	unordered_map<ll, ll> chld; //map for children nodes
	bool leaf; //true if leaf node
	ll prnt; //link to parent vertex
	ll sufixLink; //link to sufix vertex
	ll endWordLink; //link to the leaf vertex of the max length word we can make form the current prefix
	ll wordId; //id of leaf word
	char chr;
	vrt(){
		leaf = false; prnt = -1; sufixLink = -1; wordId = -1; endWordLink = -1;
	}
};

// default values for Aho croasick
vector<vrt> trie;
ll sz = 0;
ll root = 0;
vector<string> words;
vi ress;

void addString(string &s, ll wrdId){
	ll currVertex = root;
	for(char c : s){
		if(!trie[currVertex].chld.count(c)){ //checking if a vertex with this edge doesn't exists in the trie
			trie.pb(vrt()); //add our new child
			trie[sz].prnt = currVertex;
			trie[sz].chr = c;
			trie[currVertex].chld[c] = sz;
			sz++;
		}
		currVertex = trie[currVertex].chld[c]; // changing our vertex
	}
	//mark length of word and store it's id
	trie[currVertex].leaf = true;
	trie[currVertex].wordId = wrdId;
}

void calcSuffLink(ll vertex){
	if(vertex == root){ // caso base, root
		trie[vertex].sufixLink = trie[vertex].endWordLink = root;
		return;
	}
	if(trie[vertex].prnt == root){ // caso base, primer caracter de una palabra (nunca tiene sufijo)
		trie[vertex].sufixLink = root;
		if(trie[vertex].leaf) trie[vertex].endWordLink = vertex;
		else trie[vertex].endWordLink = trie[trie[vertex].sufixLink].endWordLink;
		return;
	}

	ll currVertex = trie[trie[vertex].prnt].sufixLink; // sacamos el sufijo mas grande que hace match con el substring hasta el momento
	char cv = trie[vertex].chr; // sacamos el caracter actual
	while(1){
		if(trie[currVertex].chld.count(cv)){ // si el sufijo mas grande anterior contiene como siguiente caracter a nuestro caracer nos detenemos y ese es el sufijo
			trie[vertex].sufixLink = trie[currVertex].chld[cv];
			break;
		}
		if(currVertex == root){ // si llegamos a root entonces simplemente el sufijo es root
			trie[vertex].sufixLink = root;
			break;
		}
		currVertex = trie[currVertex].sufixLink; // si no hemos llegado a root y no hubo match entonces nos vamos al siguiente sufijo mas grande
	}
	if(trie[vertex].leaf) trie[vertex].endWordLink = vertex; // si el vertice actual es una leaf entonces este es el substring mas largo que podemos formar
	else trie[vertex].endWordLink = trie[trie[vertex].sufixLink].endWordLink; // de lo contrario utilizamos el endword-link de nuestro curr vertex aka nuestro sufix link
}

void prepareAho(){
	queue<ll> vq;
	vq.push(root);
	while(!vq.empty()){
		ll currVertex = vq.front(); vq.pop();
		calcSuffLink(currVertex);
		for(auto it = trie[currVertex].chld.begin(); it != trie[currVertex].chld.end(); it ++){
			vq.push(it->second);
		}
	}
}

ll processString(string  &text){
	ll currState = root;
	ll res = 0;
	FOR(i, 0, text.length()){ // iteramos sobre los caracteres de text
		char c = text[i];
		while(1){ // loop para encontrar nuestro siguiente nodo que haga match o root
			if(trie[currState].chld.count(c)){ // si el nodo actual tiene como siguiente caracter a c
				currState = trie[currState].chld[c];	// actualizamos nuestro curr state a ese nodo
				break;
			}
			if(currState == root) break; // si llegamos a root rompemos
			currState = trie[currState].sufixLink;	// si no hubo match ni somos root nos regresamos en nuetro sufix link buscando un match tentativo
		}
		
		ll checkState = currState; // curr state ahora tiene el valor de un nodo que hace match con el caracter actual o, de no ser asi, es root 
		while(1){
			checkState = trie[checkState].endWordLink; // obtenemos el enword link de este substring
			if(checkState == root) break; // si el checkState es root esto significa que no existe palabra alguna que sea sufijo del substring actual
			// si llegamos aqui significa que si existe al menos una palabra la cual sea un sufijo de nuestro substirng actual.
			res ++; // incrementamos nuestro resultado
			//ll idxOfMatch = i + 1 - words[trie[checkState].wordId].length(); // sacamos el idx of match sobre nuestro texto
			ress[trie[checkState].wordId] ++;
			checkState = trie[checkState].sufixLink; // actualizamos el checkstate a nuestro sufix li
		}
	}
	return res;
}

void initAho(){
	//Inicializar aho croasick
	trie.pb(vrt());
	sz ++;
}

int main(){
	initAho();
	ll n;
	cin >> n;
	FOR(i, 0, n){
		string s;
		cin >> s;
		words.pb(s);
		ress.pb(0);
		addString(s, i);
	}
	prepareAho();
	string pr;
	cin.ignore();
	getline(cin, pr);
	cout << processString(pr) << etr;
	FOR(i, 0, n){
		cout << (ress[i] > 0 ? 'y' : 'n') << etr;
	}

	return 0;
}
