#include <stdio.h>

#define MAX 10
#define INF 999

int main() {
    int n, i, j, k;
    int cost[MAX][MAX], D[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);

            // Replace 0 (no edge) with INF, except diagonal
            if(i != j && cost[i][j] == 0)
                cost[i][j] = INF;

            D[i][j] = cost[i][j];
        }
    }

    // Floyd’s Algorithm
    for(k = 0; k < n; k++) {
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                if(D[i][k] + D[k][j] < D[i][j]) {
                    D[i][j] = D[i][k] + D[k][j];
                }
            }
        }
    }

    // Print shortest path matrix
    printf("\nShortest path matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(D[i][j] == INF)
                printf("INF ");
            else
                printf("%d ", D[i][j]);
        }
        printf("\n");
    }

    return 0;
}
