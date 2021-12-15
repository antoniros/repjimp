#include "gauss.h"
#include "backsubst.h"
#include "gauss.h"
#include "backsubst.h"
#include "mat_io.h"
#include <stdlib.h>
#include <stdio.h>


int main(int argc, char ** argv) {
	
	//Wczytanie danych
	int res;	
	Matrix * A = readFromFile(argv[1]);
	Matrix * b = readFromFile(argv[2]);
	Matrix * x;
	
	if (A == NULL) return -1;
	if (b == NULL) return -2;
	

	//Rozwiazanie
	printf("Macierz A:\n");
	printToScreen(A);
	printf("\n");
	
	printf("Wektor B:\n");
	printToScreen(b);
	printf("\n");
	//Test poprawnosci danych
	if(A->r != A->c){
		printf("Macierz A nie jest kwadratowa.\n");
		return -3;
	}
	if(b->c !=1){
		printf("Wektor b nie jest wektorem kolumnowym.\n");
		return -4;
	}
	if(A->r != b->r){
		printf("Liczba wierszy macierzy A oraz wektora b nie jest rowna.\n");
		return -5;
	}
	
	res = eliminate(A,b);
	
	if( res == 1 )
	{
		printf("Macierz osobliwa.\n");
		return 1;
	}
	
	x = createMatrix(b->r, 1);
	if (x != NULL) {
		res = backsubst(x,A,b);
		printf("Wynik:\n");
		printToScreen(x);
	  	freeMatrix(x);
	} else {
		fprintf(stderr,"Błąd! Nie mogłem utworzyć wektora wynikowego x.\n");
	}

	freeMatrix(A);
	freeMatrix(b);

	return 0;
}

