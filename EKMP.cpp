#include <bits/stdc++.h>
using namespace std;

const long long SIZE = 1e6+6;
//NEXT[i]:x[i...m-1] 与 x[0...m-1] 的最长公共前缀
//extend[i]:y[i...n-1] 与 x[0...m-1] 的最长公共前缀
void pre_EKMP(char x[], long long m, long long NEXT[]) {
    NEXT[0] = m;
    long long j = 0;
    while (j + 1 < m && x[j] == x[j + 1]) j++;
    NEXT[1] = j;
    long long k = 1;
    for (long long i = 2; i < m; i++) {
        long long p = NEXT[k] + k - 1;
        long long L = NEXT[i - k];
        if (i + L < p + 1)
            NEXT[i] = L;
        else {
            j = max((long long)0, p-i+1);
            while (i + j < m && x[i + j] == x[j]) j++;
            NEXT[i] = j;
            k = i;
        }
    }
}
void EKMP(char x[], long long m, char y[], long long n, long long NEXT[], long long extend[]) {
    pre_EKMP(x, m, NEXT);
    long long j = 0;
    while (j < n && j < m && x[j] == y[j]) j++;
    extend[0] = j;
    long long k = 0;
    for (long long i = 1; i < n; i++) {
        long long p = extend[k] + k - 1;
        long long L = NEXT[i - k];
        if (i + L < p + 1)
            extend[i] = L;
        else {
            j = max((long long)0, p - i + 1);
            while (i + j < n && j < m && y[i + j] == x[j]) j++;
            extend[i] = j;
            k = i;
        }
    }
}
long long NEXT[SIZE];
long long extend[SIZE];
char str[SIZE];

int main() {
    // freopen("RAW/in", "r", stdin);
    // freopen("RAW/out", "w", stdout);
    return 0;
}