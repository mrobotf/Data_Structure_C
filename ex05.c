#include <stdio.h>
#include <stdlib.h>

#define LEN sizeof(struct node)
#define NodeNum 50   //结点最大数量

typedef struct node {
    char data;
    struct node *lson, *rson;
}BTnode;

BTnode *CreateBT();
void PreOrder1(BTnode *b, char pre_1[]); //非递归，先序
void InOrder1(BTnode *b, char in_1[]); //非递归，中序
void PostOrder1(BTnode *b, char post_1[]); //非递归，后序

void PreOrderRecursion(BTnode *b); //递归，先序
void InOrderRecursion(BTnode *b); //递归，中序
void PostOrderRecursion(BTnode *b); //递归，后序
 
int Push(BTnode *sta[], BTnode *b, int top);
BTnode *Pop(BTnode *sta[], int top);

int main() {
    BTnode *root = NULL; //root 是根节点
    int i = 0;
    char pre_1[NodeNum], in_1[NodeNum], post_1[NodeNum];  //先序、中序、后序非递归遍历结果
    printf("按照先序输入结点：\n"); //结点总数不超过 NodeNum 
    root = CreateBT();
    //非递归
    PreOrder1(root, pre_1);
    InOrder1(root, in_1);
    PostOrder1(root, post_1);
    //递归
    printf("\n先序递归：");
    PreOrderRecursion(root);
    printf("\n中序递归：");
    InOrderRecursion(root);
    printf("\n后序递归：");
    PostOrderRecursion(root);
    return 0;
}


void PostOrderRecursion(BTnode *b) { //递归，后序
    if(b != NULL) {
        PostOrderRecursion(b->lson);
        PostOrderRecursion(b->rson);
        printf("%c", b->data);
    }
}

void InOrderRecursion(BTnode *b) { //递归，中序
    if(b != NULL) {
        InOrderRecursion(b->lson);
        printf("%c", b->data);
        InOrderRecursion(b->rson);
    }
}

void PreOrderRecursion(BTnode *b) { //递归，先序
    if (b != NULL) {
        printf("%c", b->data);
        PreOrderRecursion(b->lson);
        PreOrderRecursion(b->rson);
    }  
}

void PostOrder1(BTnode *b, char post_1[]) {    //非递归，后序
    if(b == NULL)
        exit(-1);

    BTnode *sta[NodeNum];
    int flag[NodeNum] = {0}; //flag == 1 第二次访问
    int sta_top = 0, i; //栈顶
    for (i = 0; i < NodeNum; i++) {
        sta[i] = NULL;
    }
    sta_top = Push(sta, b, sta_top); //压入根结点
    b = b->lson;
    i = 0;
    while(sta_top > 0) {
        if(b != NULL && b != sta[sta_top - 1]) {
            flag[sta_top] = 0;
            sta_top = Push(sta, b, sta_top);
            b = b->lson;
        }
        else if(flag[sta_top - 1] == 0) {
            flag[sta_top - 1] = 1;
            b = sta[sta_top - 1]->rson;
        }
        else{
            post_1[i] = sta[sta_top - 1]->data, i++;
            Pop(sta, sta_top), sta_top--;
            b = sta[sta_top - 1];
        }
    }
} 

void InOrder1(BTnode *b, char in_1[]) {   //一个栈 依次记录左子树，非递归
    if(b == NULL)
        exit(-1);

    BTnode *sta[NodeNum];  //存左子树
    int sta_top = 0, i; //栈顶
    for (i = 0; i < NodeNum; i++) {
        sta[i] = NULL;
    }
    i = 0;
    while(sta_top > -1) {
        while(b != NULL) {
            sta_top = Push(sta, b, sta_top);
            b = b->lson;
        }
        in_1[i] = sta[sta_top - 1]->data, i++; //弹出左结点
        b = Pop(sta, sta_top), sta_top--;
        while(b->rson == NULL) {
            in_1[i] = sta[sta_top - 1]->data, i++;
            b = Pop(sta, sta_top), sta_top--;
        }
        b = b->rson;
        if(sta_top == 0 && b->lson == NULL && b->rson == NULL) {   //遍历到最后一个结点
            in_1[i] = b->data;
            break;
        }
    }
}


void PreOrder1(BTnode *b, char pre_1[]) { //一个堆栈，先存根结点最开始，再右节点，最后左节点，
    if(b == NULL)
        exit(-1);
    
    BTnode *sta[NodeNum];  //存储右子树的栈
    int sta_top = 0, i; //sta_top 是栈顶
    for(i = 0; i < NodeNum; i++) {
        sta[i] = NULL;
    }
    sta_top = Push(sta, b, sta_top);  //压入根结点
    i = 0;                                             

    while(sta_top > 0) {
        pre_1[i] = sta[sta_top - 1]->data;
        i++;
        sta_top--;
        if(b != NULL) {
            if(b->rson != NULL)
                sta_top = Push(sta, b->rson, sta_top);
            if(b->lson != NULL)
                sta_top = Push(sta, b->lson, sta_top);
            b = b->lson;
        }
        else {
            b = Pop(sta, sta_top);
        }
    }
}


int Push(BTnode *sta[], BTnode *b, int top) {
    sta[top] = (BTnode *)malloc(LEN);
    sta[top]->data = b->data;
    sta[top]->lson = b->lson;
    sta[top]->rson = b->rson;
    top++;
    return top;
}

BTnode *Pop(BTnode *sta[], int top) {
    BTnode *n;
    n = (BTnode *)malloc(LEN);
    top--;
    n->data = sta[top]->data;
    n->lson = sta[top]->lson;
    n->rson = sta[top]->rson;
    free(sta[top]);
    return n;
}

BTnode *CreateBT() {
  char inf;
  BTnode *b;
  scanf("%c", &inf);
  if (inf == '#') {
    b = NULL;
  } else {
    b = (BTnode *)malloc(LEN);
    b->data = inf;
    b->lson = CreateBT();
    b->rson = CreateBT();
  }
  return b;
}