#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main(){
    string s;
    while(cin >> s){
        int cont = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] + 0 >= 97 && s[i] + 0 <=122 ){//letras minusculas
                cont += s[i] - 96;
            }else{
                cont += s[i] - 38; // pois A vale  65 
            }
        }
        
        bool isprimo = true;
        for(int i = 2; i <= sqrt(cont); i++){ // checkando se primo
            if(cont % i == 0){
                isprimo = false;
                break;
            }
        }

        if(isprimo == true){
            cout << "It is a prime word." << endl;
        }else{
            cout << "It is not a prime word." << endl;
        }
    }
}

