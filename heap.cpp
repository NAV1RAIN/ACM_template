#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX_N = 1e5+10;
int heap[MAX_N], sz = 0;
void push(int x) {  //����������ֵ
    //�Լ��ڵ�ı��
    int i = sz++;

    while(i > 0) {
        // ���׽ڵ�ı��
        int p = (i - 1)/2;
        // ����Ѿ�û�д�С�ߵ����˳�
        if(heap[p] <= x)
            break;
        // �Ѹ��׽ڵ����ֵ�������������Լ�����ȥ
        heap[i] = heap[p];
        i = p;
    }
    heap[i] = x;
}
int pop() {     //������ȡ��ɾ����Сֵ
    // ��Сֵ
    int ret = heap[0];
    // Ҫ�ᵽ������ֵ
    int x = heap[--sz];
    heap[sz] = 0;   //������ȥ����ֵ����
    // �Ӹ���ʼ���½���
    int i = 0;
    while(i*2 + 1 < sz) {
        //�Ƚ϶��ӵ�ֵ
        int a = i*2 + 1, b = i*2 + 2;
        if(b < sz && heap[b] < heap[a])
            a = b;
        //���û�д�С�ߵ����˳�
        if(heap[a] >= x)
            break;
        // �Ѷ��ӵ���ֵ������
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
