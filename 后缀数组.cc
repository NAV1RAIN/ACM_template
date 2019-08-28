#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn = 2e4+5;
int t1[maxn], t2[maxn], c[maxn];
bool cmp(int *r, int a, int b, int l) {
    return r[a] == r[b] && r[a+l] == r[b+l];
}
void da(int str[], int sa[], int Rank[], int height[], int n, int m) {
    n++;
    int i, j, p, *x = t1, *y = t2;
    for(i = 0; i < m; i++) c[i] = 0;
    for(i = 0; i < n; i++) c[x[i] = str[i]]++;
    for(i = 1; i < m; i++) c[i] += c[i-1];
    for(i = n-1; i >= 0; i--) sa[--c[x[i]]] = i;
    for(j = 1; j <= n; j<<=1) {
        p = 0;
        for(i = n-j; i < n; i++) y[p++] = i;
        for(i = 0; i < n; i++) if(sa[i] >= j) y[p++] = sa[i] - j;
        for(i = 0; i < m; i++) c[i] = 0;
        for(i = 0; i < n; i++) c[x[y[i]]]++;
        for(i = 1; i < m; i++) c[i] += c[i-1];
        for(i = n-1; i >= 0; i--) sa[--c[x[y[i]]]] = y[i];
        swap(x, y);
        p = 1; x[sa[0]] = 0;
        for(i = 1; i < n; i++) {
            x[sa[i]] = cmp(y, sa[i-1], sa[i], j) ? p-1 : p++;
        }
        if(p >= n) break;
        m = p;
    }
    int k = 0;
    n--;
    for(i = 0; i <= n; i++) Rank[sa[i]] = i;
    for(i = 0; i < n; i++) {
        if(k) k--;
        j = sa[Rank[i]-1];
        while(str[i+k] == str[j+k]) k++;
        height[Rank[i]] = k;
    }
}
int Rank[maxn], height[maxn];

int str[maxn];
int r[maxn];
int sa[maxn];

bool check(int n, int k) {
    int Max = sa[1], Min = sa[1];
    for(int i = 2; i <= n; i++) {
        if(height[i] < k) Max = Min = sa[i];
        else {
            if(sa[i] < Min) Min = sa[i];
            if(sa[i] > Max) Max = sa[i];
            if(Max-Min > k) return true;
        }
    }
    return false;
}
int main() {
    // freopen("in", "r", stdin);
    int n;
    while(scanf("%d", &n) != EOF && n != 0) {
        for(int i = 0; i < n; i++) {
            scanf("%d", &str[i]);
        }
        for(int i = 0; i < n; i++) {
            r[i] = str[i+1]-str[i]+91;
        }
        n--;
        da(r, sa, Rank, height, n, 200);
        int ans = -1;
        int le = 1, ri = n/2;
        while(le <= ri) {
            int mid = (le+ri)/2;
            if(check(n, mid)) {
                ans = mid;
                le = mid+1;
            } else {
                ri = mid-1;
            }
        }
        if(ans < 4) printf("0\n");
        else printf("%d\n", ans+1);
    }
    return 0;
}