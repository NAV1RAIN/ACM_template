#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;

int main(){
    int a[3] = {0,1,2}, i;
    do{
        for (i = 0; i < 3; ++i){
            printf("%d ", a[i]);
        }
        printf("\n");
    }while(next_permutation(a, a + 3));
    printf("NEXT\n");
    for (i = 0; i < 3; ++i){
        printf("%d ", a[i]);
        a[i] = 3 - i;
    }
    printf("\nPREV\n");
    do{
        for (i = 0; i < 3; ++i){
            printf("%d ", a[i]);
        }
        printf("\n");
    }while(prev_permutation(a, a + 3));

    printf("\n");
}
