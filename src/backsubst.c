#include "backsubst.h"
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int  backsubst(Matrix *x, Matrix *mat, Matrix *b) {
	int n = mat->r;
	double **a = mat->data; 
	int w = 0;
	int k = 0;
	double s;
	if ((x->r != mat->r) || (b->r != mat->r) || (x->r != b->r))
		return 2;
	for(; w < n; w ++)
		if( a[w][w] == 0) return 1;
	for(w = n - 1; w >= 0; w--){
		s = 0;
<<<<<<< HEAD
		for(k = w +1; k <n; k++) 
			s = s + (a[w][k] * x->data[k][0] );
=======
		for(k = w +1; k < n; k++) 
			s = s + (a[w][k] * x->data[k][0]);
>>>>>>> 6cb2c0aedbe3f890d668bd0efa2b3315b44d1656
		x->data[w][0] = (b->data[w][0] - s) / a[w][w];	
	}
	return 0;
}

