#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main(){
    multimap<string, int> mm1;
    multimap<string, int>::iterator mm1i, p1, p2;
    mm1.insert(make_pair("b", 3));
    mm1.insert(make_pair("a", 0));
    mm1.insert(make_pair("b", 5));
    mm1.insert(make_pair("c", 4));
    mm1.insert(make_pair("b", 2));
    cout << "Size: " << mm1.size() << endl;
    for(mm1i = mm1.begin(); mm1i != mm1.end(); mm1i++){
        cout << mm1i->first << ": " << mm1i->second << endl;
    }

    cout << "COUNT: " << mm1.count("b") << endl;
    cout << "Bound: " << endl;
    p1 = mm1.lower_bound("b");
    p2 = mm1.upper_bound("b");
    for(mm1i = p1; mm1i != p2; mm1i++){
        cout << mm1i->first << ": " << mm1i->second << endl;
    }

    return 0;
}
