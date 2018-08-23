#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;

int main(){
    int a[10];
    fill(a, a + 10, 1);
    for (int i = 0; i < 10; ++i){
        printf("%d ", a[i]);
    }
    printf("\n");

    fill_n(a, 10, 2);
    for (int i = 0; i < 10; ++i){
        printf("%d ", a[i]);
    }
    printf("\n");

    string b[10];
    fill(b, b + 10, "a");
    for (int i = 0; i < 10; ++i){
        printf("%s\n", b[i].c_str());
    }
    printf("\n");

    return 0;
}
