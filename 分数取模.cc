//分数取模 模板
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 998244353;
ll fast_mod(ll a, ll b) { //快速幂
    ll r = 1;
    a %= MOD;
    while(b) {
        if(b & 1) r = (r*a) % MOD;
        a = (a*a) % MOD;
        b >>= 1;
    }
    return r;
}
int main() {
    ll a, b; // a 为分子， b 为分母
    ll x = fast_mod(a, MOD-2);
    ll ans = ((b%MOD)*(x%MOD))%MOD; // b为分母
    printf("%lld\n", ans);
    return 0;
}

