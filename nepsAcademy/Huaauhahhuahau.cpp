#include <iostream>
#include <string>
using namespace std;

int main(){
    string risada;
    cin >> risada;
    string vogaisNaturais, vogaisReversas;
    for(int i = 0; i < risada.length(); i++){ //checando na forma direta
        
        if(risada[i] ==  'a' || risada[i] ==  'e' || risada[i] ==  'i' || risada[i] ==  'o' || risada[i] ==  'u' ){
            vogaisNaturais.push_back(risada[i]);
        }
    }

    for(int i = risada.length() - 1; i >= 0; i--){ //checando na forma reversa
        if(risada[i] ==  'a' || risada[i] ==  'e' || risada[i] ==  'i' || risada[i] ==  'o' || risada[i] ==  'u'){
            vogaisReversas.push_back(risada[i]);
        }
    }

    int wrong = 0;
    if(vogaisNaturais.length() != vogaisReversas.length()){
        cout << "N" << endl;
    }else{
        for(int i = 0; i < vogaisNaturais.length(); i++){
            if(vogaisNaturais[i] != vogaisReversas[i]){
                wrong++;
                break;
            }
        }

        if(wrong == 0){
            cout << "S" << endl;
        }else{
            cout << "N" << endl;
        }
    }
    return 0;
}