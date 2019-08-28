#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int n;

/***********************后缀数组****************************/
// x[i]表示第i个字符开头的后缀在所有后缀中的排名  sa[i]表示排名为i的后缀开头字符的位置
int sa[maxn], x[maxn], c[maxn], y[maxn], height[maxn];
;
char s[maxn];
void SA() {  //O(nlogn) 倍增求后缀数组
    int m = 128;
    for (int i = 0; i <= m; i++)
        c[i] = 0;
    for (int i = 1; i <= n; i++)
        c[x[i] = s[i]]++;
    for (int i = 1; i <= m; i++)
        c[i] += c[i - 1];
    for (int i = n; i >= 1; i--)
        sa[c[x[i]]--] = i;

    for (int k = 1; k <= n; k <<= 1) {
        int p = 0;
        for (int i = 0; i <= m; i++)
            y[i] = 0;
        for (int i = n - k + 1; i <= n; i++)
            y[++p] = i;
        for (int i = 1; i <= n; i++)
            if (sa[i] > k)
                y[++p] = sa[i] - k;

        for (int i = 0; i <= m; i++)
            c[i] = 0;
        for (int i = 1; i <= n; i++)
            c[x[y[i]]]++;
        for (int i = 1; i <= m; i++)
            c[i] += c[i - 1];
        for (int i = n; i >= 1; i--)
            sa[c[x[y[i]]]--] = y[i];

        swap(x, y);
        x[sa[1]] = 1;
        p = 1;
        for (int i = 2; i <= n; ++i)
            x[sa[i]] = (y[sa[i]] == y[sa[i - 1]] && y[sa[i] + k] == y[sa[i - 1] + k]) ? p : ++p;
        if (p >= n)
            break;
        m = p;
    }
}
void get_height() {  //求height数组
    int k = 0;
    //for (int i=1; i<=n; ++i) rk[sa[i]]=i; x数组即为rank数组
    for (int i = 1; i <= n; ++i) {
        if (x[i] == 1)
            continue;
        if (k) --k;
        int j = sa[x[i] - 1];
        while (j + k <= n && i + k <= n && s[i + k] == s[j + k]) ++k;
        height[x[i]] = k;
    }
}
/*******************************************************************/

/**************************划分树开始**************************/
int tree[30][maxn];    //表示每层每个位置的值
int sorted[maxn];      //已经排序的数
int toleft[30][maxn];  //toleft[p][i]表示第i层从1到i有多少个数分入左边

void build(int l, int r, int dep) {
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    int same = mid - l + 1;       //表示等于中间值而且被分入左边的个数  先初始化为左边的个数  之后再减
    for (int i = l; i <= r; i++)  //是L  不是one
    {
        if (tree[dep][i] < sorted[mid])
            same--;
    }
    int lpos = l;
    int rpos = mid + 1;  //本节点的两个孩子节点的开头
    for (int i = l; i <= r; i++) {
        if (tree[dep][i] < sorted[mid])  //比中间的数小，分入左边
            tree[dep + 1][lpos++] = tree[dep][i];
        else if (tree[dep][i] == sorted[mid] && same > 0) {
            tree[dep + 1][lpos++] = tree[dep][i];
            same--;
        } else  //比中间值大分入右边
            tree[dep + 1][rpos++] = tree[dep][i];
        toleft[dep][i] = toleft[dep][l - 1] + lpos - l;  //从1到i放左边的个数
    }
    build(l, mid, dep + 1);
    build(mid + 1, r, dep + 1);
}

//查询区间第k大的数，[L,R]是大区间，[l,r]是要查询的小区间
int query(int L, int R, int l, int r, int dep, int k) {
    if (l == r)
        return tree[dep][l];
    int mid = (L + R) >> 1;
    int cnt = toleft[dep][r] - toleft[dep][l - 1];  //[l,r]中位于左边的个数
    if (cnt >= k) {
        //L+要查询的区间前被放在左边的个数
        int newl = L + toleft[dep][l - 1] - toleft[dep][L - 1];
        //左端点加上查询区间会被放在左边的个数
        int newr = newl + cnt - 1;
        return query(L, mid, newl, newr, dep + 1, k);
    } else {
        int newr = r + toleft[dep][R] - toleft[dep][r];
        int newl = newr - (r - l - cnt);
        return query(mid + 1, R, newl, newr, dep + 1, k - cnt);
    }
}
/***************************划分树结束***********************************/

