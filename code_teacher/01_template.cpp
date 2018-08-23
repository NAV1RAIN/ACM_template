#include <iostream>
#include <algorithm>
using namespace std;

template<typename T>
T add(T a, T b){
    return (a + b);
}

bool intgreater(const int &a, const int &b){
    return (a > b);
}
 
int main(){

    cout << add(1, 2) << endl;
    cout << add(1.1, 2.2) << endl;
    //return 0;

    //--------------

    int a[5] = {5,3,8,6,0};

    cout << "incremental:" << endl;
    sort(a, a + 5);
    for (int i = 0; i < 5; ++i){
        cout << a[i] << endl;
    }

    cout << "decremental:" << endl;
    sort(a, a + 5, intgreater);
    for (  i = 0; i < 5; ++i){
        cout << a[i] << endl;
    }
    return 0;
}

