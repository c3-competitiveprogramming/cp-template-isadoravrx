#include <iostream>
using namespace std;

int main(){
    int helicoptero,policial,fugitivo,d;
    cin >> helicoptero >> policial >> fugitivo >> d;
    bool preso = false;

        
    if(d == -1){
        while(fugitivo != helicoptero){
            if(fugitivo == policial){
                preso = true;
                break;
            }
            if(fugitivo == 0){
                fugitivo = 15;
            }else{
                fugitivo--;
            }
            
        }
    }else{
        while(fugitivo != helicoptero){
            if(fugitivo == policial){
                preso = true;
                break;
            }
            if(fugitivo == 15){
                fugitivo = 0;
            }else{
                fugitivo++;
            }
            
        }
    }

    if(preso == false){
        cout << "S" << endl;
    }else{
        cout << "N" << endl;
    }
    

    return 0;

}