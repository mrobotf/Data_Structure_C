/*
输入在一行中给出一句话，即一个非空字符串，由不超过 1000
个英文字母、数字和空格组成，以回车结束。

输出格式：
从左到右扫描输入的句子：如果句子中有超过 3 个连续的 6，则将这串连续的 6 替换成
9；但如果有超过 9 个连续的 6，则将这串连续的 6 替换成
27。其他内容不受影响，原样输出。
*/

#include <stdio.h>
#include <string.h>

void Adjust(char a[], int m, int j) {
    int i, l;
    j = j - m;
    l = strlen(a);
    if (m > 3 && m < 10) {
        a[j] = '9';
    } else if (m > 9) {
        a[j] = '-';
    }
    j++;
    for (i = j; a[i + m - 1] != '\0'; i++) {
        a[i] = a[i + m - 1];
    }
    a[i] = '\0';
}

int main() {
    char a[1200], c;
    int i = 0, m;
    while((c = getchar()) != '\n') {
        a[i] = c;
        i++;
    }
    a[i] = '\n';
    a[i + 1] = '\0';
    for(i = 0, m = 0; a[i] != '\0'; i++) {
        if(a[i] == '6'){
            m++;
        }
        else if(m > 3){
                Adjust(a, m, i);
                m = 0;
                i = i - m + 1;
        }
        else m = 0;
    }
    for(i = 0; a[i] != '\0'; i++) {
        if(a[i] != '-'){
            printf("%c", a[i]);
        }
        else printf("27");
    }
    return 0;
}