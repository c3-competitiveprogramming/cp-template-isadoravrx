#include <iostream>
using namespace std;

int main(){
    int highvalue = -1, number;
    while(true){
        cin >> number;
        if(number == 0){
            break;
        }if(number > highvalue){
            highvalue = number;
        }
    }    

    cout << highvalue << endl;
    return 0;
}