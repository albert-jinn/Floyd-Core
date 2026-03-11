#include <stdio.h>
#include <stdlib.h>
#include "floyd.h"

int main() {

    FILE *fp = fopen("map.txt", "r"); 
    
    
    if(fp == NULL) {
        printf("파일을 찾을 수 없습니다!\n");
        return 1;
    }

    int n, m; // 도시 개수(n), 노선 개수(m)
    
    
    fscanf(fp, "%d %d", &n, &m);
    printf("데이터 로드 성공: 도시 %d개, 노선 %d개\n", n, m);
    printf("--------------------------------------\n");

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j){
            city[i][j] = 0;
        }
            else {
                city[i][j] = INF;
            }
        }
    }
   
    for(int i = 0; i < m; i++) {
        int u, v, cost;
        fscanf(fp, "%d %d %d", &u, &v, &cost);
        
        city[u][v] = cost;
        
        printf("From %d city to %d city's cost is %lld\n", u, v, city[u][v]);
    }

    
    fclose(fp);
    
    printf("--------------------------------------\n");
    printf("Map Data Parsing Complete.\n");


    floyd(n);


    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(city[i][j] != INF){
                printf("From %d city to %d city's least cost is %lld\n", i, j, city[i][j]);
            }
        }
    }



    return 0;
}