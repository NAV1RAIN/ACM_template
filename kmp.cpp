#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int SIZE = 1e6+6;
/*
 * NEXT[]的含义：x[i-NEXT[i]...i-1] = x[0...NEXT[i]-1]
 * NEXT[i]为满足 x[i-z...i-1] = x[0...z-1] 的最大z值（就是x的自身匹配）
 */
void kmp_pre(char x[], int m, int NEXT[]) {
    int i, j;
    j = NEXT[0] = -1;
    i = 0;
    while(i < m) {
        while(j != -1 && x[i] != x[j]) j = NEXT[j];
        NEXT[++i] = ++j;
    }
}
/*
 * kmpNEXT[i]的意思：NEXT[i] = NEXT[NEXT[...[NEXTp[i]]]]（直到NEXT[i] < 0 或者 x[NEXT[i]] != x[i]）
 * 这样的预处理可以快一些
 */
void preKMP(char x[], int m, int kmpNEXT[]) {
    int i, j;
    j = kmpNEXT[0] = -1;
    i = 0;
    while(i < m) {
        while(j != -1 && x[i] != x[j]) j = kmpNEXT[j];
        if(x[++i] == x[++j]) kmpNEXT[i] = kmpNEXT[j];
        else kmpNEXT[i] = j;
    }
}
/*
 * 返回 x 在 y 中出现的次数，可以重叠
 */
int NEXT[SIZE];
int KMP_Count(char x[], int m, char y[], int n) {
    int i, j;
    int ans = 0;
//    preKMP(x, m, next);
    kmp_pre(x, m, NEXT);
    i = j = 0;
    while(i < n) {
        while(j != -1 && y[i] != x[j]) j = NEXT[j];
        i++;j++;
        if(j >= m) {
            ans++;
            j = NEXT[j];
        }
    }
    return ans;
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--) {
        char str1[SIZE], str2[SIZE];
        scanf("%s", str1);
        scanf("%s", str2);
        int m = strlen(str1), n = strlen(str2);
        int ans = KMP_Count(str1, m, str2, n);
        printf("%d\n", ans);
    }
    return 0;
}
