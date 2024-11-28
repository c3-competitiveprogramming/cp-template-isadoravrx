#include <iostream>
#include <vector>
using namespace std;

int main(){ 

    bool b = true;
    for(int i = 0; i < 8; i++){
        int num;
        cin >> num;

        if(num == 9){
            b = false;
        }
    }

    if(b){
        cout << "S" << endl;
    }else{
        cout << "F" << endl;
    }
    
    return 0;
}