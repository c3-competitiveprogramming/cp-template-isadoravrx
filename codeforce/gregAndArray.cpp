#include <iostream>
#include <vector>
using namespace std;

int main(){
    int tamanhoArray, qoperacoes, qconsultas; 
    cin >> tamanhoArray >> qoperacoes >> qconsultas;
    
    long long array[tamanhoArray];
    int value;
    for(int i = 0; i < tamanhoArray; i++){ // recebendo array
        cin >> value;
        array[i] = value;
    }

    long long fronteiraLeft, fronteiraRight, somador;
    long long operacoes[qoperacoes][3];
    for(int i = 0; i < qoperacoes; i++){ // recebendo as operações e colocando na matriz
        cin >> fronteiraLeft >> fronteiraRight >> somador;
        fronteiraLeft--;
        fronteiraRight--;
        operacoes[i][0] = fronteiraLeft;
        operacoes[i][1] = fronteiraRight;
        operacoes[i][2] = somador;
    }

    int opInicial, opFinal;
    vector<long long>cadeia_operacoes;
    cadeia_operacoes.assign(qoperacoes,0);
    for(int i = 0; i < qconsultas; i++){ 
        cin >> opInicial >> opFinal;
        opInicial--;
        opFinal--;
        cadeia_operacoes[opInicial] += 1;
        if(opFinal != qoperacoes - 1){
            cadeia_operacoes[opFinal + 1] -= 1;
        }        
    } //se eu converto essa linked list, eu sei quantas vezes cada operacao foi utilizada

    vector<long long>qvezes_utilizados;
    vector<long long>cadeia_posicoes;
    cadeia_posicoes.assign(tamanhoArray,0);
    for(int i = 0; i < qoperacoes;i++ ){
        if(i == 0){
            qvezes_utilizados.push_back(cadeia_operacoes[0]);
        }else{
            qvezes_utilizados.push_back(cadeia_operacoes[i] + qvezes_utilizados[i -1]);
        }
        cadeia_posicoes[operacoes[i][0]] += operacoes[i][2] * qvezes_utilizados[i];
        if(operacoes[i][1] != tamanhoArray - 1){
            cadeia_posicoes[operacoes[i][1] + 1] -= operacoes[i][2];
        }
    } //se eu converto essa linked list, eu vou saber 
    vector<long long>somadores;
    for(int i = 0; i < tamanhoArray; i++){
        if(i == 0){
            somadores.push_back(cadeia_posicoes[0]);
        }else{
            somadores.push_back(cadeia_posicoes[i] + somadores[i -1]);
        }

        array[i] = array[i] + somadores[i];
        if(i == tamanhoArray - 1){
            cout << array[i] << endl;
            break;
        }
        cout << array[i] << " ";
    }


    return 0;

}