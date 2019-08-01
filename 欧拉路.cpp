#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1e5+5;
int val[MAXN];
int js[MAXN];
int n, m;
int ans;
int main()
{
    int T;
    scanf("%d", &T);
    while(T--) {
        ans = 0;
        memset(val, 0, sizeof(val));
        memset(js, 0, sizeof(js));
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i++) {
            scanf("%d", &val[i]);
        }
        for(int i = 1; i <= m; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
//            if(u == v) {
//                ans ^= val[u];
//                continue;
//            }
            js[u]++;
            js[v]++;
        }
        int num = 0;
        for(int i = 1; i <= n; i++) {
            int temp = js[i] >> 1;
            if(js[i] & 1) temp++, num++;
            if(temp & 1) {
                ans ^= val[i];
            }
            if(num > 2) break;
        }
        if(num == 0 || num == 2) {
            if(num == 0) {
                int temp = ans;
                for(int i = 1; i <= n; i++) {
                    temp = max(temp, ans ^ val[i]);
                }
                ans = temp;
            }
            printf("%d\n", ans);
        } else {
            printf("Impossible\n");
        }
    }
    return 0;
}
