#include <stdio.h>
#define MAX 10
#define INF 999

int cost[MAX][MAX], visited[MAX];

int main() {
    int n, i, j;
    int min, u = 0, v = 0;
    int total = 0, edges = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if(cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    // Initially mark all vertices as unvisited
    for(i = 1; i <= n; i++)
        visited[i] = 0;

    visited[1] = 1; // Start from vertex 1

    printf("\nEdges in MST:\n");

    while(edges < n - 1) {
        min = INF;

        for(i = 1; i <= n; i++) {
            if(visited[i]) {
                for(j = 1; j <= n; j++) {
                    if(!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        printf("%d -> %d = %d\n", u, v, min);

        visited[v] = 1;
        total += min;
        edges++;
    }

    printf("Total cost = %d\n", total);

    return 0;
}
