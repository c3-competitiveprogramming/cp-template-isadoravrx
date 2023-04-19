#include <iostream>
using namespace std;

int main(){
    int pesoL, pesoB;
    cin >> pesoL >> pesoB;
    int counter = 0;
    while(true){
        if(pesoL > pesoB){
            break;
        }

        pesoL *= 3;
        pesoB *= 2;
        counter++;
    }

    cout << counter << endl;
    return 0;
}