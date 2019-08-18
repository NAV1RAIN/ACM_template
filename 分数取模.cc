#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int MOD = 998244353;
LL fast_mod(LL a, LL b) {
    LL r = 1;
    a %= MOD;
    while(b) {
        if(b & 1) r = (r*a) % MOD;
        a = (a*a) % MOD;
        b >>= 1;
    }
    return r;
}
int main() {
    LL a, b;
    LL x = fast_mod(a, MOD-2);
    LL ans = ((b%MOD)*(x%MOD))%MOD;
    printf("%LLd\n", ans);
    return 0;
}

