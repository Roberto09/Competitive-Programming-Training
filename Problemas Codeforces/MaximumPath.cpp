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
#define INF 1E17

ll up[5][100005];
ll mid[7][100005];
ll down[5][100005];

ll matrix[3][100005];
bool vMatrix[3][100005];

ll n;

/*

5
10 10 10 -1 -1
-1 10 10 10 10
-1 10 10 10 10

*/

ll alg(ll prevHeight, ll actHeight, ll col){
	//llegue al final
	if(actHeight == 2 && col == n-1) return matrix[2][col];
	//la posicion actual no puede llegar
	if(col == n || vMatrix[actHeight][col]) return -INF;

	ll retVal = 0;
	vMatrix[actHeight][col] = true;

	if(actHeight == 0){
		//vino por la izquierda
		if(actHeight == prevHeight){
			//abajo no hay nada
			if(!vMatrix[1][col]){
				//abajo en la izquierda hay
				if(col > 0 && vMatrix[1][col-1]){
					//revisamos dp
					if(up[4][col] != -INF){
						retVal = up[4][col];
					}
					//podemos ir abajo y a la derecha
					else{
						retVal = up[4][col] = max(alg(actHeight, 1, col), alg(actHeight, actHeight, col+1));
					}
				}
				else{
					//revisamos dp
					if(up[0][col] != -INF){
						retVal = up[0][col];
					}
					//podemos ir abajo y a la derecha
					else{
						retVal = up[0][col] = max(alg(actHeight, 1, col), alg(actHeight, actHeight, col+1));
					}
				}
			}
			//abajo hay
			else{
				//revisamos dp
				if(up[2][col] != -INF) retVal = up[2][col];
				//solo podemos ir a la derecha
				else
					retVal = up[2][col] = alg(actHeight, actHeight, col+1);
			}
		}
		//vino por abajo
		else{
			//en la derecha abajo no hay nada
			if(col + 1 >= n || !vMatrix[1][col+1]){
				//checamos dp
				if(up[1][col] != -INF) retVal = up[1][col];
				//solo puedo ir a la derecha
				else{
					retVal = up[1][col] = alg(actHeight, actHeight, col+1);
				}
			}
			//en la derecha abajo hay algo
			else{
				//checamos dp
				if(up[3][col] != -INF) retVal = up[3][col];
				//solo puedo ir a la derecha
				else retVal = up[3][col] = alg(actHeight, actHeight, col+1);
			}
		}
	}
	
	else if(actHeight == 1){
		//venimos por arriba
		if(prevHeight == 0){
			//podemos ir a la izquierda
			if(col > 0 && !vMatrix[actHeight][col-1]){
				//checamos dp
				if(mid[5][col] != -INF) retVal = mid[5][col];
				//podemos ir a la izquierda, abajo o derecha
				else{
					retVal = mid[5][col] = max(alg(actHeight, actHeight, col-1), max(alg(actHeight, 2, col), alg(actHeight, actHeight, col+1)));
				}
			}
			else{
				//checamos dp
				if(mid[0][col] != -INF) retVal = mid[0][col];
				//podemor ir abajo o a la derecha
				else retVal = mid[0][col] = max(alg(actHeight, 2, col), alg(actHeight, actHeight, col+1));
			}
		}
		//venimos por abajo
		else if(prevHeight == 2){
			//podemos ir a la izquierda
			if(col > 0 && !vMatrix[actHeight][col-1]){
				//checamos dp
				if(mid[6][col] != -INF) retVal = mid[6][col];
				//podemos ir a la izquierda, arriba o derecha
				else{
					retVal = mid[6][col] = max(alg(actHeight, actHeight, col-1), max(alg(actHeight, 0, col), alg(actHeight, actHeight, col+1)));
				}
			}
			else{
				//checamos dp
				if(mid[1][col] != -INF) retVal = mid[1][col];
				//podemor ir arriba o a la derecha
				else retVal = mid[1][col] = max(alg(actHeight, 0, col), alg(actHeight, actHeight, col+1));
			}
		}
		//venimos por la izquierda o derecha
		else{
			//si la de abajo o la de arriba esta activa venimos por la derecha
			//arriba
			if(vMatrix[0][col]){
				//checamos dp
				if(mid[2][col] != -INF) retVal = mid[2][col];
				//solo puedo ir abajo
				else retVal = mid[2][col] = alg(actHeight, 2, col);
			}
			//abajo
			else if(vMatrix[2][col]){
				//checamos dp
				if(mid[3][col] != -INF) retVal = mid[3][col];
				//solo puedo ir arriba
				else retVal = mid[3][col] = alg(actHeight, 0, col);
			}
			//venimos por la izquierda
			else{
				//checamos dp
				if(mid[4][col] != -INF) retVal = mid[4][col];
				//podemos ir arriba, abajo o a la derecha
				else
					retVal = mid[4][col] = max(alg(actHeight, 0, col), max(alg(actHeight, 2, col), alg(actHeight, actHeight, col+1)));				
			}
		}
	}

	else{
		//vino por la izquierda
		if(actHeight == prevHeight){
			//ariba no hay nada
			if(!vMatrix[1][col]){
				//arriba en la izquierda hay
				if(col > 0 && vMatrix[1][col-1]){
					//revisamos dp
					if(down[4][col] != -INF){
						retVal = down[4][col];
					}
					//podemos ir arriba y a la derecha
					else{
						retVal = down[4][col] = max(alg(actHeight, 1, col), alg(actHeight, actHeight, col+1));
					}
				}
				else{
					//revisamos dp
					if(down[0][col] != -INF) retVal = down[0][col];
					//podemos ir arriba y a la derecha
					else{
						retVal = down[0][col] = max(alg(actHeight, 1, col), alg(actHeight, actHeight, col+1));
					}
				}
			}
			//arriba hay
			else{
				//revisamos dp
				if(down[2][col] != -INF) retVal = down[2][col];
				//solo podemos ir a la derecha
				else
					retVal = down[2][col] = alg(actHeight, actHeight, col+1);
			}
		}
		//vino por arriba
		else{
			//en la derecha arriba no hay nada
			if(col + 1 >= n || !vMatrix[1][col+1]){
				//checamos dp
				if(down[1][col] != -INF) retVal = down[1][col];
				//solo puedo ir a la derecha
				else{
					retVal = down[1][col] = alg(actHeight, actHeight, col+1);
				}
			}
			//en la derecha arriba hay algo
			else{
				//checamos dp
				if(down[3][col] != -INF) retVal = down[3][col];
				//solo puedo ir a la derecha
				else retVal = down[3][col] = alg(actHeight, actHeight, col+1);
			}
		}
	}


	vMatrix[actHeight][col] = false;
	if(retVal == -INF) return retVal;
	return retVal + matrix[actHeight][col];
}

int main(){
	sync;
	cin >> n;
	FOR(i, 0, 5){
		FOR(j, 0, n+2){
			up[i][j] = -INF;
			down[i][j] = -INF;
		}
	}
	FOR(i, 0, 7){
		FOR(j, 0, n+2){
			mid[i][j] = -INF;
		}
	}

	FOR(i, 0 , 3){
		FOR(j, 0, n){
			cin >> matrix[i][j];
		}
	}


	cout << alg(0, 0, 0) << etr;
	return 0;
}