#include "gauss.h"
#include <math.h>

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */

int eliminate(Matrix *mat, Matrix *b){

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
