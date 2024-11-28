#include <iostream>
#include <vector>
#include <math.h>
using namespace std;


bool isEquals(int temqueanunciar,vector<int>bolasPresentes){
    for(int i = 0; i < bolasPresentes.size(); i++){
        if(bolasPresentes[i] == temqueanunciar){
            return true;
        }
    }

    return false;
}

bool subAbs(int temqueanunciar,vector<int>bolasPresentes){
    int sub;
    for(int i = 0; i < bolasPresentes.size(); i++){
        for(int j = i + 1; j < bolasPresentes.size(); j++){  
            sub = abs(bolasPresentes[i] - bolasPresentes[j]);
            if(sub == temqueanunciar){
                return true;
            }
        }
    }

    return false;
}

int main(){
    while(true){
        vector<int>bolasPresentes;
        vector<int>temQueAnunciar;
        int n, bolasPermanecem;
        cin >> n >> bolasPermanecem;

        if(n == 0 && bolasPermanecem == 0){
            break;
        }
        int quantidadeBolas = n + 1;
        int numbolaPermaneceu;

        while(bolasPermanecem--){
            cin >> numbolaPermaneceu;
            bolasPresentes.push_back(numbolaPermaneceu);
        }

        for(int i = 0; i < quantidadeBolas; i++){
            temQueAnunciar.push_back(i);
        }

        bool isCalled = true;
        for(int i = 0; i < quantidadeBolas; i++){
            if(!isEquals(temQueAnunciar[i],bolasPresentes) && !subAbs(temQueAnunciar[i],bolasPresentes)){
                isCalled = false;
                break;
            }
        }

        if(isCalled){
            cout << "Y" << endl;
        }else{
            cout << "N" << endl;
        }
    }
    return 0;
}