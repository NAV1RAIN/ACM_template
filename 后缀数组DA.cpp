#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const LL LNF = 0x3f3f3f3f3f3f3f3f;
/*
 * suffix array
 * 倍增算法 O(n*log(n))
 * 待排序数组长度为n，放在0 ～ n-1中，在最后补一个0
 * da(str, sa, rank, height, n, );  //注意是n
 * 例如：
 * n = 8
 * num[] = {1, 1, 2, 1, 1, 1, 1, 2, $}; 注意 num 最后一位为 0 ， 其他大于0
 * rank[] = {4, 6, 8, 1, 2, 3, 5, 7, 0}; rank[0 ~ n-1] 为有效值， rank[n] 必定为0 无效值
 * sa[] = {8, 3, 4, 5, 0, 6, 1, 7, 2}; sa[1 ~ n] 为有效值，sa[0] 必定为 n 是无效值
 * height[] = {0, 0, 3, 2, 3, 1, 2, 0, 1}; height[2 ~ n]为有效值
 * 
 */

const int MAXN = 20010;
namespace SADA {
int t1[MAXN], t2[MAXN], c[MAXN];
//求 SA 数组需要的中间变量， 不需要赋值
//待排序的字符串放在 s 数组中， 从 s[0] 到 s[n-1]，长度为 n，且最大值小于 m，
//除 s[n-1] 外的所有 s[i] 都大于 0 ，r[n-1] = 0
//函数结束以后结果放在 sa 数组中
int rank[MAXN], height[MAXN], sa[MAXN];

bool cmp(int *r, int a, int b, int l) {
    return r[a] == r[b] && r[a + l] == r[b + l];
}
void da(int str[], int n, int m) {
    n++;
    int p, *x = t1, *y = t2;
    for (int i = 0; i < m; i++) c[i] = 0;
    for (int i = 0; i < n; i++) c[x[i] = str[i]]++;
    for (int i = 1; i < m; i++) c[i] += c[i - 1];
    for (int i = n - 1; i >= 0; i--) sa[--c[x[i]]] = i;
    for (int j = 1; j <= n; j <<= 1) {
        p = 0;
        //直接利用 sa 数组排序第二关键字
        for (int i = n - j; i < n; i++) y[p++] = i;  //后面的 j 个数第二关键字为空的最小
        for (int i = 0; i < n; i++)
            if (sa[i] >= j) y[p++] = sa[i] - j;
        //这样数组 y 保存的就是按照第二关键字排序的结果
        //基数排序第一关键字
        for (int i = 0; i < m; i++) c[i] = 0;
        for (int i = 0; i < n; i++) c[x[y[i]]]++;
        for (int i = 1; i < m; i++) c[i] += c[i - 1];
        for (int i = n - 1; i >= 0; i--) sa[--c[x[y[i]]]] = y[i];
        //根据 sa 和 x 数组计算新的 x 数组
        swap(x, y);
        p = 1;
        x[sa[0]] = 0;
        for (int i = 1; i < n; i++) {
            x[sa[i]] = cmp(y, sa[i - 1], sa[i], j) ? p - 1 : p++;
        }
        if (p >= n) break;
        m = p;  //下次基数排序的最大值
    }
    int k = 0;
    n--;
    for (int i = 0; i <= n; i++) rank[sa[i]] = i;
    for (int i = 0; i < n; i++) {
        if (k) k--;
        int j = sa[rank[i] - 1];
        while (str[i + k] == str[j + k]) k++;
        height[rank[i]] = k;
    }
}
};  // namespace SADA
int RMQ[MAXN];
int mm[MAXN];
int best[20][MAXN];
void initRMQ(int n) {
    mm[0] = -1;
    for (int i = 1; i <= n; i++) {
        mm[i] = ((i & (i - 1)) == 0) ? mm[i - 1] + 1 : mm[i - 1];
    }
    for (int i = 1; i <= n; i++) best[0][i] = i;
    for (int i = 1; i <= mm[n]; i++) {
        for (int j = 1; j + (1 << i) - 1 <= n; j++) {
            int a = best[i - 1][j];
            int b = best[i - 1][j + (1 << (i - 1))];
            if (RMQ[a] < RMQ[b])
                best[i][j] = a;
            else
                best[i][j] = b;
        }
    }
}
int askRMQ(int a, int b) {
    int t;
    t = mm[b - a + 1];
    b -= (1 << t) - 1;
    a = best[t][a];
    b = best[t][b];
    return RMQ[a] < RMQ[b] ? a : b;
}
int lcp(int a, int b) {
    a = SADA::rank[a];
    b = SADA::rank[b];
    if (a > b) swap(a, b);
    return SADA::height[askRMQ(a + 1, b)];
}
char str[MAXN];
int r[MAXN];

int main() {
    freopen("RAW/in", "r", stdin);
    freopen("RAW/out", "w", stdout);
    while (scanf("%s", str) == 1) {
        int len = strlen(str);
        int n = 2 * len + 1;
        for (int i = 0; i < len; i++) r[i] = str[i];
        for (int i = 0; i < len; i++) r[len + 1 + i] = str[len - 1 - i];
        r[len] = 1;
        r[n] = 0;
        SADA::da(r, n, 128);
        for (int i = 1; i <= n; i++) RMQ[i] = SADA::height[i];
        initRMQ(n);
        int ans = 0, st;
        int tmp;
        for(int i = 0; i < len; i++) {
            tmp = lcp(i, n - i);  //偶对称
            if(2 * tmp > ans) {
                ans = 2 * tmp;
                st = i - tmp;
            }
            tmp = lcp(i, n - i - 1);  //奇数对称
            if(2 * tmp - 1 > ans) {
                ans = 2 * tmp - 1;
                st = i - tmp + 1;
            }
        }
        str[st + ans] = 0;
        printf("%s\n", str + st);
    }
    return 0;
}
