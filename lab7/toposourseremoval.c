#include <stdio.h>

#define MAX 20

int main() {
    int adj[MAX][MAX], indegree[MAX];
    int n, i, j, k;
    int count = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    // Calculate indegree of each vertex
    for(i = 0; i < n; i++) {
        indegree[i] = 0;
    }

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(adj[i][j] == 1)
                indegree[j]++;
        }
    }

    printf("\nTopological Order:\n");

    while(count < n) {
        int found = 0;

        // Find vertex with indegree 0
        for(i = 0; i < n; i++) {
            if(indegree[i] == 0) {
                printf("%d ", i);

                // Mark as deleted
                indegree[i] = -1;

                // Remove outgoing edges
                for(k = 0; k < n; k++) {
                    if(adj[i][k] == 1)
                        indegree[k]--;
                }

                found = 1;
                count++;
            }
        }

        // Cycle detection
        if(found == 0) {
            printf("\nGraph contains a cycle. Topological ordering not possible.\n");
            return 0;
        }
    }

    return 0;
}
