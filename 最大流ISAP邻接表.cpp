#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
const int MAXE = 1000005;
const int INF = 0x3f3f3f3f;

struct Edge {
    int v;
    int c;
    int n;
    Edge() {}
    Edge(int v, int c, int n) : v(v), c(c), n(n) {}
};

Edge E[MAXE];
int H[MAXN], cntE;
int d[MAXN];
int cur[MAXN];
int pre[MAXN];
int gap[MAXN];
int s, t, nv, flow;  //s为起点，t为终点，nv为点的数量
int Q[MAXN], head, tail;

void init() {
    cntE = 0;
    memset(H, -1, sizeof(H));
}

void addedge(int u, int v, int c, int r = 0) {
    E[cntE] = Edge(v, c, H[u]);
    H[u] = cntE++;
    E[cntE] = Edge(u, r, H[v]);
    H[v] = cntE++;
}

void revbfs() {
    head = tail = 0;
    memset(d, -1, sizeof(d));
    memset(gap, 0, sizeof(gap));
    Q[tail++] = t;
    d[t] = 0;
    gap[d[t]] = 1;
    while (head != tail) {
        int u = Q[head++];
        for (int i = H[u]; ~i; i = E[i].n) {
            int v = E[i].v;
            if (~d[v]) continue;
            d[v] = d[u] + 1;
            gap[d[v]]++;
            Q[tail++] = v;
        }
    }
}

int isap() {
    memcpy(cur, H, sizeof cur);
    flow = 0;
    revbfs();
    int u = pre[s] = s, i;
    while (d[s] < nv) {
        if (u == t) {
            int f = INF;
            for (i = s; i != t; i = E[cur[i]].v) {
                if (f > E[cur[i]].c) {
                    f = E[cur[i]].c;
                    u = i;
                }
            }
            flow += f;
            for (i = s; i != t; i = E[cur[i]].v) {
                E[cur[i]].c -= f;
                E[cur[i] ^ 1].c += f;
            }
        }
        for (i = cur[u]; ~i; i = E[i].n) {
            int v = E[i].v;
            if (E[i].c && d[u] == d[v] + 1) break;
        }
        if (~i) {
            cur[u] = i;
            pre[E[i].v] = u;
            u = E[i].v;
        } else {
            if (0 == --gap[d[u]]) break;
            int minv = nv;
            for (int i = H[u]; ~i; i = E[i].n) {
                int v = E[i].v;
                if (E[i].c && minv > d[v]) {
                    minv = d[v];
                    cur[u] = i;
                }
            }
            d[u] = minv + 1;
            gap[d[u]]++;
            u = pre[u];
        }
    }
    return flow;
}

int main() {
    freopen("RAW/in", "r", stdin);
    freopen("RAW/out", "w", stdout);
    return 0;
}