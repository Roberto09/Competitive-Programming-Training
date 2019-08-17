#include <iostream>
// Horse
// Matricula: A00822089
// Nombre: Roberto Garcia Torres

using namespace std;
#define MAX 50

int horse(int n, int m){
	int mat[MAX][MAX];
	// AquÃ­ va tu codigo
	for(int i = 0; i < MAX; i++){
		for(int j = 0; j < MAX; j++) mat[i][j] = 0;
	}
	mat[0][0] = 1;
	for(int i = 0; i < MAX; i++){
		for(int j = 0; j < MAX; j++){
			int vert, hor;
			vert = i - 2;
			hor = j - 1;
			if(vert >= 0 && hor >= 0)
				mat[i][j] += mat[vert][hor];

			vert = i - 1;
			hor = j - 2;
			if(vert >= 0 && hor >= 0)
				mat[i][j] += mat[vert][hor];

		}
	}
	return mat[n-1][m-1];
}

int main(){
	int n, m;
	cin >> n  >> m;
	cout << horse(n, m)<<endl;
}