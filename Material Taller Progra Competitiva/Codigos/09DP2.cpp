/*
	DP2 Guia Basica
		Combinatoria:
			N chose K (otra vez, espero que para este punto ya lo dominen y lo puedan implementar en menos de 2 minutos)
			La mayoria de las veces se tienen que transformar a N chose K
			Maneras de formar subconjuntos (problema de las bolitas y palitos):
				- Determinar cuantas tienen que haber minimo en cada subgrupo
				- Transformar a sumatorias de sumatorias
				- Aplicar NK
			Recursivo:
				- Identificar las relaciones entre los elementos y en base a eso plantear una recursion
				- Dado que podemos vistar k estados en el estado i la combinatoria esta dado por la siguiente formula:
					Ci=sum(1,k, Cj*NK())
					Para cada estado j al que podemos llegar desde el estado i multiplicarlo por la cantidad de maneras de llegar a el.
		Probabilidad:
			Recursivo:
				- Dado que podemos vistar k estados en el estado i la probabilidad esta dada por la siguiente formula:
					Pi=sum(1,k, Pj*p(i,j))
					Para cada estado j al que podemos llegar desde el estado i multiplicarlo por la probabilidad de llegar a el.
					Notar que es posible que muchos estados a los que podemos llegar sean iguales, en dicho caso se puede simplificar al replantear probabilidades o usando combinatoria
		Valor esperado
			Recursivo:
				- Dado que podemos vistar k estados en el estado i el valor esperado esta dada por la siguiente formula:
					Ei=sum(1,k, (Ej+c(i,j))*p(i,j))
					Para cada estado j al que podemos llegar desde el estado i sumar el costo de llegar a el y multiplicarlo por la probabilidad de llegar a el.
		Gauss Jordan
			- Usualmente Se utiliza para resolver problemas de probabilidad y valor esperado
			- Se identifican porque tienden a tener una logica recursiva con ciclos
			- Plantear la matriz y luego resolver de formulazo
			- Hint: Guass Jordan es O(N^3), asi que N tiende a ser <=500
			- Hint2: Ciertas variaciones de Gauss Jordan (como el de la ranita, que viene mas abajo) se pueden resolver en tiempo O(N)
*/
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

#define MOD 1000000007
#define maxN 1000

ll fact[maxN], rfact[maxN];

// Problema de las bolitas y palitos
// Problema estandard, se tienen B bolitas y P palitos
// De cuantas maneras diferentes podemos acomodar los palitos tal que siempre exista al menos 1 bolita a la izquierda y a la derecha de cada palito
// Ejemplo de 1 manera valida dadas 6 bolitas y 2 palitos: O|OOO|OO
// Solucion al problema original: NK(B-1, P)
// Variaciones:
// 1) Se tira un dado de 6 caras 10 veces, si solo nos interesa cuantas veces aparecio cada numero cuantos resultados diferentes podemos tener
//		Notar que es el problema de bolitas y palitos (bolitas es al cantidad de veces que aparecio cada numero y los palitos marcan la division de los numeros) pero ahora pueden haber bolitas 0 a la izquierda y derecha de cada palito
//		Dadas 10^6 Queries diferentes puedes solucionar cada query eficientemente?
// 2) Tienen que haber al menos K>1 bolitas a la izquierda y derecha de cada palito

int dp[maxN][maxN], c[maxN], N, K;

ll NK(int N, int K) {
	return fact[N] * rfact[K] % MOD*rfact[N - K] % MOD;
}

// Problema de las bolitas de colores:
// Tenemos N colores y cuantas bolitas de cada color
// De cuantas maneras diferentes podemos elegir K pelotas dado que no podemos agarrar mas bolitas de las que tenemos de dicho color.
// Variaciones:
// 1) Importa el orden en que las sacamos
// 2) No importa el orden sino solo con cuantas quedamos al final

// Ambas implementaciones resuelven la primera variacion

// Brute ya no es util tratar de transformar a DP tal cual, ya que necesitamos una dimension para cada una de los N colores.
// Necesitariamos O(N*C^N) con un DP naive derivado de esto.
int bruteColores(int k) {
	if (!k) return 1;
	ll ret = 0;
	FOR(i, 0, N) {
		if (c[i]) {
			c[i]--;
			ret += bruteColores(k - 1);
			c[i]++;
		}
	}
	return ret;
}

// Maneras de elegir K pelotas dado que tenemos N colores y cuantas de cada color
// O(N*K*K)
// Ejemplo de constraints validos:
// K=2000
// N=10
int solveColores(int n, int k) {
	if (n == N) return !k;
	if (~dp[n][k]) return dp[n][k];
	dp[n][k] = 0;
	FOR(i, 0, min(k, c[n])+1) {
		dp[n][k] = (dp[n][k] + solveColores(n + 1, k - i)*NK(k, i)) % MOD;
	}
	return dp[n][k];
}

// Problema de la ranita:
// Una ranita empieza en la posicion 0 y quiere llegar a la posicion N, dado que tenemos cuantos saltos puede dar por turno, cual es el valor esperado de turnos que le tomaria llegar ahi?
// Variaciones: 
// 1) Cual es la probabilidad de que termine en K turnos
// 2) Cual es la probabilidad de que llegue a la casilla M en exactamente K turnos

#define maxK 1000

double dpr[maxN];

