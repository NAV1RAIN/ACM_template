#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

struct T1{
    int key;
    int value1, value2;
    bool operator<(const T1 &b)const{
        return (key < b.key);
    }
};

struct T2{
    int key;
    int v1, v2;
};
struct T2cmp{
    bool operator()(const T2 &a, const T2 &b){
        return (a.key < b.key);
    }
};

int main(){
    set<T1> s2;
    set<T2, T2cmp> s3;

#if 1
    set<string>s1;
    set<string>::iterator iter1;
#else
    set<string, greater<string> >s1;
    set<string, greater<string> >::iterator iter1;
#endif
    s1.insert("abc");
    s1.insert("abc");
    s1.insert("abc");
    s1.insert("bca");
    s1.insert("aaa");

    cout << "ITERATE:" << endl;
    for (iter1 = s1.begin(); iter1 != s1.end(); iter1++){
        cout << (*iter1) << endl;
    }

    cout << "FIND:" << endl;
    iter1 = s1.find("abc");
    if(iter1 != s1.end()) {
        cout << *iter1 << endl;
    }else{
        cout << "NOT FOUND" << endl;
    }

    return 0;
}
