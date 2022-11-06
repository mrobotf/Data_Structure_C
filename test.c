#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct num{ 
    int top;
    long long data[10000];
}Num;
typedef struct op{
    int top;
    char data[10000];
    int judg[10000];
}Op;


int is_digit(char c) {
    return c >= '0' && c <= '9';
}

char str[100000];
int front;

int next_int() {
    int result = 0;
    while (is_digit(str[front])) {
        result = result * 10 + str[front] - '0';
        front++;
    }
    return result;
}

int judge(char m) {
    switch(m) {
        case '+': return 1; break;
        case '-': return 1; break;
        case '/': return 3; break;
        case '*': return 4; break;
        case ')': return 5; break;
        case '(': return 6; break;
    }
}

int op1(Num n, Op ope) {
    switch ( ope.data[ope.top] ) {
        case '*':
            return n.data[n.top - 1]*str[++front];
            break;
        case '/':
            if(!str[++front]) {
                printf("ILLEGAL");
                exit(0);
            }
            else {
                return n.data[n.top - 1]/str[++front];
                break;
            }
    }
}

long long op_equal(Num n, Op ope) {
    long long num;
    switch(ope.data[ope.top - 1]) {
        case '+': 
            num = n.data[n.top - 2] + n.data[n.top - 1];
            break;
        case '-':
            num = n.data[n.top - 2] - n.data[n.top - 1];
            break;
        case '*':
            num = n.data[n.top - 2] * n.data[n.top - 1];
            break;
        case '/':
            num = n.data[n.top - 2] / n.data[n.top - 1];
            break;
    }
    ope.data[ope.top - 1] = ope.data[ope.top];
    return num;
}
long long op3 ( Num n, Op ope ) {
    long long num;
    switch(ope.data[ope.top - 1]) {
        case '+':
            num = n.data[n.top - 2] + n.data[n.top - 1];
            break;
        case '-':
            num = n.data[n.top - 2] - n.data[n.top - 1];
            break;
        case '*':
            num = n.data[n.top - 2] * n.data[n.top - 1];
            break;
        case '/':
            if(!n.data[n.top - 1]) {
                printf("ILLEGAL");
                exit(0);
            }
            num = n.data[n.top - 2] / n.data[n.top - 1];
            break;
    }
    return num;
}
int main()
{
    scanf("%s", str);

    int opera;

    Num n;
    n.top = 0;
    Op ope;
    ope.top = 0;

    while (front < strlen(str)) {
        if (is_digit(str[front])) {
            n.data[n.top] = next_int();
            n.top++;
        }
        else {
            ope.data[ope.top] = str[front];
            opera = judge ( str[front] );
            if (opera == 6) {
                ope.judg[ope.top] = 0;
                ope.top++;
            }   
            front++;

            if ( opera > ope.judg[ope.top - 1] && opera != 5) {
                n.data[n.top - 1] = op1(n, ope);
            }
            else if ( opera == ope.judg[ope.top - 1] ) {
                n.data[n.top - 2] = op_equal(n, ope);
                ope.top--;
                n.top--;
            }
            else if(opera == 5) {
                n.data[n.top - 2] = op3(n, ope);
                ope.top = ope.top - 2;
                n.top--;
            }
            else
                ope.top++;
        }
    }
    switch(ope.data[ope.top - 1]) {
        case '+':
            printf("%lld", n.data[0] + n.data[1]);
            break;
        case '-':
            printf("%lld", n.data[0] - n.data[1]);
            break;
        case '*':
            printf("%lld", n.data[0] * n.data[1]);
            break;
        case '/':
            printf("%lld", n.data[0] - n.data[1]);
            break;
    }

    return 0;
}