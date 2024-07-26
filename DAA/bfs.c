/* BFS program */

#include <stdio.h>

int v[10];

void bfs(int n, int a[][10], int s) {
    int i, q[10], u;
    int f = 0, r = -1;
    v[s] = 1;
    q[++r] = s; 

    while (f <= r) {
        u = q[f++];

        for (i = 1; i <= n; i++) {
            if (a[u][i] == 1 && v[i] == 0) { 
                q[++r] = i; 
                v[i] = 1; 
            }
        }
    }
}

int main() {
    int n, a[10][10], i, j, s;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter the source node: ");
    scanf("%d", &s);

    for (i = 1; i <= n; i++) {
        v[i] = 0; 
    }

    bfs(n, a, s);

    for (i = 1; i <= n; i++) {
        if (v[i] == 0) {
            printf("The node %d is not reachable\n", i);
        } else {
            printf("The node %d is reachable\n", i);
        }
    }

    return 0;
}