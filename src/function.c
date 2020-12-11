#include <stdlib.h>
#include <stdbool.h>

void fillBool(bool *a, bool val, int len){
        for(int i = 0; i < len; i++)
                a[i] = val;
}

void fillDob(double *a, int val, int len){
        for(int i = 0; i < len; i++)
                a[i] = val;
}

int min(int a, int b){
        if (a < b)
                return a;
        return b;
}

int minDob(double a, double b){
        if (a < b)
                return a;
        return b;
}

int ** memoryInt2D(int len){
        int **A = (int **)malloc(len*sizeof(int *));

        for(int i = 0; i < len; i++)
                A[i] = (int *)malloc(len*sizeof(int));

        return A;
}

void freeInt2D(int **A, int len){
	for(int i = 0; i < len; i++)
		free(A[i]);
	free(A);
}

double ** memoryDob2D(int len){
        double **A = (double **)malloc(len*sizeof(double *));

        for(int i = 0; i < len; i++)
                A[i] = (double *)malloc(len*sizeof(double));

        return A;

}

void freeDob2D(double **A, int len){
        for(int i = 0; i < len; i++)
                free(A[i]);
        free(A);
}

int * memoryInt1D(int len){
        int *A;
        A = malloc(len*sizeof(int));

        return A;
}

double * memoryDob1D(double len){
        double *A;
        A = malloc(len*sizeof(double));

        return A;
}


bool * memoryBool1D(int len){
        bool *A;
        A = malloc(len*sizeof(bool));

        return A;
}
