#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1010;
const int INF = 0x3f3f3f3f;
bool vis[MAXN];
int pre[MAXN];  //路径前向星数组
int cost[MAXN][MAXN];  //图
int lowcost[MAXN];  //起点到各点的最短路的值
void Dijkstra(int n, int beg) {  //n为点的数目，beg为起点
    for(int i = 0; i < n; i++) {
        lowcost[i] = INF;
        vis[i] = false;
        pre[i] = -1;
    }
    lowcost[beg] = 0;
    for(int i = 0; i < n; i++) {
        int k = -1;
        int Min = INF;
        for(int j = 0; j < n; j++) {
            if(!vis[j] && lowcost[j] < Min) {
                Min = lowcost[j];
                k = j;
            }
        }
        if(k == -1)
            break;
        vis[k] = true;
        for(int j = 0; j < n; j++) {
            if(!vis[j] && lowcost[k] + cost[k][j] < lowcost[j]) {
                lowcost[j] = lowcost[k] + cost[k][j];
                pre[j] = k;
            }
        }
    }
}

int main() {
    return 0;
}