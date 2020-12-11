#ifndef IO_H
#define IO_h

void outputFile(double **A, double **cost,int prod, int apt);

void outputScreen(double **A, double **cost, int prod, int apt);

int errInpCheck(char *file);

double *fileRead(char *file);

#endif
