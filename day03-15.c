#include <stdio.h>
char op[4] = {'+', '-', '*', '/'};

int func5(int num[]) {
    float r1, r2, result;
    int i, j, k;
    for(i = 0; i < 4; i++) {
        switch(i) {
            case 0 : r1 = num[0] + num[1]; break;
            case 1 : r1 = num[0] - num[1]; break;
            case 2 : r1 = num[0] * num[1]; break;
            case 3 : r1 = (float)num[0] / num[1]; break;
        }
        for(j = 0; j < 4; j++) {
            if(j == i) {
                continue;
            }
            switch(j) {
                case 0 : r2 = num[2] + num[3]; break;
                case 1 : r2 = num[2] - num[3]; break;
                case 2 : r2 = num[2] * num[3]; break;
                case 3 : r2 = (float)num[2] / num[3]; break;
            }
            for(k = 0; k < 4; k++) {
                if(k == j || k == i) {
                    continue;
                }
                switch(k) {
                case 0 : result = r2 + r1 ; break;
                case 1 : result = r2 - r1 ; break;
                case 2 : result = r2 * r1 ; break;
                case 3 : 
                    if(r1 == 0) {
                        result = 0;
                        break;
                    }else result = r2 / r1 ; break;
                }
                if(result == 24) {
                    printf("(%d%c%d)%c(%d%c%d)", num[0], op[i], num[1], op[k], num[2], op[j], num[3]);
                    return 0;
                }
            }
        }
    }
    return 1;
}

int func4(int num[]) {
    float result, r1, r2;
    int i, j, k;
    for(i = 0; i < 4; i++) {
        switch(i) {
            case 0 : result = num[1] + num[2]; break;
            case 1 : result = num[1] - num[2]; break;
            case 2 : result = num[1] * num[2]; break;
            case 3 : result = (float)num[1] / num[2]; break;
        }
        for(j = 0; j < 4; j++) {
            if(j == i) {
                continue;
            }
            switch(j) {
                case 0 : r1 = result + num[3] ; break;
                case 1 : r1 = result - num[3] ; break;
                case 2 : r1 = result * num[3] ; break;
                case 3 : r1 = result / num[3] ; break;
            }
            for(k = 0; k < 4; k++) {
                if(k == j || k == i) {
                    continue;
                }
                switch(k) {
                case 0 : r2 = num[0] + r1; break;
                case 1 : r2 = num[0] - r1; break;
                case 2 : r2 = num[0] * r1; break;
                case 3 : 
                    if(r1 == 0) {
                        r2 = 0;
                        break;
                    }
                    else r2 = num[0] / r1; break;
                }
                if(r2 == 24) {
                    printf("%d%c((%d%c%d)%c%d)", num[0], op[k], num[1], op[i], num[2], op[j], num[3] );
                    return 0;
                }
            }
        }
    }
    return 1;
}

int func3(int num[]) {
    float result, r1, r2;
    int i, j, k;
    for(i = 0; i < 4; i++) {
        switch(i) {
            case 0 : result = num[2] + num[3] ; break;
            case 1 : result = num[2] - num[3] ; break;
            case 2 : result = num[2] * num[3] ; break;
            case 3 : result = (float)num[2] / num[3] ; break;
        }
        for(j = 0; j < 4; j++) {
            if(j == i) {
                continue;
            }
            k = 0;
            switch(j) {
                case 0 : r1 = num[1] + result; break;
                case 1 : r1 = num[1] - result; break;
                case 2 : r1 = num[1] * result; break;
                case 3 : 
                    if(result == 0) {
                        k = 5;
                        break;
                    }                    
                    else r1 = (float)num[1] / (float)result; break;
                    //else r1 = 3.0/(float)result; break;
            }
            for(; k < 4; k++) {
                if(k == j || k == i) {
                    continue;
                }
                switch(k) {
                case 0 : r2 = num[0] + r1; break;
                case 1 : r2 = num[0] - r1; break;
                case 2 : r2 = num[0] * r1; break;
                case 3 : 
                    if(r1 == 0) {
                        r2 = 0;
                        break;
                    }else r2 = num[0] / r1; break;
                }
                if(r2 == 24) {
                    printf("%d%c(%d%c(%d%c%d))", num[0], op[k], num[1], op[j], num[2], op[i], num[3] );
                    return 0;
                }
            }
        }
    }
    return 1;
}


