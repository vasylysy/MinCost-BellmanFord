#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#include "function.h"

bool look(int source, int sink, int **capacity, double **cost, int len, bool *found, int **flow, double *dist, int *dad, double *pi){
        fillBool(found, false, len);
        fillDob(dist, INT_MAX/2, len + 1);
        dist[source] = 0;

        while(source != len){
                int best = len;
                found[source] = true;

                for(int i = 0; i < len; i++){
                        if(found[i])
                                continue;

                        if(flow[i][source] != 0){
                                double val = dist[source] + pi[source] - pi[i] - cost[i][source];

                                if(dist[i] > val){
                                        dist[i] = val;
                                        dad[i] = source;
                                }
                        }

                        if(flow[source][i] < capacity[source][i]){
                                double val = dist[source] + pi[source] - pi[i] + cost[source][i];

                                if(dist[i] > val){
                                        dist[i] = val;
                                        dad[i] = source;
                                }
                        }

                        if(dist[i] < dist[best])
                                best = i;
                }
                source = best;
        }

        for(int i = 0; i < len; i++)
                pi[i] = minDob(pi[i] + dist[i], INT_MAX/2);

        return found[sink];
}

double **getMinCost(int **capacity, double **cost, int len, int source, int sink){
        double totalCost = 0;
        double **connect = memoryDob2D(len);

        bool *found = memoryBool1D(len);
        int **flow = memoryInt2D(len);
        double *dist = memoryDob1D(len+1);
        int *dad = memoryInt1D(len);
        double *pi = memoryDob1D(len);

        while(look(source, sink, capacity, cost, len, found, flow, dist, dad, pi)) {
                int amt = INT_MAX/2;

                for(int  i = sink; i != source; i = dad[i])
                        amt = min(amt, flow[i][dad[i]] != 0 ? flow[i][dad[i]] : capacity[dad[i]][i] - flow[dad[i]][i]);

                for(int i  = sink; i != source; i = dad[i]){
                        if(flow[i][dad[i]] != 0){
                                flow[i][dad[i]] -= amt;
                                totalCost -= amt * cost[i][dad[i]];
                        } else {
                                flow[dad[i]][i] += amt;
                                totalCost += amt * cost[dad[i]][i];
                        }
                }
        }

        for(int i = 0; i < len; i++)
                for(int j = 0; j < len; j++)
                        connect[i][j] = flow[i][j];

        connect[0][0] = totalCost;

	freeInt2D(flow, len);
	free(dist);
	free(found);
	free(dad);
	free(pi);

        return connect;
}

