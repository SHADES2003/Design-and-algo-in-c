#include <stdio.h>
#include <limits.h>
int minMatrixMult(int p[], int n) {
 int m[n][n]; // To store minimum number of multiplications
 int s[n][n]; // To store splitting point for minimum multiplications
 // Base case (single matrix)
 for (int i = 0; i < n; i++) {
    
    m[i][i] = 0;
 }
 for (int l = 2; l <= n; l++) {
    for (int i = 0; i <= n - l; i++) {
        int j = i + l - 1;
        m[i][j] = INT_MAX;
        for (int k = i; k < j; k++) {
        int q = m[i][k] + m[k + 1][j] + p[i] * p[k + 1] * p[j];
        if (q < m[i][j]) {
          m[i][j] = q;
          s[i][j] = k; // Store splitting point for optimal solution
        }
      }
   }
 }
 return m[0][n - 1]; // Minimum number of multiplications
}
int main() {
 int p[] = {1, 2, 3, 4}; // Dimensions of matrices
 int n = sizeof(p) / sizeof(p[0]);
 printf("Minimum number of scalar multiplications: %d\n", minMatrixMult(p, n));
 return 0;
}
