#include <iostream>
#include <iterator>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;


int main(){
#if 0
    vector<int> con;
    vector<int>::iterator iter;
#else
    list<int> con;
    list<int>::iterator iter;
#endif
    copy(istream_iterator<int>(cin), 
            istream_iterator<int>(),
            back_inserter(con));

    cout << "output:" << endl;
    for (iter = con.begin(); iter != con.end(); iter++){
        cout << (*iter) << endl;
    }

    //sort(con.begin(), con.end());

    cout << "Another output:" << endl;
    copy(con.begin(), 
            con.end(), 
            ostream_iterator<int>(cout, "\n"));
    return 0;
}
