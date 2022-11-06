#include <stdio.h>
int main() {
    int m, n, k, i, j, p, count;
    scanf("%d %d %d", &m , &n, &k);
    int a[n], st[n]; //st[n] 辅助栈
    char tag[k];
    for(i = 0; i < k; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &a[j]);
            st[j] = j + 1;
        }
        st[a[0] - 1] = -1;
        if((count = a[0]) > m + 1) {
            tag[i] = 'N';
            j = 0;
        }
        else {
            for(j = 1; j < n; j++) {
                if(st[a[j] - 2] == -1 || st[a[j]] == -1) {
                    st[a[j] - 1] = -1;
                    if(a[j] < a[j - 1]) count--;
                }
                else if(a[j] == 7 || a[j] == 1) {
                    st[a[j] - 1] = -1;
                    if(a[j] == 1) count--;
                    else {
                        for(p = a[j - 1]; p < a[j]; p++) {
                            if(st[a[p]] != -1) count++;
                        }
                        if(count > m) {
                            tag[i] = 'N';
                            break;
                        }
                    }
                }
                else {
                    tag[i] = 'N';
                    break;
                }
            }
        }
        if(j == n) tag[i] = 'Y';
    }
    for(i = 0; i < k; i++) {
        if(tag[i] == 'N')
            printf("NO\n");
        else printf("YES\n");
    }

    return 0;
}