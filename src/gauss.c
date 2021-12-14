#include "gauss.h"

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */

int eliminate(Matrix *mat, Matrix *b){

        int n = mat->r;
        double **a = mat->data;
        double **wektb = b->data;
        double wspolczynnik;

        for(int s=0; s<n; s++)
        {
                if( a[s][s] == 0 ) return 1;
        }

        for(int w=0; w<n-1; w++)
        {
                for(int k= w+1; k<n; k++)
                {
                        wspolczynnik = a[k][w]/ a[w][w];

                        for(int p=0; p<n; p++)
                        {
                                a[k][p] = a[k][p] - wspolczynnik * a[w][p];
                        }

                        wektb[k][0] = wektb[k][0] - wspolczynnik * wektb[w][0];
                }
        }

        mat->data = a;
        b->data = wektb;

        return 0;
}
