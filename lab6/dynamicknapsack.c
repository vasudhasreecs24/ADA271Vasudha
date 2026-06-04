#include <stdio.h>

#define MAX 50

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int n, W;
    int wt[MAX], val[MAX];
    int V[MAX][MAX];

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter weights of items:\n");
    for(int i = 1; i <= n; i++) {
        scanf("%d", &wt[i]);
    }

    printf("Enter values of items:\n");
    for(int i = 1; i <= n; i++) {
        scanf("%d", &val[i]);
    }

    printf("Enter capacity of knapsack: ");
    scanf("%d", &W);

    // Build DP table
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= W; j++) {
            if(i == 0 || j == 0)
                V[i][j] = 0;
            else if(wt[i] > j)
                V[i][j] = V[i-1][j];
            else
                V[i][j] = max(V[i-1][j], val[i] + V[i-1][j - wt[i]]);
        }
    }

    // Print DP Table
    printf("\nDP Table:\n");
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= W; j++) {
            printf("%3d ", V[i][j]);
        }
        printf("\n");
    }

    printf("\nMaximum Profit = %d\n", V[n][W]);

    // Backtracking to find selected items
    int i = n, j = W;
    int selected[MAX] = {0};

    while(i > 0 && j > 0) {
        if(V[i][j] != V[i-1][j]) {
            selected[i] = 1;
            j = j - wt[i];
        }
        i--;
    }

    printf("Selected items:\n");
    for(int k = 1; k <= n; k++) {
        if(selected[k] == 1)
            printf("Item %d (Weight=%d, Value=%d)\n", k, wt[k], val[k]);
    }

    return 0;
}
