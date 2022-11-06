#include <stdio.h>

int main() {
    int n, m, k;
    int i, j, ni = 0, mi, top = 0; //ni瓶子的颜色
    scanf("%d %d %d", &n, &m, &k);
    int stack[n], tag[k];
    for(i = 0; i < k; i++) {
        ni = 1;
        scanf("%d", &stack[0]);
        top = 1;
        for(j = 1; j < n; j++) {
            scanf("%d", &stack[top]);
            if(ni == stack[top]) {
                ni++;
            }
            else if(ni == stack[top - 1]) {
                ni++;
                stack[top - 1] = stack[top];
            }
            else {
                top++;
                if(top > m) break;
            }
        }
        //ni--;
        for(mi = top - 1; mi >= 0, top > 0; mi++) {
            if(ni == stack[top - 1]) {
                ni++;
                top--;
                if(top == 0) tag[i] = 1;
            }
            else {
                tag[i] = 0;
                break;
            }
        }
        if(j == n && top == 0) {
            tag[i] = 1; 
        }
        else tag[i] = 0; 

    }
    for(i = 0; i < k; i++) {
        if(tag[i] == 0) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}
