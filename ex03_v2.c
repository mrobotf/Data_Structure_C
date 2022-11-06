#include <stdio.h>
#include <stdlib.h>
#define STACK_LEN 30  //定义栈的长度

//存储数字的栈
typedef struct stack_num {
    int top;
    int sta[STACK_LEN];
}Stack_num;

//存储运算符的栈
typedef struct stack_op {
    int top;
    char sta[STACK_LEN];
}Stack_operator;

void input(char t[]);  //输入表达式 每个操作数需小于10 操作数与操作数、运算符与运算符之间不相邻
void push_num(Stack_num *num, char n);   //数字压栈
int pop_num(Stack_num *num);   //数字出栈
void push_operator(Stack_operator *oper, char n);  //运算符压栈
char pop_operator(Stack_operator *oper);  //运算符出栈
int judgement(char s);  //判断运算符级别
int op(Stack_operator *oper, Stack_num *num, char sta[]);  //运算

int main(){
    char sta[STACK_LEN];
    int result;
    Stack_num *num;
    Stack_operator *oper;

    num = (Stack_num*)malloc(STACK_LEN);
    oper = (Stack_operator*)malloc(STACK_LEN);
    num->top = 0;
    oper->top = 0;

    input(sta);
    result = op(oper, num, sta);
    printf("\nthe result is %d", result);
    return 0;
}

int op(Stack_operator *oper, Stack_num *num, char sta[]){
    int i = 0;
    while(oper->top == 0 || num->top == 0){   //在运算前，保证两个栈都不为空
        if(sta[i] > 47)
            push_num(num, sta[i]);
        else
            push_operator(oper, sta[i]);
        i++;   
    }

    while(sta[i] != '\0'){
        if(sta[i] > 47)
            push_num(num, sta[i]);
        else{
            if(oper->sta[oper->top - 1] == '(' || judgement(sta[i]) >= judgement(oper->sta[oper->top - 1]))
                push_operator(oper, sta[i]);
            else{
                int a, b, c, d;
                a = pop_num(num);
                b = pop_num(num);
                d = pop_operator(oper);
                if(d == '+')
                    c = b + a + 48;
                else if(d == '-')
                    c = b - a + 48;
                else if(d == '*')
                    c = a * b + 48;
                else if(d == '/')
                    c = b / a + 48;
                push_num(num, c);
                if(oper->sta[oper->top - 1] == '(')
                    pop_operator(oper);
                if(sta[i] != ')')
                    push_operator(oper, sta[i]);
            }
        }
        i++;
    }

    while(oper->top != 0){
        int a, b, c, d;
        a = pop_num(num);
        b = pop_num(num);
        d = pop_operator(oper);    
        if(d == '+')
            c = b + a + 48;
        else if(d == '-')
            c = b - a + 48;
        else if(d == '*')
            c = a * b + 48;
        else if(d == '/')
            c = b / a + 48;
        push_num(num, c);
    }
    return num->sta[0];
}

int judgement(char s){   //小于进行运算
    switch (s){
    case(')'):
        return 0;
    case('+'):
        return 1;
    case('-'):
        return 1;
    case('/'):
        return 2;
    case('*'):
        return 3;
    case('('): break;
    default:
        printf("error!\n"), exit(-2);
    }
    return 0;
}

void input(char sta[]){
    printf("输入表达式(总长度小于 %d)\n", STACK_LEN);  //对括号整体进行运算，运算符放到括号后
    scanf("%s", sta);
}

void push_num(Stack_num *num, char n){   //n is sta[i]
    if(num->top == STACK_LEN){
        printf("the stack_num is full.\n");
        exit(-1);
    }
    else{
        num->sta[num->top] = n - 48;
        num->top++;
    }
}

int pop_num(Stack_num *num){
    int n;
    if(num->top == 0){
        printf("the stack_num is empty.\n");
        exit(-1);
    }
    else{
        n = num->sta[num->top - 1];
        num->top--;
    }
    return n;
}

void push_operator(Stack_operator *oper, char n){
    if(oper->top == STACK_LEN){
        printf("the stack_operator is full.\n");
        exit(-1);
    }
    else{
        oper->sta[oper->top] = n;
        oper->top++;
    }
}

char pop_operator(Stack_operator *oper){
    char n;
    if(oper->top == 0){
        printf("the stack_operator is empty.\n");
        exit(-1);
    }
    else{
        n = oper->sta[oper->top - 1];
        oper->top--;
    }
    return n;
}



//1+(2-3)*4+4/2