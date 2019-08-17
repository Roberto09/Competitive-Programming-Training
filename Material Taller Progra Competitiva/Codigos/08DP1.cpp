/*
	DP: Dynamic Programming

	Consiste en: solucionar el problema y luego optimizarlo al darse cuenta que los estados son repetidos y se puede evitar calcularlos muchas veces.
	Llamamos un estado toda la información relevante al DP, en mochila el estado es representado por el indice de la mochila en la que vamos y el peso que podemos cargar en la bolsa

	Cuando podemos aplicar DP?
		a) al menos 1 dimension siempre crece: Yes
		b) al menos 1 dimension siempre decrece: Yes
		c) al menos 1 dimension siempre crece o es igual: Yes (siempre y cuando no existan ciclos o se lidien con ellos)
		d) al menos 1 dimension siempre decrece o es igual Yes (siempre y cuando no existan ciclos o se lidien con ellos)
		e) Todas las dimensiones pueden crecer y decrecer o mantenerse igual: Probablemente no es dp
		f) Existen ciclos: Definitivamente no es dp

	Un ciclo es cuando de un estado existe un camino que puedo tomar que me vuelva a llevar a dicho estado.
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

#define maxW 5000
#define maxN 20
int peso[maxW], cost[maxW];

// El problema de la mochila es que tenemos N articulos, cada uno con un peso y un valor.
// Tambien tenemos una mochila que puede cargar W en peso sin romperse
// Cuando es el maximo valor que podemos cargar en nuestra mochila sin que se rompa?

// n = Item id
// w = peso que la mochila soporta
// Orden factorial
int bruteMochila(int n, int w) {
	if (w < 0) return -INF;
	if (!n) return 0;
	return max(bruteMochila(n-1, w), bruteMochila(n - 1, w - peso[n]) + cost[n]);
}

int dp[maxN][maxW];

// O(N*W)
int dpMochila(int n, int w) {
	if (w < 0) return -INF;
	if (!n) return 0;
	if (~dp[n][w]) return dp[n][w];
	return dp[n][w] = max(dpMochila(n - 1, w), dpMochila(n - 1, w - peso[n]) + cost[n]);
}

// El problema del viajero consiste en que un viajero quiere visitar todas las N ciudades de un pais, cual es el menor costo de hacer eso?
// Tambien se le conoce como TSP (Traveling Salesman Problem).
// En esta variacion un hombre quiere vender sus productos en cada una de las ciudades empezando en su ciudad natal y terminando en su ciudad natal.
// Usualmente queremos precalcular los costos y tenerlos en costViajero (podemos usar Floyd)
int N, dpViajero[maxN][1 << maxN], vis[maxN], costViajero[maxN][maxN];

// Dada una matriz de adyacencias actualiza costViajero[i][j] => el costo minimo de viajar desde la ciudad i a la ciudad j, potencialmente visitando otras.
// O(N^3)
// Nota especial: Debido a que floyd puede usar ciudades intermedias entre i y j,
// Solo precalculamos con floyd si no nos importa cuantas veces visitemos cada ciudad con que sea al menos 1 vez.
// En caso de que cada ciudad deba ser visitada exactamente 1 vez, no es conveniente precalcular con floyd.
void precalcFloyd(int N) {
	FOR(k, 0, N) {
		FOR(i, 0, N) {
			FOR(j, 0, N) {
				costViajero[i][j] = min(costViajero[i][j], costViajero[i][k] + costViajero[k][j]);
			}
		}
	}
}

// Brute viajero visitar todos los nodos en cualquier orden.
// O(N!*N)
int bruteViajero(int n) {
	// Caso base ya visitamos todo.
	bool end = true;
	FOR(i, 0, N) if (!vis[i]) end = false;
	if (end) return 0;
	int ret = INF;
	FOR(i, 0, N) {
		// Recordar que vis nos indica si ya visitamos un estado o no.
		if (!vis[i]) {
			vis[i] = 1;
			ret=min(ret, bruteViajero(i)+costViajero[n][i]);
			vis[i] = 0;
		}
	}
	return ret;
}

// si mask tiene un 1 significa que podemos visitarlo
// 0 en mask significa que ya todo esta visitado
// O(N^2*2^N)
int solveViajero(int n, int mask) {
	if (!mask) return 0;
	int &c = dpViajero[n][mask];
	if (~c) return c;
	c = INF;
	// Problema reto:
		// Optimiza el metodo solveViajero para que no tenga que iterar sobre los N elementos para ver cuales podemos visitar.
		// Si podemos visitar k ciudades, que haga solamente k iteraciones.
		// Tip: Bitwise operators
		// Nota: Hacer esto reduce la constante, sin embargo la complejidad sigue siendo la misma
	FOR(i, 0, N) {
		// Si el bit esta prendido si podemos visitar esa ciudad.
		if (mask & 1 << i) {
			c = min(c, solveViajero(i, mask ^ 1 << i) + costViajero[n][i]);
		}
	}
	return c;
}

// Pasc es el triangulo de pascal i,j corresponde a la formula de combinatoria i!/(j!*(i-j)!)
ll pasc[maxN][maxN];

int main() {
	// Precalcular triangulo de pascal: 
	pasc[0][0] = 1;
	FOR(i, 1, maxN) {
		pasc[i][0] = 1;
		for (int j = 1; j <= i; j++) {
			pasc[i][j] = pasc[i - 1][j - 1] + pasc[i - 1][j];
		}
	}

	// Mochila iterativo
	int W;
	// Complejidad de tiempo O(N*W)
	// O(N*W) memoria
	FOR(i, 0, N) {
		FOR(j, 0, peso[i]) dp[i][j] = dp[i - 1][j];
		FOR(j, peso[i], W) {
			dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - peso[i]] + cost[i]);
		}
	}
	// Optimizacion de mochila, misma complejidad de tiempo O(N*W)
	// O(W) memoria 
	// A esta tecnica se le llama reduccion de dimension y lo podemos utilizar para que sea mas rapido el programa (por una constante), ya que puede mantener en memoria cache todo el arreglo.
	int dp2[maxW];
	memset(dp2, 0, sizeof(dp2));
	FOR(i, 0, N) {
		for (int j = W; j >= peso[i]; i--) {
			dp2[j] = min(dp2[j], dp2[j - peso[i]] + cost[i]);
		}
	}
	// Variaciones de mochila: 
	// Existe un numero practicamente infinito de items de cada tipo. (puedes agarrar muchas veces el item i)
	// Cada item i se puede agarrar k[i] veces.
	// Cada item tiene 2 costos a y b, encuentra que items seleccionar para que el min(c,d) sea el maximo posible, donde c es la suma de a de los elementos seleccionados y d es la suma de sus bs

	

	// TSP
	// Dado que ya tenemos el dp programado iteramos sobre todas las ciudades y vemos empezando en cual se obtiene el menor costo
	int maskInicial = (1 << N) - 1, ans = INF;
	FOR(i, 0, N) {
		ans = min(ans, solveViajero(i, maskInicial ^ 1 << i));
	}
	// Variaciones de TSP: 
	// Empezar en la ciudad m
	// Terminar en la ciudad k
	// Cada ciudad se puede visitar solo 1 vez

	// Tema extra:
	// LIS (Longest Increasing Subsequence)
	// Tenemos un arreglo y queremos encontrar la subsecuencia mas grande de dicho arreglo tal que todos los elementos esten en orden estrictamente ascedente
	// Solucion: Tenemos un segundo arreglo que contiene una subsecuencia y vamos modificandolo, hacemos busqueda binaria en el y ahi ponemos el nuevo valor, si es el mas grande lo insertamos al final.
	// Si solo queremos el tamaño de la subsecuencia con el tamaño del arreglo auxiliar (lis) es suficiente, si queremos reconstruir necesitamos saber el ID de cada elemento de lis y cual era el previo cuando lo introdujimos a lis.
	// ejemplo de input: 1, 4, 3, 2, 6, 7, 1, 2, 3
	// respuesta esperada: 1,2,6,7
	cin >> N;
	int a[maxN], lis[maxN], id[maxN], prev[maxN], lc = 0;
	FOR(i, 0, N) cin >> a[i];
	// LIS
	FOR(i, 0, N) {
		int p = lower_bound(lis, lis + lc, a[i]) - lis;
		if (p) {
			prev[i] = id[p - 1];
		}
		else prev[i] = -1;
		lis[p] = a[i];
		id[p] = i;
		if (p == lc) lc++;
	}
	// Reconstruimos la respuesta y guardamos en st
	int st[maxN], sc = 0, id2 = id[lc - 1];
	while (~id2) {
		st[sc++] = a[id2];
		id2 = prev[id2];
	}
	// Imprimimos la respuesta en orden invertido ya que reconstruimos de mayor a menor
	cout << lc << endl;
	for (int i = sc - 1; i >= 0; i--) {
		cout << st[i] << " \n"[!i];
	}
	// Variaciones de LIS: 
	// El orden final no tiene que ser estrictamente ascendente (1,1,1,2,3,4,4,5 es un ejemplo valido de respuesta)
	// De mayor a menor (9,4,2,1 es un ejemplo de respuesta)
	// No es necesario reconstruir la respuesta

	// Ejemplo de LIS: 
	// Se tienen 1<=N<=10^5 puntos en el espacio (x,y), encuentra el subset de mayor tamaño tal que para cada punto en el subset si x[i]<x[j] entonces y[i]<y[j]
	return 0;
}
