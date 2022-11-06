#include <stdio.h>
#include <string.h>

#define MAX_N 1010

int n, m;

int edge[MAX_N][MAX_N];

unsigned int distance[MAX_N][MAX_N];

int queue[MAX_N * 2], left, right;

void bfs(int node) {

    left = right = 0;
    queue[right++] = node;
    queue[right++] = 0;

    distance[node][node] = 0;

    while (left != right) {
        int x = queue[left++], dis = queue[left++] + 1, i;
        for (i = 1; i <= n; ++i) {
            if (edge[x][i] && distance[node][i] == -1) {
                distance[node][i] = dis;
                queue[right++] = i;
                queue[right++] = dis;
            }
        }
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    
    while (m--) {
        int from, to;
        scanf("%d %d", &from, &to);
        edge[from][to] = 1;
        edge[to][from] = 1;
    }

    int counts;
    for (int i = 1; i <= n; ++i) {
        memset(distance[i] + 1, -1, n * sizeof(int));
        bfs(i);
        counts = 0;
        for (int j = 1; j <= n; ++j) {
            if (distance[i][j] <= 6) {
                ++counts;
            }
        }
        printf("%d: %.2f%%\n", i, 100.0 * counts / n);
    }

    return 0;
}