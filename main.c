/*Design and implement C/C++ Program to solve 0/1 Knapsack problem using Dynamic
Programming method.*/

#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapSack(int W, int wt[], int val[], int n) {
    int K[n+1][W+1];
    
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            if (i == 0 || j == 0)
                K[i][j] = 0;
            else if (wt[i-1] <= j)
                K[i][j] = max(val[i-1] + K[i-1][j-wt[i-1]], K[i-1][j]);
            else
                K[i][j] = K[i-1][j];
        }
    }
    
    return K[n][W];
}

int main() {
    int n, W;
    printf("Enter number of items: ");
    scanf("%d", &n);

    int val[n], wt[n];
    printf("Enter value and weight of items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &val[i], &wt[i]);
    }

    printf("Enter size of knapsack: ");
    scanf("%d", &W);

    printf("Maximum value in knapsack = %d\n", knapSack(W, wt, val, n));
    return 0;
}
