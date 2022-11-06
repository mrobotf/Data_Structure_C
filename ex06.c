//图用邻接表存储，输入一个无向图的信息并存储
//实现图的DFS和BFS

//8 10 顶点数，总的边数
//0 表示孤立结点
#include <stdio.h>
#include <stdlib.h>

#define FILE_NAME_LEN 30
#define NODE_NUM 20
#define LEN sizeof(struct graphnode)

typedef struct graphnode {
    int data;
    struct graphnode *link;
}Node;

typedef struct que {
    int data[NODE_NUM];
    int count;
    int front;
    int rear;
}Queue;

void CreatG(Node graph[], FILE *fp, int num[]);
void DFS(Node graph[], int viseted[], int v);
void BFS(Node graph[], int visited[], Queue *que, int i, int v);
void In(int d, Queue *que, int v);
int Out(Queue *que, int v);

int main() {
    // open file
    char file_name[FILE_NAME_LEN];
    printf("输入存储图的文件名(文件内字符数小于%d)：\n", FILE_NAME_LEN);
    scanf("%s", file_name);
    FILE *fp = fopen(file_name, "r");
    if (fp == NULL) {
        printf("打开文件失败。");
        exit(-1);
    }

    Node graph[NODE_NUM];
    int num[2], i, v0 = 0; //num[0] 表示总节点数，num[1] 表示总边数
    CreatG(graph, fp, num);   //文件每行末尾没有空格

    //DFS
    int visited[num[0]]; // 0:未访问过, 1:访问过
    for(i = 0; i < num[0]; i++)
        visited[i] = 0;
    printf("\nDFS: ");
    DFS(graph, visited, v0);

    //BFS
    for (i = 0; i < num[0]; i++)
        visited[i] = 0;
    Queue *que;
    que = (Queue*)malloc(sizeof(Queue));
    que->front = 0;
    que->rear = 0;
    que->count = 1;

    int v = num[0];

    printf("\nBFS: ");
    printf("%d  ", graph[num[0] - 1].data);
    i = num[0] - 1;
    BFS(graph, visited, que, i, v);

    fclose(fp);

    return 0;
}

void BFS(Node graph[], int visited[], Queue *que, int i, int v) {
    visited[i] = 1;
    Node *p;
    p = (Node*)malloc(sizeof(Node));
    p = graph[i].link;
    while(p != NULL) {
        if(visited[p->data - 1] == 0) {
            printf("%d  ", p->data);
            visited[p->data - 1] = 1;
            que->count++;
            In(p->data, que, v);
        }
        p = p->link;
    }
    if(que->count < v) {
        i = Out(que, v);
        BFS(graph, visited, que, i, v);
    }
}

void In(int d, Queue *que, int v) {
    que->rear++;
    if(que->rear == v)
        que->rear = 0;
    if(que->front != que->rear)
        que->data[que->rear] = d;
    else printf("the queue is full");
}

int Out(Queue *que, int v) {
    int data;
    if(que->rear == que->front){
        printf("the queue is empty");
        exit;
    }
    que->front++;
    if(que->front == v)
        que->front = 0;
    data = que->data[que->front] - 1;
    return data;
}

void DFS(Node graph[], int visited[], int v) {
    Node *p;
    printf("%d  ", graph[v].data);
    visited[v] = 1;
    p = graph[v].link;
    while(p != NULL) {
        if(visited[p->data - 1] == 0) {
            DFS(graph, visited, p->data - 1);
        }
        p = p->link;
    }
}

void CreatG(Node graph[], FILE *fp, int a[]) {
    int i = 0, c;  //a[0]表示结点总数，a[1]表示边数,i表示当前纪录到的结点数,c暂时记录信息
    Node *p1, *p2, *head; //搜索指针
    fscanf(fp, "%d%d", &a[0], &a[1]);
    fgetc(fp);  //读取  '\n'

    while(1) {
        head = (Node *)malloc(LEN);
        head->link = NULL;
        p1 = head;
        fscanf(fp, "%d", &graph[i].data);
        fgetc(fp);
        while(1) {
            p2 = (Node*)malloc(LEN);
            fscanf(fp, "%d", &p2->data);
            p1->link = p2;
            p1 = p2;
            if((c = fgetc(fp)) == '\n' || c == -1) {
                p1->link = NULL;
                break;
            }
        }
        graph[i].link = head->link;
        free(head);
        i++;
        if(c == -1) {
            break;
        }
    }
    printf("%d", graph[7].data);
}