int func2(int num[]) {
    float result, r1, r2;
    int i, j, k;
    for(i = 0; i < 4; i++) {
        int tag1 = 0, tag2 = 0;
        switch(i) {
            case 0 : result = num[1] + num[2]; break;
            case 1 : result = num[1] - num[2]; break;
            case 2 : result = num[1] * num[2]; break;
            case 3 : result = (float)num[1] / num[2]; break;
        }
        for(j = 0; j < 4; j++) {
            if(j == i) {
                continue;
            }
            k = 0;
            switch(j) {
                case 0 : r1 = num[0] + result; break;
                case 1 : r1 = num[0] - result; break;
                case 2 : r1 = num[0] * result; break;
                case 3 : 
                    if(result == 0) {
                        k = 5;
                        break;
                    }else r1 = num[0] / result; break;
            }
            for(; k < 4; k++) {
                if(k == j || k == i) {
                    continue;
                }
                switch(k) {
                case 0 : r2 = r1 + num[3] ; break;
                case 1 : r2 = r1 - num[3] ; break;
                case 2 : r2 = r1 * num[3] ; break;
                case 3 : r2 = r1 / num[3] ; break;
                }
                if(r2 == 24) {
                    printf("(%d%c(%d%c%d))%c%d", num[0], op[j], num[1], op[i], num[2], op[k], num[3]);
                    return 0;
                }
            }
        }
    }
    return 1;
}



int func1(int num[]) {
    float result, r1, r2;
    int i, j, k;
    for(i = 0; i < 4; i++) {
        switch(i) {
            case 0 : result = num[0] + num[1]; break;
            case 1 : result = num[0] - num[1]; break;
            case 2 : result = num[0] * num[1]; break;
            case 3 : result = num[0] / num[1]; break;
        }
        for(j = 0; j < 4; j++) {
            if(j == i) {
                continue;
            }
            switch(j) {
                case 0 : r1 = result + num[2]; break;
                case 1 : r1 = result - num[2]; break;
                case 2 : r1 = result * num[2]; break;
                case 3 : r1 = result / num[2]; break;
            }
            for(k = 0; k < 4; k++) {
                if(k == j || k == i) {
                    continue;
                }
                switch(k) {
                    case 0 : r2 = r1 + num[3] ; break;
                    case 1 : r2 = r1 - num[3] ; break;
                    case 2 : r2 = r1 * num[3] ; break;
                    case 3 : r2 = r1 / num[3] ; break;
                }
                if(r2 == 24) {
                    printf("((%d%c%d)%c%d)%c%d", num[0], op[i], num[1], op[j], num[2], op[k], num[3] );
                    return 0;
                }
            }
        }
    }
    return 1;
}

int cal(int num[]) {
    int r = 1, i;
        if(!(r = func1(num))) return 0; //((A op B) op C) op D
        if(!(r = func2(num))) return 0;//(A op (B op C)) op D
        if(!(r = func3(num))) return 0;// A op (B op (C op D))
        if(!(r = func4(num))) return 0; // A op ((B op C) op D)
        if(!(r = func5(num))) return 0; //(A op B) op (C op D)
    if(r == 1) {
        return 1;
    }
}

 
int main() {
    int num[4], i, j, k, t;
    int x, y, m, n, tag;
    scanf("%d %d %d %d", &x, &y, &m, &n);
    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            if(j == i) continue;
            for(k = 0; k < 4;k++){
                if(i == k || k == j) continue;
                for(t = 0; t < 4; t++){
                    if(t == i || t == j || t==k) continue;
                        num[i] = x;
                        num[j] = y;
                        num[k] = m;
                        num[t] = n;
                    if(!(tag = cal(num))) return 0;
                }
            }
        }
    }
    if(tag == 1) printf("-1");
    return 0;
}