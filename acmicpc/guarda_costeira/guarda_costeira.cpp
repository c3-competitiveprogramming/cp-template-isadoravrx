#include <iostream>
#include <cmath>
using namespace std;

int main(){
    double d,v1,v2;
    
    while(cin >> d >> v1 >> v2){
        double dist = sqrt(144 + (d*d));

        double tempo_policia = dist/v2;

        double tempo_ladrao = 12/v1;

        if(tempo_policia <= tempo_ladrao){
            cout << "S" << endl;
        }else{
            cout << "N" << endl;
        }
    }
}