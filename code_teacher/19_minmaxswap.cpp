#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;

int main(){
    int a = 1, b = 2;
    cout << min(a, b) << endl;
    cout << max(a, b) << endl;
    swap(a, b);
    cout << a << ", " << b << endl;
    return 0;
}
