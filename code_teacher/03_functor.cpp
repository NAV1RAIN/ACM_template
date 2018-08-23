#include <iostream>
#include <algorithm>
using namespace std;

struct T1{
    int v;
};

struct cmp{
    const bool operator()(const T1 &a, const T1 &b){
        return (a.v < b.v);
    }
};

void test1();
void test2();

int main(){
    test1();
    test2();
    return 0;
}

void test1(){
    T1 a[5];

    int i;
    for (i = 0; i < 5; ++i){
        a[i].v = 5 - i;
    }

    sort(a, a + 5, cmp());

    for (i = 0; i < 5; ++i){
        cout << a[i].v << endl;
    }
}

#include <set>
void test2(){
    T1 t;
    set<T1, cmp> a;

    int i;
    for (i = 0; i < 5; ++i){
        t.v = 5 - i;
        a.insert(t);
    }

    for (set<T1, cmp>::iterator it = a.begin();
            it != a.end();
            it++){
        cout << it->v << endl;
    }
}
