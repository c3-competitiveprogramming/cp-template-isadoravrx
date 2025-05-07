#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int exp, nov;
    cin >> exp >> nov;
    int counter = 0;
    while(true){
        if(exp < nov){
            exp--;
            nov = nov - 2;
        }else{  //exp == nov entra aqui
            exp = exp - 2;
            nov--;
        }
        if(exp < 0 || nov < 0){
            break;
        }

        counter++;
    }    


    cout << counter << endl;

    return 0;
}