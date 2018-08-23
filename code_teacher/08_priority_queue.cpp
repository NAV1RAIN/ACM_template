#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define pow2(a) ((a)*(a))
#define dist2(x, y) (pow2(x) + pow2(y))
struct coord{
    int x, y;
    const bool operator<(const coord &b)const{
        return (dist2(x, y) < dist2(b.x, b.y));
    }
};

struct cmp{
    const bool operator()(const coord &a, const coord &b){
        return (dist2(a.x, a.y) < dist2(b.x, b.y));
    }
};

int main(){
    priority_queue<coord> s; //重载operator<, 不需要functor
    //priority_queue<coord, vector<coord>, cmp> s; //没有重载,使用functor
    coord a;
    a.x = 3, a.y = 2;
    s.push(a);
    a.x = 1, a.y = 2;
    s.push(a);
    a.x = 2, a.y = 2;
    s.push(a);

    cout << "Size: " << s.size() << endl;
    cout << "Top: " << s.top().x << ", " << s.top().y << endl;

    s.pop();
    cout << "Size: " << s.size() << endl;
    cout << "Top: " << s.top().x << ", " << s.top().y << endl;

    if(s.empty()){
        cout << "Is empty" << endl;
    }else{
        cout << "Is not empty" << endl;
    }
    return 0;
}
