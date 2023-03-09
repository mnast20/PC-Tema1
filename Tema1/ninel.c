//Nastase Maria
//311 CA
#include <stdio.h>

int main(void)
{
	long N, ant, mij, post, S = 0, nr = 0, nr_apar = 0;
	long xmin_par = 1000000, xmax_impar = -1;
	double m_a = 0.0;
	scanf("%lu", &N);
	scanf("%lu", &ant);
	scanf("%lu", &mij);
	for (long i = 2; i < N; i++) {
		scanf("%lu", &post);
		//identificare copaci speciali
		if (mij > ant && mij > post) {
			//s-a identificat copac special
			S += mij;
			nr++;
			if ((i - 1) % 2 == 1 && mij > xmax_impar) {
				//cel mai inalt copac de indice par
				xmax_impar = mij;
			} else if ((i - 1) % 2 == 0 && mij < xmin_par) {
				//cel mai mic copac de indice impar
				xmin_par = mij;
				nr_apar++;
			}
		}
		//reinitializare
		ant = mij;
		mij = post;
	}
	if (nr == 0) {
		xmin_par = 0;
		xmax_impar = 0;
	} else {
		if (nr_apar == 0)
			xmin_par = -1;
		m_a = (double)S / nr;
	}
	printf("%lu\n%0.7f\n%lu\n%ld\n", S, m_a, xmax_impar, xmin_par);
	return 0;
}
