#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> valores;
int n;
int sumlinhas = 0;
int sumcolunas = 0;
vector<int>somadaslinhas;
vector<int>somadascolunas;


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


    for(int i = 0; i < n; i++){ //soma das linhas
        for(int j = 0; j < n; j++){
            sumlinhas += valores[i][j];
        }
        somadaslinhas.push_back(sumlinhas);
        sumlinhas = 0;
    }

    for(int i = 0; i < n; i++){ //soma das colunas
        for(int j = 0; j < n; j++){
            sumcolunas += valores[j][i];
        }
        somadascolunas.push_back(sumcolunas);
        sumcolunas = 0;
    }

    int highpeso = 0;
    int nowpeso;
    int sum = 0; 

    for(int i = 0; i < n; i++){  //calculando os pesos
        for(int j = 0; j < n; j++){
            nowpeso = somadaslinhas[i] + somadascolunas[j] - 2 *valores[i][j];    
 
            if(nowpeso > highpeso){
                highpeso = nowpeso;
            }
        }
    }

    cout << highpeso << endl;
    return 0;
}