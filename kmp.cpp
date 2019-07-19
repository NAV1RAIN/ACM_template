#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int SIZE = 1e6+6;
/*
 * NEXT[]�ĺ��壺x[i-NEXT[i]...i-1] = x[0...NEXT[i]-1]
 * NEXT[i]Ϊ���� x[i-z...i-1] = x[0...z-1] �����zֵ������x������ƥ�䣩
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
 * kmpNEXT[i]����˼��NEXT[i] = NEXT[NEXT[...[NEXTp[i]]]]��ֱ��NEXT[i] < 0 ���� x[NEXT[i]] != x[i]��
 * ������Ԥ�������Կ�һЩ
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
 * ���� x �� y �г��ֵĴ����������ص�
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
