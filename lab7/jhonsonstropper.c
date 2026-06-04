#include <stdio.h>

#define LEFT -1
#define RIGHT 1

// Function to print permutation
void printPermutation(int perm[], int n) {
    for(int i = 0; i < n; i++)
        printf("%d ", perm[i]);
    printf("\n");
}

// Find position of largest mobile integer
int getMobile(int perm[], int dir[], int n) {
    int mobile = 0;
    int mobileIndex = -1;

    for(int i = 0; i < n; i++) {

        // Check left direction
        if(dir[perm[i]-1] == LEFT && i != 0) {
            if(perm[i] > perm[i-1] && perm[i] > mobile) {
                mobile = perm[i];
                mobileIndex = i;
            }
        }

        // Check right direction
        if(dir[perm[i]-1] == RIGHT && i != n-1) {
            if(perm[i] > perm[i+1] && perm[i] > mobile) {
                mobile = perm[i];
                mobileIndex = i;
            }
        }
    }

    return mobileIndex;
}

int main() {
    int n;

    printf("Enter value of n: ");
    scanf("%d", &n);

    int perm[n];
    int dir[n];

    // Initialize permutation and directions
    for(int i = 0; i < n; i++) {
        perm[i] = i + 1;
        dir[i] = LEFT;
    }

    printf("\nPermutations are:\n");

    // Print first permutation
    printPermutation(perm, n);

    while(1) {

        // Find largest mobile integer
        int mobileIndex = getMobile(perm, dir, n);

        // If no mobile integer exists
        if(mobileIndex == -1)
            break;

        int mobile = perm[mobileIndex];

        // Swap according to direction
        if(dir[mobile - 1] == LEFT) {
            int temp = perm[mobileIndex];
            perm[mobileIndex] = perm[mobileIndex - 1];
            perm[mobileIndex - 1] = temp;

            mobileIndex--;
        }
        else {
            int temp = perm[mobileIndex];
            perm[mobileIndex] = perm[mobileIndex + 1];
            perm[mobileIndex + 1] = temp;

            mobileIndex++;
        }

        // Reverse direction of all integers greater than mobile
        for(int i = 0; i < n; i++) {
            if(perm[i] > mobile)
                dir[perm[i] - 1] *= -1;
        }

        // Print next permutation
        printPermutation(perm, n);
    }

    return 0;
}
