#ifndef ALGORITHM_H
#define ALGORITHM_H

bool look(int source, int sink, int **capacity, double **cost, int len, bool *found, int **flow, double *dist, int *dad, double *pi);

double **getMinCost(int **capacity, double **cost, int len, int source, int sink);

#endif
