#include <stdio.h>

// Structure for an item
struct Item {
    int weight;
    int profit;
    float ratio;
};

// Function to sort items by profit/weight ratio (descending)
void sort(struct Item items[], int n) {
    struct Item temp;
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(items[i].ratio < items[j].ratio) {
                temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }
}

int main() {
    int n, capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item items[n];

    // Input weights and profits
    for(int i = 0; i < n; i++) {
        printf("Enter weight and profit for item %d: ", i + 1);
        scanf("%d %d", &items[i].weight, &items[i].profit);
        items[i].ratio = (float)items[i].profit / items[i].weight;
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    // Sort items based on ratio
    sort(items, n);

    float totalProfit = 0.0;

    printf("\nItems selected:\n");

    for(int i = 0; i < n; i++) {
        if(capacity == 0)
            break;

        if(items[i].weight <= capacity) {
            // Take full item
            printf("Item %d taken completely\n", i + 1);
            capacity -= items[i].weight;
            totalProfit += items[i].profit;
        } else {
            // Take fraction
            float fraction = (float)capacity / items[i].weight;
            printf("Item %d taken fraction %.2f\n", i + 1, fraction);
            totalProfit += items[i].profit * fraction;
            capacity = 0;
        }
    }

    printf("\nMaximum Profit = %.2f\n", totalProfit);

    return 0;
}
