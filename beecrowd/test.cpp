#include <iostream>
#include <bitset>
using namespace std;

int main(){
    bitset<10> bt(0);
    bt.set();
    for(int i = 0; i < 10; i++){
        cout << bt[i] << endl;
    }
}
