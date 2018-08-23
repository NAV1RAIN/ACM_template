#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    string t1, t2("a");
    t1 = "b";
    cout << "t1: " << t1 << ", t2: " << t2 << endl;
    cout << "t2[0] = " << t2[0] << endl;
    t1 += "def";
    cout << "t1 = " << t1 << endl;

    if(t1 == t2){
        cout << "t1 == t2" << endl;
    }else{
        cout << "t1 != t2" << endl;
    }

    printf("t1 = %s\n", t1.c_str()); //不要修改!

    unsigned idx = t1.find("de");
    if(idx != string::npos){
        cout << "find @ index " << idx << endl;
    }else{
        cout << "not found " << endl;
    }

    string t3 = "abcd";
    t3.replace(1, 2, "ooxx");
    cout << "t3: " << t3 << ", size = " << t3.size() << endl;
    return 0;
}
