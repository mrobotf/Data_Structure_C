#include <stdio.h>

int dis[3] = {0};  //dis[0] = distance, dis[1] & dis[2] == loc of both sides homes
int x;

void Judge ( int loc[], int i ) {
    if( x < dis[2] && x > dis[1] ) {
        if( x - dis[1] > dis[2] - x ) {
            dis[2] = x;
            dis[0] = x - dis[1] - 1;
        }
        else {
            dis[1] = x;
            dis[0] = dis[2] - x - 1;
        }
    }
}

int main () {
    int N, M, i, max = 0;   //N 间房，M头牛
    scanf("%d %d", &N, &M);
    int loc[N];

    scanf("%d", &loc[0]);
    for( i = 1; i < N; i++ ) {
        scanf("%d", &loc[i]);
        if( loc[i] - max > dis[0]) {
            dis[1] = loc[i - 1];
            dis[2] = loc[i];
            dis[0] = loc[i] - loc[i - 1] - 1;
        }
        else {
            x = loc[i];
            Judge(loc, i);
        }
            if( loc[i] > max ) 
                max = loc[i];
    }

    printf("%d", dis[0]);




    return 0;
}