#include "gauss.h"
<<<<<<< HEAD
=======
#include <math.h>

>>>>>>> 6c0263ce6d6dfd1d2f8b0580dde3877d20eb41ff
/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b){

<<<<<<< HEAD
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
=======
	int n = mat->r;
	double **a = mat->data; //macierz A
	double **wektb = b->data; //wektor b
	double wspolczynnik;

	double atmp, btmp, max, x;
	int w, k, p, m, i;

	// Metoda wyboru elementu głównego
	for( w=0; w<n-1; w++)
	{
		max = fabs( a[w][w] );
		m = w;

		for( k= w+1; k<n; k++)
		{
			x = fabs( a[k][w] );

			if( x > max)
			{
				max = x;
				m = k;
			}
>>>>>>> 6c0263ce6d6dfd1d2f8b0580dde3877d20eb41ff

		}
		if( m != w )
		{
			btmp = wektb[w][0];
			wektb[w][0] = wektb[m][0];
			wektb[m][0] = btmp;
			for( i=w; i<n; i++)
			{
				atmp = a[w][i];
				a[w][i] = a[m][i];
				a[m][i] = atmp;
			}
		}
	}

	//Sprawdzenie, czy macierz jest osobliwa
	for(w=0; w<n-1; w++)
	{
		if( a[w][w] == 0 ) return 1;
	}

	// Metoda eliminacji Gaussa
	for(w=0; w<n; w++)
	{
		for(k= w+1; k<n; k++)
		{
			wspolczynnik = a[k][w]/ a[w][w];	
			
			for( p=0; p<n; p++)
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
                                                                                                 
