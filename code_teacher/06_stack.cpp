#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int main(){
    stack<int>s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout << "Top: " << s.top() << endl;
    cout << "Size: " << s.size() << endl;
    s.pop();
    cout << "Size: " << s.size() << endl;
    if(s.empty()){
        cout << "Is empty" << endl;
    }else{
        cout << "Is not empty" << endl;
    }
    return 0;
}
