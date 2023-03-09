//Nastase Maria
//311 CA
#include <stdio.h>
#define NMAX 100

//calcul 10 la puterea n
int power(int n)
{
	int P = 1, i;
	for (i = n; i >= 1; i--)
		P = P * 10;
	return P;
}

int calcul_numar(unsigned int N)
{
	unsigned int c[10] = {0}, nr = 0, cresc = 0, descresc = 0, num = 0;
	while (N > 0) {
		//determinare cifre N
		c[N % 10]++;
		N = N / 10;
		nr++;
	}
	if (c[0] > 0)
		nr = nr - c[0];
	for (unsigned int i = 1; i <= 9 && nr > 0; ++i) {
		while (c[i] > 0) {
			//formare nr cu cifre in ordine crescatoare
			cresc = cresc + power(nr - 1) * i;
			//formare nr cu cifre in ordine descrescatoare
			descresc = descresc + i * power(num);
			c[i]--;
			nr--;
			num++;
		}
	}
	if (c[0] > 0)
		descresc = descresc * power(c[0]);
	return (descresc - cresc);
}

int main(void)
{
	unsigned long N, v[NMAX] = {0}, nr = 1, repet = 0, k;
	scanf("%lu", &N);
	v[nr] = calcul_numar(N);
	nr++;
	while (repet == 0) {
		//identificare secventa
		v[nr] = calcul_numar(v[nr - 1]);
		for (unsigned int i = 1; i < nr && repet == 0; ++i)
			if (v[nr] == v[i]) {
				//numar repetat
				repet++;
				k = i;
			}
		nr++;
	}
	printf("%lu\n", k - 1);
	for (unsigned int i = k; i < nr - 1; ++i)
		printf("%lu ", v[i]);
	printf("\n");
	return 0;
}
