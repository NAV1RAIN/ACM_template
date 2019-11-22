#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 1e5 + 5;
long long num[MAXN];
struct node {
    int l, r;
    long long lazy;
    long long nSum;
} segTree[MAXN * 3];
void pushdown(int i) {
    segTree[i << 1].lazy += segTree[i].lazy;
    segTree[i << 1 | 1].lazy += segTree[i].lazy;
    segTree[i << 1].nSum +=
        segTree[i].lazy * (segTree[i << 1].r - segTree[i << 1].l + 1);
    segTree[i << 1 | 1].nSum +=
        segTree[i].lazy * (segTree[i << 1 | 1].r - segTree[i << 1 | 1].l + 1);
    segTree[i].lazy = 0;
}
void Build(int i, int l, int r) {
    segTree[i].l = l;
    segTree[i].r = r;
    segTree[i].lazy = 0;
    if (l == r) {
        segTree[i].nSum = num[l];
        return;
    }
    int mid = (l + r) >> 1;
    Build(i << 1, l, mid);
    Build(i << 1 | 1, mid + 1, r);
    segTree[i].nSum = segTree[i << 1].nSum + segTree[i << 1 | 1].nSum;
}
void Add(int i, int l, int r, int b) {
    if (r < segTree[i].l || l > segTree[i].r)
        return;
    if (l <= segTree[i].l && r >= segTree[i].r) {
        segTree[i].lazy += b;
        segTree[i].nSum += b * (segTree[i].r - segTree[i].l + 1);
        return;
    }
    if (segTree[i].lazy)
        pushdown(i);
    Add(i << 1, l, r, b);
    Add(i << 1 | 1, l, r, b);
    segTree[i].nSum = segTree[i << 1].nSum + segTree[i << 1 | 1].nSum;
}
long long Query(int i, int l, int r) {
    if (r < segTree[i].l || l > segTree[i].r)
        return 0;
    if (l <= segTree[i].l && r >= segTree[i].r) {
        return segTree[i].nSum;
    }
    if (segTree[i].lazy)
        pushdown(i);
    int mid = (segTree[i].l + segTree[i].r) >> 1;
    if (r <= mid) {
        return Query(i << 1, l, r);
    } else if (l > mid) {
        return Query(i << 1 | 1, l, r);
    } else
        return Query(i << 1, l, mid) + Query(i << 1 | 1, mid + 1, r);
}
int main(int argc, const char *argv[]) {
    int n, q;
    char str[5];
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &num[i]);
    }
    Build(1, 1, n);
    while (q--) {
        scanf("%s", str);
        if (str[0] == 'Q') {
            int a, b;
            scanf("%d%d", &a, &b);
            printf("%lld\n", Query(1, a, b));
        } else if (str[0] == 'C') {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            Add(1, a, b, c);
        }
    }
    return 0;
}