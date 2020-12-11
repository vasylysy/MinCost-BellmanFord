#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#include "function.h"
#include "algorithm.h"
#include "io.h"

int main(int argc, char **argv){
	
	int inpCheck = errInpCheck(argv[1]);

       	if (inpCheck == 1){
		printf("plik '%s' nie istnieje\n" , argv[1]);
		return 1;
	}

	if (inpCheck == 2){
		printf("plik '%s' jest pusty\n", argv[1]);
		return 2;

	}

	double *read = fileRead(argv[1]);

	int prod = read[0];
	int apt = read[1];

	int len = prod + apt + 2;
	
	int source = len - 2;
	int sink = len - 1;

	int **capacity = memoryInt2D(len);
	double **cost = memoryDob2D(len);

	int n = 2;

	int sumProd = 0;
	int sumApt = 0;

	for(int i = 0; i < prod; i++){
		capacity[source][i] = read[n];
		n++;
		sumProd += capacity[source][i];
	}

	for(int i = prod; i < source; i++){
		capacity[i][sink] = read[n];
		n++;
		sumApt += capacity[i][sink];
	}

	if(sumApt > sumProd)
		printf("zaglodzenie apteki");
		
	for(int i = 0; i < prod; i++)
                for(int j = prod; j < source; j++){
                	capacity[i][j] = read[n];
		   	n++;	
		}

	for(int i = 0; i < prod; i++)
                for(int j = prod; j < source; j++){
			cost[i][j] = read[n];
			n++;
		}

	double **wynik = getMinCost(capacity, cost, len, source, sink);
	
	outputScreen(wynik, cost, prod, apt);
	outputFile(wynik, cost, prod, apt);
	
	freeInt2D(capacity, len);
	freeDob2D(cost, len);
	freeDob2D(wynik, len);

	free(read);

	return 0;
}
