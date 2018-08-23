#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;

int main(){
    int a[10] = {1,3,5,2,4,6,7,5,2,5};
    sort(a, a + 10);
    for (int i = 0; i < 10; ++i){
        printf("%d  ", a[i]);
    }
    printf("\n");

    int *s, *e;
    s = lower_bound(a, a + 10, 5);
    e = upper_bound(a, a + 10, 5);
    printf("[%d, %d)\n", s - a, e - a);
    while(s != e){
        printf("%d ", *s++);
    }

    return 0;
}
