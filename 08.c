#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int A[100];
void Create(int n);
void Adjust(int n);
void sort(int n);

int main(){
    int n, i;
    printf("-----------堆排序------------\n");
    printf("请输入序列中元素总数：");
    scanf("%d", &n);
    printf("\n请输入该未排序序列: ");
    for(i = 1; i <= n; i++)
        scanf("%d",&A[i]);
    sort(n);
    printf("\n堆排序后的序列：");
    for(i = 1; i <= n; i++)
        printf("%d ", A[i]);
    return 0;
}


void Create(int n){    //建堆 
    int i, j, m;
    for(i = 2; i <= n; i++){
        j = i;
        while(j > 1){
            if(A[j/2] < A[j])    //与自己的父亲比
                break;
            else{               //大于父亲，则交换 
                m = A[j/2];
                A[j/2] = A[j];
                A[j] = m;
                j = j/2;
            }
        }
    }
}


void Adjust(int n) {
    int j;
    j = n/2;
}

/*
void Adjust(int n){      //删除结点后调整 
    int i = 1, j, k;
    int m;
    j = 2 * i;
    while(j + 1 <= n){
        if(A[j] < A[j+1])   //比较两个孩子，得出较小值 
            k = j;
        else k = j + 1;
        if(A[i] > A[k]) {
            m = A[i];
            A[i] = A[k];
            A[k] = m;
            i = k;
            j = i * 2;
        }
        else
            break;
    }
    if(j == n && A[i] > A[n]){
        m = A[i];
        A[i] = A[n];
        A[n] = m;
    }
} 
*/

void sort(int n){     //堆排序
    int i, m, j;
    Create(n);       //建立初始堆
    for(i = n; i >= 2; i--) {
        j = i * 2;
        if(A[j] > A[j + 1]) {
            m = A[j];
            A[j] = A[j + 1];
            A[j + 1] = m;
        }
        if(A[i] < A[i + 1]) {
            m = A[];
            A[j] = A[j + 1];
            A[j + 1] = m;            
        }
        //Adjust(i - 1);
    }
}
