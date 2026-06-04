#include <stdio.h>

#define MAX 10
#define INF 999

int parent[MAX];

// Find function (to find root of a vertex)
int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

// Union function (to join two sets)
void unionSet(int i, int j) {
    parent[j] = i;
}

int main() {
    int n, i, j, u, v, min, cost[MAX][MAX];
    int edges = 0, totalCost = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);

            // Replace 0 with INF (no edge)
            if (cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    // Initialize parent array
    for (i = 0; i < n; i++)
        parent[i] = i;

    printf("\nEdges in Minimum Spanning Tree:\n");

    while (edges < n - 1) {
        min = INF;

        // Find minimum edge
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    u = i;
                    v = j;
                }
            }
        }

        int set_u = find(u);
        int set_v = find(v);

        // If no cycle, include edge
        if (set_u != set_v) {
            printf("%d -> %d = %d\n", u, v, min);
            totalCost += min;
            unionSet(set_u, set_v);
            edges++;
        }

        // Remove edge
        cost[u][v] = cost[v][u] = INF;
    }

    printf("\nTotal cost of MST = %d\n", totalCost);

    return 0;
}
