#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX_N = 1e5+10;
int heap[MAX_N], sz = 0;
void push(int x) {  //用作插入数值
    //自己节点的编号
    int i = sz++;

    while(i > 0) {
        // 父亲节点的编号
        int p = (i - 1)/2;
        // 如果已经没有大小颠倒则退出
        if(heap[p] <= x)
            break;
        // 把父亲节点的数值放下来，而把自己提上去
        heap[i] = heap[p];
        i = p;
    }
    heap[i] = x;
}
int pop() {     //用作提取并删除最小值
    // 最小值
    int ret = heap[0];
    // 要提到根的数值
    int x = heap[--sz];
    heap[sz] = 0;   //把提上去的数值清零
    // 从根开始向下交换
    int i = 0;
    while(i*2 + 1 < sz) {
        //比较儿子的值
        int a = i*2 + 1, b = i*2 + 2;
        if(b < sz && heap[b] < heap[a])
            a = b;
        //如果没有大小颠倒则退出
        if(heap[a] >= x)
            break;
        // 把儿子的数值提上来
        heap[i] = heap[a];
        i = a;
    }
    heap[i] = x;
    return ret;
}
int main() {
    int temp, n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &temp);
        push(temp);
    }
    printf("%d\n", pop());
    for(int i = 0; i < n-1; i++) {
        printf("%d ", heap[i]);
    }
    printf("%d\n", heap[n-1]);
    return 0;
}
