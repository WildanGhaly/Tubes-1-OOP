#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main(){
    deque<int> d;
    d.push_back(1);
    d.push_back(2);
    d.push_back(3);
    d.push_back(4);
    d.push_front(0);

    for(int i = 0; i < d.size(); i++){
        cout << d[i] << endl;
    }
    cout<<endl;
    reverse(d.begin(),d.end());

    for(int i = 0; i < d.size(); i++){
        cout << d[i] << endl;
    }
   
}