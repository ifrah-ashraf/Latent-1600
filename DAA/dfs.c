#include <stdio.h>

int a[20][20], reach[20], n;

void dfs(int v) {
    int i;
    reach[v] = 1;
    for(i = 1; i <= n; i++) { 
        if(a[v][i] && !reach[i]) {
            printf("\n%d -> %d", v, i);
            dfs(i);
        }
    }
}

int main() {
    int i, j, count = 0, s;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++) {
        reach[i] = 0;
    }

    printf("Enter adjacency matrix:\n");
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) { 
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter the source vertex: ");
    scanf("%d", &s);
    dfs(s);

    printf("\n");
    for(i = 1; i <= n; i++) {
        if(reach[i])
            count++;
    }

    if(count == n)
        printf("Graph is connected\n");
    else
        printf("Graph is not connected\n");

    return 0;
}