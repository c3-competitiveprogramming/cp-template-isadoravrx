#include <iostream>
#include <vector>
using namespace std;

int main(){
    
    vector<int>digits;
    digits.push_back(9);
    
    long digitsLenght = digits.size();
    
    for(int i = digitsLenght - 1; i >= 0; i-- ){
        if(digits[i] != 9){
            digits[i] = digits[i] + 1;
            break;
        }else{
            digits[i] = 0;
        }

    }

    if(digits[0] == 0){
        digits.push_back(0);
        digits[0] = 1;
    }
}
