#include <stdio.h>
#include <stdlib.h>
#define LEN sizeof(struct item)

typedef struct item{
    int x;
    float coeffi; //系数
    int index;   //指数
    struct item *next;
}Item;

int main(){
    Item *heada, *headb, *headc, *p1a, *p2a, *p1b, *p2b, *p1c, *p2c;
    heada = p1a = (Item*)malloc(LEN);
    headb = p1b = (Item*)malloc(LEN);
    headc = p1c = (Item*)malloc(LEN);
    heada->next = NULL;
    headb->next = NULL;
    headc->next = NULL;
    p2a = (Item*)malloc(LEN);
    p2b = (Item*)malloc(LEN);
    if(p1a == NULL || p1b == NULL || p1c == NULL || p2a == NULL || p2b == NULL){
        printf("内存分配失败，程序终止\n");
        exit(-1);
    }

    printf("\n输入第一个多项式(输入字母结束输入)\n");
    while(scanf("%f %d", &p2a->coeffi, &p2a->index) != 0){   //coefficient first, index next
        p1a->next = p2a;
        p1a = p2a;
        p2a = (Item*)malloc(LEN);        
    }
    p2a = NULL;
    p1a->next = p2a;
    
    while (getchar() == '\n')
        continue;

    printf("输入第二个多项式(输入字母结束输入)\n");
    while(scanf("%f %d", &p2b->coeffi, &p2b->index) != 0){
        p1b->next = p2b;
        p1b = p2b;
        p2b = (Item*)malloc(LEN);        
    }
    p2b = NULL;
    p1b->next = p2b;

    p2a = heada->next;
    p2b = headb->next;
    while (getchar() == '\n')
        continue;
    char c;
    printf("A.进行加法运算\nB.进行减法运算\n");
    scanf("\n%c", &c);
    if(c == 65 || c == 97){
        do{ 
            p2c = (Item*)malloc(LEN);
            if(p2a->index > p2b->index){
                p2c->index = p2a->index;
                p2c->coeffi = p2a->coeffi;
                p2a = p2a->next;
            }
            else if(p2a->index < p2b->index){
                p2c->index = p2b->index;
                p2c->coeffi = p2b->coeffi;
                p2b = p2b->next;
            }
            else{
                p2c->index = p2b->index;
                p2c->coeffi = p2b->coeffi + p2a->coeffi;
                p2a = p2a->next;
                p2b = p2b->next;
            }
            p1c->next = p2c;
            p1c = p2c;
        }while(p2a != NULL && p2b != NULL);
    
        if(p2a == NULL && p2b != NULL){
            do{
                p2c = (Item*)malloc(LEN);
                p2c->index = p2b->index;
                p2c->coeffi = p2b->coeffi;            
                p1c->next = p2c;
                p1c = p2c;
                p2b = p2b->next;
            }while (p2b != NULL);
        }
        else if(p2b == NULL && p2a != NULL){
            do{
                p2c = (Item*)malloc(LEN);
                p2c->index = p2a->index;
                p2c->coeffi = p2a->coeffi;            
                p1c->next = p2c;
                p1c = p2c;
                p2a = p2a->next;
            }while (p2a != NULL);
        }
    }
    else if(c == 66 || c == 98){
        do{ 
            p2c = (Item*)malloc(LEN);
            if(p2a->index > p2b->index){
                p2c->index = p2a->index;
                p2c->coeffi = p2a->coeffi;
                p2a = p2a->next;
            }
            else if(p2a->index < p2b->index){
                p2c->index = p2b->index;
                p2c->coeffi = p2b->coeffi*(-1);
                p2b = p2b->next;
            }
            else{
                p2c->index = p2b->index;
                p2c->coeffi = p2a->coeffi - p2b->coeffi;
                p2a = p2a->next;
                p2b = p2b->next;
            }
            p1c->next = p2c;
            p1c = p2c;
        }while(p2a != NULL && p2b != NULL);

        if(p2a == NULL && p2b != NULL){
            do{
                p2c = (Item*)malloc(LEN);
                p2c->index = p2b->index;
                p2c->coeffi = p2b->coeffi*(-1);
                p1c->next = p2c;
                p1c = p2c;
                p2b = p2b->next;
            }while (p2b != NULL);
        }
        else if(p2b == NULL && p2a != NULL){
            do{
                p2c = (Item*)malloc(LEN);
                p2c->index = p2a->index;
                p2c->coeffi = p2a->coeffi;            
                p1c->next = p2c;
                p1c = p2c;
                p2a = p2a->next;
            }while (p2a != NULL);
        }
    }
    else printf("输入不正确");
    p1c->next = NULL;
    
    //output
    p1c = headc->next;
    printf("The output is");
    do{
        if(p1c->coeffi != 0)
            printf("\n %+4.2f %d", p1c->coeffi, p1c->index);
        p1c = p1c->next;
    }while(p1c != NULL);

    //free
    p1a = heada->next;
    while(p1a->next != NULL){
        p2a = p1a->next;
        free(p1a);
        p1a = p2a;
    }
    free(p1a);
    free(heada);
    p1a = NULL;
    heada = NULL;

    p1b = headb->next;
    while(p1b->next != NULL){
        p2b = p1b->next;
        free(p1b);
        p1b = p2b;
    }
    free(p1b);
    free(headb);
    p1b = NULL;
    headb = NULL;

    return 0;
}