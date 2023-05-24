#include <iostream>
#include <vector>
using namespace std;

vector<int>array;
vector<vector<int>>operacoes;

void somadorDoArray(vector<int>adds){ 
    for(int i = 0; i < array.size(); i++){
        array[i] =  array[i] + adds[i];
    }
}

int main(){
    int tamanhoArray, qoperacoes, qconsultas; 
    cin >> tamanhoArray >> qoperacoes >> qconsultas;
    int value;
    while(tamanhoArray--){ // recebendo array
        cin >> value;
        array.push_back(value);
    }

    int fronteiraLeft, fronteiraRight, somador;
    operacoes.resize(qoperacoes);
    for(int i = 0; i < qoperacoes; i++){ // recebendo as operações e colocando na matriz
        
        cin >> fronteiraLeft >> fronteiraRight >> somador;
        fronteiraLeft--;
        fronteiraRight--;
        operacoes[i].push_back(fronteiraLeft);
        operacoes[i].push_back(fronteiraRight);
        operacoes[i].push_back(somador);
    }

    int opInicial, opFinal;
    vector<vector<int>>somadores;
    for(int i = 0; i < qconsultas; i++){ //recebendo o intervalo de operações 
        cin >> opInicial >> opFinal;
        opInicial--;
        opFinal--;
        
        
        somadores[i].assign(array.size(),0);

        for(int j = opInicial; j <= opFinal; j++){
            for(int k = 0; k < array.size(); k++){
                if(k >= operacoes[j][0] && k <= operacoes[j][1]){
                    somadores[i][k]+= operacoes[j][2];
                }
            }
        }

        
    }

    for(int i = 0; i < array.size(); i++){
        if(i == array.size() - 1){
            cout << array[i] << endl;
            break;
        }
        cout << array[i] << " ";
    }

    return 0;

}