// Resuelve problema original (en esta variacion cada movimiento tiene la misma probabilidad de ocurrir)
double solveRanita(int n) {
	if (n >= N) return 0;
	if (dpr[n] != -1) return dpr[n];
	dpr[n] = 0;
	// Si la ranita puede saltar 0, 1, 2 o 3 hacia adelante cada turno (necesitamos hacer las mates y despejar el valor esperado de dpr[n]
	return dpr[n] = (solveRanita(n + 1) + solveRanita(n + 2) + solveRanita(n + 3) + 4) / 3.;
	// Si la ranita puede saltar 1,2,3 o 4 hacia adelanta en cada turno
	//return dpr[n] = (solveRanita(n + 1) + solveRanita(n + 2) + solveRanita(n + 3) + solveRanita(n + 4)) / 4. + 1;
}

// Variacion extra de la ranita:
// La ranita puede saltar hacia atras!!
// Notar que hay una recursion ciclica imposible de eliminar :S
// Se resuelve con gauss jordan, se tienen que dejar todas las variables del lado izquierdo y las constantes del derecho.
// Despues se usa el algoritmo tal cual:
// Agarramos el primer renglon y lo utilizamos para despejar (dejar en 0s) la primera columna (N^2, porque son N operaciones por renglon y tenemos N renglones)
// Despejar la segunda columna usando el segundo renglon O(N^2)
// Despejar la columna i usando el renglon i O(N^2)
// Notar que repetimos para cada una de las N columnas, asi que queda O(N^3)
// Nos debe quedar una matriz con puros 0s, excepto en la diagonal principal y la ultima columna (las constantes)
// Simplificamos la matriz a una matriz unitaria dividiendo el renglon (notar que como todo es 0, solo necesitamos dividir la columna i y la constante)
// Usualmente la respuesta es el valor de la constante del primer renglon

// Problema reto: Dado que la ranita puede saltar de la casilla i a las casillas i-1, i y i+1 equiprobablemente (de la casilla 0 solo puede a la 0 y a la 1)
// Obtener el valor esperado de turnos que le tomara a la ranita llegar a la casilla N, en tiempo lineal
// Hint: Notar que la matriz de gauss jordan todo seran 0s, excepto a lo mucho 4 casillas por renglon.

// Variaciones de Gauss Jordan:
// 1) Se tiene una hormiga en un cubo, cual es el valor esperado de turnos que le tomara llegar a la esquina opuesta de donde empezo.
// 2) Cual es la probabilidad de que la ranita se regrese a la primera casilla al menos 1 vez antes de llegar a la meta.

// regresa x elevado a la n en modulo MOD
// O(logN)
ll fastPow(ll x, ll n) {
	ll ret = 1;
	while (n) {
		if (n & 1) ret = ret*x%MOD;
		x = x*x%MOD;
		n >>= 1;
	}
	return ret;
}

double mat[maxN][maxN];

// Resuelve una matriz de ecuaciones lineales usando Gauss-Jordan
void gaussJordan(int N) {
	FOR(i, 0, N) {
		FOR(j, 0, N) {
			if (i == j) continue;
			// Notar que estamos suponiendo que no hay 0s en la diagonal
			double mult = mat[j][i] / mat[i][i];
			FOR(k, i, N + 1) {
				mat[j][k] -= mat[i][k] * mult;
			}
		}
	}
}

// Problema reto, resuelvelo en tiempo lineal notando que hay muchos 0s en la matriz
double ranitaCiclos(int N) {
	// Resetear a 0s
	// Notar que tenemos la matriz NxN y aparte el renglon extra de las constantes
	FOR(i, 0, N + 1) FOR(j, 0, N + 2) mat[i][j] = 0;
	// Inicializar la primera posicion (mencione que como no podia saltar hacia atras solo tenia ahi mismo y adelante y son equiprobables)
	// Sale ese resultado sale de pasar variables al lado izquierdo E[0]=(E[0]+E[1])/2+1;
	mat[0][0] = 1. / 2.;
	mat[0][1] = -1. / 2.;
	mat[0][N + 1] = 1;
	FOR(i, 1, N) {
		// Notar los negativos, salen de despejar las Es a la izquierda en E[i]=(E[i-1]+E[i]+E[i+1])/3+1
		mat[i][i - 1] = -1. / 3.;
		mat[i][i] = 2. / 3.;
		mat[i][i + 1] = -1. / 3.;
		mat[i][N + 1] = 1;
	}
	// El ultimo renglon ya es la respuesta, entonces ya acabamos y sabemos que tiene un valor esperado de 0
	mat[N][N] = 1;
	gaussJordan(N + 1);
	return mat[0][N + 1] / mat[0][0];
}

int main() {
	// Precalcular factoriales
	fact[0] = 1;
	FOR(i, 1, maxN) fact[i] = fact[i - 1] * i%MOD;
	// Precalcular inversos multiplicativos de factoriales en tiempo lineal
	rfact[maxN - 1] = fastPow(fact[maxN - 1], MOD - 2);
	for (int i = maxN - 2; i >= 0; i--) rfact[i] = rfact[i + 1] * (i + 1) % MOD;
	K = 14;
	N = 3;
	memset(dp, -1, sizeof(dp));
	c[0] = 2, c[1] = 5, c[2] = 7;
	cout << bruteColores(K) << endl;
	cout << solveColores(0, K) << endl;
	N = 100;
	cout << fixed << setprecision(6);
	FOR(i, 0, N) dpr[i] = -1;
	cout << solveRanita(0) << endl;
	cout << ranitaCiclos(10) << endl;
	return 0;
}
