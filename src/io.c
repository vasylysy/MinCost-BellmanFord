#include <stdlib.h>
#include <stdio.h>

#include "function.h"

void outputFile(double **A, double **cost,int prod, int apt){
        FILE *out = fopen("output.txt", "w");

        for(int i =  0; i < prod; i++)
                for(int j = prod; j < prod+apt; j++)
                        if(A[i][j] != 0)
                                fprintf(out, "\n%d -> %d [Koszt = %.0lf * %.2lf = %.2lf zl]", i, j-prod, A[i][j], cost[i][j], A[i][j]*cost[i][j]);

        fprintf(out, "\nOplaty calkowite: %0.2lf zl\n", A[0][0]);

        fclose(out);
}

void outputScreen(double **A, double **cost, int prod, int apt){
        for(int i =  0; i < prod; i++)
                for(int j = prod; j < prod+apt; j++)
                        if(A[i][j] != 0)
                                printf("\n%d -> %d [Koszt = %.0lf * %.2lf = %.2lf zl]", i, j-prod, A[i][j], cost[i][j], A[i][j]*cost[i][j]);

        printf("\nOplaty calkowite: %0.2lf zl\n", A[0][0]);
}

int errInpCheck(char *file){
	FILE *in = fopen(file, "r");
	
	if(in == NULL)
		return 1;
	
	int c, k = 0;

        while ((c = fgetc(in)) != EOF){
        	if (c == '\n')
                k++;
        }

	if(k == 0)
		return 2;
	
	fclose(in);

	return 0;
}

double *fileRead(char *file){
        FILE *in = fopen(file, "r");
        int a, b;
        fscanf(in, "%d%d", &a, &b);
        int len = 2 + a + b + 2*a*b;
        double *A = memoryDob1D(len);

        A[0] = a;
        A[1] = b;

        for(int  i = 2; i < len; i++)
                fscanf(in, "%lf", &A[i]);

        return A;
}

