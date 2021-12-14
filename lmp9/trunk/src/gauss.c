#include "gauss.h"
/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b){

        int n = mat->r;
	int mx, w, k;
	double *temp;
	double tempb;
        double **a = mat->data;
        double **wektb = b->data;
        double wspolczynnik;
	
        for(w=0; w<n; w++)
        {
                if( a[w][w] == 0 ) return 1;
        }

        for(w=0; w < n; w++)
        {
		mx = w;
		for(k = w + 1; k < n; k++)
			if(a[k][w] > a[mx][w])
				mx = k;
		if (mx != k) {
			temp = a[w];
			a[w] = a[mx];
			a[mx] = temp;
			tempb = wektb[w][0];
			wektb[w][0] = wektb[mx][0];
			wektb[mx][0] = tempb;
		}		
                for(int k= w+1; k<n; k++)
                {
                        wspolczynnik = a[k][w]/ a[w][w];

                        for(int p=0; p<n; p++)
                        {
                                a[k][p] = a[k][p] - wspolczynnik * a[w][p];
                                wektb[k][0] = wektb[k][0] - wspolczynnik * wektb[w][0];

                        }
                }
        }

        mat->data = a;
        b->data = wektb;

        return 0;
}
                                                                                                 
