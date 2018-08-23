#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main(){
    queue<int>s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout << "Size: " << s.size() << endl;
    cout << "Front: " << s.front() << endl;
    cout << "Back: " << s.back() << endl;
    cout << endl;

    s.pop();
    cout << "Size: " << s.size() << endl;
    cout << "Front: " << s.front() << endl;
    cout << "Back: " << s.back() << endl;
    if(s.empty()){
        cout << "Is empty" << endl;
    }else{
        cout << "Is not empty" << endl;
    }
    return 0;
}
