#include <stdio.h>
#include <limits.h>

// Function to find the minimum cost of matrix multiplication
int matrixmultiplication(int p[], int n) {
    int dp[n][n];
    int i, j, k, L, q;

    // Initialize the dp array to zero
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            dp[i][j] = 0;
        }
    }

    // l is chain length
    for (L = 2; L < n; L++) {
        for (i = 1; i < n - L + 1; i++) {
            j = i + L - 1;
            dp[i][j] = INT_MAX;
            for (k = i; k < j; k++) {
                q = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < dp[i][j]) {
                    dp[i][j] = q;
                }
            }
        }
    }
    return dp[1][n - 1];
}

int main() {
    int arr[] = {1, 2, 3, 4, 3};
    int N = sizeof(arr) / sizeof(arr[0]);
    printf("Minimum number of multiplications is %d\n", matrixmultiplication(arr, N));
    return 0;
}
