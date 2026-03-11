#include "floyd.h"

long long city[105][105];

void floyd(int n){
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(city[i][k] != INF && city[k][j] != INF){
                    if(city[i][k] + city[k][j] < city[i][j]){
                        city[i][j] = city[i][k] + city[k][j];
                }
                }
            }
        }
    }
}