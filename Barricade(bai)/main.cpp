#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 1010;
const int SIZE = 1e4+5;
struct Node {
    int from, to, w;
}Edge[SIZE];

struct edge {
    int to, cap, rev;
};

vector<edge> G[MAXN];

int cost[MAXN][MAXN];
int dis[MAXN];
bool used[MAXN];
int n, m;

void dijkstra(int s) {
    memset(dis, INF, sizeof(dis));
    memset(used, 0, sizeof(used));
    dis[s] = 0;

    while(true) {
        int v = -1;
        for(int u = 1; u <= n; u++) {
            if(!used[u] && (v == -1 || dis[u] < dis[v])) v = u;
        }

        if(v == -1) break;
        used[v] = true;

        for(int u = 1; u <= n; u++) {
            dis[u] = min(dis[u], dis[v]+cost[v][u]);
        }
    }
}

void addEdge(int from, int to, int cap) {
    int lenf = G[from].size();
    int lent = G[to].size();
    edge t1, t2;
    t1.to = to, t1.cap = cap, t1.rev = lent;
    t2.to = from, t2.cap = 0, t2.rev = lenf;
    G[from].push_back(t1);
    G[to].push_back(t2);
}

int dfs(int v, int t, int f) {
    if(v == t) return f;
    used[v] = true;
    int len = G[v].size();
    for(int i = 0; i < len; i++) {
        edge &e = G[v][i];
        if(!used[e.to] && e.cap > 0) {
            int d = dfs(e.to, t, min(f, e.cap));
            if(dis[e.to]-dis[v] == 1 && d > 0) {
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

int max_flow(int s, int t) {
    int flow = 0;
    while(true) {
        memset(used, 0, sizeof(used));
        int f = dfs(s, t, INF);
        if(f == 0) return flow;
        flow += f;
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--) {
        memset(cost, INF, sizeof(cost));
        memset(Edge, 0, sizeof(Edge));
        for(int i = 0; i < MAXN; i++) {
            G[i].clear();
        }
        scanf("%d%d", &n, &m);
        for(int i = 0; i < m; i++) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            Edge[i].from = u, Edge[i].to = v, Edge[i].w = w;
            cost[u][v] = 1;
            cost[v][u] = 1;
        }
        dijkstra(n);

        if(dis[1] == INF) {
            printf("0\n");
            continue;
        }
        for(int i = 0; i < m; i++) {
            int u, v, w;
            u = Edge[i].from;
            v = Edge[i].to;
            w = Edge[i].w;
            if(dis[v]-dis[u] == 1) {
                addEdge(u, v, w);
            }
            if(dis[u]-dis[v] == 1) {
                addEdge(v, u, w);
            }
        }

        int ans = max_flow(n, 1);

        printf("%d\n", ans);
    }
    return 0;
}
