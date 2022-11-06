#include <stdio.h>
int main(){
    int n, m;
    printf("输入总人数 m 和 出列序号 n \n");
    scanf("%d%d", &m, &n);

    int end, start = 0;
    end = m - 1;

    int a[m] = {0}, b[m] = {0};
    int total = 0, i, j;
    int q;

    for(i = 0, j = 1; total != m;){
        if(a[i] != 1){
            if(j == n){
                a[i] = 1;
                b[total] = i + 1;
                total++;
                j = 0;
                q = i;  
                if(i == start){   //当移去的是开始一次循环的人
                    while(a[q] == 1){
                        start++;
                        q++;
                    }
                }
                if(i == end){   //当移去的是结束一次循环的人
                    while (a[q] == 1){
                        q--;
                        end--;
                    }
                }
            }
            i++;
            j++;
            if(i > end){
                i = start;
            }
        }
        else{
            i++;
        }
    }
    for(i = 0; i < total; i++){
        printf("\n%d", b[i]);
    }
    printf("\n猴王为第 %d 个", b[total - 1]);
    return 0;
}
