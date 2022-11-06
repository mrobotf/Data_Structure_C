#include <stdio.h>
#include <string.h>

#define MAX_N 1010


int queue[MAX_N * 2], left, right;
int graph[MAX_N + 1][MAX_N + 1];

unsigned int distance[MAX_N][MAX_N];

typedef struct graphnode {
    int num, top;
    int nod[1000];
}Node;

typedef struct que {
    int data[1000];
    int count, level[7];
    int front, rear;
}Queue;



void In(int d, Queue que, int N) {
    que.rear++;
    if(que.rear == N)
        que.rear = 0;
    if(que.front != que.rear)
        que.data[que.rear] = d;
    else printf("the queue is full");
}

/*
void BFS(Node graph[], int visited[], Queue que, int i, int N) {
    visited[i] = 1;
    int j = 0;
    //Node *p;
    //p = graph[i].link;
    while(j < graph[i].top ) {
        if(visited[i - 1] == 0) {
            //printf("%d  ", p->data);
            visited[i - 1] = 1;
            que.count++;
            In(graph[i].nod[j], que, N);
        }
        j++;
    }
    if(que.count < N) {
        i = Out(que, N);
        if(tag == j - 1)
            que.level++;
        BFS(graph, visited, que, i, N);
    }
}

*/

void BFS (int node, int N) {
    int x, dis, i;
    left = right = 0;
    queue[right++] = node;
    queue[right++] = 0;

    distance[node][node] = 0;

    while (left != right) {
        x = queue[left++], dis = queue[left++] + 1;
        for (i = 1; i <= N; i++) {
            if (graph[x][i] && distance[node][i] == -1) {
                distance[node][i] = dis;
                queue[right++] = i;
                queue[right++] = dis;
            }
        }
    }


}


void CreatG(int M) {
    int i, x, y;
    for(i = 0; i < M; i++) {
        scanf("%d %d", &x, &y);
        graph[x][y] = 1;
        graph[y][x] = 1;
    }
}


int main() {
    int N, M, i, j;     //结点数N（1<N≤10000​​ ，表示人数）、边数M（≤33×N，表示社交关系数）
    scanf("%d %d", &N, &M);

    for(i = 1; i <= M; i++) 
        for(j = 1; j <= M; j++)
        graph[i][j] = 0;  

    CreatG(M);


    //BFS
    int count;
    for (i = 1; i <= N; i++) {
        memset(distance[i] + 1, -1, N*sizeof(int));
        count = 0;
        BFS(i, N);
        for (j = 1; j <= N; j++)
            if (distance[i][j] < 7)
            count++;

        printf("%d: %.2f%%\n", i, 100.0*count/N);
    }



    return 0;
}
