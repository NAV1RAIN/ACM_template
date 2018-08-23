#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

struct T1{
    int v;
    bool operator<(const T1 &a)const{
        return (v < a.v);
    }
};

struct T2{
    int v;
};
struct cmp{
    const bool operator()(const T2 &a, const T2 &b){
        return (a.v < b.v);
    }
};

int main(){
    map<T1, int>mt1; //example for user-defined class
    map<T2, int, cmp>mt2; //example for user-defined class(functor)

    map<string, int> m2;
    map<string, int>::iterator m2i, p1, p2;
    //map<string, int, greater<string> >m2;
    //map<string, int, greater<string> >::iterator m2i, p1, p2;
    m2["abd"] = 2;
    m2["abc"] = 1;
    m2["cba"] = 2;
    m2.insert(make_pair("aaa", 9));
    m2["abf"] = 4;
    m2["abe"] = 2;
    cout << m2["abc"] << endl;

    m2i = m2.find("cba");
    if(m2i != m2.end()){
        cout << m2i->first << ": " << m2i->second << endl;
    }else{
        cout << "find nothing" << endl;
    }

    cout << "Iterate" << endl;
    for(m2i = m2.begin(); m2i != m2.end(); m2i++){
        cout << m2i->first << ": " << m2i->second << endl;
    }

    return 0;
}
