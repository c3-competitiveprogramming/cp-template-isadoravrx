#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int voltas, placas, totalDePlacas,calculation,answer, multiplicacao;
    cin >> voltas >> placas;
    totalDePlacas = voltas * placas;
    int numerador = 10;
    while(numerador <= 90){
        
        multiplicacao = numerador * totalDePlacas;
        calculation = multiplicacao / 100;
        
        if(multiplicacao % 100  == 0){
            
            answer = calculation;
        
        }else{
            answer = calculation + 1;
        }
        
        if(numerador == 90){

            cout << answer << endl;
        }else{
            cout << answer << " ";
        }
        multiplicacao = 0;
        calculation = 0;
        numerador = numerador + 10;
        
    }

    return 0;
}
