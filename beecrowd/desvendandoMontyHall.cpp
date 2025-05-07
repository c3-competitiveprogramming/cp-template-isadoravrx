#include <iostream>
using namespace std;

int main(){
    int jogosQ;
    int portaCarro;
    int counter = 0;
    cin >> jogosQ;
    
    while(jogosQ--){
        cin >> portaCarro;
        if(portaCarro != 1){
            counter++;
        }
    }

    cout << counter << endl;
}

