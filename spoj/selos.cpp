#include <iostream>
#include <math.h>
using namespace std;

int main(){
    long long n, divisions = 0;
    cin >> n;
    for(long long i = 2; i<= sqrt(n); i++){
        if(n % i == 0){
            divisions++;    
        }
    }

    if(divisions == 0){ // se for primo, não consegue fazer
        cout << "N" << endl;
    }else{
        cout << "S" << endl;
    }
    return 0;
}