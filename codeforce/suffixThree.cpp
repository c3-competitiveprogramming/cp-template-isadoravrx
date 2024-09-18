#include <iostream>
#include <string>
using namespace std; 

int main(){
    int tests;
    cin >> tests;

    while(tests--){
        string frase;
        cin >> frase;

        int tamanhofrase = frase.length();
        string substring;
        substring =  frase.substr(tamanhofrase-2);

        if(substring == "po"){
            cout << "FILIPINO" << endl;
        }else if(substring == "su"){
            cout << "JAPANESE" << endl;
        }else if (substring == "da"){
            cout << "KOREAN" << endl;
        }

       
    }

    return 0;
}