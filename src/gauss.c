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
	for( w=0; w<n; w++)
	{
		max = (double) fabs( a[w][w] );
		m = w;

		for( k= w+1; k<n; k++)
		{
			x = (double) fabs( a[k][w] );

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
		for(p=0; p<n; p++)  //Sprawdzenie czy macierz jest osobliwa
		{
			if(a[p][p] == 0){
				return 1;
			}
		}
		for( k=w+1; k<n; k++) //eliminacja Gaussa
		{
			wspolczynnik = a[k][w]/ a[w][w];	
			
			for(i = w+1; i<n; i++)
			{		
				a[k][i] = a[k][i] - wspolczynnik * a[w][i];
			}

			wektb[k][0] = wektb[k][0] - wspolczynnik * wektb[w][0];	
		}

	}

	mat->data = a;
	b->data = wektb;

	return 0;
}
