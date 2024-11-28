#include <iostream>
using namespace std;

int main(){
    int number,kTimes;
    cin >> number >> kTimes;
    while(kTimes--){
        if(number % 10 == 0){
            number /= 10;
        }else{
            number--;
        }
    }

    cout << number << endl;
    return 0;
}