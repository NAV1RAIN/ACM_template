#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 2010;
struct TT {
    ll sum, maxsum, lmax, rmax;
} tree[MAXN << 2];
int idList[MAXN];
int arr[MAXN];
void update(int id) {
    int ls = id << 1, rs = id << 1 | 1;
    tree[id].sum = tree[ls].sum + tree[rs].sum;
    tree[id].maxsum = max(max(tree[ls].maxsum, tree[rs].maxsum), tree[ls].rmax + tree[rs].lmax);
    tree[id].lmax = max(tree[ls].lmax, tree[ls].sum + tree[rs].lmax);
    tree[id].rmax = max(tree[rs].rmax, tree[rs].sum + tree[ls].rmax);
}
void build(int id, int l, int r) {
    if(l == r) {
        idList[l] = id;
        tree[id].sum = tree[id].lmax = tree[id].rmax = tree[id].maxsum = arr[l];
        return ;
    }
    int mid = (l + r) >> 1;
    int ls = id << 1, rs = id << 1 | 1;
    build(ls, l, mid), build(rs, mid + 1, r);
    update(id);
}
TT query(int id, int l, int r, int ql, int qr) {
    if(ql <= l && r <= qr) return tree[id];
    int mid = (l + r) >> 1, ls = id << 1, rs = id << 1 | 1;
    if(qr <= mid) return query(ls, l, mid, ql, qr);
    if(ql > mid) return query(rs, mid + 1, r, ql, qr);
    TT tl = query(ls, l, mid, ql, qr), tr = query(rs, mid + 1, r, ql, qr);
    TT ans;
    ans.sum = tl.sum + tr.sum;
    ans.maxsum = max(max(tl.maxsum, tr.maxsum), tl.rmax + tr.lmax);
    ans.lmax = max(tl.lmax, tl.sum + tr.lmax);
    ans.rmax = max(tr.rmax, tr.sum + tl.rmax);
    return ans;
}
int main() {
    freopen("RAW/in", "r", stdin);
    freopen("RAW/out", "w", stdout);
    return 0;
}