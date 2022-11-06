#include <stdio.h>
#include <stdlib.h>
#define LEN sizeof(struct list)

typedef struct list{
    int num;
    struct list *next;
}List;

int main(){
    int m, n, total = 0, i = 1;
    printf("输入队列人数 m 和 出列序号 n");
    scanf("%d%d", &m, &n);
    int a[m];

    List *head, *p1, *p2;
    head = p1 = (List*)malloc(LEN);
    head->next = NULL;
    if(NULL == p1){
        printf("内存分配失败，程序终止\n");
        exit(-1);
    }

    do{
        p2 = (List*)malloc(LEN);
        p2->num = i;
        p1->next = p2;
        p1 = p2;
        i++;
        if(i > m){
            p1->next = head->next;   //head 结点没有被计数，跳过head 结点连接到下一个结点
            break;
        }
    }while(1);

    p1 = head;
    p2 = p1->next;
    free(head);
    i = 0;
    do{
        i++;
        if(i == n){
            a[total] = p2->num;
            total++;
            i = 0;
            p1->next = p2->next; //删除结点，同时释放空间
            free(p2);
            p2 = p1;  
        }
        p1 = p2;
        p2 = p2->next;                
    } while(total < m);

    for(i = 0; i < m; i++){
        printf("\n%d", a[i]);
    }
    printf("\n猴王为第 %d 个", a[total - 1]);
    return 0;
}