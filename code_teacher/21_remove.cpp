#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;

bool test(int i){
    return (i < 5);
}

int main(){
    int a[5] = {1,2,1,3,1};
    int *e = remove(a, a + 5, 1);
    cout << "END: " << (e - a) << endl;
    for (int i = 0; i < 5; ++i){
        cout << a[i] << " ";
    }
    cout << endl;
    cout << "Left: " << endl;
    for(int *s = a; s < e; s++) cout << *s << " ";
    cout << endl;

    int d[10] = {1,3,5,7,9,2,4,6,8,10};
    e = remove_if(d, d + 10, test);
    cout << "END: " << (e - d) << endl;
    for (int i = 0; i < 10; ++i){
        cout << d[i] << " ";
    }
    cout << endl;
    cout << "Left: " << endl;
    for(int *s = d; s < e; s++) cout << *s << " ";
    cout << endl;

    int b[7] = {1,2,1,3,1,4,1};
    vector<int>v;
    vector<int>::iterator vi;
    copy(b, b + 7, back_inserter(v)); 
    vi = remove(v.begin(), v.end(), 1);
    //v.erase(remove(v.begin(), v.end(), 1), v.end());
    cout << "Size: " << v.size() << endl;
    for (int i = 0; i < (int)v.size(); ++i){
        cout << v[i] << " ";
    }

    return 0;
}
