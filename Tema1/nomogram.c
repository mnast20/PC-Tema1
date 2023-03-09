//Nastase Maria
//311 CA
#include <stdio.h>
#define NMAX 300

//citire reguli
void retinere_reguli(int N, int M, int v[][NMAX])
{
	int nr, val;
	for (int i = 1; i <= N + M; ++i) {
		scanf("%d", &nr);
		for (int j = 1; j <= nr; ++j) {
			scanf("%d", &val);
			v[i][j] = val;
		}
	}
}

//parcurgere matrice pe linii si verificare reguli
int verificare_linii(int N, int M, int v[][NMAX], int c[][NMAX])
{
	int nr = 0, ok = 1, regula = 1;
	for (int i = 1; i <= N && ok == 1; ++i) {
		regula = 1;
		for (int j = 1; j <= M && ok == 1; ++j) {
			if (c[i][j] == 1) {
				nr++;
				if (c[i][j + 1] == 0 || j == M) {
					if (v[i][regula] != nr)
						ok = 0;
					regula++;
					nr = 0;
				}
			}
		}
		if (v[i][regula] != 0)
			ok = 0;
	}
	return ok;
}

//parcurgere matrice pe coloane si verificare reguli
int verificare_coloane(int N, int M, int v[][NMAX], int c[][NMAX])
{
	int linie = N + 1, nr = 0, ok = 1, regula = 1;
	for (int i = 1; i <= M && ok == 1; ++i) {
		regula = 1;
		for (int j = 1; j <= N && ok == 1; ++j) {
			if (c[j][i] == 1) {
				nr++;
				if (c[j + 1][i] == 0 || j == N) {
					if (v[linie][regula] != nr)
						ok = 0;
					regula++;
					nr = 0;
				}
			}
		}
		if (v[linie][regula] != 0)
			ok = 0;
		linie++;
	}
	return ok;
}

//initializare matrice reguli si nomograma
void golire(int N, int M, int v[][NMAX], int c[][NMAX])
{
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j)
			c[i][j] = 0;
	int j;
	for (int i = 1 ; i <= N + M; ++i) {
		j = 1;
		while (v[i][j] != 0) {
			v[i][j] = 0;
			j++;
		}
	}
}

int main(void)
{
	int T, N, M, v[NMAX][NMAX] = {0}, c[NMAX][NMAX] = {0}, rez[NMAX] = {0};
	scanf("%d", &T);
	for (int i = 1; i <= T; ++i) {
		scanf("%d%d", &N, &M);
		retinere_reguli(N, M, v);
		for (int k = 1; k <= N; ++k)
			for (int j = 1; j <= M; ++j)
				scanf("%d", &c[k][j]);
		if (verificare_linii(N, M, v, c) == 0 ||
			verificare_coloane(N, M, v, c) == 0)
			rez[i] = 0;
		else
			//nomograma identificata
			rez[i] = 1;
		if (T > 1)
			golire(N, M, v, c);
	}
	for (int i = 1; i <= T; ++i) {
		if (rez[i] == 0)
			printf("Eroare\n");
		else
			printf("Corect\n");
	}
	return 0;
}
