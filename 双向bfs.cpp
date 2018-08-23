#include <iostream>
#include <queue>
using namespace std;
char ss[3];
char ee[3];
typedef struct node {
    int x;
    int y;
    int steps;
} node;
int d[8][2]= {{-2,1},{-2,-1},{-1,-2},{-1,2},{2,-1},{2,1},{1,-2},{1,2}};
int visited[8][8];
int color[8][8];//区分当前位置是哪个队列查找过了
node s;
node e;
int in(node n) {
    if(n.x<0||n.y<0||n.x>7||n.y>7)
        return 0;
    return 1;
}
int bfs() {
    queue<node>qf;                          //我发现如果把qf和qb放在外面的话，节省的时间挺惊人的，耗时16MS
    queue<node>qb;
    memset(visited,0,sizeof(visited));
    memset(color,0,sizeof(color));
    qf.push(s);
    qb.push(e);
    visited[s.x][s.y]=0;
    visited[e.x][e.y]=1;
    color[s.x][s.y]=1;//着色
    color[e.x][e.y]=2;
    while(!qf.empty()||!qb.empty()) {
        if(!qf.empty()) {
            node st=qf.front();
            qf.pop();
            for(int i=0; i<8; ++i) {
                node t;
                t.x=st.x+d[i][0];
                t.y=st.y+d[i][1];
                if(in(t)) {
                    if(color[t.x][t.y]==0) {
                        visited[t.x][t.y]=visited[st.x][st.y]+1;
                        color[t.x][t.y]=1;
                        qf.push(t);
                    } else if(color[t.x][t.y]==2) {
                        return visited[st.x][st.y]+visited[t.x][t.y];
                    }
                }
            }
        }
        if(!qb.empty()) {
            node st=qb.front();
            qb.pop();
            for(int i=0; i<8; ++i) {
                node t;
                t.x=st.x+d[i][0];
                t.y=st.y+d[i][1];
                if(in(t)) {
                    if(color[t.x][t.y]==0) {
                        visited[t.x][t.y]=visited[st.x][st.y]+1;
                        color[t.x][t.y]=2;
                        qb.push(t);
                    } else if(color[t.x][t.y]==1) {
                        return visited[st.x][st.y]+visited[t.x][t.y];
                    }
                }
            }
        }
    }
}
int main(int argc, char *argv[]) {
    // freopen("in.txt","r",stdin);
    while(scanf("%s %s",ss,ee)==2) {
        s.x=ss[0]-'a';
        s.y=ss[1]-'1';
        e.x=ee[0]-'a';
        e.y=ee[1]-'1';
        s.steps=0;
        e.steps=1;
        if(s.x==e.x&&s.y==e.y)
            printf("0");
        else
            printf("",bfs());
    }
    return 0;
}
