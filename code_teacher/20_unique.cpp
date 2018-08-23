#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;

int main(){
    int a[7] = {1,1,1,1,2,2,3};
    int *e = unique(a, a + 7);
    cout << "END: " << (e - a) << endl;
    for (int i = 0; i < 7; ++i){
        cout << a[i] << endl;
    }

int b[7] = {1,1,1,1,2,2,3};
vector<int>v;
copy(b, b + 7, back_inserter(v)); 
unique(v.begin(), v.end());
    //v.erase(unique(v.begin(), v.end()), v.end());
cout << "Size: " << v.size() << endl;
    for (int i = 0; i < (int)v.size(); ++i){
        cout << v[i] << endl;
    }
    return 0;
}
