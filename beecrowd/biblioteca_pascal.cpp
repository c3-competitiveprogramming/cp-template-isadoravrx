#include <iostream>
#include <bitset>
using namespace std;

int main(){
    int n, d;
    while(true){
        cin >> n >> d;
        if(n == 0 && d == 0){
            break;
        }
        bitset<100> bt(0);
        bt.set();
        for(int i = 0; i < d; i++){
            for(int j = 0; j < n; j++){
                int value;
                cin >> value;
                if(value != 1){
                    bt[j] = 0;
                }
            }
        }
        
        bool hasAtLeastOne = false;
        for(int i = 0; i < n; i++){
            if(bt[i] == 1){
                hasAtLeastOne = true;
                break;
            }
        }

        if(hasAtLeastOne == true){
            cout << "yes" << endl;
        }else{
            cout << "no" << endl;
        }

    }
}

