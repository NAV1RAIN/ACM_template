#include <iostream>
#include <list>
using namespace std;

int main(){
    list<int>lis;
    list<int>::iterator li;
    for (int i = 0; i < 2; ++i){
        lis.push_back(i);
        lis.push_front(i);
    }
    lis.sort();
    //lis.unique();
    cout << "Size: " << lis.size() << endl;
    for (li = lis.begin(); li != lis.end(); li++){
        cout << *li << endl;
    }

    lis.pop_front();
    cout << "Size: " << lis.size() << endl;
    for (li = lis.begin(); li != lis.end(); li++){
        cout << *li << endl;
    }

    lis.pop_back();
    cout << "Size: " << lis.size() << endl;
    for (li = lis.begin(); li != lis.end(); li++){
        cout << *li << endl;
    }


    return 0;
}
