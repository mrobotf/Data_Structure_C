#include <stdio.h>
#include <stdlib.h>
#define LEN sizeof(struct item)

typedef struct item{
    int x;
    float coeffi; //系数
    int index;   //指数
    struct item *next;
}Item;

Item *input();
Item *addition(Item *heada, Item *headb);
Item *subtraction(Item *heada, Item *headb); //链表a 减去链表b
Item *multiplication(Item *heada, Item *headb);
void fre(Item *head);

int main(){
    Item *heada, *headb, *head_add, *head_sub, *head_mulit; //headc 是链表a 和b 相加后的结果
    heada = input(), headb = input();
    head_add = addition(heada, headb);  //进行加法运算
    head_sub = subtraction(heada, headb); //进行减法运算
    head_mulit = multiplication(heada, headb);  //进行乘法运算
    fre(heada), fre(headb);
    return 0;
}

Item *input(){
    Item *p1, *p2, *head;
    head = p1 = (Item*)malloc(LEN);
    head->next = NULL;
    p2 = (Item*)malloc(LEN);
    if(p1 == NULL || p2 == NULL){
        printf("内存分配失败，程序终止\n");
        exit(-1);
    }

    printf("\n输入多项式(输入字母结束输入)\n");
    while(scanf("%f %d", &p2->coeffi, &p2->index) != 0){
        p1->next = p2;
        p1 = p2;
        p2 = (Item*)malloc(LEN);        
    }
    p2 = NULL;
    p1->next = p2;
    while (getchar() == '\n')
        continue;
    return head;
}

Item *addition(Item *heada, Item *headb){
    Item *p1c, *p2c, *pa, *pb, *head;
    head = p1c = (Item*)malloc(LEN);
    head->next = NULL;
    if(p1c == NULL){
        printf("内存分配失败，程序终止\n");
        exit(-1);
    }

    pa = heada->next;
    pb = headb->next;
    do{
        p2c = (Item*)malloc(LEN);
        if(pa->index > pb->index){
            p2c->index = pa->index;
            p2c->coeffi = pa->coeffi;
            pa = pa->next;
        }
        else if(pa->index < pb->index){
            p2c->index = pb->index;
            p2c->coeffi = pb->coeffi;
            pb = pb->next;
        }
        else{
            p2c->index = pb->index;
            p2c->coeffi = pb->coeffi + pa->coeffi;
            pa = pa->next;
            pb = pb->next;
        }
        p1c->next = p2c;
        p1c = p2c;
    }while(pa != NULL && pb != NULL);
    
    if(pa == NULL && pb != NULL){
        do{
            p2c = (Item*)malloc(LEN);
            p2c->index = pb->index;
            p2c->coeffi = pb->coeffi;
            p1c->next = p2c;
            p1c = p2c;
            pb = pb->next;
        }while (pb != NULL);
    }
    else if(pb == NULL && pa != NULL){
        do{
            p2c = (Item*)malloc(LEN);
            p2c->index = pa->index;
            p2c->coeffi = pa->coeffi;
            p1c->next = p2c;
            p1c = p2c;
            pa = pa->next;
        }while (pa != NULL);
    }
    p1c->next = NULL;
    return head;
}

Item *subtraction(Item *heada, Item *headb){
    Item *head, *p1c, *p2c, *pa, *pb;
    head = p1c = (Item*)malloc(LEN);
    head->next = NULL;
    if(p1c == NULL){
        printf("内存分配失败，程序终止\n");
        exit(-1);
    }

    pa = heada->next;
    pb = headb->next;
    do{
        p2c = (Item*)malloc(LEN);
        if(pa->index > pb->index){
            p2c->index = pa->index;
            p2c->coeffi = pa->coeffi;
            pa = pa->next;
        }
        else if(pa->index < pb->index){           
            p2c->index = pb->index;
            p2c->coeffi = pb->coeffi*(-1);
            pb = pb->next;
        }
        else{
            p2c->index = pb->index;
            p2c->coeffi = pa->coeffi - pb->coeffi;
            pa = pa->next;
            pb = pb->next;
        }
        p1c->next = p2c;
        p1c = p2c;
    }while(pa != NULL && pb != NULL);

    if(pa == NULL && pb != NULL){
        do{
            p2c = (Item*)malloc(LEN);
            p2c->index = pb->index;
            p2c->coeffi = pb->coeffi*(-1);
            p1c->next = p2c;
            p1c = p2c;
            pb = pb->next;
        }while (pb != NULL);
    }
    else if(pb == NULL && pa != NULL){
        do{
            p2c = (Item*)malloc(LEN);
            p2c->index = pa->index;
            p2c->coeffi = pa->coeffi;            
            p1c->next = p2c;
            p1c = p2c;
            pa = pa->next;
        }while (pa != NULL);
    }
    p1c->next = NULL;
    return head;
}

Item *multiplication(Item *heada, Item *headb){
    Item *head, *p1c, *p2c, *pa, *pb;
    head = p1c = (Item*)malloc(LEN);
    head->next = NULL;
    if(p1c == NULL){
        printf("内存分配失败，程序终止\n");
        exit(-1);
    }

    pa = heada->next;
    pb = headb->next;
    
    // modification
    do{
        p2c = (Item*)malloc(LEN);
        if(pa->index > pb->index){
            p2c->index = pa->index;
            p2c->coeffi = pa->coeffi;
            pa = pa->next;
        }
        else if(pa->index < pb->index){
            p2c->index = pb->index;
            p2c->coeffi = pb->coeffi;
            pb = pb->next;
        }
        else{
            p2c->index = pb->index;
            p2c->coeffi = pb->coeffi + pa->coeffi;
            pa = pa->next;
            pb = pb->next;
        }
        p1c->next = p2c;
        p1c = p2c;
    }while(pa != NULL && pb != NULL);



    return head;
}


void fre(Item *head){
    Item *p1, *p2;
    p1 = head->next;
    while(p1 != NULL){
        p2 = p1->next;
        free(p1);
        p1 = p2;
    }
    free(head);
    head = NULL;
}

