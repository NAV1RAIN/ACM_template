#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

const int MAX = 2e5+10;
int z1[4] = {-1,1,0,0};
int z2[4] = {0,0,1,-1};
char maze[5][MAX];
int vis[5][MAX];
int col[5][MAX];
struct node {
    int x;
    int y;
    int steps;
};
node s;
node e;
int M;
int in(node n) {
    if(n.x < 0 || n.y < 0 || n.x > 2 || n.y > M || maze[n.x][n.y] == 'X') {
        return 0;
    } else return 1;
}
int bfs() {
    queue<node> qf;
    queue<node> qb;
    memset(vis, 0, sizeof(vis));
    memset(col, 0, sizeof(col));
    qf.push(s);
    qb.push(e);
    vis[s.x][s.y] = 0;
    vis[e.x][e.y] = 1;
    col[s.x][s.y] = 1;
    col[e.x][e.y] = 2;
    while(qf.size() || qb.size()) {
        if(qf.size()) {
            node st = qf.front();
            qf.pop();
            for(int i = 0; i < 4; i++) {
                node t;
                t.x = st.x + z1[i];
                t.y = st.y + z2[i];
                if(in(t)) {
                    if(col[t.x][t.y] == 0) {
                        vis[t.x][t.y] = vis[st.x][st.y] + 1;
                        col[t.x][t.y] = 1;
                        qf.push(t);
                    } else if(col[t.x][t.y] == 2) {
                        return vis[st.x][st.y]+vis[t.x][t.y];
                    }
                }
            }
        }
        if(qb.size()) {
            node st = qb.front();
            qb.pop();
            for(int i = 0; i < 4; i++) {
                node t;
                t.x = st.x + z1[i];
                t.y = st.y + z2[i];
                if(in(t)) {
                    if(col[t.x][t.y] == 0) {
                        vis[t.x][t.y] = vis[st.x][st.y] + 1;
                        col[t.x][t.y] = 2;
                        qb.push(t);
                    } else if(col[t.x][t.y] == 1) {
                        return vis[st.x][st.y] + vis[t.x][t.y];
                    }
                }
            }
        }
    }
    return 0;
}
int main() {
    int a, b, m, n;
    scanf("%d%d", &m, &n);
    M = m;
    for(int i = 0; i < 2; i++) {
        scanf("%s", maze[i]);
    }
    for(int i = 0; i < n; i++) {
        int sx, sy, gx, gy;
        scanf("%d%d", &a, &b);
        sx = (a-1)/m, sy = (a-1)%m;
        gx = (b-1)/m, gy = (b-1)%m;
        s.x = sx, s.y = sy;
        e.x = gx, e.y = gy;
        s.steps = 0, e.steps = 1;
        if(s.x == e.x && s.y == e.y) puts("0");
        else {
            int res = bfs();
            if(res == 0 || maze[sx][sy] == 'X' || maze[gx][gy] == 'X') {
                puts("-1");
            } else printf("%d\n", res);
        }
    }
    return 0;
}
