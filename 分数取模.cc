//����ȡģ ģ��
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 998244353;
ll fast_mod(ll a, ll b) { //������
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
    ll a, b; // a Ϊ���ӣ� b Ϊ��ĸ
    ll x = fast_mod(a, MOD-2);
    ll ans = ((b%MOD)*(x%MOD))%MOD; // bΪ��ĸ
    printf("%lld\n", ans);
    return 0;
}

