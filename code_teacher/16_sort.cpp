#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
using namespace std;

int main(){
    int a[5] = {1,3,5,2,4};
    sort(a, a + 5);
    for (int i = 0; i < 5; ++i){
        printf("%d  ", a[i]);
    }
    printf("\n");

    sort(a, a + 5, greater<int>());
    for (int i = 0; i < 5; ++i){
        printf("%d  ", a[i]);
    }
    printf("\n");

    stable_sort(a, a + 5);
    for (int i = 0; i < 5; ++i){
        printf("%d  ", a[i]);
    }
    printf("\n");
    return 0;
}
