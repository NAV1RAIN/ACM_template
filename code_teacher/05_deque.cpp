#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

int main(){
    deque<int> a;
    for (int i = 0; i < 5; ++i){
        a.push_back(5 - i);
    }
    cout << "Size: " << a.size() << endl;
    a.push_front(0);

    cout << "Size: " << a.size() << endl;
    for (int i = 0; i < (int)a.size(); ++i){
        cout << a[i] << ", " << endl;
    }
    cout << endl;

    sort(a.begin(), a.end());
    cout << "Size: " << a.size() << endl;
    for (int i = 0; i < (int)a.size(); ++i){
        cout << a[i] << ", " << endl;
    }
    cout << endl;

    a.clear();
    cout << "Size: " << a.size() << endl;
    return 0;
}
