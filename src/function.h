#ifndef FUNCTION_H
#define FUNCTION_H
#include <stdbool.h>

void fillBool(bool *a, bool val, int len);
void fillDob(double *a, int val, int len);

int min(int a, int b);
int minDob(double a, double b);

int ** memoryInt2D(int len);
void freeInt2D(int **A, int len);

double ** memoryDob2D(int len);
void freeDob2D(double **A, int len);

int * memoryInt1D(int len);
double * memoryDob1D(double len);
bool * memoryBool1D(int len);

#endif
