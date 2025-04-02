#include <iostream>
using namespace std;

int main(){

    int quns = 0;
    for(int i = 0; i < 7; i++){
        int num;
        cin >> num;

        if(num == 1){
            quns++;
        }
    }

    bool ispar = false;
    if(quns % 2 == 0){
        ispar = true;
    }


    int bitseg;
    cin >> bitseg;

    if(ispar && bitseg == 0 || !ispar && bitseg == 1){
        cout << "N?" << endl;
    }else{
        cout << "S" << endl;
    }

}