#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> valores;
int n;

int calculatingpeso(int line , int column){
    int sum = 0; 
        
    for(int j = 0; j < n; j++){    //calculando o da linha
        if(j != column){
            sum+= valores[line][j];
        }
    }

    for(int i = 0; i < n; i++){ //calculando o da coluna
        if(i != line){
            sum += valores[i][column];
        }
    }

    return sum;
}


int main(){
    
    cin >> n;
    valores.resize(n);
    for(int i = 0; i < n; i++){ //recebendo a matriz
        for(int j = 0; j < n; j++){
            int value;
            cin >> value;
            valores[i].push_back(value);
        }
    }
    int highpeso = 0;
    int nowpeso;
    for(int i = 0; i < n; i++){  //calculando os pesos
        for(int j = 0; j < n; j++){
            nowpeso = calculatingpeso(i,j);
            if(nowpeso > highpeso){
                highpeso = nowpeso;
            }
        }
    }

    cout << highpeso << endl;
    return 0;
}