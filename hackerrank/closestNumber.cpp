#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b,x,testes;
    cin >> testes;
    while(testes--){
        cin >> a >> b >> x;
        double potencia;  
        potencia = pow(a,b);           
        int division = potencia / x;
        int lowAnswer = division * x;
        int highAnswer = (division * x) + x;  
        int lowSub = potencia - lowAnswer;
        int highSub =  highAnswer - potencia;
            if(lowSub < highSub){
                cout << lowAnswer << endl;
          
            }else if(lowSub > highSub){
                cout << highAnswer << endl;

            }else if(lowSub == highSub){
                cout << lowAnswer << endl;
            }

    }

    return 0;
    
}
