#include <stdio.h>
#include <stdlib.h>
typedef struct num{
    int top;
    int data[100];
}Num;
typedef struct op{
    int top;
    char data[100];
}Op;

int main() {
    Num n;
    n.top = 1;
    Op ope;
    ope.top = 1;
    char c1, c2;
    int num;

    scanf("%d%c", &n.data[n.top - 1], &ope.data[ope.top - 1]);
    while((c1 = getchar()) != '\n') {
        if(c1 < 58 && c1 > 47) {
            c1 = c1-48;
            num = c1;
            int i = 0;
            for(;;) {
                c2 = getchar();
                if (c2 < 58 && c2 > 47){
                    i++;
                    num = c1*10 + (c2 - 48);
                }
                else {
                    n.data[n.top] = num;
                    n.top++;
                    c1 = c2;
                    break;
                }
            }
        }
        if(c1 == '\n') {
            break;
        }
        if(c1 > 57 || c1 < 48) {
            ope.data[ope.top] = c1;
            ope.top++;
            //scanf("%d", &num);
            /*
            switch(c1){
                case 42 :
                    scanf("%d", &num);
                    n.data[n.top - 1] = n.data[n.top - 1] * num;
                    ope.top--;
                    break;
                case 47 :
                    scanf("%d", &num);
                    n.data[n.top - 1] = n.data[n.top - 1] / num;
                    ope.top--;
                    break;
            }
            */ 
        }
        else {
            printf("ERROR");
            exit(0);
        }
    }
    

    int result = n.data[0];
    int i = 0, j = 1;
    while(i < ope.top) {
        switch(ope.data[i]) {
            case '+' :
                result = result + n.data[j];
                break;
            case '-' :
                result = result - n.data[j];
                break;
            case '*' :
                result = result * n.data[j];
                break;
            case '/' :
                if(n.data[j] == 0) {
                    printf("ERROR");
                    exit(0);
                }
                result = result / n.data[j];
                break;
        }
        j++;
        i++;
    }
    printf("%d", result);
    return 0;
}