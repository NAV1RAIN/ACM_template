#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int SIZE = 1e4+5;
const int MAXN = 1010;
const int INF = 0x3f3f3f3f;

struct Edge {
    int to, next, cap, flow;
}edge[SIZE];
struct NODE{
    int from, to, cap;
}G_temp[SIZE];

int n, m;
int tol;
int head[MAXN];
int gap[MAXN], dep[MAXN], pre[MAXN], cur[MAXN];

bool vis[MAXN];
int lowcost[MAXN];
int cost[MAXN][MAXN];

void Dijkstra(int beg)
{
    memset(lowcost, INF, sizeof(lowcost));
    memset(vis, false, sizeof(vis));
    lowcost[beg] = 0;
    for(int j = 1; j <= n; j++) {
        int k = -1, Min = INF;
        for(int i = 1; i <= n; i++) {
            if(!vis[i] && lowcost[i] < Min) {
                Min = lowcost[i];
                k = i;
            }
        }
        if(k == -1) break;
        vis[k] = true;
        for(int i = 1; i <= n; i++) {
            if(!vis[i] && lowcost[k]+cost[k][i] < lowcost[i]) {
                lowcost[i] = lowcost[k]+cost[k][i];
            }
        }
    }
}

void init() {
    tol = 0;
    memset(head, -1, sizeof(head));
}
void addedge(int u, int v, int w) {

}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &n, &m);
        memset(cost, INF, sizeof(cost));
        for(int i = 0; i < m; i++) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            cost[u][v] = 1;
            cost[v][u] = 1;
            G_temp[i].from = u, G_temp[i].to = v, G_temp[i].cap = w;
        }
        Dijkstra(n);
        if(lowcost[1] == INF) {
            printf("0\n");
            continue;
        }
        init();
        for(int i = 0; i < m; i++) {
            int u, v, w;
            u = G_temp[i].from;
            v = G_temp[i].to;
            w = G_temp[i].cap;
            if(lowcost[v]-lowcost[u] == 1) {

            } else if(lowcost[u]-lowcost[v] == 1) {

            }
        }
    }
    return 0;
}
