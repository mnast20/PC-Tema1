//Nastase Maria
//311 CA
#include <stdio.h>
#define NMAX 101
void sortare_vector(unsigned int N, unsigned int v[NMAX])
{
	unsigned int aux;
	for (unsigned int i = 1; i <= N; ++i)
		while ((v[i - 1] < v[i]) && (i >= 2)) {
			aux = v[i - 1];
			v[i - 1] = v[i];
			v[i] = aux;
			i--;
		}
}

int main(void)
{
	unsigned int N, x, c, v[NMAX], p_min, ok = 0;
	unsigned long S = 0;
	int dif, sum = 0;
	scanf("%u", &N);
	for (unsigned int i = 1; i <= N; ++i) {
		//citire note
		scanf("%u", &x);
		//stocare penalizari
		v[i] = 10 - x;
	}
	for (unsigned int i = 1; i <= N; ++i) {
		//citire credite
		scanf("%u", &c);
		//calcul punctaj
		S += c * (10 - v[i]);
		//calcul penalizare in credite
		v[i] = c * v[i];
	}
	scanf("%u", &p_min);
	//diferenta punctaj minim si punctaj elev
	dif = p_min - S;
	if (dif > 0) {
		sortare_vector(N, v);
		for (unsigned int i = 1; i <= N && ok == 0; ++i) {
			sum += v[i];
			if (sum >= dif) {
				ok = 1;
				//identificare nr minim mariri
				printf("%u\n", i);
			}
		}
		if (ok == 0)
			printf("%d\n", -1);
	} else {
		printf("%d\n", -1);
	}
	return 0;
}
