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
Stack_num creat_stack_num();  //创建存储数字的栈
Stack_operator creat_stack_operator();  //创建存储运算符的栈
int judgement(char a);  //进行运算符运算级的判断
void operate(Stack_num num, Stack_operator oper);


int push(char sta[], Stack_num num, Stack_operator oper);  //数字压栈


int main(){
    char sta[STACK_LEN];
    int result;
    Stack_num num;
    Stack_operator oper;
    input(sta);
    num = creat_stack_num();
    oper = creat_stack_operator();
    result = push(sta, num, oper);
    printf("\nthe result is %d", result);
    return 0;
}

void input(char sta[]){
    printf("input expression(the total length is less than %d)\n", STACK_LEN);  //对括号整体进行运算，运算符放到括号后
    scanf("%s", sta);
}

Stack_num creat_stack_num(){
    Stack_num num;
    num.top = 0;
    return num;
}

Stack_operator creat_stack_operator(){
    Stack_operator oper;
    oper.top = 0;
    return oper;
}

int judgement(char sta){   //小于进行运算
    switch (sta){
    case(')'): return 0;
    case('+'): return 1;
    case('-'): return 1;
    case('/'): return 2;
    case('*'): return 3;
    case('('): break;
    default: printf("error!\n"), exit(-2);
    }
}

void operate(Stack_num num, Stack_operator oper){
    if(oper.sta[oper.top - 1] == '+'){
            num.sta[num.top - 2] = num.sta[num.top - 2] + num.sta[num.top -1];
            num.top--;
    }
    else if(oper.sta[oper.top - 1] == '-'){
            num.sta[num.top - 2] = num.sta[num.top - 2] - num.sta[num.top -1];
            num.top--;
    }
    else if(oper.sta[oper.top - 1] == '*'){
            num.sta[num.top - 2] = num.sta[num.top - 2] * num.sta[num.top -1];
            num.top--;
    }
    else if(oper.sta[oper.top - 1] == '/'){
            num.sta[num.top - 2] = num.sta[num.top - 2] / num.sta[num.top -1];
            num.top--;
    }
    else if(oper.sta[oper.top - 1] == '('){
            while(oper.sta[oper.top - 1] != '('){
                switch(oper.sta[oper.top - 1]){
                    case('+'): 
                        num.sta[num.top - 2] = num.sta[num.top - 2] + num.sta[num.top -1];
                    case('-'):
                        num.sta[num.top - 2] = num.sta[num.top - 2] - num.sta[num.top -1];
                    case('*'):
                        num.sta[num.top - 2] = num.sta[num.top - 2] * num.sta[num.top -1];
                    case('/'):
                        num.sta[num.top - 2] = num.sta[num.top - 2] / num.sta[num.top -1];
                }
                num.top--;
                oper.top--;
            }
    }
    oper.top--;
}

int push(char sta[], Stack_num num, Stack_operator oper){
    int i;
    while(oper.top == 0 || num.top == 0){   //在运算前，保证两个栈都不为空
        if(sta[i] > 47){
            num.sta[num.top] = sta[i] - 48;
            num.top++;
        }
        else{
            oper.sta[oper.top] = sta[i];
            oper.top++;
        }
        i++;   
    }
    while(sta[i] != '\0'){
        if(sta[i] > 47){
            if(num.top == STACK_LEN){
                printf("the stack_num is full\n");
                exit(-1);
            }
            else{
                num.sta[num.top] = sta[i] - 48;
                num.top++;
            }
        }
        else{
            if(oper.sta[oper.top - 1] == '(' || judgement(sta[i]) >= judgement(oper.sta[oper.top - 1])){   // && sta[i] == ')'
                oper.sta[oper.top] = sta[i];
                oper.top++;
            }
            else{
                if(oper.sta[oper.top - 1] == '+'){
                num.sta[num.top - 2] = num.sta[num.top - 2] + num.sta[num.top -1];
                num.top--;
                }
                else if(oper.sta[oper.top - 1] == '-'){
                    num.sta[num.top - 2] = num.sta[num.top - 2] - num.sta[num.top -1];
                    num.top--;
                }  
                else if(oper.sta[oper.top - 1] == '*'){
                        num.sta[num.top - 2] = num.sta[num.top - 2] * num.sta[num.top -1];
                        num.top--;
                }
                else if(oper.sta[oper.top - 1] == '/'){
                        num.sta[num.top - 2] = num.sta[num.top - 2] / num.sta[num.top -1];
                        num.top--;
                }
                /************************
                else if(oper.sta[oper.top - 1] == '('){
                    while(oper.sta[oper.top - 1] != '('){
                        switch(oper.sta[oper.top - 1]){
                            case('+'): 
                                num.sta[num.top - 2] = num.sta[num.top - 2] + num.sta[num.top -1];
                            case('-'):
                                num.sta[num.top - 2] = num.sta[num.top - 2] - num.sta[num.top -1];
                            case('*'):
                                num.sta[num.top - 2] = num.sta[num.top - 2] * num.sta[num.top -1];
                            case('/'):
                                num.sta[num.top - 2] = num.sta[num.top - 2] / num.sta[num.top -1];
                        }
                        num.top--;
                        oper.top--;
                    }
                }
                **********************/
                oper.top--;
                if(oper.sta[oper.top - 1] == '(')
                    oper.top--;
                
            }
        }
        i++;
    }



    
    //operate(num, oper);
    return num.sta[num.top - 1];
}

//1+(2-3)*4+4/2