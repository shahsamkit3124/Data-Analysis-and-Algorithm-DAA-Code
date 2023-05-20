
//Q16 Dynamic TSP

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define N 4

int adjmat[N][N];
int visited[N];
int count = 0;

int tsp(int s,int path[]) {
    visited[s] = 1;
    path[count]=s;
    count++;
    if (count == N) {
        visited[s] = 0;
        count--;
        return adjmat[s][0];
    }
    int ans = INT_MAX;
    for (int i = 0; i < N; i++) {
        if (visited[i] == 0) {
            int subproblem = tsp(i,path);
            int cost = adjmat[s][i] + subproblem;
            if (cost < ans) {
                ans = cost;
            }
        }
    }
    visited[s] = 0;
    count--;
    return ans;
}

int main() {
    int path[N+1] = {-1};
    printf("Enter the adjacency matrix:\n");
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            scanf("%d", &adjmat[i][j]);
        }
    }
    int ans = tsp(0,path);
    printf("Minimum cost: %d\n", ans);
    printf("Path taken: ");
    for (int i = N; i >= 0; i--) {
        printf("%d ",(path[i]+1));
    }
    return 0;
}
