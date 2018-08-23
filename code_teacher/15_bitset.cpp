#include <iostream>
#include <bitset>
using namespace std;

int main(){
    bitset<64> bs;
    bs = 1;
    cout << bs << endl;
    bs ^= 63;
    cout << bs << endl;
    bs >>= 1;
    cout << bs << endl;
    cout << ~bs << endl;
    cout << "1 Bits: " << bs.count() << endl;
    cout << bs[32] << endl;
    bs.set(32);
    cout << bs[32] << endl;
    bs.flip(32);
    cout << bs[32] << endl;

    string t = bs.to_string();
    unsigned long t1 = bs.to_ulong();
    cout << t << endl << t1 << endl; 

    bs.reset();
    cout << bs << endl;
    cout <<  "Size: " << bs.size() << endl;

    cout << bs.any() << endl;
    cout << bs.none() << endl;

    cout << "input 0-1 string: " << endl;
    cin >> bs;
    cout << bs << endl;
    return 0;
}