inline int read() {
    int sgn = 1;
    int cnt = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            sgn = -sgn;
        ch = getchar();
    }
    while ('0' <= ch && ch <= '9') {
        cnt = cnt * 10 + (ch - '0');
        ch = getchar();
    }
    return sgn * cnt;
}

/****************************   S  T  表   ****************************/
int g[maxn][20];  //区间最小
void ST_prewoek() {
    for (int i = 1; i <= n; i++) {
        g[i][0] = height[i];
    }
    for (int i = 1, imax = log2(n); i <= imax; i++) {
        for (int j = 1; j + (1 << i) - 1 <= n; j++)  //注意j的右端点为j+(1<<i)-1，-1是因为要包含j自己
        {
            g[j][i] = min(g[j][i - 1], g[j + (1 << i - 1)][i - 1]);
        }
    }
}

int ST_query(int l, int r) {  //求[l,r]中的最小值
    int k = log2(r - l + 1);
    return min(g[l][k], g[r - (1 << k) + 1][k]);
}
/************************************************************/

bool check(int l, int r, int len) {  //二分判断函数
    if (l == r)
        return true;
    l = x[l];
    r = x[r];
    if (l > r)
        swap(l, r);
    if (ST_query(l + 1, r) > len)
        return true;
    return false;
}
/*
 * 题意：给你一个长度为n的字符串，每次询问给出三个数：L , R , K,表示原串 L 到 R 的子串在原串第K次出现的首字母的位置
 * 解题思路：对子串的大量操作，不难想到后缀数组（后缀树/后缀自动机不会，所以没想到），注意到子串s[L.....R]必
 * 然是某一个后缀的前缀，所以所有前缀是该子串的后缀的排名（即rank数组的值）必定连续，也就是说在后缀数组（sa数
 * 组）中，下标是连续的，那么就是求区间第K大了（因为sa数组的值代表的是在字符串中的位置）（这里区间第K大我用划
 * 分树求），至于这一段区间的起点和终点，可以用二分求，因为 rank[ L ] 必定是所求区间中的一个值，那么就可以以rank[ L ]
 * 为中心，左右分别二分向外扩展区间，二分的check函数（判断成立条件），可以求出当前位置的后缀和L开始的后缀的LCP（最长公
 * 共前缀），判断是否大于等于（R - L + 1）即可，自然语言比较无力，直接看代码吧=。=
 * 
 */

int main() {
    int t, Q;
    scanf("%d", &t);
    while (t--) {
        memset(tree, 0, sizeof(tree));
        scanf("%d%d", &n, &Q);
        scanf("%s", s + 1);
        SA();
        get_height();
        for (int i = 1; i <= n; i++) {
            tree[0][i] = sorted[i] = sa[i];
        }
        sort(sorted + 1, sorted + n + 1);
        build(1, n, 0);
        ST_prewoek();
        int l, r, k;
        while (Q--) {
            l = read();
            r = read();
            k = read();
            int rk = x[l], len = r - l;
            int tl = 1, tr = rk;
            int nl = rk, nr = rk;
            while (tl <= tr) {
                int mid = (tl + tr) / 2;
                if (check(sa[mid], l, len)) {
                    nl = mid;
                    tr = mid - 1;
                } else {
                    tl = mid + 1;
                }
            }
            tl = rk;
            tr = n;
            while (tl <= tr) {
                int mid = (tl + tr) / 2;
                if (check(sa[mid], l, len)) {
                    nr = mid;
                    tl = mid + 1;
                } else {
                    tr = mid - 1;
                }
            }
            if (nr - nl + 1 < k) {
                puts("-1");
            } else {
                printf("%d\n", query(1, n, nl, nr, 0, k));
            }
        }
    }
    return 0;
}